class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        //using bfs level wise pattern solve
        unordered_set<string>st(wordList.begin(),wordList.end());
        //if target word is not present in the possible word list
        if(st.count(endWord)==0)
        return 0;
        queue<string>q;
        q.push(beginWord);
        int level=1;//find sequence so begin word is already a squence
        while(!q.empty())
        {
            int size=q.size();
            while(size--)
            {
                string word=q.front();
                q.pop();
                if(word==endWord)
                {
                    return level;
                }
                //generate neig
                for(int i=0;i<word.size();i++)
                {
                    char originalCh=word[i];
                    //one single ch vary from a-z
                    for(char ch ='a';ch<='z';ch++)
                    {
                        if(originalCh==ch)
                        continue;
                        word[i]=ch;
                        //agra word  wordlist me hoga tab hi queue me push krenge 
                        //and for mark as visited->remove that word from the list
                        if(st.count(word)==1)
                        {
                            q.push(word);
                            st.erase(word);
                        }
                        //restore the char for remaining index;
                        word[i]=originalCh;
                    }
                }
            }
             level++;
        }
        return 0;  
    }
};
