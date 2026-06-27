#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

class Edge{
public:
    int v;
    int wt;
    Edge(int v,int wt){
        this->v=v;
        this->wt=wt;
    }
    
};
    void dijakstra(int st,vector<vector<Edge>> &g,int V){
        vector<int>distance(V,INT_MAX);
        distance[st]=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>> >pq;//dis[u,v],u;
        pq.push({0,st});
        while(!pq.empty()){
            int u=pq.top().second;
            pq.pop();

            for(auto e:g[u]){
                if(distance[e.v]>distance[u]+e.wt){
                    distance[e.v]=distance[u]+e.wt;
                    pq.push({distance[e.v],e.v});
                }
            }
        }
        for(int i=0;i<V;i++){
            cout<<distance[i]<<" ";
        }
        cout<<endl;
    }
    void bellmanfordalgo(int st,vector<vector<Edge>> &g,int V){
        vector<int>dis(V,INT_MAX);
        dis[st]=0;

        for(int i=0;i<V-1;i++){
            for(int u=0;u<V;u++){
                for(auto e:g[u]){
                    if(dis[u] != INT_MAX && dis[e.v]>dis[u]+e.wt){
                        dis[e.v]=dis[u]+e.wt;
                    }
                }
            }
        }
        for(int i=0;i<V;i++){
            cout<<dis[i]<<" ";
        }
        cout<<endl;

    }
    
int main(){
    int V=6;
    vector<vector<Edge>> g(V);
    g[0].push_back(Edge(1,2));
    g[0].push_back(Edge(2,4));

    g[1].push_back(Edge(2,1));
    g[1].push_back(Edge(3,7));

    g[2].push_back(Edge(4,3));

    g[4].push_back(Edge(3,2));
    g[4].push_back(Edge(5,5));

    g[3].push_back(Edge(5,1));
    dijakstra(0,g,V);
    bellmanfordalgo(0,g,V);
}