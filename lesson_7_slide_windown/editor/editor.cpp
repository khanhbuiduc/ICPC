#include <bits/stdc++.h>

using namespace std;
#define NAME "editor."
#define ff first
#define ss second
ifstream fi(NAME "inp");
ofstream fo(NAME "out");
typedef pair<int, int> pdd;
int mx = INT_MAX;

vector<int64_t> min_to(const vector<int64_t> &lines, int start_row)
{
    int n = lines.size();
    vector<int64_t> min_dist(n, INT64_MAX);
    min_dist[start_row] = 0;

    // Tính khoảng cách từ dòng start_row sang trái
    for (int i = start_row - 1; i >= 0; --i)
    {
        min_dist[i] = min_dist[i + 1] + abs(lines[i + 1] - lines[i]);
    }

    // Tính khoảng cách từ dòng start_row sang phải
    for (int i = start_row + 1; i < n; ++i)
    {
        min_dist[i] = min_dist[i - 1] + abs(lines[i] - lines[i - 1]);
    }

    return min_dist;
}
int64_t abs_diff(int64_t a, int64_t b)
{
    if (a > b)
        return a - b;
    else
        return b - a;
}
//=============================================

int main()
{
    int64_t n, x, y, row, col;
    fi >> n >> x >> y >> row >> col;
    pdd st = {x, y};
    pdd ed = {row, col};
    vector<int64_t> lines(n);
    for (auto &line : lines)
        fi >> line;
    auto direct_path = [&]()
    {
        auto rows = minmax(st.ff, ed.ff);
        for (int i = rows.ff; i <= rows.ss; i++)
        {
            if (lines[i] < min(st.ss, ed.ss))
                return mx;
        }
        return abs(st.ff - ed.ff) + abs(st.ss - ed.ss);
    };
    auto fall_path = [&]()
    {
        vector<int64_t> mn_to_st = min_to(lines, st.ff);
        vector<int64_t> mn_to_ed = min_to(lines, ed.ff);
        int64_t best = mx;
        for (int i = 0; i < n; ++i)
        {
            int64_t lth = lines[i];
            if (lth > st.ss || lth > mn_to_st[i] || lth > mn_to_ed[i])
                continue;
            int64_t score = abs(st.ff - i) + abs(ed.ff - i) + abs(ed.ss - lth);
            best = min(best, score);
        }
        return best;
    };
    auto jump_path = [&]()
    {
        auto cols = minmax(st.ss, ed.ss);
        auto rows = minmax(st.ff, ed.ff);

        int64_t rowMin = lines[st.ss];
        for (int i = rows.ff; i <= rows.ss; i++)
        {
            rowMin = min(rowMin, lines[i]);
        }
        int64_t dis = (rowMin - cols.ss) <= 0 ? 0 : rowMin - cols.ss;
        return cols.ff + 1 + dis;
    };
    int64_t minDis = direct_path() < fall_path() ? direct_path() : fall_path();
    minDis = minDis < jump_path() ? minDis : jump_path();
    fo << direct_path()
       << " " << fall_path() << " " << jump_path();
    fo << "\nmin: =" << minDis;
}