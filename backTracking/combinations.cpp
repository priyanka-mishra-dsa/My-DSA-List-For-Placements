class Solution {
public:
   vector<vector<int>>result;
   void solve(int start,int &n,int k ,vector<int>&temp)
   {
     //fix templete of backtracking
     //s1:handle base case
     if(k==0)
     {
        result.push_back(temp);
        return;
     }
     //edge case(values 1-n ke range me hona chahiye)
     if(start>n)
     {
        return;
     }
     //S2:choose current value
     temp.push_back(start);
     //S3:after choosing current value call recusion for next element
     solve(start+1,n,k-1,temp);
     //s4:remove current element(main backtracking)
     temp.pop_back();
     //s5:after removing now call recusion for next element
     solve(start+1,n,k,temp);

   }

    vector<vector<int>> combine(int n, int k) {
        vector<int>temp;
        solve(1,n,k,temp);
        return result;
        
    }
};
