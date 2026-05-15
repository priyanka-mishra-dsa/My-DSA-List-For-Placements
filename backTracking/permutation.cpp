class Solution {
public:
vector<vector<int>>result;
void solve(int index,vector<int>& nums,  vector<int>&temp, vector<int>&visited)
{
    //base case
    if(temp.size()==nums.size())
    {
        result.push_back(temp);
        return;
    }
    //edge case
    if(index>=nums.size())
    return;

    //pick current index wala element ,if it is not visited
    if(visited[index]==0)
    {
        visited[index]=1;
        temp.push_back(nums[index]);
        //now call recursion for all the unused element
        solve(0,nums,temp,visited);
        //backtracking
        temp.pop_back();//remove last element
        //mark as unvisited
        visited[index]=0;
    }
    //call recusion,do not pick current index wala element
    solve(index+1,nums,temp,visited);

    
}
    vector<vector<int>> permute(vector<int>& nums) {
        //in making permutaions->use each elements exactly one time
        int n=nums.size();
        vector<int>temp;
        vector<int>visited(n,0);
        solve(0,nums,temp,visited);
        return result;
        
    }
};
