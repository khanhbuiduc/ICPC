#include <bits/stdc++.h>
using namespace std;

struct TrieNode
{
    TrieNode *child[26];
    int maxValue;
    TrieNode()
    {
        for (int i = 0; i < 26; i++)
            child[i] = nullptr;
        maxValue = 0;
    }
};

struct Trie
{
    TrieNode *root;
    Trie()
    {
        root = new TrieNode();
    }

    // Thêm 1 chuỗi cùng với value
    void add(const string &s, int value)
    {
        TrieNode *cur = root;
        for (char ch : s)
        {
            int idx = ch - 'a';
            if (cur->child[idx] == nullptr)
                cur->child[idx] = new TrieNode();
            cur = cur->child[idx];
            cur->maxValue = max(cur->maxValue, value);
        }
    }

    // Tìm maxValue của prefix s
    int findMax(const string &s)
    {
        TrieNode *cur = root;
        for (char ch : s)
        {
            int idx = ch - 'a';
            if (cur->child[idx] == nullptr)
                return -1; // prefix không tồn tại
            cur = cur->child[idx];
        }
        return cur->maxValue;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    Trie trie;
    for (int i = 0; i < n; i++)
    {
        string s;
        int val;
        cin >> s >> val;
        trie.add(s, val);
    }

    while (q--)
    {
        string s;
        cin >> s;
        cout << trie.findMax(s) << "\n";
    }
}
