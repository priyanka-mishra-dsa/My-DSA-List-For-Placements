class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five=0,ten=0;
        for(int i=0;i<bills.size();i++)
        {
           //5 rupya mila
           if(bills[i]==5)
           {
              //koi bhi change nhi dena to the customer
              //just count
              five++;
           }
           //10 rupya mila
           else if(bills[i]==10)
           {
              //change 5 ka ek
              //agar 5 present hi nhi hai 
              if(five==0)
              {
                return false;
              }
              five--;
              ten++;
           }
           //customer ne 20 rupaya diya
           else if(bills[i]==20)
           {
             //if 5 and 10 dono present hai
             if(five>0 && ten>0)
             {
                five--;
                ten--;
             }
             //agar 10 present nhi hai toh 
             //hme 5->3 changes dena pdega
             else if(ten==0&&five>=3)
             {
                five=five-3;
             }
             //5 and 10 both are not present
             else
             {
                return false;
             }

           }
        }
        return true;
        
    }
};
