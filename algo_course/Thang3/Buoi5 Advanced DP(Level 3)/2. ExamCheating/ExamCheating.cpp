#include <bits/stdc++.h>
using namespace std;

int f[2][1005][53][53];
int n, p, k;
int ScoreA[1005], ScoreB[1005];

void maxPoint(int &a, int b)
{
    a = max(a, b);
}

int score(int nextPos, int ka, int kb)
{
    return (ka && ScoreA[nextPos]) | (kb && ScoreB[nextPos]);
}

int main()
{
    cin >> n >> p >> k;
    int cnt;
    cin >> cnt;
    for (int i = 1; i <= cnt; i++)
    {
        int idx;
        cin >> idx;
        ScoreA[idx] = 1;
    }
    cin >> cnt;
    for (int i = 1; i <= cnt; i++)
    {
        int idx;
        cin >> idx;
        ScoreB[idx] = 1;
    }

    int maxCopies = 2 * ((n + k - 1) / k);
    if (p >= maxCopies)
    {
        int res = 0;
        for (int i = 1; i <= n; i++)
        {
            res += ScoreA[i] | ScoreB[i];
        }
        cout << res;
        return 0;
    }
    // bài toán cơ sở
    for (int i = 0; i <= 1; i++)
    {
        for (int j = 0; j <= p; j++)
        {
            for (int ka = 0; ka <= k; ka++)
            {
                for (int kb = 0; kb <= k; kb++)
                {
                    f[i][j][ka][kb] = -1;
                }
            }
        }
    }

    f[0][0][0][0] = 0;
    // quy hoạch động
    for (int i = 0; i < n; i++)
    {
        int cur = i & 1;
        int next = 1 - cur;

        for (int j = 0; j <= p; j++)
        {
            for (int ka = 0; ka <= k; ka++)
            {
                for (int kb = 0; kb <= k; kb++)
                {
                    f[next][j][ka][kb] = -1;
                }
            }
        }

        for (int j = 0; j <= p; j++)
        {
            for (int ka = 0; ka <= k; ka++)
            {
                for (int kb = 0; kb <= k; kb++)
                {
                    if (f[cur][j][ka][kb] == -1)
                        continue;

                    int nextka = (ka == 0 || ka == k ? 0 : ka + 1);
                    int nextkb = (kb == 0 || kb == k ? 0 : kb + 1);

                    maxPoint(f[next][j][nextka][nextkb],
                             f[cur][j][ka][kb] + score(i + 1, nextka, nextkb));

                    if (j + 1 <= p)
                    {
                        maxPoint(f[next][j + 1][nextka][1],
                                 f[cur][j][ka][kb] + score(i + 1, nextka, 1));
                        maxPoint(f[next][j + 1][1][nextkb],
                                 f[cur][j][ka][kb] + score(i + 1, 1, nextkb));
                    }
                    if (j + 2 <= p)
                    {
                        maxPoint(f[next][j + 2][1][1],
                                 f[cur][j][ka][kb] + score(i + 1, 1, 1));
                    }
                }
            }
        }
    }

    int res = -1;
    for (int ka = 0; ka <= k; ka++)
    {
        for (int kb = 0; kb <= k; kb++)
        {
            maxPoint(res, f[n & 1][p][ka][kb]);
        }
    }
    cout << res;
    return 0;
}

/*
n câu hỏi, p lần liếc. mỗi lần liếc chép đc 3 câu
1 ≤ n, p ≤ 1, 000, 1 ≤ k ≤ min(n, 50))

kết quả

n=6 p=2 k=3
3 1 3 6
4 1 2 5 6
gọi f[i][j][ka][kb] là số điểm chép đc cao nhất với i câu hỏi và j lượt chép ka câu liên tục của an và kb câu liên tục của bình.
    --------------
    bài toán ban đầu:
        f[0][0][0][0] = 0
        f[i][j][a][b] != -inf
    kết quả: f[n][P][ka][ka] với ka: 0->k; kb: 0->k

    đật nextka, nextkb lần lượt là giá trị ka, kb khi không có lượt chép bài mới
    nextka = (1 <= ka <= k-1)? ka + 1: 0;
    nextkb  = (1 <= kb  <= k-1)? kb  + 1: 0;
    QHD: (f[i][j][a][b] != -inf)
    xét câu i + 1:
        case 1:không mở đợt chép bài mới ở câu i + 1:
            f[i + 1][j][nextka][nextkb] = max(f[i + 1][j][nextka][nextkb], f[i][j][ka][kb] + score(i+1, nextka>0,nextkb>0));
        case 2: mở đợt chép bài mới ở câu i + 1 của bạn an
            f[i + 1][j+1][1][nextkb] = max(f[i + 1][j+1][1][nextkb], f[i][j][ka][kb] + score(i+1, true,nextkb>0));
        case 2: mở đợt chép bài mới ở câu i + 1 của bạn bình
            f[i + 1][j+1][nextka][1] = max(f[i + 1][j+1][nextka][1], f[i][j][ka][kb] + score(i+1,  nextka>0,true));
        case 3: mở đợt chép bài mới ở câu i + 1 của cả 2 bạn an và bình
             f[i + 1][j+2][1][1] = max(f[i + 1][j+2][1][1], f[i][j][ka][kb] + score(i+1,  true,true))
    độ phức tạp: 1000*1000*50*50= 2500'000'000
    nhận xét:
        (N+k-1)/k lần chép là phủ toàn bộ n câu của của an
        2*(N+k-1)/k lần chép là phủ toàn bộ n câu của của an và bình
        ==> nếu P >= 2*(N+k-1)/k return
            nếu ngược lại: QHD
        O(n*p*k*k)= O(n^2*k) = 50'000'000
*/