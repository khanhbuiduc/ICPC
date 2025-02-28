
#include <bits/stdc++.h>
using namespace std;

// Function to demonstrate pair operations
void demonstratePairs()
{
    cout << "\n=== PAIR DEMONSTRATIONS ===\n";

    // Basic pair usage
    pair<int, string> p1(1, "one");
    cout << "1. Basic pair: {" << p1.first << ", " << p1.second << "}\n";

    // Make_pair usage
    auto p2 = make_pair(2, "two");
    cout << "2. Make_pair: {" << p2.first << ", " << p2.second << "}\n";

    // Nested pair
    pair<string, pair<int, double>> nested("test", {10, 3.14});
    cout << "3. Nested pair: {" << nested.first << ", {"
         << nested.second.first << ", " << nested.second.second << "}}\n";

    // Vector of pairs
    vector<pair<int, string>> pairVec = {{1, "one"}, {2, "two"}};
    cout << "4. Vector of pairs: ";
    for (const auto &[num, str] : pairVec)
    {
        cout << "{" << num << "," << str << "} ";
    }
    cout << "\n";
}

// Function to demonstrate auto usage
void demonstrateAuto()
{
    cout << "\n=== AUTO DEMONSTRATIONS ===\n";

    // Auto with basic types
    auto i = 42;      // int
    auto d = 3.14;    // double
    auto s = "hello"; // const char*
    cout << "1. Auto basic types: " << typeid(i).name() << ", "
         << typeid(d).name() << ", " << typeid(s).name() << "\n";

    // Auto with containers
    vector<int> nums = {1, 2, 3};
    cout << "2. Auto with iterators: ";
    for (auto it = nums.begin(); it != nums.end(); ++it)
    {
        cout << *it << " ";
    }
    cout << "\n";

    // Auto with range-based for
    cout << "3. Range-based for with auto: ";
    for (const auto &num : nums)
    {
        cout << num << " ";
    }
    cout << "\n";

    // Auto with structured bindings (C++17)
    map<string, int> scores = {{"Alice", 100}, {"Bob", 90}};
    cout << "4. Structured bindings: \n";
    for (const auto &[name, score] : scores)
    {
        cout << "   " << name << ": " << score << "\n";
    }
}

int main()
{
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);

    // Read input data
    vector<int> inputData;
    int x;
    while (cin >> x)
    {
        inputData.push_back(x);
    }
    cout << "Input data: ";
    for (const auto &num : inputData)
    {
        cout << num << " ";
    }
    cout << "\n";

    // Demonstrate pairs
    demonstratePairs();

    // Demonstrate auto
    demonstrateAuto();

    return 0;
}