#include <iostream>
long long a[200005];
int n, k;

int main()
{
  std::cin >> n >> k;
  for (int i = 1; i <= n; i++)
  {
    std::cin >> a[i];
  }
  long long lo = 1;
  long long hi = 2'000'000'000'000'007LL;
  long long ans = 0LL;
  while (lo <= hi)
  {
    long long mid = (lo + hi) >> 1;
    int numbArray = 0;
    long long sum = 10'000'000'000'000'007LL;
    bool check = true;
    for (int i = 1; i <= n; i++)
    {
      if (a[i] > mid)
      {
        check = false;
        break;
      }
      if (sum + a[i] <= mid)
      {
        sum += a[i];
      }
      else
      {
        sum = a[i];
        numbArray++;
      }
    }
    if (check == false || numbArray > k)
    {
      lo = mid + 1;
    }
    else
    {
      ans = mid;
      hi = mid - 1;
    }
  }
  std::cout << ans;
  return 0;
}