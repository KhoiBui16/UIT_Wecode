#include <bits/stdc++.h>

using namespace std;

bool isAnagram(string s, string t)
{
    if (s.length() != t.length()) return 0;
    sort (s.begin(), s.end());
    sort (t.begin(), t.end());
    return s == t;
}

int main()
{
    string s, t;
    getline(cin, s);
    getline(cin, t);
    map <char, long long> mp1, mp2;
    for (auto i: s) mp1[i]++;
    for (auto i: t) mp2[i]++;
    (isAnagram(s, t)) ? cout << "IS ANAGRAM" : cout << "NOT ANAGRAM!!!";
}