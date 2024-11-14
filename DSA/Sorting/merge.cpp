#include <iostream>
using namespace std;

void merge(int arr[], int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;

    int *L = new int[n1];
    int *R = new int[n2];

    for (int i = 0; i < n1; i++)
    {
        L[i] = arr[l + i];
    }
    for (int i = 0; i < n2; i++)
    {
        R[i] = arr[m + 1 + i];
    }
    int i = 0;
    int j = 0;
    int k = l;

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}
void mergesort(int A[], int low, int high)
{
    int medium;
    if (low < high)
    {
        medium = (low + high) / 2;
        mergesort(A, low, medium);
        mergesort(A, medium + 1, high);
        merge(A, low, medium, high);
    }
}

void printArray(int *A, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << A[i] << "  ";
    }
    cout << endl;
}
int main()
{
    int A[] = {9, 4, 4, 8, 7, 5, 6, 12};
    int n = 8;
    printArray(A, n);
    mergesort(A, 0, n - 1);
    printArray(A, n);
}