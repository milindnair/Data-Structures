#include <iostream>
using namespace std;


/*  It takes four arguments: `P[]` and `W[]` are arrays of integers representing the profit and
weight of each item respectively, `n` is the number of items, and `Wt` is the maximum weight that
the knapsack can hold. The function returns an integer value which is the maximum profit that can be
obtained by selecting a subset of the items such that their total weight is less than or equal to
`Wt`. */
int knapsack (int P[], int W[], int n, int Wt)
{
    int K[n+1][Wt+1];
    /* This is the implementation of the dynamic programming approach to solve the 0/1 Knapsack
    problem. The nested for loop initializes a 2D array `K` of size `(n+1) x (Wt+1)` where `n` is
    the number of items and `Wt` is the maximum weight that the knapsack can hold. The array `K`
    stores the maximum profit that can be obtained by selecting a subset of the items such that
    their total weight is less than or equal to `j`. */
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=Wt;j++)
        {
            /* This code block is initializing the first row and first column of the 2D array `K` to 0.
            This is because if there are no items or the maximum weight that the knapsack can hold
            is 0, then the maximum profit that can be obtained is 0. Therefore, the first row and
            first column of the array `K` are initialized to 0. */
            if(i==0 || j==0)
            {
                K[i][j] = 0;
            }
            /* This code block is checking if the weight of the current item `W[i]` is less than or
            equal to the current maximum weight `j`. If it is, then the maximum profit that can be
            obtained by selecting a subset of the items such that their total weight is less than or
            equal to `j` is calculated using the formula `max(P[i] + K[i-1][j-W[i]], K[i-1][j])`.
            This formula takes into account the profit of the current item `P[i]` and the maximum
            profit that can be obtained by selecting a subset of the items such that their total
            weight is less than or equal to `j-W[i]` (which is the remaining weight after selecting
            the current item). The `max` function is used to select the maximum profit between these
            two options. If the weight of the current item is greater than the current maximum
            weight, then the maximum profit that can be obtained by selecting a subset of the items
            such that their total weight is less than or equal to `j` is simply the maximum profit
            that can be obtained by selecting a subset of the items such that their total weight is
            less than or equal to ` */
            // ⬇️
            else if(W[i] <= j)
            {
                K[i][j] = max(P[i] + K[i-1][j-W[i]], K[i-1][j]);
            }
            /* This code block is executed when the weight of the current item `W[i]` is greater than
            the current maximum weight `j`. In this case, it is not possible to select the current
            item as it would exceed the maximum weight limit of the knapsack. Therefore, the maximum
            profit that can be obtained by selecting a subset of the items such that their total
            weight is less than or equal to `j` is simply the maximum profit that can be obtained by
            selecting a subset of the items such that their total weight is less than or equal to
            `j` without considering the current item. This value is stored in the 2D array `K` at
            position `(i,j)`. */
            else
            {
                K[i][j] = K[i-1][j];
            }
        }
    }
    return K[n][Wt];
}

int main(){
    int n;
    cout<<"Enter the number of items: ";
    cin>>n;
    int P[n+1], W[n+1];
    cout<<"Enter the profit and weight of each item: ";
    for(int i=1;i<=n;i++)
    {
        cin>>P[i]>>W[i];
    }
    int Wt;
    cout<<"Enter the maximum weight: ";
    cin>>Wt;
    cout<<"The maximum profit is: "<<knapsack(P, W, n, Wt);
    return 0;
}