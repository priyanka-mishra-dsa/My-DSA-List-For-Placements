#include<bits/stdc++.h>
using namespace std;
int main()
{
        int N;
        cin>>N;
        vector<string>name(N);
        vector<string>gender(N);
        vector<char>grade(N);
        vector<int>age(N);
        for(int i=0;i<N;i++)
        {
                cin>>name[i]>>age[i]>>grade[i]>>gender[i];
               
        }
        //solve Q1
        for(int i=0;i<N;i++)
        {
                if(age[i]>20)
                cout<<name[i]<<" ";
        }
        //solve Q2
        int sumGrade=0,countFemale=0;
        for(int i=0;i<N;i++)
        {
           if(gender[i]=="Female")
           {
                sumGrade=sumGrade+grade[i];
                countFemale++;
           }
        }
        if(countFemale>0)
        {
             int average=sumGrade/countFemale;
             cout<<average;   
        }
        else
        {
                cout<<"No Female students";
        }
}
