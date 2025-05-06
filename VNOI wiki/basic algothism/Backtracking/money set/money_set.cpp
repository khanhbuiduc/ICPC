#include <bits/stdc++.h>
using namespace std;

int n, S;
vector<int> prices;
typedef tuple<int, int, vector<int>> tiiv;
vector<vector<int>> result;
vector<int> suffixSum;

void printResult()
{
    for (auto row : result)
    {
        for (auto price : row)
            cout << price << " ";
        cout << endl;
    }
}
void preProceed()
{
    suffixSum.resize(n + 1);
    suffixSum[n] = 0;
    for (int i = n - 1; i >= 0; i--)
        suffixSum[i] = suffixSum[i + 1] + prices[i];
}
void genMonneySet()
{
    stack<tiiv> moneysets;
    moneysets.push({0, 0, {}});

    while (!moneysets.empty())
    {
        auto [index, sum, subset] = moneysets.top();
        moneysets.pop();

        for (int i = index; i < n; i++)
        {
            if (i > index && prices[i] == prices[i - 1])
                continue;
            int newSum = sum + prices[i];
            if (newSum > S)
                continue;
            auto newSubset = subset;
            newSubset.push_back(prices[i]);

            if (newSum == S)
                result.push_back(newSubset);
            else if (newSum < S)
                // nếu tổng của phần tiền còn lại không đủ bỏ qua nhánh
                if (newSum + suffixSum[i + 1] >= S)
                    moneysets.push({i + 1, newSum, newSubset});
        }
    }
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> n >> S;
    prices.resize(n);
    for (int &i : prices)
        cin >> i;
    sort(prices.rbegin(), prices.rend());
    preProceed();
    genMonneySet();
    printResult();
}
