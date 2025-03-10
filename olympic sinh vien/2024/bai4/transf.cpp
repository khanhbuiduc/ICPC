#include <bits/stdc++.h>
using namespace std;
// lưu trữ hàm ban đầuđầu
vector<string> allowed_substrings = {"AA", "BB", "CC", "DDDD", "BABA", "ACAC", "DABCACB"};
// lưu trữ các bước;
// phuơng pháp này chỉ giải quyết khi steps<10;
struct State
{
    string current;
    vector<pair<int, int>> steps;
};

vector<pair<int, int>> get_transformations(string S, string T)
{
    queue<State> q;
    unordered_set<string> visited;
    q.push({S, {}});
    visited.insert(S);

    while (!q.empty())
    {
        State state = q.front();
        q.pop();
        if (state.current == T)
            return state.steps;

        // Try inserting
        for (int i = 0; i < allowed_substrings.size(); ++i)
        {
            const string &sub = allowed_substrings[i];
            for (int pos = 0; pos <= state.current.size(); ++pos)
            {
                string new_str = state.current.substr(0, pos) + sub + state.current.substr(pos);
                if (visited.find(new_str) == visited.end())
                {
                    visited.insert(new_str);
                    auto new_steps = state.steps;
                    new_steps.emplace_back(pos + 1, i + 1);
                    q.push({new_str, new_steps});
                }
            }
        }

        // Try deleting
        for (int i = 0; i < allowed_substrings.size(); ++i)
        {
            const string &sub = allowed_substrings[i];
            size_t pos = 0;
            while ((pos = state.current.find(sub, pos)) != string::npos)
            {
                string new_str = state.current.substr(0, pos) + state.current.substr(pos + sub.size());
                if (visited.find(new_str) == visited.end())
                {
                    visited.insert(new_str);
                    auto new_steps = state.steps;
                    new_steps.emplace_back(pos + 1, -(i + 1));
                    q.push({new_str, new_steps});
                }
                pos += 1;
            }
        }
    }

    return {}; // No solution found
}

int main()
{
    freopen("transf.inp", "r", stdin);
    freopen("transf.out", "w", stdout);
    string S, T;
    cin >> S >> T;

    vector<pair<int, int>> steps = get_transformations(S, T);
    if (!steps.empty())
    {
        cout << steps.size() << "\n";
        for (const auto &step : steps)
        {
            cout << step.first << " " << step.second << "\n";
        }
    }
    else
    {
        cout << -1 << "\n"; // No solution found
    }

    return 0;
}
