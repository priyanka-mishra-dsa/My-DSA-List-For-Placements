class Solution {
public:
vector<vector<int>>result;
void solve(int index,vector<int>&nums,vector<int>&temp)
{
    if(index==nums.size())
    {
        result.push_back(temp);
        return;
    }
    //take current index element usko
    temp.push_back(nums[index]);
    //call the recusion for the next index
    solve(index+1,nums,temp);
    //backtracking
    temp.pop_back();
    //call recurion when not taking current index element
    solve(index+1,nums,temp);
}
    vector<vector<int>> subsets(vector<int>&nums) {
        vector<int>temp;
        solve(0,nums,temp);
        return result;
        
    }
};
