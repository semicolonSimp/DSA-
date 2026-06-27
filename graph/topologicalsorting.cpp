//topological sorting is only applicable for DAG(Directed Acyclic graph).
//concept is all u values are first than v
#include<iostream>
#include<stack>
#include<vector>
#include<list>
#include<queue>
using namespace std;
class Graph{
    int V;
    list<int> *l;
public:

    Graph(int V){
        this->V=V;
        l=new list<int>[V];
    }
    void addEdge(int u,int v){
        l[u].push_back(v);
    }
    void printAdjList(){
        for(int i=0;i<V;i++){
            cout<<i<<":";
            for(int n:l[i]){
                cout<<n<<" ";
            }
            cout<<endl;
        }
    }
    //Topological sort for dfs-
    void dfs(int start,vector<bool>&vis,stack<int>&s){
        vis[start]=true;
        for(int neighbour:l[start]){
            if(!vis[neighbour]){
                dfs(neighbour,vis,s);
            }
        }
        s.push(start);
    }
    void topologicalsort(){
        vector<bool>vis(V,false);
        stack<int>s;
        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfs(i,vis,s);
            }
        }
        while(s.size()>0){
            cout<<s.top();
            s.pop();

        }
        cout<<endl;
    }

    //Topological sort for bfs-kans algorithm
    void topoLogicalSort(){
        vector<int>result;
        vector<int>indegree(V,0);
        //calculate indegree
        for(int u=0;u<V;u++){
            for(int v:l[u]){
                indegree[v]++;
            }
        }
        //push in queue when inderee is zero
        queue<int>q;
        for(int i=0;i<V;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        //bfs
        while(q.size()>0){
            int curr=q.front();
            q.pop();
            result.push_back(curr);
            for(int v:l[curr]){
                indegree[v]--;
                if(indegree[v]==0){
                    q.push(v);
                }
            }
        }
        //print result
        for(int val:result){
            cout<<val<<" ";
        }
        cout<<endl;
    }
};
int main(){
    Graph g(5);
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(1,3);
    g.addEdge(2,3);
    g.addEdge(2,4);
    g.printAdjList();
    g.topologicalsort();
    g.topoLogicalSort();
}
