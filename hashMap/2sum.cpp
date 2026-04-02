class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        //array is not sorted so you cannot use 2 pointer concept here,use hashmap
        //we have to find=>a+b=target,we can write->b=target-a;(a=nums[i])
        //agar b first time dekha hai toh store and agin dekh liya means target se match ho gya
        //b is the no jo mil jaye to we can make a target
        vector<int>ans;
        unordered_map<int,int>m;
        for(int i=0;i<nums.size();i++)
        {
            int reqValue=target-nums[i];
            //if required value is already present in map,we can find target
            //return previous value and current value index
            if(m.count(reqValue))//value presnt hai ya nhi
            {
              //present hai
              ans.push_back(m[reqValue]);
              ans.push_back(i);
              return ans;
            }
            //if required value is not present in map
            m[nums[i]]=i;
        }
        //agar target value na mile then return empty array
       return {};
        
    }
};
