#include <iostream>
using namespace std;

// Item struct to store the weight and value of an item
struct Item {
    int weight;
    int value;
};

// Function to swap two items
void swapItems(Item& a, Item& b) {
    Item temp = a;
    a = b;
    b = temp;
}

// Greedy function to solve 0/1 Knapsack problem
int knapsackGreedy(int capacity, Item items[], int n) {
    int totalValue = 0;
    // Sort the items based on their value-to-weight ratio
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if ((double) items[i].value / items[i].weight < (double) items[j].value / items[j].weight) {
                swapItems(items[i], items[j]);
            }
        }
    }
    // Fill the knapsack with items in decreasing order of value-to-weight ratio
    for (int i = 0; i < n; i++) {
        if (capacity >= items[i].weight) {
            totalValue += items[i].value;
            capacity -= items[i].weight;
        } else {
            break;
        }
    }
    return totalValue;
}

// Driver code to test the knapsackGreedy function
int main() {
    int capacity = 50;
    Item items[] = {{10, 60}, {20, 100}, {30, 120}};
    int n = sizeof(items) / sizeof(items[0]);
    int maxVal = knapsackGreedy(capacity, items, n);
    cout << "Maximum value of items that can be put into the knapsack is " << maxVal << endl;
    return 0;
}
