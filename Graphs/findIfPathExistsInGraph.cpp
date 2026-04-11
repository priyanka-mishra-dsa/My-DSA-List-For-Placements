class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        //build the graph
        vector<vector<int>>adj(n);
        for(int i=0;i<edges.size();i++)
        {
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<bool>visited(n,0);
        queue<int>q;
        q.push(source);
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            if(node==destination)
            {
                return true;
            }
            for(int i=0;i<adj[node].size();i++)
            {
                int neig=adj[node][i];
                if(visited[neig]==0)
                {
                    q.push(neig);
                    visited[neig]=1;
                }
            }
        }
        return false;
        
    }
};
