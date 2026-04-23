class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        //path score->minimum dist from path 1->n
        //using simple bfs traversal
        //s1:build graph
        vector<vector<pair<int,int>>>adj(n);
        for(int i=0;i<roads.size();i++)
        {
            int u=roads[i][0]-1;
            int v=roads[i][1]-1;
            int w=roads[i][2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        //take visited array
        vector<bool>visited(n,0);
        queue<int>q;
        //intialize queue
        q.push(0);
        visited[0]=1;
        int ans=INT_MAX;
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            //visit neig node of node
            for(int i=0;i<adj[node].size();i++)
            {
                int neig=adj[node][i].first;
                int dist=adj[node][i].second;
                ans=min(ans,dist);
                if(visited[neig]==0)
                {
                    q.push(neig);
                    //mark as visited
                    visited[neig]=1;
                }
            }
        }
        return ans;
    }
};
