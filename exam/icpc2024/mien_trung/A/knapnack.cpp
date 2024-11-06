#include <bits/stdc++.h>
using namespace std;
#define NAME "knapsack."

ifstream fi(NAME "inp");
ofstream fo(NAME "out");

void enter(int &n, int &W, vector<pair<int, int>> &items) // Pass by reference
{
    fi >> n >> W;
    items.resize(n + 1);
    for (int i = 1; i <= n; ++i)
        fi >> items[i].first >> items[i].second;
}

// Trace back chosen items
void trace_back(int n, int W, vector<vector<int>> &dp, vector<pair<int, int>> &items)
{
    vector<int> picked_items;
    while (n > 0)
    {
        if (dp[n][W] != dp[n - 1][W])
        {
            picked_items.push_back(n);
            W -= items[n].second;
        }
        n--;
    }

    for (int i : picked_items)
        fo << i << ' ';
}

// Dynamic programming solution
void solution(int n, int W, vector<pair<int, int>> &items)
{
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    for (int i = 1; i <= n; ++i)
        for (int j = 0; j <= W; ++j)
        {
            dp[i][j] = dp[i - 1][j];

            if (j >= items[i].first)
                dp[i][j] = max(dp[i][j], dp[i - 1][j - items[i].first] + items[i].second);
        }

    // Output result
    fo << dp[n][W] << endl;
    trace_back(n, W, dp, items);
}

int main()
{
    int n, W;
    vector<pair<int, int>> items;

    if (!fi || !fo) // Check if files are opened successfully
    {
        cerr << "Error opening files." << endl;
        return 1;
    }

    enter(n, W, items);
    solution(n, W, items);

    fi.close();
    fo.close();
    return 0;
}
