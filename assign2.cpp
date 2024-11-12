#include <iostream>
using namespace std;

// Function to partition the array
int partition(int arr[], int lb, int ub) {
    int pivot = arr[lb];
    int start = lb;
    int end = ub;

    while (start < end) {
        while (start < ub && arr[start] <= pivot) {
            start++;
        }
        while (arr[end] > pivot) {
            end--;
        }
        if (start < end) {
            // Swap elements at start and end
            swap(arr[start], arr[end]);
        }
    }

    // Swap pivot with the element at the end position
    swap(arr[lb], arr[end]);
    return end;
}

// Function to partition the array with the last element as the pivot
// int partition(int arr[], int lb, int ub) {
//     int pivot = arr[ub];  // Set the pivot as the last element
//     int start = lb;
//     int end = ub - 1;

//     while (start <= end) {
//         while (start <= end && arr[start] <= pivot) {
//             start++;
//         }
//         while (end >= start && arr[end] > pivot) {
//             end--;
//         }
//         if (start < end) {
//             // Swap elements at start and end
//             swap(arr[start], arr[end]);
//         }
//     }

//     // Swap pivot with the element at the start position
//     swap(arr[start], arr[ub]);
//     return start;  // Return the pivot index
// }


// Recursive QuickSort function
void quicksort(int arr[], int lb, int ub) {
    if (lb < ub) {
        int loc = partition(arr, lb, ub);
        quicksort(arr, lb, loc - 1);
        quicksort(arr, loc + 1, ub);
    }
}

int main() {
    int arr[] = {7, 6, 10, 5, 9, 2, 1, 15, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    quicksort(arr, 0, n - 1);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
