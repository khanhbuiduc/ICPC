#include <bits/stdc++.h>
using namespace std;

int main()
{
    // Open input and output files
    freopen("string.inp", "r", stdin);
    freopen("string.out", "w", stdout);

    // 1. Read strings from input
    string str1, str2;
    cin >> str1 >> str2;

    // 2. Basic Operations
    cout << "String 1: " << str1 << endl;
    cout << "String 2: " << str2 << endl;
    cout << "Length of str1: " << str1.length() << endl;
    cout << "Size of str2: " << str2.size() << endl;
    cout << "Capacity of str1: " << str1.capacity() << endl;
    cout << "Is str1 empty? " << (str1.empty() ? "Yes" : "No") << endl;

    // 3. Access Operations
    cout << "First char of str1: " << str1[0] << endl;
    cout << "Last char of str1: " << str1.back() << endl;

    // 4. Modification Methods
    string modified = str1;
    modified.append(" " + str2);
    cout << "After append: " << modified << endl;

    modified.insert(str1.length(), "!");
    cout << "After insert: " << modified << endl;

    modified.replace(0, 5, "Hi");
    cout << "After replace: " << modified << endl;

    // 5. Search Operations
    cout << "Position of str2 in modified: " << modified.find(str2) << endl;
    cout << "Last occurrence of 'l': " << modified.rfind('l') << endl;

    // 6. Substring
    cout << "Substring of str1: " << str1.substr(0, 3) << endl;

    // 7. Comparison
    cout << "Compare str1 and str2: " << str1.compare(str2) << endl;

    // 8. Concatenation
    string result = str1 + " " + str2;
    cout << "Concatenated string: " << result << endl;

    // 9. String to Number conversions
    string numStr = "12345";
    int num = 0;
    // Convert string to number using ASCII
    for (char c : numStr)
    {
        num = num * 10 + (c - '0'); // c - '0' converts char to int using ASCII
    }
    cout << "\nString to Number conversion:" << endl;
    cout << "String '" << numStr << "' to number: " << num << endl;

    // 10. Number to String conversion using ASCII
    int number = 67890;
    string strNum = "";
    int temp = number;
    // Convert each digit to char and build string in reverse
    while (temp > 0)
    {
        char digit = (temp % 10) + '0'; // Convert digit to char using ASCII
        strNum = digit + strNum;        // Add at beginning to maintain order
        temp /= 10;
    }
    cout << "Number " << number << " to string: '" << strNum << "'" << endl;

    // 11. Character ASCII demonstrations
    cout << "\nASCII Demonstrations:" << endl;
    string abc = "ABC";
    cout << "ASCII values of 'ABC': ";
    for (char c : abc)
    {
        cout << (int)c << " ";
    }
    cout << endl;

    // 12. Create string from ASCII values
    vector<int> ascii = {97, 98, 99}; // ASCII for "abc"
    string fromAscii = "";
    for (int val : ascii)
    {
        fromAscii += (char)val;
    }
    cout << "String from ASCII values 97,98,99: '" << fromAscii << "'" << endl;

    return 0;
}
