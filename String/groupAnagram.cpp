//***imp
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>>m;
        for(int i=0;i<strs.size();i++)
        {
            string word=strs[i];//store original string
            string key=word;
            //sort the word
            sort(key.begin(),key.end());
            m[key].push_back(word);
        }
        vector<vector<string>>ans;
        //move all groups of anagram into ans 
        //for this iterate on map
        //map me second value is group of anagram which is stored in the form of vector string
        for(auto pair:m)
        {
            ans.push_back(pair.second);
        }
        return ans;
    }
};
