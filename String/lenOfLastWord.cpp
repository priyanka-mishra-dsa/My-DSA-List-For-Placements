class Solution {
public:
    int lengthOfLastWord(string s) {
        //start iteration from the end so take a pointer at the last index
        int length=0;
        int i=s.size()-1;
        //step1:skip spaces
        while(i>=0 &&s[i]==' ')
        {
            //skip(move the pointer)
            i--;
        }
        //step2:count length of last word
        while(i>=0&&s[i]!=' ')
        {
            length++;
            i--;
        }
        return length;     
    }
};
