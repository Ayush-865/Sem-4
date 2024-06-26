#include <bits/stdc++.h>
using namespace std;

vector<int> prefix_function(string s)
{
    int n = s.size();
    vector<int> pi(n, 0);
    for (int i = 1; i < n; i++)
    {
        int j = pi[i - 1];

        while (j > 0 && s[i] != s[j])
            j = pi[j - 1];

        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
}

int main()
{
    string s = "abcabcd";
    vector<int> prefix = prefix_function(s);
    string t = "cd";
    int pos = -1;
    int i = 0, j = 0;

    while (i < s.size())
    {
        if (s[i] == t[j])
        {
            i++;
            j++;
        }
        else
        {
            if (j != 0)
                j = prefix[j - 1];
            else
                i++;
        }
        if (j == t.size())
        {
            pos = i - t.size();
            break;
        }
    }

    cout << pos << "\n";

    for (auto it : prefix)
        cout << it << " ";
    return 0;
}