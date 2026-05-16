class Solution {
public:
vector<vector<string>>result;
bool isPalindrome(string &s,int left,int right)
{
    while(left<right)
    {
        if(s[left]==s[right])
        {
            left++;
            right--;
        }
        else
        {
            return false;
        }
    }
    return true;
}
void solve(int start,int end,string &s,int &n ,vector<string>&temp)
{
    //base case
    //our start is original index of string
    if(start==n)
    {
        result.push_back(temp);
        return;
    }
    if(end==n)
    return;
    //start->end substring check that ki substring is palindrome
    //if substring is palindrome then you have apply core process
    if(isPalindrome(s,start,end))
    {
        //add in temp array because substring is palindrome
        temp.push_back(s.substr(start,end-start+1));
        //call the recursion for move to next partition
        solve(end+1,end+1,s,n,temp);
        //now backtracking
        temp.pop_back();
    }
    //not take current cut
    //expand substring
    solve(start,end+1,s,n,temp);
}
    vector<vector<string>> partition(string s) {
        vector<string>temp;
        int n=s.size();
        solve(0,0,s,n,temp);
        return result;    
    }
};
