#include <iostream>
using namespace std;
int main()
{
    int arr[7] = {4, 7, 1, 2, 6, 3, 5};
    int size = 7;
    for (int gap = size / 2; gap > 0; gap /= 2)
    {
        for(int j=gap;j<size;j++){
            int temp=arr[j];
            int res=j;
            while(res>=gap && arr[res-gap] > temp){
                arr[res] = arr[res - gap];
                res -= gap;
            }
            arr[res]=temp;
        }
    }
    for(int i=0;i<7;i++){
        cout<<arr[i]<<endl;
    }
}