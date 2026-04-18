//Method1:using sort+2 pointer
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int i=0,j=1;
        while(j<nums.size())
        {
            if(nums[i]==nums[j])
            {
                return true;
            }
            else
            {
                i++;
                j++;
            }
        }
        return false;
    }
};
//Method:using map count freq of each element of arr
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,int>freq;
        for(int i=0;i<nums.size();i++)
        {
           freq[nums[i]]++;
           if(freq[nums[i]]>1)
           {
            return true;
           }
        }
        return false;
    }
};
