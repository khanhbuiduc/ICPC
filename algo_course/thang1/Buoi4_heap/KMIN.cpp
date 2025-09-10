#include <bits/stdc++.h>
using namespace std;
typedef pair<int, pair<int, int>> node; // sum,{ai,bi}
int main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int M, N, K;
    cin >> M >> N >> K;
    priority_queue<node, vector<node>, greater<node>> p;
    vector<int> A(M);
    vector<int> B(N);
    for (auto &i : A)
        cin >> i;
    for (auto &i : B)
        cin >> i;
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    for (int i = 0; i < M; i++)
        p.push({A[i] + B[0], {i, 0}});
    while (K--)
    {
        int sum = p.top().first;
        auto [i, j] = p.top().second;
        p.pop();
        cout << sum << "\n";
        if (j + 1 < N)
            p.push({A[i] + B[j + 1], {i, j + 1}});
    }
}
/*
ngây thơ
    A: 1 2 3 4
    B: 2 3 4 5
    for i:A
        for j:B
            thêm i+j vào C
    C.priority_queue: in ra k phần tử đầu tiên
chuẩn:
    for i:A;
        thêm {i+0,{i,0}} vào c;     //c={3,{0,0}} , {4,{1,0}} , {5,{2,0}} , {4,{3,0}}
    for 1->k
        get min:                   //{3,{0,0}}:
        in sum;thêm i,j+1 vaò p    //thêm vào j+1 {4,{0,0+1}}

*/