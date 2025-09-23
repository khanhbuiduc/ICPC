#include <iostream>
#include <math.h>
int a[1000005];
int n;
int fw[1000005];
int smaller[1000005], bigger[1000005];
long long totalSmaller[1000005], totalBigger[1000005];

void update(int index, int value)
{
  for (; index <= 1000000; index += index & -index)
  {
    fw[index] += value;
  }
}

int get(int index)
{
  int ret = 0;
  for (; index > 0; index -= index & -index)
  {
    ret += fw[index];
  }
  return ret;
}

int main()
{
  std::cin >> n;
  for (int i = 1; i <= n; i++)
  {
    std::cin >> a[i];
  }
  for (int i = 1; i <= n; i++)
  {
    smaller[a[i]] = a[i] - 1 - get(a[i] - 1);
    bigger[a[i]] = i - 1 - get(a[i] - 1);
    update(a[i], 1);
  }
  for (int i = 1; i <= n; i++)
  {
    totalSmaller[i] = totalSmaller[i - 1] + smaller[i];
  }
  for (int i = n; i >= 1; i--)
  {
    totalBigger[i] = totalBigger[i + 1] + bigger[i];
  }
  long long ans = 1000000000000007LL;
  for (int i = 1; i <= n; i++)
  {
    ans = std::min(ans, totalSmaller[i - 1] + totalBigger[i + 1]);
  }
  std::cout << ans;
  return 0;
}