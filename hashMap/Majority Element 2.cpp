//Using unordered map
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans;
        unordered_map<int,int>m;
        for(int i=0;i<n;i++)
        {
            m[nums[i]]++;
        }
        for(auto it:m)
        {
            if(it.second>n/3)
            {
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};
//For optimizing space from 0(n) to 0(1)
//we will use boyer moore voting algorithum
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        //in this question->maximum 2 and min 1 majority element ho sakte hai
        //apply both element ke liye boyer moore voting algorithum 
        int n=nums.size();
        int count1=0,candidate1=0;
        int count2=0,candidate2=0;
        //step1:for finding c1 and c2
        for(int i=0;i<n;i++)
        {
            if(nums[i]==candidate1)
            {
                count1++;
            }
            else if(nums[i]==candidate2)
            {
                count2++;
            }
            else if(count1==0)
            {
                candidate1=nums[i];
                count1=1;
            }
            else if(count2==0)
            {
                candidate2=nums[i];
                count2=1;
            }
            else//if nums[i]==3rd candidate in the case count of both candiadte ki value dec
            {
                count1--;
                count2--;
            }
        }
        //[3,2,3]->c1=3,c2=2
        //verify that both candidates is majority element or not
        count1=0,count2=0;
        vector<int>ans;
        for(int i=0;i<n;i++)
        {
            if(nums[i]==candidate1)
            count1++;
            else if(nums[i]==candidate2)
            count2++;
        }
        if(count1>n/3)
        ans.push_back(candidate1);
        if(count2>n/3)
        ans.push_back(candidate2);
        return ans;   
    }
};
