class Solution {
public:
    vector<int> getRow(int rowIndex) {
        //row given hai->pascal's triangle me us row ke corresponding jo value hongi usi value ko return krna hai
        //first create value then return it
        vector<int>row(rowIndex+1,1);
        //update value of row(first &last element value unchanged)
        for(int i=1;i<rowIndex;i++)
        {
            for(int j=i;j>0;j--)
            {
                row[j]=row[j]+row[j-1];
            }
        }
        return row;      
    }
};
