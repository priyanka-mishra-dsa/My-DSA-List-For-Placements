//Imp**
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        //sliding window solve(use 2 pointer concept)
        //length of window is not given ,means variable length of sliding window
        //length is variable->window ka size abhi 0 pr hi rhega

        //s consists of English letters, digits, symbols and spaces.
        //koi char repeate na ho->count freq of each ch
        //longest substring me all char ki freq->1

        vector<bool>charFreq(256,0);
        int first=0,second=0,length=0;
        //"abcabcbb"
        while(second<s.size())
        {
            //second pointer char ke freq 0 hai
            char ch=s[second];
            if(charFreq[ch]==0)
            {
                //main isko ab dekh liya mark as visited
                charFreq[ch]=1;
                //count the length(sliding window ka length=second-first+1);
                length=max(length,second-first+1);
                //move second pointer
                second++;
            }
            else if(charFreq[ch]==1)
            {
                //window ko srink krenge
                //ja se hum move kiye uski freq fir se 0 kar do
                charFreq[s[first]]=0;
                first++;
                //when we dec the size of window ,len is become small thats why we do not cal leng here

            }
        }  
        return length;      
    }
};
