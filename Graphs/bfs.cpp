//BFS Traversal:it is Graph traversal method which helps to visit all the nodes of the graph.
//Logic:take a visited array and a queue for BFS Traversal.
//Time Complexity: O(V + E)
//Space Complexity:O(V+E)
class Solution {
  public:
    vector<int> bfs(vector<vector<int>> &adj) {
        int vertex=adj.size();
        vector<int>visited(vertex,0);
        queue<int>q;
        q.push(0);
        visited[0]=1;
        vector<int>ans;
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            ans.push_back(node);
            //check node ka neig node
            for(int i=0;i<adj[node].size();i++)
            {
                if(visited[adj[node][i]]==0)
                {
                    q.push(adj[node][i]);
                    visited[adj[node][i]]=1;
                }
            }
        }
        return ans;
        
    }
};
