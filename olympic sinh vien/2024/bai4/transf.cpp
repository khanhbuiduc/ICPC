#include <bits/stdc++.h>

using namespace std;

// Hàm hỗ trợ tối ưu hóa giá trị
template <class X, class Y>
bool minimize(X &x, const Y &y)
{
    if (x > y)
    {
        x = y;
        return true;
    }
    return false;
}

template <class X, class Y>
bool maximize(X &x, const Y &y)
{
    if (x < y)
    {
        x = y;
        return true;
    }
    return false;
}

template <class T>
T Abs(const T &x)
{
    return (x < 0 ? -x : x);
}

const int AB_TO_BA[3][2] = {{1, 2}, {5, 1}, {2, -5}};
const int AC_TO_CA[3][2] = {{1, 3}, {2, 1}, {3, -6}};
const int D_TO_EMPTY[6][2] = {{2, 1}, {3, 5}, {6, -1}, {5, 6}, {4, -1}, {1, -7}};

vector<pair<int, int>> transABtoBA, transACtoCA, transDtoEmpty;

void convert(const int arr[][2], int sz, vector<pair<int, int>> &trans)
{
    trans.resize(sz);
    for (int i = 0; i < sz; i++)
    {
        trans[i].first = arr[i][0] - 1;
        trans[i].second = arr[i][1];
    }
}

void reverseTransform(vector<pair<int, int>> &trans)
{
    reverse(trans.begin(), trans.end());
    for (auto &p : trans)
        p.second *= -1;
}

bool prepared = false;
void prepare()
{
    if (prepared)
        return;
    prepared = true;

    convert(AB_TO_BA, 3, transABtoBA);
    convert(AC_TO_CA, 3, transACtoCA);
    convert(D_TO_EMPTY, 6, transDtoEmpty);
}

void transformToCore(string &source, vector<pair<int, int>> &trans)
{
    trans.clear();

    // Bước 1: Xóa tất cả ký tự 'D'
    for (int i = source.size() - 1; i >= 0; i--)
    {
        if (source[i] == 'D')
        {
            for (const auto &p : transDtoEmpty)
            {
                trans.emplace_back(p.first + i, p.second);
            }
            source.erase(source.begin() + i);
        }
    }

    // Bước 2: Di chuyển tất cả 'A' về cuối chuỗi
    for (int i = source.size() - 1; i >= 0; i--)
    {
        if (source[i] == 'A')
        {
            int j = i;
            while (j + 1 < source.size() && source[j + 1] != 'A')
            {
                const auto &transList = (source[j + 1] == 'B') ? transABtoBA : transACtoCA;
                for (const auto &p : transList)
                {
                    trans.emplace_back(p.first + j, p.second);
                }
                swap(source[j], source[j + 1]);
                j++;
            }
        }
    }

    // Bước 3: Xóa các cặp 'AA' ở cuối
    while (source.size() >= 2 && source[source.size() - 2] == 'A' && source[source.size() - 1] == 'A')
    {
        trans.emplace_back(source.size() - 2, -1);
        source.pop_back();
        source.pop_back();
    }

    // Bước 4: Xóa các cặp 'BB' và 'CC'
    while (source.size() >= 2)
    {
        bool needContinue = false;
        for (int i = source.size() - 2; i >= 0; i--)
        {
            if (source[i] == source[i + 1])
            {
                trans.emplace_back(i, (source[i] == 'B' ? -2 : -3));
                source.erase(i, 2);
                needContinue = true;
            }
        }
        if (!needContinue)
            break;
    }
}

void solve(string sta, string fin)
{
    prepare();

    vector<pair<int, int>> transSta, transFin;
    transformToCore(sta, transSta);
    transformToCore(fin, transFin);

    assert(sta == fin);

    reverseTransform(transFin);
    cout << transSta.size() + transFin.size() << "\n";
    for (const auto &p : transSta)
    {
        cout << p.first + 1 << " " << p.second << "\n";
    }
    for (const auto &p : transFin)
    {
        cout << p.first + 1 << " " << p.second << "\n";
    }
    cout << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string sta, fin;
    while (cin >> sta >> fin)
    {
        solve(sta, fin);
    }
    return 0;
}
