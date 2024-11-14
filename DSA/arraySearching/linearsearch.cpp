#include <iostream>

using namespace std;

// Function to perform linear search
int linear_search(int arr[],int size, int target) {
    for (int i = 0; i < size; ++i) {
        if (arr[i] == target) {
            return i; // Return the index of the target element if found
        }
    }
    return -1; // Return -1 if target is not found in the array
}

int main() {
    int array[] = {5, 3, 8, 6, 2, 7, 1, 4};
    int target_value = 6;

    int result = linear_search(array,8, target_value);

    if (result != -1) {
        cout << "Target " << target_value << " found at index " << result << "." << endl;
    } else {
        cout << "Target " << target_value << " not found in the array." << endl;
    }

    return 0;
}
