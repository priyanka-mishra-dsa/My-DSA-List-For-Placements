class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans(n);
        int i=0,j=n-1;
        int k=n-1;
        while(i<=j)
        {
            int sqrOfi=nums[i]*nums[i];
            int sqrOfj=nums[j]*nums[j];
            //value of square also maintain sorted order
            //fill larget value in end so start iteration from the end;
            if(sqrOfj>sqrOfi)
            {
                ans[k]=sqrOfj;
                //move j pointer
                j--;
                k--;
            }
            else if(sqrOfi>=sqrOfj)
            {
                ans[k]=sqrOfi;
                //move i pointer
                i++;
                k--;
            }
        }
        return ans;

    }
};
