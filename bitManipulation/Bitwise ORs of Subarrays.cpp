class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        //use set for storing all or operations of subarrays of previous element
        unordered_set<int>prev;
        //use set for storing all or operations of subarrays of current element
        unordered_set<int>curr;
        //use set for storing all or operations of subarrays as a final result
        unordered_set<int>ans;
        for(int i=0;i<arr.size();i++)
        {
            int element=arr[i];
            //with the help of prev set ,we can find curr element all subarrays or  values
            for(int x:prev)
            {
                curr.insert(x|element);
                ans.insert(x|element);
            }
            //after visiting all prev or values
            //or of current element ko bhi store krna pdega
            curr.insert(element);
            ans.insert(element);
            //update
            prev=curr;
            curr.clear();//for calculating next element values
        }
        //ans set only stores unique values of or operations
        return ans.size();
    }
};
