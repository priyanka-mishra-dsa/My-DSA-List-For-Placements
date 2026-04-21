class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        //solve using normal bfs(dijkstra fails due to condition k)
        //we cal lowest price withine k from src node to all the node
        //and then we will return lowest price of our destination node
        //for handling k we consider level of bfs

        //s1:build graph
        vector<vector<pair<int,int>>>adj(n);
        for(int i=0;i<flights.size();i++)
        {
            int u=flights[i][0];
            int v=flights[i][1];
            int p=flights[i][2];
            adj[u].push_back({v,p});
        }
        //s2:take a queue and dist(min price store)vector
        queue<pair<int,int>>q;
        vector<int>dist(n,INT_MAX);
        //s3:intialize queue and dist vector
        dist[src]=0;
        q.push({dist[src],src});
        int level=0;
        while(!q.empty()&& level<=k)
        {
            int size=q.size();
            while(size--)
            {
                int price=q.front().first;
                int node=q.front().second;
                q.pop();
                 //go to visit neig node and store its min dist/price
                 for(int i=0;i<adj[node].size();i++)
                 {
                    int neig=adj[node][i].first;
                    int neigPrice=adj[node][i].second;
                    if(dist[neig]>price+neigPrice)
                    {
                        dist[neig]=price+neigPrice;
                        q.push({dist[neig],neig});
                    }
                 }
            }
            level++;
        }
        return dist[dst]==INT_MAX?-1:dist[dst];
        
    }
};
