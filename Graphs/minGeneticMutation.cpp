class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        unordered_set<string>st(bank.begin(),bank.end());
        queue<string>q;
        q.push(startGene);
        int level=0;
        //ch can change b/w A,C,G,T
        vector<char>neig={'A','C','G','T'};
        while(!q.empty())
        {
            int size=q.size();
            while(size--)
            {
                string word=q.front();
                q.pop();
                if(word==endGene)
                return level;
                for(int i=0;i<word.size();i++)
                {
                   char originalCh=word[i];
                   for(int j=0;j<neig.size();j++)
                   {
                     char ch=neig[j];
                     if(originalCh==ch)
                     continue;
                     word[i]=ch;
                     if(st.count(word)==1)
                     {
                        q.push(word);
                        st.erase(word);
                     }
                   }
                   //restore it
                   word[i]=originalCh;
                }

            }
            level++;

        }
        return -1;

        
    }
};
