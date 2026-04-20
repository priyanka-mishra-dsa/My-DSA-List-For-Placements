class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        //build graph
        vector<vector<pair<int,int>>>adj(n);
        for(int i=0;i<edges.size();i++)
        {
           int u=edges[i][0]-1;
           int v=edges[i][1]-1;
           int w=edges[i][2];
           adj[u].push_back(make_pair(v,w));
           adj[v].push_back(make_pair(u,w));
        }
        //step1:find shortest distance from src to all nodes
        //step2:find path use parent vector
        vector<int>parent(n,-1);
        vector<bool>visited(n,0);
        vector<int>dist(n,INT_MAX);
        dist[0]=0;
           //take min heap
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> p;
        p.push(make_pair(dist[0],0));
        while(!p.empty())
        {
            //top pr wo node hoga jiska dist min hoga
            int node=p.top().second;
            p.pop();
            if(visited[node]==1)
            continue;
            visited[node]=1;
            //assign min dist to neig node of current node
            for(int i=0;i<adj[node].size();i++)
            {
                int neig=adj[node][i].first;
                int wei=adj[node][i].second;
                if(dist[neig]>dist[node]+wei)
                {
                    dist[neig]=dist[node]+wei;
                    parent[neig]=node;
                    p.push(make_pair(dist[neig],neig));
                }
            }
        }
        //find path(start finding from the last node)
        vector<int>path;
        int node=n-1;
        if(dist[n-1]==INT_MAX)
        {
            return {-1};
        }
        while(node!=-1)
        {
            path.push_back(node+1);
            //node will go back to its parent node
            node=parent[node];
        }
        reverse(path.begin(),path.end());
        //in ans dist of last node and path also stored
        vector<int>ans;
        ans.push_back(dist[n-1]);
        for(int i=0;i<path.size();i++)
        {
            ans.push_back(path[i]);
        }
        return ans;
    }
};
