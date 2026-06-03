#include<iostream>
using namespace std;
int main()
{
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
        cin>>arr[i];
        //main logic
        //using 2 pointer we will revese the array
        int first=0;
        int second=n-1;
        while(first<second)
        {
                swap(arr[first],arr[second]);
                first++;
                second--;
        }
        //print the reverse array
        for(int i=0;i<n;i++)
        {
                cout<<arr[i]<<" ";
        }
}
