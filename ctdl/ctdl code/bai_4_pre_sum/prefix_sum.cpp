#include <bits/stdc++.h>
using namespace std;

void demonstrate1DPrefixSum()
{
    cout << "\n=== 1D PREFIX SUM DEMONSTRATIONS ===\n";
    vector<int> arr = {1, 2, 3, 4, 5};
    vector<int> prefix(arr.size());

    // Calculate prefix sum
    prefix[0] = arr[0];
    for (size_t i = 1; i < arr.size(); i++)
    {
        prefix[i] = prefix[i - 1] + arr[i];
    }

    // Print original and prefix arrays
    cout << "Original array: ";
    for (int x : arr)
        cout << x << " ";
    cout << "\nPrefix sum array: ";
    for (int x : prefix)
        cout << x << " ";
    cout << "\n";

    // Query examples
    int l = 1, r = 3; // Get sum from index 1 to 3
    cout << "Sum from index " << l << " to " << r << ": " << prefix[r] - (l > 0 ? prefix[l - 1] : 0) << "\n";
}

void demonstrate2DPrefixSum()
{
    cout << "\n=== 2D PREFIX SUM DEMONSTRATIONS ===\n";
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};
    int n = matrix.size(), m = matrix[0].size();
    vector<vector<int>> prefix(n, vector<int>(m));

    // Calculate 2D prefix sum
    prefix[0][0] = matrix[0][0];
    // Fill first row
    for (int j = 1; j < m; j++)
        prefix[0][j] = prefix[0][j - 1] + matrix[0][j];
    // Fill first column
    for (int i = 1; i < n; i++)
        prefix[i][0] = prefix[i - 1][0] + matrix[i][0];
    // Fill rest of matrix
    for (int i = 1; i < n; i++)
        for (int j = 1; j < m; j++)
            prefix[i][j] = prefix[i - 1][j] + prefix[i][j - 1] - prefix[i - 1][j - 1] + matrix[i][j];

    // Print original matrix
    cout << "Original matrix:\n";
    for (const auto &row : matrix)
    {
        for (int x : row)
            cout << x << " ";
        cout << "\n";
    }

    // Print prefix sum matrix
    cout << "Prefix sum matrix:\n";
    for (const auto &row : prefix)
    {
        for (int x : row)
            cout << x << " ";
        cout << "\n";
    }

    // Query example: sum in rectangle from (r1,c1) to (r2,c2)
    int r1 = 1, c1 = 1, r2 = 2, c2 = 2;
    // Sum in rectangle = prefix[r2][c2] - prefix[r1-1][c2] - prefix[r2][c1-1] + prefix[r1-1][c1-1]=45-12-6+1=28
    int sum = prefix[r2][c2];
    if (r1 > 0)
        sum -= prefix[r1 - 1][c2];
    if (c1 > 0)
        sum -= prefix[r2][c1 - 1];
    if (r1 > 0 && c1 > 0)
        sum += prefix[r1 - 1][c1 - 1];
    cout << "Sum in rectangle from (" << r1 << "," << c1 << ") to ("
         << r2 << "," << c2 << "): " << sum << "\n";
}

int main()
{
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);

    // Demonstrate 1D prefix sum
    demonstrate1DPrefixSum();

    // Demonstrate 2D prefix sum
    demonstrate2DPrefixSum();

    return 0;
}
