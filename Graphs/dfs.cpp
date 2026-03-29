//DFS Traversal:it is Graph traversal method which helps to visit all the nodes of the graph.
//Logic:Basically recursion method is used here.
//Time Complexity: O(V + E)
//Space Complexity:O(V+E)
class Solution {
  public:
  void dfs(int node,vector<vector<int>>& adj,vector<int>&visited,vector<int>&ans)
  {
    visited[node]=1;
    ans.push_back(node);
    //check for the neig node
    for(int i=0;i<adj[node].size();i++)
    {
        if(visited[adj[node][i]]==0)
        {
            //call dfs
            dfs(adj[node][i],adj,visited,ans);
        }
    }
  }
    vector<int> dfs(vector<vector<int>>& adj) {
        // Code here
        int vertex=adj.size();
        vector<int>visited(vertex,0);
        vector<int>ans;
        dfs(0,adj,visited,ans);
        return ans;
    }
};
