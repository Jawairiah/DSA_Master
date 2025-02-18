#include <iostream>
using namespace std;
class Heap
{
public:
    int arr[100];
    int size;
    Heap()
    {
        size = 0;
        arr[0] = -1;
    }
    void insert(int key)
    {
        size = size + 1;
        int index = size;
        arr[index] = key;

        while (index > 1)
        {
            int parent = index / 2;
            if (arr[parent] < arr[index])
            {
                swap(arr[parent], arr[index]);
                index = parent;
            }
            else
            {
                return;
            }
        }
    }
    void print()
    {
        for (int i = 1; i <= size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    void deletion()
    {
        if (size == 0)
        {
            cout << "Nothing to delete" << endl;
            return;
        }

        arr[1] = arr[size];
        size--;
        int i = 1;
        while (i < size)
        {
            int leftIndex = 2 * i;
            int rightIndex = 2 * i + 1;
            if (leftIndex < size && arr[i] < arr[leftIndex])
            {
                swap(arr[i], arr[leftIndex]);
                i = leftIndex;
            }
            else if (rightIndex < size && arr[rightIndex])
            {
                swap(arr[i], arr[rightIndex]);
                i = rightIndex;
            }
            else
            {
                return;
            }
        }
    }
};
void Heapify(int arr[], int n, int i)
{
    int largest = i;
    int left = 2 * i;
    int right = 2 * i + 1;

    if (left<n && arr[left] > arr[largest])
    {
        largest = left;
    }
    if (right<n && arr[right] > arr[largest])
    {
        largest = right;
    }

    if(largest!=i){
        swap(arr[largest],arr[i]);
        Heapify(arr,n,largest);
    }
}
int main()
{
    // Heap h;
    // h.insert(50);
    // h.insert(55);
    // h.insert(53);
    // h.insert(52);
    // h.insert(54);
    // h.print();
    // h.deletion();
    // h.print();

    int n=5;
    int arr2[6]={-1,54,53,55,52,50};
    for(int i=n/2;i>0;i--)
    {
       Heapify(arr2,n,i);
    }
    for(int i=1;i<=n;i++){
        cout<<arr2[i]<<" ";
    }
}