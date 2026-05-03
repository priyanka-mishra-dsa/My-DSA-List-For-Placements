class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        //Greedy->pattern(sort+two pointer)
        int n=g.size();
        int m=s.size();
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int i=0,j=0;
        int count=0;
        while(i<n&&j<m)
        {
            if(s[j]>=g[i])
            {
               count++;
               //move pointer
               i++;
               j++;
            }
            else
            {
                //try new cookie to feed them
                j++;
            }
        }
        return count;
    }
};
