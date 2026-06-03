#include<iostream>
using namespace std;
int main()
{
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
        cin>>arr[i];
        int largest=arr[0];
        int secondLargest=-1;
        for(int i=1;i<n;i++)
        {
                //element largest element se bhi greater hai
                if(arr[i]>largest)
                {
                        secondLargest=largest;
                        largest=arr[i];
                }
                //any element is not greater than largest
                else if(arr[i]>secondLargest && arr[i]<largest)
                {
                        secondLargest=arr[i];
                }
        }
        cout<<secondLargest;
}
