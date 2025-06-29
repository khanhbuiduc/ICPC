#include <iostream>
#include <queue>
#include <string>
#include <vector>
struct argus {
  int ID, p, v;
};
std::string command;
struct compare {
  bool operator () (argus &a, argus &b) {
    if (a.v != b.v) {
      return a.v > b.v;
    }
    else {
      return a.ID > b.ID;
    }
  }
}; 
std::priority_queue <argus, std::vector <argus>, compare> pq; 

int main () {
  while (true) {
    std::cin >> command; 
    if (command == "Register") {
      int ID, p;
      std::cin >> ID >> p;
      argus element;
      element.ID = ID;
      element.p = element.v = p;
      pq.push(element); 
    }
    else {
      break;
    }
  }
  int numQuery;
  std::cin >> numQuery;
  for (int query = 1; query <= numQuery; query++) {
    argus element = pq.top();
    pq.pop();
    std::cout << element.ID << std::endl;
    element.v += element.p;
    pq.push(element);
  }
  return 0;
}