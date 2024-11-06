#include <bits/stdc++.h>

using namespace std;
int main()
{
    // Create an unordered_map
    unordered_map<string, int> umap;

    // Inserting elements
    umap["apple"] = 1;
    umap["banana"] = 2;
    umap["orange"] = 3;

    // Accessing elements
    cout << "Apple: " << umap["apple"] << endl;

    // Iterating through the unordered_map
    for (const auto &pair : umap)
    {
        cout << pair.first << ": " << pair.second << endl;
    }

    // Checking if a key exists
    if (umap.find("banana") != umap.end())
    {
        cout << "Banana exists in the map." << endl;
    }
    if (umap.count("banana") > 0)
    {
        cout << "Banana exists in the map." << endl;
    }
    // Removing an element
    umap.erase("orange");

    return 0;
}
