#include <iostream>
using namespace std;

// Partition function using Lomuto partition scheme, this scheme is not the same like in our slide, because our slide uses the first
// element as pivot.
int partition(int arr[], int low, int high) {
    // Choose the rightmost element as pivot
    int pivot = arr[high];
    int i = low - 1; // Index of smaller element

    for (int j = low; j < high; j++) {
        // If current element is smaller than or equal to pivot
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    // Place pivot in its correct position
    swap(arr[i + 1], arr[high]);
    return i + 1; // Return the partition index
}

// Recursive quick sort function
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        // Recursively sort elements before and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    quickSort(arr, 0, n - 1);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}