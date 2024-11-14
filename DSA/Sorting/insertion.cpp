#include<iostream>
using namespace std;
int main()
{
    int arr[6]={3,6,9,2,4,1};
    for(int i=0;i<6;i++)
    {
        for(int j=i;j>0;j--){
            if(arr[j]<arr[j-1]){
                int l=arr[j];
                arr[j]=arr[j-1];
                arr[j-1]=l;
            }
        }
    }
    for(int i=0;i<6;i++){
        cout<<arr[i]<<endl;
    }
}