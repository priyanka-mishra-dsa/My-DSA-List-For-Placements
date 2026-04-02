//Method1:TC:O(V2)
class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Convert edges into adj list(Graph)
        vector<vector<pair<int,int>>>adj(V);
        for(int i=0;i<edges.size();i++)
        {
            int u=edges[i][0];
            int v=edges[i][1];
            int w=edges[i][2];
            adj[u].push_back(make_pair(v,w));
            adj[v].push_back(make_pair(u,w));
        }
        //take a visited array
        vector<bool>visited(V,0);
        //take a dist array (min dist of all nodes from src)
        vector<int>dist(V,INT_MAX);
        dist[src]=0;
        //may be it is a disconnected graph
        //so you need to visit all the nodes
        int count=V;
        while(count--)
    {
        int node=-1,value=INT_MAX;
        for(int i=0;i<V;i++)
        {
            //step1:select that node who is unvisited and uska dist min hai
            //among all the unvisited node
            if(visited[i]==0&&value>dist[i])
            {
                node=i;
                value=dist[i];
            }
        }
        //selected node ko mark kro as visited
        visited[node]=1;
        //step 2:node will check its neig and give them the min dist
        for(int i=0;i<adj[node].size();i++)
        {
            int neig=adj[node][i].first;
            int weight=adj[node][i].second;
            if(visited[neig]==0&& dist[neig]>dist[node]+weight)
            {
                dist[neig]=dist[node]+weight;
            }
        }
    }
    return dist;
        
    }
};
//Method2:(optimized)
//using min heap
class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
          // Convert edges into adj list(Graph)
        vector<vector<pair<int,int>>>adj(V);
        for(int i=0;i<edges.size();i++)
        {
            int u=edges[i][0];
            int v=edges[i][1];
            int w=edges[i][2];
            adj[u].push_back(make_pair(v,w));
            adj[v].push_back(make_pair(u,w));
        }
        //take a visited array
        vector<bool>visited(V,0);
        //take a dist array (min dist of all nodes from src)
        vector<int>dist(V,INT_MAX);
        dist[src]=0;
        //for selection min dist node use min heap
        priority_queue<pair<int,int>,vector< pair<int,int>>,greater< pair<int,int>>>p;
        p.push(make_pair(0,src));
        while(!p.empty())
        {
            //find min dist node
            int node=p.top().second;
            p.pop();
            //check node is visited or not
            if(visited[node]==1)
            continue;
            //not visited
            visited[node]=1;
            //check for neig node of node
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
        return dist;
        
    }
};
