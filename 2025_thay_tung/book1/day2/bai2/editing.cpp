#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define ALL(v) (v).begin(), (v).end()
typedef long long ll;
typedef pair<int, int> pii;

set<char> nguyen_am = {'a', 'e', 'o', 'i', 'u', 'y'};

bool isVowel(char c)
{
    return nguyen_am.find(c) != nguyen_am.end();
}

int solve(string str)
{
    int n = str.size();

    // Chi phí chuyển thành động từ (tất cả nguyên âm)
    int price_v = 0;
    for (char c : str)
    {
        if (!isVowel(c))
            price_v++;
    }

    // Chi phí chuyển thành danh từ: nguyên âm - phụ âm - nguyên âm - phụ âm...
    int price_n1 = 0;
    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0)
        { // Vị trí chẵn → cần nguyên âm
            if (!isVowel(str[i]))
                price_n1++;
        }
        else
        { // Vị trí lẻ → cần phụ âm
            if (isVowel(str[i]))
                price_n1++;
        }
    }

    // Chi phí chuyển thành danh từ: phụ âm - nguyên âm - phụ âm - nguyên âm...
    int price_n2 = 0;
    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0)
        { // Vị trí chẵn → cần phụ âm
            if (isVowel(str[i]))
                price_n2++;
        }
        else
        { // Vị trí lẻ → cần nguyên âm
            if (!isVowel(str[i]))
                price_n2++;
        }
    }

    return min({price_v, price_n1, price_n2});
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    string str;
    int ans = 0;
    while (cin >> str)
    {
        ans += solve(str);
    }
    cout << ans << endl;

    return 0;
}