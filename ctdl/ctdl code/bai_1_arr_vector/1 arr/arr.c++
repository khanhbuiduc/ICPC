#include <bits/stdc++.h>
using namespace std;

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);

    int arr[1000];
    int n = 0;

    // 1. Input array
    int x;
    while (cin >> x)
    {
        arr[n++] = x;
    }

    cout << "Original array: ";
    printArray(arr, n);

    // 2. Sort array ascending
    sort(arr, arr + n);
    cout << "Sorted ascending: ";
    printArray(arr, n);

    // 3. Sort array descending
    sort(arr, arr + n, greater<int>());
    cout << "Sorted descending: ";
    printArray(arr, n);

    // 4. Find min and max
    int *min_pos = min_element(arr, arr + n);
    int *max_pos = max_element(arr, arr + n);
    cout << "Min element: " << *min_pos << endl;
    cout << "Max element: " << *max_pos << endl;

    // 5. Binary search (requires sorted array)
    sort(arr, arr + n);
    bool found = binary_search(arr, arr + n, 2);
    cout << "Binary search for 2: " << (found ? "Found" : "Not found") << endl;

    // 6. Count occurrences
    int count2 = count(arr, arr + n, 2);
    cout << "Count of 2: " << count2 << endl;

    // 7. Reverse array
    reverse(arr, arr + n);
    cout << "Reversed array: ";
    printArray(arr, n);

    // 8. Sum of array
    int sum = accumulate(arr, arr + n, 0);
    cout << "Sum of elements: " << sum << endl;

    // 9. Find first occurrence
    auto it = find(arr, arr + n, 2);
    if (it != arr + n)
    {
        cout << "First occurrence of 2 at position: " << (it - arr) << endl;
    }

    // 10. Remove duplicates (requires sorted array)
    sort(arr, arr + n);
    auto last = unique(arr, arr + n);
    int new_size = last - arr;
    cout << "Array after removing duplicates: ";
    printArray(arr, new_size);

    // 11. Fill array with value
    fill(arr, arr + n, 5);
    cout << "Array after filling with 5: ";
    printArray(arr, n);

    // 12. Rotate array
    rotate(arr, arr + 1, arr + n); // rotate left by 1
    cout << "Array after rotating left by 1: ";
    printArray(arr, n);

    // 13. Check if array is sorted
    bool is_array_sorted = is_sorted(arr, arr + n);
    cout << "Is array sorted? " << (is_array_sorted ? "Yes" : "No") << endl;

    // 14. Find adjacent duplicates
    auto adjacent = adjacent_find(arr, arr + n);
    if (adjacent != arr + n)
    {
        cout << "Adjacent duplicates found at position: " << (adjacent - arr) << endl;
    }

    return 0;
}