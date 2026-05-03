class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxReach=0;//maxReach==>after max jump from any index max kitne index pr reach kro
        for(int i=0;i<nums.size();i++)
        {
            int maxJump=nums[i];//i=1->maxJump=3
            int maxJumpIndex=i+maxJump;//after jump aap 3 index pr nhi 4 index pr ja rhe ho isliye add 1
            //Greedy (always select maxReach wale index ko)
            if(i<=maxReach)
            {
                maxReach=max(maxReach,maxJumpIndex);
            }
            else //unreaceble index
            {
                return false;
            }
        }
        return true;
    }
};
