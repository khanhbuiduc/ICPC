#include <bits/stdc++.h>
using namespace std;
#define NAME "max_34."
ifstream fi(NAME "inp");
ofstream fo(NAME "out");
void printArr(vector<int> arr)
{
    for (int i : arr)
        fo << i << " ";
    fo << "\n";
}
int main()
{
    int n;
    fi >> n;
    vector<int> a(n);
    for (int &i : a)
        fi >> i;
    // sort(a.begin(), a.end(), greater<int>());
    nth_element(a.begin(), a.begin() + 2, a.end(), less<int>());
    printArr(a);
    fo << a[2] << " " << endl;
    nth_element(a.begin(), a.begin() + 3, a.end(), greater<int>());
    printArr(a);
    fo << a[3] << " ";
}
// độ phức tạp của sort là O(n.log(n)) còn độ phức tạp của nth_element là O(n);