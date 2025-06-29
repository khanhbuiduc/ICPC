#include <iostream> 
#include <string>
#include <map>
#include <tuple> 
#include <math.h> 
#include <vector>
int numTest; 
int n; 
std::map <std::string, std::tuple <long long, std::vector <std::string>, std::vector <std::string> > > mymap; 

std::tuple <long long, std::vector <std::string>, std::vector <std::string> > process(const std::string &value) {
  std::tuple <long long, std::vector <std::string>, std::vector <std::string> > ret; 
  long long numb = 0LL; 
  for (int i = 0; i + 3 < (int) value.size(); i++) {
    if (value[i] == 'h' && value[i + 1] == 'a' && value[i + 2] == 'h' && value[i + 3] == 'a') {
      numb++; 
    }  
  }
  int len = (int) value.size(); 
  std::vector <std::string> prefix;
  for (int i = 0; i <= std::min(len - 1, 2); i++) {
    std::string s = ""; 
    for (int j = 0; j <= i; j++) {
      s += value[j]; 
    }
    prefix.push_back(s); 
  } 
  std::vector <std::string> suffix;
  for (int i = len - 1; i >= std::max(0, len - 3); i--) {
    std::string s = ""; 
    for (int j = i; j <= len - 1; j++) {
      s += value[j]; 
    }
    suffix.push_back(s); 
  }  
  ret = std::make_tuple(numb, prefix, suffix); 
  return ret; 
}

std::tuple <long long, std::vector <std::string>, std::vector <std::string> > mergeInfo(const std::tuple <long long, std::vector <std::string>, std::vector <std::string> > &info1, const std::tuple <long long, std::vector <std::string>, std::vector <std::string> > &info2) {
  std::tuple <long long, std::vector <std::string>, std::vector <std::string> > ret; 
  long long numb1 = std::get <0> (info1); 
  std::vector <std::string> prefix1 = std::get <1> (info1); 
  std::vector <std::string> suffix1 = std::get <2> (info1); 
  long long numb2 = std::get <0> (info2); 
  std::vector <std::string> prefix2 = std::get <1> (info2); 
  std::vector <std::string> suffix2 = std::get <2> (info2); 
  long long numb = numb1 + numb2; 
  for (int i = 0; i < (int) suffix1.size(); i++) {
    for (int j = 0; j < (int) prefix2.size(); j++) {
      if (suffix1[i] + prefix2[j] == "haha") {
        numb++;   
      }
    }
  }
  std::vector <std::string> prefix = prefix1; 
  for (int i = 0; i < (int) prefix2.size(); i++) {
    if ((int) prefix1.back().size() + (int) prefix2[i].size() <= 3) {
      prefix.push_back(prefix1.back() + prefix2[i]); 
    }
  }
  std::vector <std::string> suffix = suffix2; 
  for (int i = 0; i < (int) suffix1.size(); i++) {
    if ((int) suffix1[i].size() + (int) suffix2.back().size() <= 3) {
      suffix.push_back(suffix1[i] + suffix2.back()); 
    }
  }
  ret = std::make_tuple(numb, prefix, suffix);
  return ret; 
}

int main () {
  std::cin >> numTest; 
  for (int testCase = 1; testCase <= numTest; testCase++) {
    mymap.clear();
    std::string lastName; 
    std::cin >> n;
    for (int i = 1; i <= n; i++) {
      std::string name, oper;
      std::cin >> name >> oper;
      lastName = name; 
      if (oper == ":=") {
        std::string value; 
        std::cin >> value; 
        std::tuple <long long, std::vector <std::string>, std::vector <std::string> > information = process(value); 
        mymap[name] = information;                                                                                 
      }        
      else {
        std::string name1, name2;
        std::string plusOperator;
        std::cin >> name1 >> plusOperator >> name2;
        std::tuple <long long, std::vector <std::string>, std::vector <std::string> > information1 = mymap[name1]; 
        std::tuple <long long, std::vector <std::string>, std::vector <std::string> > information2 = mymap[name2];
        std::tuple <long long, std::vector <std::string>, std::vector <std::string> > information = mergeInfo(information1, information2);
        mymap[name] = information;    
      } 
    }
    std::tuple <long long, std::vector <std::string>, std::vector <std::string> > information = mymap[lastName];
    std::cout << std::get <0> (information) << std::endl;  
  }
  return 0; 
}