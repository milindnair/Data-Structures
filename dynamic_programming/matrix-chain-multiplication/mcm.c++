#include <iostream>
#include <cstring>
using namespace std;

const int MAX = 100;
int dp[MAX][MAX];


//  The `matrixChain` function is a recursive function that calculates the
//  minimum number of scalar multiplications required to multiply a chain of matrices.
//  It takes in an array `p` that represents the dimensions of the matrices in the chain, 
// and two indices `start` and `end` that represent the start and end indices of the subchain being considered.
int matrixChain(int p[], int start, int end) {
    
    // The `if (start == end)` condition checks if there is only one matrix in the chain.
    //  If there is only one matrix, then there is no need to multiply it with any other matrix, so the function returns 0.
    // ⬇️
    if (start == end) {
        return 0;
    }

    // The `if (dp[start][end] != -1)` condition checks if the value of `dp[start][end]` has already been calculated 
    // and stored in the `dp` array. If it has been calculated, then the function returns the stored value instead of recalculating it. 
    // This is done to avoid redundant calculations and improve the efficiency of the algorithm.
    // ⬇️
    if (dp[start][end] != -1) {
        return dp[start][end];
    }

    // This code block is implementing the dynamic programming approach to solve the matrix chain multiplication problem.
    dp[start][end] = MAX;
    for (int k = start; k < end; k++) {
        dp[start][end] = min(dp[start][end], matrixChain(p, start, k) + matrixChain(p, k + 1, end) + p[start - 1] * p[k] * p[end]);
    }
    return dp[start][end];
}

// The function initializes i to 1 and j to n-1 because the matrixChain() function expects the matrices 
// to be multiplied starting from the first matrix (matrix A1) and ending with the last matrix (matrix An). 
// The dimensions of the first matrix (A1) are given by p[0] x p[1], and the dimensions of the last matrix (An) are given by p[n-2] x p[n-1].

int MatrixChainOrder(int p[], int n) {
    int i = 1, j = n - 1;
    return matrixChain(p, i, j);
}

int main() {
    int N;
    cout << "How many numbers for matrix? ";
    cin >> N;
    int arr[N];
    cout << "Enter the numbers: ";
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    memset(dp, -1, sizeof(dp));
    cout << "Minimum number of multiplications is " << MatrixChainOrder(arr, N) << endl;
    return 0;
}
