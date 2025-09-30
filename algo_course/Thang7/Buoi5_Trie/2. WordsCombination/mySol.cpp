#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a), _b = (b); i <= (_b); i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= (_a); i++)
#define FORE(i, a) for (auto i : a)
using namespace std;
typedef long long ll;
//
int len;
vector<vector<int>> have;
int f[5005];
const int mod = 1000000007;
bool maximum(int &X, const int &Y)
{
    if (X < Y)
    {
        X = Y;
        return true;
    }
    return false;
}

struct TrieNode
{
    TrieNode *child[26];
    bool isEnd;
    TrieNode()
    {
        FOR(i, 0, 25) { child[i] = NULL; }
        isEnd = false;
    }
};
void addString(string &s, TrieNode *&root)
{
    TrieNode *p = root;
    for (char c : s)
    {
        if (p->child[c - 'a'] == NULL)
            p->child[c - 'a'] = new TrieNode();
        p = p->child[c - 'a'];
    }
    p->isEnd = true;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    string pattern, s;
    TrieNode *root = new TrieNode();
    cin >> pattern;
    len = pattern.length();
    int numWord;
    cin >> numWord;
    while (numWord--)
    {
        cin >> s;
        addString(s, root);
    }
    // đếm xem từ i có những kết thúc nào.
    have.resize(len);
    for (int i = 0; i < len; i++)
    {
        TrieNode *p = root;
        for (int j = i; j < len; j++)
        {
            if (p->child[pattern[j] - 'a'] == NULL)
            {
                break;
            }
            p = p->child[pattern[j] - 'a'];
            if (p->isEnd == true)
            {
                have[i].push_back(j);
            }
        }
    }
    f[0] = 1;
    for (int i = 0; i < len; i++)
    {
        FORE(ci, have[i])
        {
            (f[ci + 1] += f[i]) %= mod;
        }
    }
    cout << f[len];
}
/*
string s;
dictionary[k]:
có bao nhiêu cách tạo string từ những từ này.
QHD:
    f[i]: số cách tạo s, khi s chỉ có i kí tự.
f[0] = 1;
kết quả: f[n];
---
    nếu i cần 1 ký tự và có kí tự thỏa mãn
        f[i] += f[i-1];
    nếu i cần 2 ký tự cà có kí tự thảo mãn
        f[i] += f[i-n];
    ..... cần n ký tự và có từ thỏa mãn.
        f[i] += f[i-n];
......

f[i] != 0:
    duyệt: ababc;

--
dictionary lưu trong trie.

---
mỗi khi xét
*/