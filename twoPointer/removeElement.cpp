class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        //use 2 pointer
        int i=0;//i pointer represent krta hai kaha pr val hai jisko remove krna hai
        int j=0;//move in entire array
        while(j<nums.size())
        {
            //agar val mil gya 
            if(nums[j]==val)
            {
                //skip (remove)that element
                j++;
            }
            else if(nums[j]!=val)
            {
                nums[i]=nums[j];
                i++;
            }
        }
        //return unique element 
        return i;

        
    }
};
