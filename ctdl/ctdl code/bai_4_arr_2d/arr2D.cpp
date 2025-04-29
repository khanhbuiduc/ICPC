// C++
#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

// Read 2D array from input file.
// Expects first two numbers as rows and cols.
void read2DArray(vector<vector<int>> &arr)
{
    int rows, cols;
    cin >> rows >> cols;
    arr.resize(rows, vector<int>(cols, 0));
    for (auto &row : arr)
        for (auto &elem : row)
            cin >> elem;
}

// Print 2D array.
void print2DArray(const vector<vector<int>> &arr)
{
    for (const auto &row : arr)
    {
        for (int x : row)
            cout << x << " ";
        cout << "\n";
    }
}

// Matrix multiplication.
vector<vector<int>> matrixMultiply(const vector<vector<int>> &a, const vector<vector<int>> &b)
{
    int n = a.size();
    int m = a[0].size();
    int p = b[0].size();
    vector<vector<int>> result(n, vector<int>(p, 0));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < p; j++)
            for (int k = 0; k < m; k++)
                result[i][j] += a[i][k] * b[k][j];
    return result;
}

// Compute 2D prefix sum.
void prefixSum2D(vector<vector<int>> &arr)
{
    int rows = arr.size();
    if (rows == 0)
        return;
    int cols = arr[0].size();
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            int top = (i > 0) ? arr[i - 1][j] : 0;
            int left = (j > 0) ? arr[i][j - 1] : 0;
            int topLeft = (i > 0 && j > 0) ? arr[i - 1][j - 1] : 0;
            arr[i][j] = arr[i][j] + top + left - topLeft;
        }
    }
}

// Find sum of all elements
int sumAll(const vector<vector<int>> &arr)
{
    int sum = 0;
    for (const auto &row : arr)
        for (int x : row)
            sum += x;
    return sum;
}

// Find max element
int findMax(const vector<vector<int>> &arr)
{
    int maxVal = INT_MIN;
    for (const auto &row : arr)
        for (int x : row)
            maxVal = max(maxVal, x);
    return maxVal;
}

// Check if value exists
bool exists(const vector<vector<int>> &arr, int target)
{
    for (const auto &row : arr)
        for (int x : row)
            if (x == target)
                return true;
    return false;
}

// Get number of rows and columns
pair<int, int> getDimensions(const vector<vector<int>> &arr)
{
    if (arr.empty())
        return {0, 0};
    return {arr.size(), arr[0].size()};
}

// Rotate matrix 90 degrees clockwise
void rotate90(vector<vector<int>> &arr)
{
    int n = arr.size();
    for (int i = 0; i < n / 2; i++)
    {
        for (int j = i; j < n - i - 1; j++)
        {
            int temp = arr[i][j];
            arr[i][j] = arr[n - j - 1][i];
            arr[n - j - 1][i] = arr[n - i - 1][n - j - 1];
            arr[n - i - 1][n - j - 1] = arr[j][n - i - 1];
            arr[j][n - i - 1] = temp;
        }
    }
}

// Transpose matrix
void transpose(vector<vector<int>> &arr)
{
    int n = arr.size();
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            swap(arr[i][j], arr[j][i]);
}
// Traverse neighbors in 4 directions and in 8 directions from given cell (i, j)
void traverseDirections(const vector<vector<int>> &arr, int i, int j)
{
    int rows = arr.size();
    if (rows == 0)
        return;
    int cols = arr[0].size();

    // 4-directional neighbors: up, right, down, left.
    int di4[] = {-1, 0, 1, 0};
    int dj4[] = {0, 1, 0, -1};
    cout << "4-directional neighbours of cell (" << i << ", " << j << "):\n";
    for (int d = 0; d < 4; d++)
    {
        int ni = i + di4[d], nj = j + dj4[d];
        if (ni >= 0 && ni < rows && nj >= 0 && nj < cols)
            cout << "(" << ni << ", " << nj << "): " << arr[ni][nj] << "\n";
    }

    // 8-directional neighbors: include diagonals.
    int di8[] = {-1, -1, 0, 1, 1, 1, 0, -1};
    int dj8[] = {0, 1, 1, 1, 0, -1, -1, -1};
    cout << "8-directional neighbours of cell (" << i << ", " << j << "):\n";
    for (int d = 0; d < 8; d++)
    {
        int ni = i + di8[d], nj = j + dj8[d];
        if (ni >= 0 && ni < rows && nj >= 0 && nj < cols)
            cout << "(" << ni << ", " << nj << "): " << arr[ni][nj] << "\n";
    }
}
int main()
{
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);

    vector<vector<int>> arr;
    read2DArray(arr);

    cout << "Original array:\n";
    print2DArray(arr);

    // Test basic operations
    cout << "\nSum of all elements: " << sumAll(arr) << "\n";
    cout << "Maximum element: " << findMax(arr) << "\n";
    cout << "Does 5 exist? " << (exists(arr, 5) ? "Yes" : "No") << "\n";

    auto [rows, cols] = getDimensions(arr);
    cout << "Dimensions: " << rows << "x" << cols << "\n";
    // Demonstrate neighbor traversal from cell (0, 0)
    if (!arr.empty() && !arr[0].empty())
        traverseDirections(arr, 0, 0);
    // Test matrix operations (only if square)
    if (rows == cols)
    {
        vector<vector<int>> arrCopy = arr;
        rotate90(arrCopy);
        cout << "\nAfter 90-degree rotation:\n";
        print2DArray(arrCopy);

        arrCopy = arr;
        transpose(arrCopy);
        cout << "\nAfter transpose:\n";
        print2DArray(arrCopy);
    }

    // Test matrix multiplication (only for square matrix)
    if (rows == cols)
    {
        vector<vector<int>> result = matrixMultiply(arr, arr);
        cout << "\nMatrix multiplication result:\n";
        print2DArray(result);
    }

    // Test 2D prefix sum
    vector<vector<int>> prefixArr = arr;
    prefixSum2D(prefixArr);
    cout << "\n2D prefix sum array:\n";
    print2DArray(prefixArr);

    return 0;
}