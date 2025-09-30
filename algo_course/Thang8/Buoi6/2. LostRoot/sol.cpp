#include <iostream> 
#include <string> 
#include <time.h>
#include <random>
#include <algorithm> 
#include <vector>
int n, k; 

std::string ask(int a, int b, int c) {
  std::cout << "? " << a << ' ' << b << ' ' << c << std::endl;
  fflush(stdout);
  std::string ret;
  std::cin >> ret;
  return ret;   
}                               

int main () {
  std::srand(time(NULL)); 
  std::cin >> n >> k; 
  int numbNodes = n; 
  int height = 0; 
  while (numbNodes > 0) {
    numbNodes /= k;
    height++; 
  }
  int leaf1 = -1, leaf2 = -1;
  std::vector <int> listVertex; 
  while (true) {
    listVertex.clear(); 
    leaf1 = std::rand() % n + 1; 
    leaf2 = std::rand() % n + 1; 
    if (leaf1 != leaf2) {
      for (int u = 1; u <= n; u++) {
        if (u == leaf1 || u == leaf2) {
          continue;
        }
        std::string ans = ask(leaf1, u, leaf2); 
        if (ans == "Yes") {
          listVertex.push_back(u); 
        }
      }
      if (height * 2 - 3 == (int) listVertex.size()) {
        break; 
      }   
    }
  }
  for (int i = 0; i < (int) listVertex.size(); i++) {
    int root = listVertex[i]; 
    int cnt = 0; 
    for (int j = 0; j < (int) listVertex.size(); j++) {
      int node = listVertex[j];
      if (root == node || root == leaf1) {
        continue;
      } 
      std::string ans = ask(leaf1, node, root); 
      if (ans == "Yes") {
        cnt++; 
      }
    }
    if (cnt == height - 2) {
      std::cout << "! " << root << std::endl;
      fflush(stdout); 
      return 0; 
    }
  }
  return 0; 
}