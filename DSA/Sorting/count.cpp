#include<iostream>
using namespace std;
int main()
{
    int arr[6]={3,6,9,2,4,1};
    int max=-999;
    for(int i=0;i<6;i++)
    {
        if(arr[i]>max){
            max=arr[i];
        }
    }
    int arr2[max+1];
    for(int i=0;i<max+1;i++)
    {
        arr2[i]=0;
    }
    for(int i=0;i<6;i++)
    {
        int x=arr[i];
        arr2[x]++;
    }
    int j=0;
    for(int i=0;i<max+1;i++)
    {
        while(arr2[i]!=0){
            arr[j]=i;
            j++;
            arr2[i]--;
        }
        
    }
    for(int i=0;i<6;i++){
        cout<<arr[i]<<endl;
    }
}