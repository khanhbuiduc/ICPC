#include <bits/stdc++.h> 

using namespace std; 
int test; 
string s; 

int main () {
  freopen("SPC6.INP", "r", stdin);
  freopen("SPC6.OUT", "w", stdout); 
  cin >> test; 
  for (int tt = 1; tt <= test; tt++) {
    cin >> s; 
    stack <int> st; 
    for (int i = 0; i < (int) s.size(); i++) {
      if (s[i] == '(') {
        st.push(-1); 
      }
      else if (s[i] == 'C') {
        st.push(12);
      } 
      else if (s[i] == 'H') {
        st.push(1); 
      }
      else if (s[i] == 'O') {
        st.push(16); 
      }
      else if (s[i] == ')') {
        int sum = 0; 
        while (true) {
          int t = st.top();             
          st.pop(); 
          if (t == -1) {
            break; 
          }
          sum += t; 
        }
        st.push(sum);
      }
      else {
        int t = st.top();
        st.pop(); 
        t *= s[i] - '0'; 
        st.push(t); 
      }
    }
    int res = 0;
    while (!st.empty()) {
      int t = st.top(); 
      st.pop();
      res += t; 
    }
    cout << res << endl; 
  }
  return 0; 
}