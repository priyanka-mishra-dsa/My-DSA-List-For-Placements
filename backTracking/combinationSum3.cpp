class Solution {
public:
vector<vector<int>>result;
void solve(int start,int k,int target,vector<int>&temp)
{
    //base case
    if(k==0 && target==0)
    {
        result.push_back(temp);
        return;
    }
    //handle some invalid cases
    if(start>9 || k<0 ||target<0)
    return;
    //take current value
    temp.push_back(start);
    //call recursion for next value
    solve(start+1,k-1,target-start,temp);
    //backtracking
    temp.pop_back();
    //call recursion for next value
    solve(start+1,k,target,temp);
}
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>temp;
        solve(1,k,n,temp);
        return result;
    }
};
