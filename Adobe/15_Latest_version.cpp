// Given two library versions of an executable: for example, “10.1.1.3” and “10.1.1.9” or “10” and “10.1”. Find out which one is more recent? Strings can be empty also

#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    vector<int> vec1, vec2;
    string str = "";
    for (auto x : s1)
    {
        if (x == '.')
        {
            vec1.push_back(stoi(str));
            str = "";
        }
        else
            str += x;
    }
    vec1.push_back(stoi(str));

    str = "";
    for (auto x : s2)
    {
        if (x == '.')
        {
            vec2.push_back(stoi(str));
            str = "";
        }
        else
            str += x;
    }
    vec2.push_back(stoi(str));

    int n = vec1.size(), m = vec2.size(), i = 0, j = 0;
    while (i < n && j < m)
    {
        if (vec1[i] > vec2[j])
        {
            cout << s1;
            return 0;
        }
        else if (vec1[i] < vec2[j])
        {
            cout << s2;
            return 0;
        }
        i++, j++;
    }
    if (i < n)
        cout << s1;
    else
        cout << s2;
    return 0;
}