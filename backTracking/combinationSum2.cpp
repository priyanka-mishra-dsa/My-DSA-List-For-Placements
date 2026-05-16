class Solution {
public:
vector<vector<int>>result;
void solve(int index,int &n,vector<int>& candidates, int target,vector<int>&temp)
{
    //base case
    if(target==0)
    {
        result.push_back(temp);
        return;
    }
    //edge case
    if(index==n || target<0)
    return;
    //take current index element
    temp.push_back(candidates[index]);
    //call recusion for next index,because one element only can use one time only
    solve(index+1,n,candidates,target-candidates[index],temp);
    //backtracking
    temp.pop_back();
    //currently present current index and i want to go on the next index
    //before going check that index+1 element is duplicate element
    //if duplicate than skip
    while(index+1<n &&candidates[index]==candidates[index+1])
    {
        index++;
    }
    //call recursion to take next element
    solve(index+1,n,candidates,target,temp);

}
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        int n=candidates.size();
        vector<int>temp;
        solve(0,n,candidates,target,temp);
        return result;   
    }
};
