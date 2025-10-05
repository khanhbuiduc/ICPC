/*
Search Engine - hackerearth.

Given N strings, string i has power value p[i]
Given Q queries, each query has string st, among strings that have st as prefix,
which string has maximum power?
*/

#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a), _b = (b); i <= (_b); i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= (_a); i--)
#define FORE(i, a) for (auto i : a)
using namespace std;

bool maximum(int &X, const int &Y)
{
    if (X < Y)
    {
        X = Y;
        return true;
    }
    return false;
}

typedef long long ll;
struct TrieNode
{
    TrieNode *child[26];
    int maxWeight;
    TrieNode(int __maxWeight)
    {
        FOR(i, 0, 25) { child[i] = NULL; }
        maxWeight = __maxWeight;
    }
};

void addString(string &s, int w, TrieNode *&root)
{
    TrieNode *p = root;
    for (char c : s)
    {
        if (p->child[c - 'a'] != NULL)
            maximum(p->child[c - 'a']->maxWeight, w);
        if (p->child[c - 'a'] == NULL)
            p->child[c - 'a'] = new TrieNode(w);
        p = p->child[c - 'a'];
    }
}

int checkString(string &s, TrieNode *root)
{
    TrieNode *p = root;
    int w = -1;
    for (char c : s)
    {
        if (p->child[c - 'a'] == NULL)
            return -1;
        w = p->child[c - 'a']->maxWeight;
        p = p->child[c - 'a'];
    }
    return w;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q, w;
    string s;
    cin >> n >> q;
    TrieNode *root = new TrieNode(0);
    FOR(i, 1, n)
    {
        cin >> s >> w;
        addString(s, w, root);
    }
    FOR(i, 1, q)
    {
        cin >> s;
        cout << checkString(s, root) << endl;
    }
}