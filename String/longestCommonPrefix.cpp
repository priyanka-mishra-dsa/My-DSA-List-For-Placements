class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        //intialize ans string with first index of string
        string ans=strs[0];
        //comapre with remaining string
        for(int i=1;i<strs.size();i++)
        {
            string current=strs[i];
            string temp="";
            //comapre char of ans and current one by one
            for(int j=0;j<ans.size()&&j<current.size();j++)
            {
                if(ans[j]==current[j])
                {
                    temp=temp+ans[j];
                }
                //char mismatch toh stop comparision
                else if(ans[j]!=current[j])
                {
                    break;
                }
            }
            ans=temp;
        }
        return ans;
        
    }
};
