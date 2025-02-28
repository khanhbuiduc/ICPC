#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);

    vector<int> v;

    // 1. Push elements from input
    int x;
    while (cin >> x)
    {
        v.push_back(x);
    }

    // 2. Basic vector operations
    cout << "Size of vector: " << v.size() << endl;
    cout << "First element: " << v.front() << endl;
    cout << "Last element: " << v.back() << endl;

    // 3. Insert elements
    v.insert(v.begin(), 10);     // Insert at beginning
    v.insert(v.begin() + 2, 20); // Insert at position 2

    // 4. Remove elements
    v.pop_back(); // Remove last element
    if (!v.empty())
    {
        v.erase(v.begin()); // Remove first element
    }

    // 5. Vector capacity
    cout << "Capacity: " << v.capacity() << endl;
    cout << "Max size: " << v.max_size() << endl;

    // 6. Resize vector
    v.resize(5); // Resize to 5 elements

    // 7. Clear vector
    vector<int> temp = v;
    v.clear();
    cout << "After clear, size: " << v.size() << endl;
    v = temp; // Restore vector

    // 8. Different sorting methods
    sort(v.begin(), v.end());
    sort(v.rbegin(), v.rend());

    // 9. Reverse vector
    reverse(v.begin(), v.end());

    // 10. Find element
    auto it = find(v.begin(), v.end(), 2);
    if (it != v.end())
    {
        cout << "Found 2 at position: " << it - v.begin() << endl;
    }

    // 11. Count occurrences
    int count2 = count(v.begin(), v.end(), 2);
    cout << "Number of 2s: " << count2 << endl;

    // 12. Min and Max elements
    auto minmax = minmax_element(v.begin(), v.end());
    cout << "Min: " << *minmax.first << ", Max: " << *minmax.second << endl;

    // 13. Print final vector
    cout << "Final vector: ";
    for (int num : v)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}