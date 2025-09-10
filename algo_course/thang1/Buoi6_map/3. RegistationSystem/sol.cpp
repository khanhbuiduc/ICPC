#include <iostream>
#include <string>
#include <map>
std::map <std::string, int> database;
int n;  

int main () {
  std::cin >> n;
  for (int i = 1; i <= n; i++) {
    std::string username;
    std::cin >> username; 
    if (database.find(username) == database.end()) {
      std::cout << "OK" << std::endl; 
      database[username] = 1; 
    }
    else {
      std::cout << username << database[username] << std::endl; 
      database[username]++; 
    }
  }
  return 0; 
}