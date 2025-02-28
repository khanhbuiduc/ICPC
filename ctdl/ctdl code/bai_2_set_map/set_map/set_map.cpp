#include <bits/stdc++.h>
using namespace std;
// set and map are associative containers that store unique keys
// set and map are implemented using balanced binary search trees (Red-Black Trees)
void demonstrateSetMethods()
{
    cout << "\n=== SET METHODS DEMONSTRATION ===\n";

    // 1. Initialization methods
    set<int> s1 = {3, 1, 4, 1, 5};         // Basic initialization
    set<int> s2(s1.begin(), s1.end());     // Iterator initialization
    set<int, greater<int>> s3 = {1, 5, 3}; // Custom comparator

    // 2. Insertion methods  O(M log N) (M is the number of elements to insert)
    cout << "1. Insertion Methods:\n";
    s1.insert(6);                      // Single element
    auto [it, success] = s1.insert(7); // With insertion status
    s1.insert({8, 9, 10});             // Multiple elements
    s1.insert(s2.begin(), s2.end());   // Range insertion
    cout << "   After insertions: ";
    for (int x : s1)
        cout << x << " ";
    cout << "\n";

    // 3. Removal methods O(K log N) (K is the number of elements to remove)
    cout << "2. Removal Methods:\n";
    s1.erase(6);                    // Remove by value
    s1.erase(s1.begin());           // Remove by iterator
    s1.erase(s1.find(8), s1.end()); // Remove range
    cout << "   After erasures: ";
    for (int x : s1)
        cout << x << " ";
    cout << "\n";

    // 4. Search methods O(log N)
    cout << "3. Search Methods:\n";
    cout << "   Contains 4? " << (s1.count(4)) << "\n";
    cout << "   Find 3: " << (*s1.find(3)) << "\n";
    cout << "   Lower bound of 3: " << (*s1.lower_bound(3)) << "\n";
    cout << "   Upper bound of 3: " << (*s1.upper_bound(3)) << "\n";

    // 5. Size methods O(1)
    cout << "4. Size Methods:\n";
    cout << "   Size: " << s1.size() << "\n";
    cout << "   Max size: " << s1.max_size() << "\n";
    cout << "   Empty? " << s1.empty() << "\n";

    // 6. Iterator methods O(1)
    cout << "5. Iterator Methods:\n";
    cout << "   First element: " << *s1.begin() << "\n";
    cout << "   Last element: " << *prev(s1.end()) << "\n";
    cout << "   Reverse first: " << *s1.rbegin() << "\n";
}

void demonstrateMapMethods()
{
    cout << "\n=== MAP METHODS DEMONSTRATION ===\n";

    // 1. Initialization methods
    map<string, int> m1 = {{"one", 1}, {"two", 2}};
    map<string, int> m2(m1.begin(), m1.end());
    map<string, int, greater<string>> m3 = {{"z", 26}, {"y", 25}};

    // 2. Insertion methods O(log N)
    cout << "1. Insertion Methods:\n";
    m1.insert({"three", 3});         // Single pair
    m1.insert(make_pair("four", 4)); // Using make_pair
    m1["five"] = 5;                  // Using operator[]
    m1.emplace("six", 6);            // Using emplace
    cout << "   After insertions:\n";
    for (const auto &[key, value] : m1)
        cout << "   " << key << ": " << value << "\n";

    // 3. Access methods O(log N) at() throws exception if key not found
    cout << "2. Access Methods:\n";
    cout << "   Direct access: " << m1["one"] << "\n";
    cout << "   Using at(): " << m1.at("two") << "\n";
    // 4. Removal methods O(log N)
    cout << "3. Removal Methods:\n";
    m1.erase("one");          // Remove by key, find and erase
    m1.erase(m1.find("two")); // Remove by iterator
    cout << "   After erasures:\n";
    for (const auto &[key, value] : m1)
        cout << "   " << key << ": " << value << "\n";

    // 5. Search methods O(log N)
    cout << "4. Search Methods:\n";
    cout << "   Contains 'three'? " << m1.count("three") << "\n";
    auto it = m1.find("four");
    if (it != m1.end())
        cout << "   Found four: " << it->second << "\n";
    cout << "   Lower bound of 'four': " << m1.lower_bound("four")->first << "\n";

    // 6. Size methods O(1)
    cout << "5. Size Methods:\n";
    cout << "   Size: " << m1.size() << "\n";
    cout << "   Max size: " << m1.max_size() << "\n";
    cout << "   Empty? " << m1.empty() << "\n";

    // 7. Advanced operations O(log N)
    cout << "6. Advanced Operations:\n";
    // Merge two maps
    map<string, int> m4 = {{"seven", 7}, {"eight", 8}};
    m1.merge(m4);
    cout << "   After merge:\n";
    // Extract and insert O(log N)
    auto node = m1.extract("four");
    node.key() = "FOUR";
    m1.insert(move(node));
    for (const auto &[key, value] : m1)
        cout << "   " << key << ": " << value << "\n";
}

int main()
{
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);

    // Demonstrate all set methods
    demonstrateSetMethods();

    // Demonstrate all map methods
    demonstrateMapMethods();

    return 0;
}
