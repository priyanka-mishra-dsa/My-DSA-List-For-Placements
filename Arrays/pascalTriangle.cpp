class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        //given only numbers of rows
        //create pascal's traingle upto given no of rows
        vector<vector<int>>ans;
        for(int i=0;i<numRows;i++)
        {
            //create row,all values of row intially 1 hoga
            vector<int>row(i+1,1);
            //val change start from 3rd row and first and last element value no change
            for(int j=1;j<i;j++)
            {
               row[j]=ans[i-1][j-1]+ans[i-1][j];
            }
            ans.push_back(row);
        }
        return ans;
    }
};
