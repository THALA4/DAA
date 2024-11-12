#include <iostream>
using namespace std;

// Function to merge two halves of an array
void merge(int A[], int l, int mid, int h) {
    int i = l, j = mid + 1, k = l;
    int B[h+1]; // Temporary array for merging

    while (i <= mid && j <= h) {
        if (A[i] < A[j]) {
            B[k++] = A[i++];
        } else {
            B[k++] = A[j++];
        }
    }

    // Copy any remaining elements from the left half
    while (i <= mid) {
        B[k++] = A[i++];
    }

    // Copy any remaining elements from the right half
    while (j <= h) {
        B[k++] = A[j++];
    }

    // Copy the sorted elements back to the original array
    for (i = l; i <= h; i++) {
        A[i] = B[i];
    }
}

// Recursive MergeSort function
void mergeSort(int A[], int l, int h) {
    if (l < h) {
        int mid = (l + h) / 2;
        mergeSort(A, l, mid);      // Sort the left half
        mergeSort(A, mid + 1, h);  // Sort the right half
        merge(A, l, mid, h);       // Merge the sorted halves
    }
}

int main() {
    int A[] = {7, 6, 10, 5, 9, 2, 1, 15, 7};
    int n = sizeof(A) / sizeof(A[0]);

    cout << "Original array: ";
    for (int i = 0; i < n; i++) {
        cout << A[i] << " ";
    }
    cout << endl;

    mergeSort(A, 0, n - 1);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << A[i] << " ";
    }
    cout << endl;

    return 0;
}
