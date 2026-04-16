class Solution {
public:
    bool isPerfectSquare(int num) {
        //Apply binary search here
        long long start=0;
        long long end=num;
        long long mid=0;
        while(start<=end)
        {
            mid=start+(end-start)/2;
            //calculate square
            long long square=mid*mid;
            if(square>num)
            {
                //go to left side
                end=mid-1;
            }
            else if(square<num)
            {
                //go to right side
                start=mid+1;
            }
            else if(square==num)
            {
                return true;
            }
        }
        return false;
        
    }
};
