class Solution {
  public:
  int r,c;
  //covid patient can infect in up,down,left ,right direction
  int row[4]={-1,1,0,0};
  int col[4]={0,0,-1,1};
  //check index of row and col is valid or not
  bool valid(int i,int j)
  {
    return i>=0&&i<r&&j>=0&&j<c;
  }
    int helpaterp(vector<vector<int>> hospital) {
        //find row and col
        r=hospital.size();
        c=hospital[0].size();
        queue<pair<int,int>>q;
        //pure hospital me ghumo jisko corona hua hai usko queue me daalo
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(hospital[i][j]==2)
                {
                  //push only row and col of 2 into the queue
                  q.push(make_pair(i,j));
                }
            }
        }
         int timer=0;
        while(!q.empty())
        {
            timer++;
            //total no of corona patient in the queue
            int current_patient=q.size();
            while(current_patient--)
            {
                //corona patient kis row and col index pr hai
                int Row=q.front().first;
                int Col=q.front().second;
                q.pop();
                //corona pat spread corona to cell 1 in 4 direction
                for(int k=0;k<4;k++)
                {
                    if(valid(Row+row[k],Col+col[k])&& hospital[Row+row[k]][Col+col[k]]==1)
                    {
                        hospital[Row+row[k]][Col+col[k]]=2;
                        q.push(make_pair(Row+row[k],Col+col[k]));
                    }
                }
            }
        }
        //agar corona spread hi nhi hua
        if(timer==0)
        return 0;
        //pure hospital me check ki 1 present hai ya nhi
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(hospital[i][j]==1)
                {
                  return -1;
                }
            }
        }
        
        
        return timer-1;
        
        
    }
};
