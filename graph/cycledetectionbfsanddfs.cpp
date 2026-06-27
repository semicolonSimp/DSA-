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
//cycle detection with directed graph use the method of dfs 
    bool cycledfs(int start,vector<bool>&vis,vector<bool>&rec){
        vis[start]=true;
        rec[start]=true;
        for(int neighbour:l[start]){
            if(!vis[neighbour]){
                if(cycledfs(neighbour,vis,rec)){
                    return true;
                }
            }else if(rec[neighbour]){
                return true;
            }
        }
        rec[start]=false;
        return false;
    }
    bool cycle(){
        vector<bool>visited(V,false);
        vector<bool>recursive(V,false);
        for(int i=0;i<V;i++){
            if(!visited[i]){
                if(cycledfs(i,visited,recursive)){
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
    if(g.cycle()){
        cout << "\nCycle Present";
    }
    else{
        cout << "\nCycle Not Present";
    }
}