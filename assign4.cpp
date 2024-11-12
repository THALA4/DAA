#include <iostream>
using namespace std;

// Function to find the minimum and maximum in an array using Divide and Conquer
void findMinMax(int arr[], int low, int high, int &min, int &max) {
    // If there is only one element, set it as both min and max
    if (low == high) {
        min = max = arr[low];
        return;
    }

    // If there are two elements, compare them and set min and max accordingly
    if (high == low + 1) {
        if (arr[low] < arr[high]) {
            min = arr[low];
            max = arr[high];
        } else {
            min = arr[high];
            max = arr[low];
        }
        return;
    }

    // More than two elements, so divide the array into halves
    int mid = (low + high) / 2;
    
    // Variables to hold min and max of each half
    int minLeft, maxLeft;
    int minRight, maxRight;

    // Recursively find the minimum and maximum in the left half
    findMinMax(arr, low, mid, minLeft, maxLeft);

    // Recursively find the minimum and maximum in the right half
    findMinMax(arr, mid + 1, high, minRight, maxRight);

    // Combine results from the left and right halves
    min = (minLeft < minRight) ? minLeft : minRight;
    max = (maxLeft > maxRight) ? maxLeft : maxRight;
}

int main() {
    int arr[] = {7, 6, 10, 5, 9, 2, 1, 15, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Variables to store the final minimum and maximum
    int min, max;

    // Find minimum and maximum using Divide and Conquer
    findMinMax(arr, 0, n - 1, min, max);

    cout << "Minimum element: " << min << endl;
    cout << "Maximum element: " << max << endl;

    return 0;
}
