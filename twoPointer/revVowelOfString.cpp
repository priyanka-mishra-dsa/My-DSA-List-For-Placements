class Solution {
public:
bool isVowel(char ch)
{
    if(ch=='A'||ch=='E'||ch=='I'||ch=='O'||ch=='U'||ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u')
    return true;
    else 
    return false;
}
    string reverseVowels(string s) {
        int n=s.size();
        //apply 2 pointer
        int first=0;
        int second=n-1;
        while(first<second)
        {
            if(isVowel(s[first])&& isVowel(s[second]))
            {
                swap(s[first],s[second]);
                first++;
                second--;
            }
            else if(!isVowel(s[first]))
            {
                first++;
            }
            else if(!isVowel(s[second]))
            {
                second--;
            }
        }
        return s;   
    }
};
