#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#include <utility>
int n, numQueries;
int a[100005];
std::vector<std::pair<int, int>> save;
int level[100005];
struct itnode
{
  itnode *left, *right;
  int cnt;
};
std::vector<itnode *> version;
int ans[100005];

itnode *createNode()
{
  itnode *ret = new itnode();
  ret->left = NULL;
  ret->right = NULL;
  ret->cnt = 0;
  return ret;
}

void build(itnode *&root, int L, int R)
{
  root = createNode();
  if (L == R)
  {
    return;
  }
  int mid = (L + R) / 2;
  build(root->left, L, mid);
  build(root->right, mid + 1, R);
}

void update(itnode *&root, int L, int R, int level)
{
  if (L == R)
  {
    root = createNode();
    root->cnt++;
    return;
  }
  itnode *tmp = createNode();
  *tmp = *root;
  int mid = (L + R) / 2;
  if (level <= mid)
  {
    update(tmp->left, L, mid, level);
  }
  else
  {
    update(tmp->right, mid + 1, R, level);
  }
  root = tmp;
  root->cnt = root->left->cnt + root->right->cnt;
}

int get(itnode *rootLeft, itnode *rootRight, int L, int R, int k)
{
  if (L == R)
  {
    return L;
  }
  int mid = (L + R) / 2;
  int numb = rootRight->left->cnt - rootLeft->left->cnt;
  if (numb >= k)
  {
    return get(rootLeft->left, rootRight->left, L, mid, k);
  }
  return get(rootLeft->right, rootRight->right, mid + 1, R, k - numb);
}

int main()
{
  std::cin >> n >> numQueries;
  for (int i = 1; i <= n; i++)
  {
    std::cin >> a[i];
    save.push_back(std::make_pair(a[i], i));
  }
  std::sort(save.begin(), save.end());
  for (int i = 0; i < n; i++)
  {
    level[save[i].second] = i + 1;
    ans[i + 1] = save[i].first;
  }
  itnode *version0;
  build(version0, 1, n);
  version.push_back(version0);
  for (int i = 1; i <= n; i++)
  {
    itnode *newver = createNode();
    *newver = *version.back();
    update(newver, 1, n, level[i]);
    version.push_back(newver);
  }
  for (int query = 1; query <= numQueries; query++)
  {
    int l, r, k;
    std::cin >> l >> r >> k;
    int foundLevel = get(version[l - 1], version[r], 1, n, k);
    std::cout << ans[foundLevel] << std::endl;
  }
  return 0;
}