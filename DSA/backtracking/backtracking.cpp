#include<iostream>
using namespace std;
int ret=0;
int sum(int len,int arr[],int target)
{
    int cursum=0;
    if(len>0){
        for(int i=0;i<len;i++){
            while(cursum<=target){
                if(cursum==target){
                    ret++;
                }
                cursum=cursum + arr[i];   
            }
            cursum=cursum-arr[i];
        }
        sum(len--,arr,target);
    }  
    return ret;
}
int main()
{
    int arr[4]={2,3,6,7};
    int target=7;
    int x=sum(4,arr,target);
    cout<<"No of combinations are  "<< x;
}