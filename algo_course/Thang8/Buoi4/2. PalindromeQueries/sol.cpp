#include <iostream>
#include <utility>
#include <string> 
int n, numQueries; 
std::string s; 
long long power27[200005]; 
struct itnode {
  long long prefix = 0LL, suffix = 0LL; 
};
itnode it[4 * 200005]; 

void build(int index, int L, int R) {
  if (L == R) {
    it[index].prefix = power27[L - 1] * (s[L - 1] - 'a' + 1); 
    it[index].suffix = power27[n - L] * (s[L - 1] - 'a' + 1); 
    return; 
  }
  int mid = (L + R) / 2; 
  build(2 * index, L, mid); 
  build(2 * index + 1, mid + 1, R); 
  it[index].prefix = it[2 * index].prefix + it[2 * index + 1].prefix; 
  it[index].suffix = it[2 * index].suffix + it[2 * index + 1].suffix; 
}

void update(int index, int L, int R, int position, const long long &mul) {
  if (L > position || R < position) {
    return; 
  }
  if (position <= L && R <= position) {
    it[index].prefix += mul * (s[position - 1] - 'a' + 1) * power27[position - 1];
    it[index].suffix += mul * (s[position - 1] - 'a' + 1) * power27[n - position];
    return; 
  }
  int mid = (L + R) / 2; 
  update(2 * index, L, mid, position, mul);
  update(2 * index + 1, mid + 1, R, position, mul); 
  it[index].prefix = it[2 * index].prefix + it[2 * index + 1].prefix; 
  it[index].suffix = it[2 * index].suffix + it[2 * index + 1].suffix;
}

std::pair <long long, long long> get(int index, int L, int R, int l, int r) {
  if (l > R || L > r) {
    return std::make_pair(0LL, 0LL); 
  }  
  if (l <= L && R <= r) {
    return std::make_pair(it[index].prefix, it[index].suffix); 
  }
  int mid = (L + R) / 2;
  std::pair <long long, long long> leftNode = get(2 * index, L, mid, l, r); 
  std::pair <long long, long long> rightNode = get(2 * index + 1, mid + 1, R, l, r); 
  return std::make_pair(leftNode.first + rightNode.first, leftNode.second + rightNode.second); 
}

void init() {
  power27[0] = 1LL; 
  for (int i = 1; i <= n; i++) {
    power27[i] = power27[i - 1] * 27LL; 
  }
  build(1, 1, n); 
}

int main () {
  std::cin >> n >> numQueries; 
  std::cin >> s; 
  init(); 
  for (int query = 1; query <= numQueries; query++) {
    int type; 
    std::cin >> type; 
    if (type == 1) {
      int position;
      char c; 
      std::cin >> position >> c; 
      update(1, 1, n, position, (long long) -1);
      s[position - 1] = c;
      update(1, 1, n, position, (long long) 1);  
    }
    else {
      int l, r;
      std::cin >> l >> r; 
      std::pair <long long, long long> value = get(1, 1, n, l, r);
      if (value.first * power27[n - r] == value.second * power27[l - 1]) {
        std::cout << "YES" << std::endl; 
      }                   
      else {
        std::cout << "NO" << std::endl;
      }
    }
  }
  return 0;
}