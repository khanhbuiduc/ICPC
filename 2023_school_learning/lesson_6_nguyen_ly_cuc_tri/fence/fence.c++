#include <bits/stdc++.h>

using namespace std;
#define NAME "fence."
ifstream fi(NAME "inp");
ofstream fo(NAME "out");

typedef pair<double, double> pdd;
int n, k;
double area(pdd a, pdd b, pdd c) // cùng chiều kim đồng hồ >0; ngược chiều <0
{
    return a.first * (b.second - c.second) + b.first * (c.second - a.second) + c.first * (a.second - b.second);
}
double distance(pdd a, pdd b)
{
    return sqrt((a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second));
}
void convex(int n, vector<pdd> &a)
{
    sort(a.begin(), a.end());
    // a(n)=(1,1),(3,3),(3,5),(4,0),(5,1),(5,2),(5,3),(6,5),(7,2)
    vector<pdd> up, down;
    // chọn 2 điểm cực trị: Leftmost point p1 = (1, 1); Rightmost point p2 = (7, 2)
    pdd p1 = a[0], p2 = a.back();
    up.push_back(p1);
    down.push_back(p1);

    // Tạo chuỗi bao trên và dưới
    for (int i = 1; i < a.size(); ++i)
    {
        // bao trên
        if (i == a.size() - 1 || area(p1, a[i], p2) < 0)
        {
            while (up.size() >= 2 && area(up[up.size() - 2], up.back(), a[i]) >= 0)
                up.pop_back();
            up.push_back(a[i]);
        }
        // bao dưới
        if (i == a.size() - 1 || area(p1, a[i], p2) > 0)
        {
            while (down.size() >= 2 && area(down[down.size() - 2], down.back(), a[i]) <= 0)
                down.pop_back();
            down.push_back(a[i]);
        }
    }
    a.clear();
    // Thêm các điểm của chuỗi bao trên
    for (int i = 0; i < up.size(); ++i)
        a.push_back(up[i]);
    for (int i = down.size() - 2; i > 0; --i)
        a.push_back(down[i]);
};
void printConvex(vector<pdd> a)
{
    for (int i = 0; i < a.size(); ++i)
    {
        cout << fixed << setprecision(6) << a[i].first << " " << a[i].second << "\n";
    }
}
int main()
{
    fi >> n >> k;
    vector<pdd> a(n);
    vector<pdd> fence;
    for (auto &i : a)
    {
        fi >> i.first >> i.second;
    }
    convex(n, a);
    for (pdd p : a)
    {
        fence.push_back({p.first + k, p.second});
        fence.push_back({p.first - k, p.second});
        fence.push_back({p.first, p.second + k});
        fence.push_back({p.first, p.second - k});
    }
    convex(fence.size(), fence);
    double length = distance(fence[0], fence.back());
    for (int i = 1; i < fence.size(); i++)
    {
        length += distance(fence[i], fence[i - 1]);
    }
    fo << fixed << setprecision(6) << length;
    return 0;
}
