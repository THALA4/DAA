#include <iostream>
#include <algorithm>
using namespace std;

// Structure to represent an item with profit and weight
struct Item
{
    int profit;
    int weight;
};

// Comparison function to sort items by profit-to-weight ratio
bool compare(Item a, Item b) {
    return (double)a.profit / a.weight > (double)b.profit / b.weight;
}


// Function to calculate the maximum profit in the knapsack using Greedy approach
int fractionalKnapsack(int W, Item arr[], int n)
{
    // Sort items by profit-to-weight ratio
    sort(arr, arr + n, compare);

    int totalProfit = 0;   // Total profit in the knapsack
    int currentWeight = 0; // Current weight in the knapsack

    cout << "Item details taken in knapsack:\n";
    cout << "Profit\tWeight\tFraction taken\n";

    for (int i = 0; i < n; i++)
    {
        // If adding the whole item doesn't exceed capacity
        if (currentWeight + arr[i].weight <= W)
        {
            currentWeight += arr[i].weight;
            totalProfit += arr[i].profit;
            cout << arr[i].profit << "\t" << arr[i].weight << "\t1 (Full)" << endl;
        }
        else
        {
            // Take the integer part of the fraction of the item that fits
            int remainingWeight = W - currentWeight;
            // Approximate by taking as much of the item as possible in whole units
            totalProfit += (arr[i].profit * remainingWeight) / arr[i].weight;
            cout << arr[i].profit << "\t" << arr[i].weight << "\t" << remainingWeight << "/" << arr[i].weight << endl;
            break; // Knapsack is full
        }
    }

    return totalProfit;
}

int main()
{
    int n, W;

    // Input number of items and knapsack capacity
    cout << "Enter the number of items: ";
    cin >> n;

    Item arr[n];

    // Input profit and weight of each item
    cout << "Enter profit and weight of each item:\n";
    for (int i = 0; i < n; i++)
    {
        cout << "Item " << i + 1 << " - Profit: ";
        cin >> arr[i].profit;
        cout << "Item " << i + 1 << " - Weight: ";
        cin >> arr[i].weight;
    }

    // Input knapsack capacity
    cout << "Enter the capacity of the knapsack: ";
    cin >> W;

    // Calculate maximum profit for the knapsack
    int maxProfit = fractionalKnapsack(W, arr, n);

    cout << "Maximum profit in Knapsack: " << maxProfit << endl;

    return 0;
}
