class Solution {
public:
    int trap(vector<int>& height) {
        //using 2 pointer approach
        int n=height.size();
        int water=0,leftMaxheight=0,rightMaxheight=0;
        int i=0,j=n-1;
        while(i<j)
        {
            leftMaxheight=max(leftMaxheight,height[i]);
            rightMaxheight=max(rightMaxheight,height[j]);
            //select that side jiska height min hai 
            //because if you select max height water will be leak
            if(leftMaxheight<rightMaxheight)
            {
                //select less height wala and calculate water
                water=water+leftMaxheight-height[i];
                i++;
            }
            else if(rightMaxheight<=leftMaxheight)
            {
               water=water+rightMaxheight-height[j];
               j--;
            }
        }
        return water;
        
    }
};
