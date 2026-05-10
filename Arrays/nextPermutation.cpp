//Imp ***
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        //step1:traverse from right side and find first chota element index
        int chotaElemIndex=-1;
        for(int i=n-1;i>0;i--)
        {
            if(nums[i]>nums[i-1])
            {
              chotaElemIndex=i-1;
              break;
            }
        }
         //edge case 
        //koi first chota element mila hi nhi
        //in that case reverse entire value wahi next permutation hoga
        if(chotaElemIndex==-1)
        {
            reverse(nums.begin(),nums.end());
            return;
        }
        //chota element se just next greater elem find kro and swap
        for(int i=n-1;i>chotaElemIndex;i--)
        {
            if(nums[i]>nums[chotaElemIndex])
            {
                swap(nums[i],nums[chotaElemIndex]);
                break;
            }
        }
        //reverse remaining part
        reverse(nums.begin()+chotaElemIndex+1,nums.end());   
    }
};
