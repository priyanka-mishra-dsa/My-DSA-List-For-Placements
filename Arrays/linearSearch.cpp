#include<iostream>
using namespace std;
int main()
{
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
        cin>>arr[i];
        int target;
        cin>>target;
        bool found=false;
        //main logic
        for(int i=0;i<n;i++)
        {
                if(arr[i]==target)
                {
                        found=true;
                        break;
                        
                }
        }
        if(found==true)
        {
                cout<<"target is found";
        }
        else
        cout<<"target is not found";
}
