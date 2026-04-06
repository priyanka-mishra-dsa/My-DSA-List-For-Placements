class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        //make a graph
        vector<vector<int>>adj(n+1);
        for(auto&edges:dislikes)
        {
            int a=edges[0];
            int b=edges[1];
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        //using 2 coloring method of bfs
        vector<int>color(n+1,-1);
        queue<int>q;
        for(int i=0;i<n;i++)
        {
            if(color[i]==-1)
            {
                color[i]=0;
                q.push(i);
            }
            while(!q.empty())
            {
                int node=q.front();
                q.pop();
                for(int i=0;i<adj[node].size();i++)
                {
                    //1.color is not assign to neigh node
                    if(color[adj[node][i]]==-1)
                    {
                        color[adj[node][i]]=(color[node]+1)%2;
                        q.push(adj[node][i]);
                    }
                    //2.color is already assign to neigh node
                    else
                    {
                        //check ki same color toh nhi hai na
                        if(color[adj[node][i]]==color[node])
                        {
                            return false;
                        }
                    }
                }
            }
        }
        return true;
        
    }
};
