#include <iostream> 
#include <stdio.h>
#include <vector> 
#include <math.h>
int a[100005]; 
int numQueries, n; 
int block[100005]; 
int final[100005]; 
int next[100005];
int numbSteps[100005];  
          
int main () {
  scanf("%d %d", &n, &numQueries);            
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]); 
  }
  int BLOCK = 375; 
  numbSteps[n] = 0; 
  for (int i = n - 1; i >= 0; i--) {
    final[i] = i; 
    block[i] = i / BLOCK; 
    next[i] = std::min(n, i + a[i]);
    numbSteps[i] = 0;
    if (next[i] < n && i / BLOCK == next[i] / BLOCK) {
      final[i] = final[next[i]]; 
      numbSteps[i] = numbSteps[next[i]] + 1; 
    }   
  }
  for (int query = 1; query <= numQueries; query++) {
    int type;
    scanf("%d", &type); 
    if (type == 0) {
      int position, step;
      scanf("%d %d", &position, &step); 
      position--; 
      a[position] = step; 
      for (int i = position; i / BLOCK == position / BLOCK && i >= 0; i--) {
        final[i] = i; 
        next[i] = std::min(n, i + a[i]); 
        numbSteps[i] = 0; 
        if (next[i] < n && i / BLOCK == next[i] / BLOCK) {
          final[i] = final[next[i]];
          numbSteps[i] = numbSteps[next[i]] + 1;  
        }
      }  
    }
    else {
      int position; 
      scanf("%d", &position);
      position--;          
      int p = position; 
      int ans = 0;                                       
      int ansLast = 0; 
      while (p < n) {
        ansLast = p; 
        if (final[p] != p) {
          ans += numbSteps[p]; 
          p = final[p]; 
        }      
        else {
          ans++; 
          p = next[p]; 
        }
      }                              
      printf("%d %d\n", ansLast + 1, ans); 
    }
  }
  return 0; 
}