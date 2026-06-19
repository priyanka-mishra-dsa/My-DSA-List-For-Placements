//Using recursion
class Solution {
public:
int recursion(vector<int>&cost,int index)
{
    
    int n=cost.size();
    //base case
    if(index>=n)
    return 0;
    int climb1step=recursion(cost,index+1)+cost[index];
    int climb2step=recursion(cost,index+2)+cost[index];
    int mincost=min(climb1step,climb2step);
    return mincost;
}
    int minCostClimbingStairs(vector<int>& cost) {
        //start from index 0
        int cost1=recursion(cost,0);
        //start from index 1
        int cost2=recursion(cost,1);
        //return min cost among them
        int minCost=min(cost1,cost2);
        return minCost; 
    }
};
//Using memorization Dp
