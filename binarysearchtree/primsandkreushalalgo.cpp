

void prims(vector<vector<Edge>> &g(V),int V){
        vector<bool>InMst(V,false);
        priority_queue(vector<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>> >)pq;
        int mincost=0;
        pq.push({0,0});//{wt,vertex}
        
        while(!pq.empty()){
            int p=pq.top();
            int wt=p.first;
            int u=p.second;
            pq.pop();
            if(!InMst[u]){
                InMst[u]=true;
                mincost+=wt
            }
            for(int i=0;i<)
        }