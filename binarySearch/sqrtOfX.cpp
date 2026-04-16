class Solution {
public:
    int mySqrt(int x) {
        int start=0;
        int end=x;
        int mid=0;
        int ans=0;
        //edge cases
        if(x==0)
        return 0;
        if(x==1)
        return 1;
        while(start<=end)
        {
            mid=start+(end-start)/2;
            //find square=mid*mid
            if(mid>x/mid)
            {
                //move on left side
                end=mid-1;
            }
            else if(mid<x/mid)
            {
                //first store the mid
                ans=mid;
                //then move on right side
                start=mid+1;
            }
            else if(mid==x/mid)
            {
              return mid;
            }
        }
        return ans;
    }
};
