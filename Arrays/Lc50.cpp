class Solution {
public:
double solve (double x,long n)
{
    //x power 0 ==1 (n==0)
    if(n==0)
    return 1;
    //n is negative(x ka power -n)=>1/x ka power n
    if(n<0)
    {
        return solve(1/x,-n);
    }
    //value of n is even
    //2 power 8 -> 
    if(n%2==0)
    {
        return solve(x*x,n/2);
    }
    else
    return x*solve(x*x,(n-1)/2);
}
    double myPow(double x, int n) {
        return  solve(x,(long)n);
        
    }
};
