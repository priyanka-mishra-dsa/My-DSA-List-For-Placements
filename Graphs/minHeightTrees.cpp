class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        //edge case
        if(n==1)
        return {0};
        //build a graph
        vector<vector<int>>adj(n);
        vector<int>degree(n,0);
        for(int i=0;i<edges.size();i++)
        {
            int a=edges[i][0];
            int b=edges[i][1];
            adj[a].push_back(b);
            adj[b].push_back(a);
            degree[a]++;
            degree[b]++;
        }
        vector<bool>visited(n,0);
        queue<int>q;
        for(int i=0;i<n;i++)
        {
            if(degree[i]==1)
            {
                q.push(i);
            }
        }
        int remainingNode=n;//n=6
        while(remainingNode>2)
        {
            int size=q.size();
            remainingNode=remainingNode-size;//6-4 =2
            while(size--)
            {
                int node=q.front();
                q.pop();
                for(int j=0;j<adj[node].size();j++)
                {
                    int neig=adj[node][j];
                    degree[neig]--;
                    if(degree[neig]==1)
                    {
                        q.push(neig);
                    }
                }
            }
        }
        //remaining nodes is present in the queue
        vector<int>ans;
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            ans.push_back(node);
        }
        return ans;   
    }
};
