#include <bits/stdc++.h>
using namespace std;
typedef tuple<int, int, int> tiii;
void printDogs(vector<tiii> dogs)
{
    int w, i, v;
    for (auto dog : dogs)
    {
        tie(w, i, v) = dog;
        cout << w << " " << i << " " << v << "\n";
    }
}
int main()
{
    freopen("hunting_dog.inp", "r", stdin);
    freopen("hunting_dog.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int v, w, i;
    int sum = 0;
    int n;
    cin >> n;
    if (n == 1)
    {
        cin >> w >> i >> v;
        cout << v;
    }
    vector<tiii> dogs(n);
    for (auto &dog : dogs)
    {
        cin >> w >> i >> v;
        dog = {w, i, v};
    }
    sort(dogs.begin(), dogs.end());
    printDogs(dogs);
    for (int p = 0; p < n - 1; p++)
    {
        for (int q = p + 1; q < n; q++)
        {

            if (get<1>(dogs[p]) <= get<1>(dogs[q]))
            {

                sum = max(sum, (get<2>(dogs[p]) + get<2>(dogs[q])));
            }
        }
    }
    cout << sum;
    return 0;
}