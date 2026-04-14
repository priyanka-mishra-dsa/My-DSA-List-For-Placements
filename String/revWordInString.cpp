//IMP**
class Solution {
public:
    string reverseWords(string s) {
        //remove extra spaces between two words.
        //remove extra spaces from front and back.
        //and reverse the words of given string and return the string

        //step1:reverse the whole string(means swap/rev each char ko)
        string ans="";
        int n=s.size();
        reverse(s.begin(),s.end());
        //step2:find word from string and reverse char of each word of the string
        for(int i=0;i<n;i++)
        {
            string word="";
            while(i<n && s[i]!=' ')
            {
                word=word+s[i];
                i++;
            }
            //reverse the word
            reverse(word.begin(),word.end());
            if(word.size()>0)
            {
                ans=ans+" "+word;//because b/w 2 words 1 space is must
            }
        }
        //in ans string begning(0 index pr) one extra space is added so you need to remove that space
        return ans.substr(1);//ans ko first index se return kar rhe hai
        
    }
};
