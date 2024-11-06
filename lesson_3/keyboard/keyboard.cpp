#include <bits/stdc++.h>
using namespace std;
ifstream fi("input");
ofstream fo("output");
int main()
{
    string s;
    int n;
    unordered_map<char, vector<int>> countChar; //{ci,{xi,count}}x
    fi >> s >> n;
    int lng = s.length();
    cout << "length of string:" << lng << endl;
    int answer = lng;
    for (int i = 0; i < n; i++)
    {
        char ci;
        int xi;
        fi >> ci >> xi;
        countChar[ci] = {xi, 0};
    }
    for (char c : s)
    {
        if (countChar.count(c) > 0)
        {
            countChar[c][1]++;
        };
    }
    // print pair
    for (const auto &pair : countChar)
    {
        cout << "Key: " << pair.first << ", Values: [" << pair.second[0] << ", " << pair.second[1] << "]" << endl;
    }
    for (const auto &pair : countChar)
    {
        int ci = pair.second[1];
        int xi = pair.second[0];
        answer += 1 + (ci - 1) / (xi);
    }
    cout << "answer:" << answer << endl;
    fo << answer;
}