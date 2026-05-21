class Solution {
public:
vector<string>result;
void solve(int index,string &digits,string&temp,unordered_map<char,string>&m)
{
    //base case
    if(index==digits.size())
    {
        result.push_back(temp);
        return;
    }
    //respective char no ke liye jo string hai first find that
    char ch=digits[index];
    string s=m[ch];
    for(int i=0;i<s.size();i++)
    {
        char ch=s[i];
        temp.push_back(ch);
        solve(index+1,digits,temp,m);
        //backtrack
        temp.pop_back();
    }
    
}
    vector<string> letterCombinations(string digits) {
        unordered_map<char,string>m;
        m['2']="abc";
        m['3']="def";
        m['4']="ghi";
        m['5']="jkl";
        m['6']="mno";
        m['7']="pqrs";
        m['8']="tuv";
        m['9']="wxyz";
        string temp ="";
        solve(0,digits,temp,m);
        return result;   
    }
};
