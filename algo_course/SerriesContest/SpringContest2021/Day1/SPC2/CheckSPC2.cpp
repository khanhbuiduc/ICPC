#include <iostream>
#include <vector>
#include <utility>
#include <set>

using namespace std;
vector <int> inp;
vector <vector <pair <int, int> > > out;
int numTest;

bool isCorrect(int N, vector <pair <int, int> > &result) {
  set <int> S;
  if ((int) result.size() != N) {
    return false;
  }
  for (int i = 0; i < N; i++) {
    if (result[i].first > N || result[i].first < 1) {
      return false;
    }
    if (result[i].second > N || result[i].second < 1) {
      return false;
    }
    S.insert(result[i].first);
  }
  if ((int) S.size() != N) {
    return false;
  }
  S.clear();
  set <int> S1, S2;
  for (int i = 0; i < N; i++) {
    int x = result[i].first;
    int y = result[i].second;
    if (S1.find(x - y) != S1.end() || S2.find(x + y) != S2.end()) {
      return false;
    }
    S1.insert(x - y);
    S2.insert(x + y);
  }
  return true;
}

int main () {
  freopen("SPC2.INP", "r", stdin);
  cin >> numTest;
  for (int i = 1; i <= numTest; i++) {
    int N;
    cin >> N;
    inp.push_back(N);
  }
  cin.clear();
  freopen("SPC2.OUT", "r", stdin);
  for (int i = 0; i < numTest; i++) {
    int N = inp[i];
    vector <pair <int, int> > v;
    for (int j = 1; j <= N; j++) {
      int r, c;
      cin >> r >> c;
      v.push_back(make_pair(r, c));
    }
    out.push_back(v);
  }
  bool check = true;
  for (int i = 0; i < numTest; i++) {
    if (isCorrect(inp[i], out[i]) == false) {
      check = false;
      break;
    }
  }
  if (check == false) {
    cout << "Wrong Answer" << endl;
    cout << 0.0 << endl;
  }
  else {
    cout << "Correct!!!!" << endl;
    cout << 1.0 << endl;
  }
  return 0;
}