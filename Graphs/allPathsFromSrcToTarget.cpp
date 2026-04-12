 //find all the paths from first node(source node) to last node(target) and store them.
//Graph->Directed acyclic graph means no cycle is present in the graph
//we cannot apply bfs here
//just do dfs traversal
//do not take visited vector because you miss the valid path ,use backtracking 
class Solution {
public:
void dfs(vector<vector<int>>& graph,int source,int target,vector<int>&path,vector<vector<int>>&result)
{
    int node=source;
    path.push_back(node);
    //if node==target means we get the path
    if(node==target)
    {
        result.push_back(path);
    }
    //if node!=target then visit all the neig
    else
    {
        for(int i=0;i<graph[node].size();i++)
        {
            int neig=graph[node][i];
            dfs(graph,neig,target,path,result);
        }
    }
    //do backtracking to find all possible path
    path.pop_back();
}
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n=graph.size();
        int source=0;
        int target=n-1;
        vector<vector<int>>result;
        vector<int>path;
        dfs(graph,source,target,path,result);
        return result;      
    }
};
