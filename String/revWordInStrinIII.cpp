//Method 1:Tc=0(n*n)
class Solution {
public:
    string reverseWords(string s) {
        //find indiviual word
        //then reverse the char of that word
        //and store new words in string and return string
        int n=s.size();
        string ans="";
        for(int i=0;i<n;i++)
        {
            string word="";
            while(i<n && s[i]!=' ')
            {
                word=word+s[i];
                i++;
            }
            //reverse each char of word
            reverse(word.begin(),word.end());
            //store it in ans
            if(word.size()>0)
            {
               ans=ans+" "+word;
            }
        }
        return ans.substr(1);//because one extra space is added on oth index
        
    }
};
//Method2:Tc=0(n) using 2 pointer
class Solution {
public:
    string reverseWords(string s) {
        int n=s.size();
        int start=0;//starting index value
        for(int i=0;i<=n;i++)
        {
            if(i==n || s[i]==' ')
            {
                //now apply 2 pointer here
                int first=start;
                int second=i-1;
                while(first<second)
                {
                    swap(s[first],s[second]);
                    first++;
                    second--;
                }
                 start=i+1;//move to next word
            } 
        }
        return s;  
    }
};
