class Solution {
public:
bool isVowel(char &ch)
{
    if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u'||ch=='A'||ch=='E'||ch=='I'||ch=='O'||ch=='U')
    return true;
    return false;
}
    string reverseVowels(string s) {
        int n=s.size();
        //take 2 pointer
        int i=0,j=n-1;
        while(i<j)
        {
            //i pointer wala char is not a vowel then move the pointer
            if(!isVowel(s[i]))
            {
                i++;
            }
             //j pointer wala char is not a vowel then move the pointer
            else if(!isVowel(s[j]))
            {
                j--;
            }
            else
            {
                //both char is vowel
                swap(s[i],s[j]);
                i++;
                j--;
            }
        }
        return s;

        
    }
};
