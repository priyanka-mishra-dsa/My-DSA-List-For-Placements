 class Solution {
public:
vector<vector<int>>result;
vector<int>path;
void solve(int src,int target,vector<vector<int>>& graph)
{
    int node=src;
    path.push_back(node);
    //base case
    if(node==target)
    {
        //we get a path
        result.push_back(path);
    }
    else if(node!=target)
    {
        //visit neig of curr node
        for(int i=0;i<graph[node].size();i++)
        {
            int neig=graph[node][i];
            solve(neig,target,graph);
        }
    }
    //use backtracking for next path
    path.pop_back();
}
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        //no of nodes
        int n=graph.size();
        //source
        int src=0;
        //target
        int target=n-1;
        solve(src,target,graph);
        return result;   
    }
};
