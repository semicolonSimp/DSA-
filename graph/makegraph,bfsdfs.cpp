#include<iostream>
#include<list>
#include<vector>
#include<queue>
using namespace std;
//start graph make 
class Graph{
    int V;
    list<int> *l;

public:
    Graph(int V){
        this->V=V;
        l= new list<int>[V];
    
    }
//make connection b/w edge and verticies
    void addEdge(int u,int v){
        l[u].push_back(v);
        l[v].push_back(u);

    }
//print adjency list
    void print_Adjlist(){
        for(int i=0;i<V;i++){
            cout<<i<<":";
            for(int n:l[i]){
                cout<<n<<" ";
            }
            cout <<endl;
        }
    }
//end graph make 

//code for bfs
    void validbfs(int start,vector<bool>&vis){
        queue<int>q;
        q.push(start);
        vis[start]=true;
        while(q.size()>0){
            int u=q.front();
            q.pop();
            cout<<u<<" ";

            for(int neighbour:l[u]){
                if(!vis[neighbour]){
                    vis[neighbour]=true;
                    q.push(neighbour);
                }
            }
        }

    }
    void bfs(){
        vector<bool>visited(V,false);
        for(int i=0;i<V;i++){
            if(!visited[i]){
                validbfs(i,visited);
            }
        }
    }

//code for dfs
    void validdfs(int start,vector<bool>&vis){
        cout<<start;
        vis[start]=true;
        for(int neighbour:l[start]){
            if(!vis[neighbour]){
                validdfs(neighbour,vis);
            }
        }
    }
    void dfs(){
        vector<bool>visited(V,false);
        for(int i=0;i<V;i++){
            if(!visited[i]){
                validdfs(i,visited);
            }
        } 
    }
//cycle detection use the method of dfs 
    bool cycledfs(int start,int parent,vector<bool>&vis){
        vis[start]=true;
        for(int neighbour:l[start]){
            if(!vis[neighbour]){
                if(cycledfs(neighbour,start,vis)){
                    return true;
                }
            }else if(neighbour!=parent){
                return true;
            }
        }
        return false;
    }
    bool cycle(){
        vector<bool>visited(V,false);
        for(int i=0;i<V;i++){
            if(!visited[i]){
                if(cycledfs(i,-1,visited)){
                    return true;
                }
            }
        } 
        return false;
    }
//cycle detection for bfs method
    bool cyclevalidbfs(int start,vector<bool>&vis){
        queue<pair<int,int>>q;
        q.push({start,-1});
        vis[start]=true;
        while(q.size()>0){
            int u=q.front().first;
            int paru=q.front().second;
            q.pop();

            for(int neighbour:l[u]){
                if(!vis[neighbour]){
                    vis[neighbour]=true;
                    q.push({neighbour,u});
                }else if(neighbour!=paru){
                    return true;
                }
            }
            
        }

        return false;
    }
    bool cyclebfs(){
        vector<bool>visited(V,false);
        for(int i=0;i<V;i++){
            if(!visited[i]){
                if(cyclevalidbfs(i,visited)){
                    return true;
                }
            }
        }
        return false;
    }
};
int main(){
    Graph g(5);
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(1,3);
    g.addEdge(2,3);
    g.addEdge(2,4);
    g.print_Adjlist();
    g.bfs();
    g.dfs();
    
    if(g.cycle()){
        cout << "\nCycle Present";
    }
    else{
        cout << "\nCycle Not Present";
    }
    if(g.cyclebfs()){
        cout << "\nCycle Present";
    }
    else{
        cout << "\nCycle Not Present";
    }
    return 0;


}
