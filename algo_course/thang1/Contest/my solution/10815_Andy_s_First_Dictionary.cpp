#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
typedef pair<int, int> pii;
typedef tuple<int, int, int> tiii;
typedef long long ll;
set<string> dic;
void solveString(string &str)
{
    string newstring = "";
    for (auto c : str)
    {
        if (isalpha(c))
            newstring += tolower(c);
        else if (!newstring.empty())
        {
            dic.insert(newstring);
            newstring = "";
        }
    }
    if (!newstring.empty())
        dic.insert(newstring);
}
int main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    string str;
    while (cin >> str)
    {
        solveString(str);
    }
    for (auto word : dic)
        if (!word.empty())
            cout << word << "\n";
    return 0;
}

// lưu trữ trong  set
/*
    duyệt từng từ:
        -lower case
        -bỏ dấu qua những kỹ tự không phải alphabet
    in lần lượt các chữ ra màn hình

    số ký tự 5000*200=1000000 ký tự
    //thiếu sử lý trường hợp "alpha-beta"

*/