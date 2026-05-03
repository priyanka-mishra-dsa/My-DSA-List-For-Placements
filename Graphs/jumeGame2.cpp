class Solution {
public:
    int jump(vector<int>& nums) {
        //use bfs and count levels
        //here levels==jumps
        int n=nums.size();
        queue<int>q;
        vector<bool>visited(n,0);
        q.push(0);
        visited[0]=1;
        int jumps=0;
        while(!q.empty())
        {
            int size=q.size();
            while(size--)
            {
                //index nikalo and check for neig index
                int i=q.front();
                q.pop();
                for(int j=i+1;j<=i+nums[i]&&j<n;j++)
                {
                    //jo neig mila wahi last index hai
                    if(j==n-1)
                    return jumps+1;
                    if(visited[j]==0)
                    {
                        q.push(j);
                        visited[j]=1;
                    }
                }

            }
            jumps++;
        }
        return 0;
        
    }
};
