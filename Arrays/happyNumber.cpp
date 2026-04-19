class Solution {
public:
//fun to calcualte sum of squares of digits
int Sum(int n)
{
    int sum=0;
    while(n!=0)
    {
        int digit=n%10;
        sum=sum+digit*digit;
        n=n/10;
    }
    return sum;
}
    bool isHappy(int n) {
        //digits of square==1(happy no)
        //digits of square=trap in cycle (not a happy no)when slow==fast
        //using slow and fast pointer
        int slow=n;
        int fast=n;
        //slow moves 1 step and fast moves 2 step
        while(true)
        {
            slow=Sum(slow);
            fast=Sum(Sum(fast));
            if(fast==1)
            return true;
            if(slow==fast)
            return false;
        }
    }
};
