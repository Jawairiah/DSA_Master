#include<iostream>
using namespace std;
int main()
{
    int arr[6]={3,6,9,2,4,1};
    int j,min;
    for(int i=0;i<6;i++){
		min=i;
		for(int j=i+1;j<6;j++){
			if(arr[j]<arr[min]){
				min=j;
			}
		}
		int temp;
	    temp=arr[i];
		arr[i]=arr[min];
		arr[min]=temp;
	}
    for(int i=0;i<6;i++){
        cout<<arr[i]<<endl;
    }
}