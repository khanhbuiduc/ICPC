#include <bits/stdc++.h>
using namespace std;

multiset<int> smaller, larger; // Always: smaller.size() >= larger.size()

void rebalance()
{
    // Nếu larger có nhiều phần tử hơn, chuyển phần nhỏ nhất từ larger sang smaller
    if (smaller.size() < larger.size())
    {
        auto it = larger.begin();
        smaller.insert(*it);
        larger.erase(it);
    }

    // Nếu smaller nhiều hơn larger hơn 1 phần tử, chuyển phần tử lớn nhất từ smaller sang larger
    if (smaller.size() > larger.size() + 1)
    {
        auto it = prev(smaller.end());
        larger.insert(*it);
        smaller.erase(it);
    }
}

int main()
{
    int q, x;
    cin >> q;
    string t;

    while (q--)
    {
        cin >> t;
        if (t == "IN")
        {
            cin >> x;
            // chèn vào multiset thích hợp
            if (smaller.empty() || x <= *prev(smaller.end()))
                smaller.insert(x);
            else
                larger.insert(x);
            rebalance();
        }
        else if (t == "OUT")
        {
            cin >> x;
            if (auto it = smaller.find(x); it != smaller.end())
                smaller.erase(it);
            else if (auto it = larger.find(x); it != larger.end())
                larger.erase(it);
            rebalance();
        }
        else if (t == "MEDIAN")
        {
            int s = smaller.size(), l = larger.size();

            if (s == 0)
            {
                cout << "0\n"; // Không có phần tử nào
            }
            else if (s != l)
            {
                // lẻ → trả ra phần tử lớn nhất của smaller
                cout << *prev(smaller.end()) << "\n";
            }
            else
            {
                // chẵn → trung bình của max(smaller) và min(larger)
                int a = *prev(smaller.end());
                int b = *larger.begin();
                cout << (a + b) / 2.0 << "\n";
            }
        }
    }
}
