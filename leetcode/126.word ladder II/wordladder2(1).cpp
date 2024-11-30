#include <bits/stdc++.h>
using namespace std;
void printLadders(vector<vector<string>> ladders)
{
    for (auto ladder : ladders)
    {
        for (auto word : ladder)
            cout << word << " ";
        cout << endl;
    }
}
vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList)
{
    unordered_set<string> wordSet(wordList.begin(), wordList.end());
    vector<vector<string>> ans;
    queue<vector<string>> paths;
    wordSet.insert(endWord);
    paths.push({beginWord});
    int level = 1;
    int minLevel = INT_MAX;
    if (wordSet.find(endWord) != wordSet.end())
        return ans;
    unordered_set<string> visited;

    while (!paths.empty())
    {
        vector<string> path = paths.front();
        paths.pop();
        if (path.size() > level)
        {
            // reach a new level
            for (string w : visited)
                wordSet.erase(w);
            visited.clear();
            if (path.size() > minLevel)
                break;
            else
                level = path.size();
        }
        string last = path.back();

        for (int i = 0; i < last.size(); ++i)
        {
            string news = last;
            for (char c = 'a'; c <= 'z'; ++c)
            {
                news[i] = c;
                if (wordSet.find(news) != wordSet.end())
                {

                    vector<string> newpath = path;
                    newpath.push_back(news);
                    visited.insert(news);
                    if (news == endWord)
                    {
                        minLevel = level;
                        ans.push_back(newpath);
                    }
                    else
                        paths.push(newpath);
                }
            }
        }
    }
    return ans;
}

int main()
{
    freopen("WordLadder2.inp", "r", stdin);
    freopen("WordLadder2.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;

    string beginWord;
    string endWord;
    cin >> n;
    vector<string> wordList(n);
    for (string &word : wordList)
        cin >> word;
    cin >> beginWord >> endWord;
    vector<vector<string>> ladders = findLadders(beginWord, endWord, wordList);
    printLadders(ladders);
}
