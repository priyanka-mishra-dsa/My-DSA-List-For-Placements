class Solution {
public:
vector<string> findNeig(string curr)
{
    vector<string>result;
    for(int i=0;i<4;i++)
    {
        char ch=curr[i];
        //each wheel ko 2 ways to move inc and dec
        //increment
        char inc=ch=='9'?'0':ch+1;
        curr[i]=inc;
        result.push_back(curr);
        //decrement
        char dec=ch=='0'?'9':ch-1;
        curr[i]=dec;
        result.push_back(curr);
        //restore value because har ek index ke liye neig find krna hai
        curr[i]=ch;
    }
    return result;
}
    int openLock(vector<string>& deadends, string target) {
        //mark state as visited ->each deadends also a visited state
        unordered_set<string>st(deadends.begin(),deadends.end());
        string start="0000";
        if(st.count(start)==1)//means start end is the dead end
        return -1;
        queue<string>q;
        q.push(start);
        st.insert(start);
        int level=0;//minimum moves
        while(!q.empty())
        {
            int size=q.size();
            while(size--)
            {
               string currState=q.front();
            q.pop();
            if(currState==target)
            return level;
            //find all possible neigh of state 
            vector<string>neig=findNeig(currState);
            //traverse on neig
            for(int i=0;i<neig.size();i++)
            {
                string neigState=neig[i];
                //if it is not visited 
                if(st.count(neigState)==0)
                {
                    q.push(neigState);
                    //mark as visited
                    st.insert(neigState);
                }
            }
            }
            
            level++; 
        }
        return -1;  
    }
};
