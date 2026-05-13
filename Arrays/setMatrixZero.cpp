class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        vector<int>row(m,0);
        vector<int>col(n,0);
        //pure matrix me traverse kro jis index ka value
        //0 hai uske row and col ko mark as 1 in row and col vector
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(matrix[i][j]==0)
                {
                    row[i]=1;
                    col[j]=1;
                }
            }
        }
        //fir se pure matrix me traverse karo jis and jis row and col ki value
        //row and col matrix me 1 ayegi
        //usi cell ko mark as 0
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(row[i]==1 || col[j]==1)
                {
                    matrix[i][j]=0;
                }
            }
        }
        
        
    }
};
