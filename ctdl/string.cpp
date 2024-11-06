#include <iostream>
#include <string>
using namespace std;
int main()
{
    // 2.Creating strings
    std::string str1 = "Hello, World!";
    std::string str2; // Empty string
    // string with n element 0
    int n = 5;
    string s(n, '0');
    // Assigning a value
    str2 = "Welcome to C++ programming.";

    // Outputting the strings
    std::cout << str1 << std::endl;
    std::cout << str2 << std::endl;
    // 3. String Operations
    std::string str3 = str1 + " " + str2;
    cout << "Length of str1: " << str1.length();
    char firstChar = str1[0];       // 'H'
    char secondChar = str1.at(1);   // 'e'
    string sub = str1.substr(0, 5); // "Hello"
    // find position;
    size_t pos = str1.find("World");
    if (pos != std::string::npos)
    {
        std::cout << "'World' found at position: " << pos << std::endl;
    }
    str1.replace(7, 5, "C++"); // Changes "World" to "C++"
    str1.erase(5, 1);          // Removes the comma
    // interating through the string
    for (char c : str1)
    {
        cout << c << endl;
    }
    // stoi() : Chuyển chuỗi thành int.
    // stol() : Chuyển chuỗi thành long.
    //  stoll() : Chuyển chuỗi thành long long.
    //  stof() : Chuyển chuỗi thành float.
    //  stod() : Chuyển chuỗi thành double.
    //  stold() : Chuyển chuỗi thành long double.
    // int num = c - '0'; c là char
    return 0;
}