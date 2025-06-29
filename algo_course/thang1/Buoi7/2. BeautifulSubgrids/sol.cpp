#pragma GCC target("popcnt")
#include <iostream>
#include <bitset>
#include <string>
std::bitset<3000> S[3000];
int n;

int main()
{
  std::cin >> n;
  for (int i = 0; i < n; i++)
  {
    std::string s;
    std::cin >> s;
    for (int j = 0; j < n; j++)
    {
      if (s[j] == '1')
      {
        S[i].set(j, 1);
      }
    }
  }
  long long ans = 0LL;
  for (int i = 0; i < n; i++)
  {
    for (int j = i + 1; j < n; j++)
    {
      int cnt = (S[i] & S[j]).count();
      ans += cnt * (cnt - 1) / 2;
    }
  }
  std::cout << ans;
  return 0;
}