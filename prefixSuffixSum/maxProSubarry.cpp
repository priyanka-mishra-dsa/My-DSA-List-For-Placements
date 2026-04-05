class Solution {
public:
    int maxProduct(vector<int>& nums) {
        //we cannot ignore neg no because(neg*neg)=positive
        //here you need to calculate maxproduct and minproduct of subarray
        int maxProduc=nums[0];
        int currMaxPro=1,currMinPro=1;
        for(int i=0;i<nums.size();i++)
        {
             //if nums[i]==0 then reset the value
             if(nums[i]==0)
             {
                currMaxPro=1;
                currMinPro=1;
                maxProduc=max(maxProduc,0);
             }
             //if nums[i] neg value ,we cannot ignore this 
             if(nums[i]<0)
             {
                swap(currMaxPro,currMinPro);
             }
             currMaxPro=max(currMaxPro*nums[i],nums[i]);
             currMinPro=min(currMinPro*nums[i],nums[i]);
             maxProduc=max(maxProduc,currMaxPro);
        }
        return maxProduc;

        
    }
};
