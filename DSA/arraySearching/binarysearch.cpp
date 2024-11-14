#include <iostream>
using namespace std;
int binary_search(int arr[],int low,int high, int target) {
    while(low<=high){
        int mid=(low+high)/2;
        if(target==arr[mid])
        {
            return mid; 
        }
        else if(target>arr[mid])
        {
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return -1; // Return -1 if target is not found in the array
}
int rec_binary_search(int arr[],int low,int high, int target) {
    if(low<=high){
        int mid=(low+high)/2;
        if(target==arr[mid])
        {
            return mid;
        }
        else if(target>arr[mid])
        {
            return rec_binary_search(arr,mid+1,high, target);
        }
        else{
            return rec_binary_search(arr,low,mid-1, target);
        }
    }
    return -1; // Return -1 if target is not found in the array
}

int main() {
    int array[] = {1,2,3,4,6,6,6,6,10,13};
    int target_value = 6;

    int result = binary_search(array,0,10, target_value);

    if (result != -1) {
        cout << "Target " << target_value << " found at index " << result << "." << endl;
    } else {
        cout << "Target " << target_value << " not found in the array." << endl;
    }

    return 0;
}
