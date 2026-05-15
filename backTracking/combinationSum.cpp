class Solution {
public:
vector<vector<int>> result;
void solve(int index,vector<int>& candidates, int target, vector<int>&temp)
{
    //base case 
    if(target==0)
    {
        result.push_back(temp);
        return;
    }
    //edge case
    if(index>=candidates.size() || target<0 )
    return;
    //take same index element
    temp.push_back(candidates[index]);
    //after that call recusion
    //use same index because it is mention in question
    solve(index,candidates,target-candidates[index],temp);
    //do backtracking
    temp.pop_back();
    //not choosing current index
    //now after backtracking call recusion for next index
    //do not substract target when we are moving to next index
    solve(index+1,candidates,target,temp);
}
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>temp;
        solve(0,candidates,target,temp);
        return result;   
    }
};
