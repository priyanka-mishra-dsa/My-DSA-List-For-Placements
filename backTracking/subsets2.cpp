class Solution {
public:
vector<vector<int>>result;
void solve(int index,int &n,vector<int>& nums,vector<int>&temp)
{
    //base case
    if(index==n)
    {
        result.push_back(temp);
        return;
    }
    //take current index element
    temp.push_back(nums[index]);
    //call the recursion for next index element
    solve(index+1,n,nums,temp);
    //backtracking
    temp.pop_back();
    //currently i am present on index and want to go on the index+1 element
    //if index+1 wala element is duplicate element then skip that index+1 element
    //and move to the next index
    while(index+1<n && nums[index]==nums[index+1])
    {
        index++;
    }
    //now call recursion for next index element
    solve(index+1,n,nums,temp);

}
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        //to not include or ignore duplicate subset
        //sort the array so that duplicate elements becomes adjacent to each other
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<int>temp;
        solve(0,n,nums,temp);
        return result;   
    }
};
