class Solution {
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        //using bfs(Khan's Algorithum)
        //convert edges into adj list(graph)
        vector<vector<int>>adj(V);
         //calculate indegree of each vertex
        vector<int>inDegree(V,0);
        for(int i=0;i<edges.size();i++)
        {
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(v);
            inDegree[v]++;
        }
        //take a queue
        vector<bool>visited(V,0);
        vector<int>ans;
        queue<int>q;
        //push that element in queue whose indegree is 0
        for(int i=0;i<V;i++)
        {
            if(visited[i]==0&&inDegree[i]==0)
            {
                q.push(i);
            }
        }
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            ans.push_back(node);
            //check node's neig node
            for(int i=0;i<adj[node].size();i++)
            {
                //dec neig node indegree by 1
                inDegree[adj[node][i]]--;
                //push node jiski indegree 0 ho gya hai
                if(inDegree[adj[node][i]]==0&&visited[adj[node][i]]==0)
                {
                    q.push(adj[node][i]);
                }
            }
        }
        return ans;
        
        
        
    }
};
