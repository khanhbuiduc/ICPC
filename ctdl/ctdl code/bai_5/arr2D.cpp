#include <iostream>
#include <vector>
using namespace std;

// Function to read 2D vector from file
void read2DArray(vector<vector<int>> &arr)
{

    int rows, cols;
    cin >> rows >> cols;

    arr.resize(rows, vector<int>(cols));
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cin >> arr[i][j];
        }
    }
}

// Print 2D vector
void print2DArray(const vector<vector<int>> &arr)
{
    cout << "Array contents:\n";
    for (const auto &row : arr)
    {
        for (int val : row)
        {
            cout << val << " ";
        }
        cout << endl;
    }
}

int main()
{
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);
    vector<vector<int>> arr;
    read2DArray(arr);
    print2DArray(arr);
    return 0;
}