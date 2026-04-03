//Using Dijkstra Algorithum
class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        //conert edgest into adj list graph
        int k=distanceThreshold;
        vector<vector<pair<int,int>>>adj(n);
        for(int i=0;i<edges.size();i++)
        {
            //undirected graph
            int u=edges[i][0];
            int v=edges[i][1];
            int w=edges[i][2];
            adj[u].push_back(make_pair(v,w));
            adj[v].push_back(make_pair(u,w));
        }
        //treat each node as source node and find shortest dist using dijkstra algorithum
        int resultCity=-1,minRecableCity=n;
        for(int src=0;src<n;src++)
        {
            vector<bool>visited(n,0);
            vector<int>dist(n,INT_MAX);
            dist[src]=0;
            //take a min heap
            priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>p;
            //intialize queue
            p.push(make_pair(dist[src],src));
            while(!p.empty())
            {
                //chose that node whose dist is min 
                int node=p.top().second;
                p.pop();
                //if node is visited
                if(visited[node]==1)
                continue;
                //not visited
                visited[node]=1;
                //check for the neig node
                for(int i=0;i<adj[node].size();i++)
                {
                    int neig=adj[node][i].first;
                    int weight=adj[node][i].second;
                    if(visited[neig]==0&&dist[neig]>dist[node]+weight)
                    {
                        dist[neig]=dist[node]+weight;
                        p.push(make_pair(dist[neig],neig));
                    }
                }
            }
            //step2:count reacable city(dist<=k) for each src node 
            int count=0;
            for(int j=0;j<n;j++)
          {
            if(j!=src &&dist[j]<=k)
            {
                count++;
            }
          }
             //step3:find that city(src ) jise min city reaceble hai
            if(count<minRecableCity)
            {
                minRecableCity=count;
                resultCity=src;
            }
            //If two cities have the same number of reachable cities, choose the city with larger index
            else if(count==minRecableCity)
            {
                //city 0 and city 3 same,chose city 3
                resultCity=src;
            }
        
        }
        return resultCity;

    }
};
