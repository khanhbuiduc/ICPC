#include <bits/stdc++.h>
using namespace std;
int main()
{
    priority_queue<int, vector<int>, greater<int>> minHeap;
    int N, ai;
    while (cin >> N && N)
    {
        int sum = 0;
        while (N--)
        {
            cin >> ai;
            minHeap.push(ai);
        }
        while (minHeap.size() > 1)
        {
            // chi chi phí
            int cost = minHeap.top();
            minHeap.pop();
            cost += minHeap.top();
            minHeap.pop();
            // tổng chi phí
            sum += cost;
            // update minHeap
            minHeap.push(cost);
        }
        minHeap.pop();
        cout << sum << "\n";
    }
}