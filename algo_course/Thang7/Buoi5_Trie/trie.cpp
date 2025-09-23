#include <bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
map<char, int> id = {{'A', 1}, {'T', 2}, {'G', 3}, {'X', 4}};
struct Node
{
    Node *child[4];
    bool isEnd;
    Node()
    {
        FOR(i, 0, 3) { child[i] = nullptr; }
        isEnd = false;
    }
};
void addString(string &s, Node *&root)
{
    Node *p = root;
    for (auto c : s)
    {
        if (p->child[id[c]] == NULL)
        {
            p->child[id[c]] = new Node();
        }
        p = p->child[id[c]];
    }
    p->isEnd = true;
}

bool check(const string &s, Node *root)
{
    Node *p = root;
    for (auto c : s)
    {
        if (p->child[id[c]] == NULL)
            return false;
        p = p->child[id[c]];
    }
    return p->isEnd;
}

main()
{
    Node *root = new Node();
}
