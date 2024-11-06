#include <iostream>
#include <set>
using namespace std;
void findElementInSet(set<int> mySet)
{
    auto it = mySet.find(4);
    if (it != mySet.end())
    {
        cout << "Element found: " << *it << endl;
    }
    else
    {
        cout << "Element not found" << endl;
    }
}
void insertElementInSet(set<int> &mySet)
{
    int n;
    cin >> n;
    int ni;
    for (int i = 0; i < n; i++)
    {
        cin >> ni;
        mySet.insert(ni);
    }
}
void printSet(set<int> &mySet)

{
    cout << "Elements in set: ";
    for (const auto &element : mySet)
    {
        cout << element << " "; // Output: 10 20 30
    }
    cout << endl;
};
void RemoveElement(set<int> &mySet)
{
    mySet.erase(20);
    cout << "Elements in set after erasing 20: ";
    for (const auto &element : mySet)
    {
        cout << element << " "; // Output: 10 30
    }
    cout << endl;
}
int main()
{
    freopen("input", "r", stdin);
    freopen("outut", "w", stdout);
    set<int> mySet;
    insertElementInSet(mySet);
    printSet(mySet);
    findElementInSet(mySet);
    RemoveElement(mySet);
    cout << "Size of set: " << mySet.size() << endl;
    return 0;
}
