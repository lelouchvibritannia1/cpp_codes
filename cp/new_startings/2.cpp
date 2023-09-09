#include <bits/stdc++.h>
using namespace std;

int i;

bool check(int m, map<int, int> &mp)
{
    int temp = 0;
    for (auto x : mp)
    {
        if (x.second % m > 1)
            return false;
        temp += x.second / m;
    }
    i = temp;
    return true;
}

void minSecurityLevels(vector<int> &a)
{

    int n = a.size();
    map<int, int> mp;
    for (int i : a)
    {
        mp[i]++;
        // cout << i << " ";
    }
    int mn = n;
    for (auto x : mp)
    {
        // cout << x.first << " " << x.second << endl;
        mn = min(x.second, mn);
    }
    int l = 1, r = mn;
    int ans;
    for (int m = mn; m > 0; m--)
    {
        if (check(m, mp))
        {
            cout << i << endl;
            return;
        }
    }
    cout << n << endl;
}

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a)
        cin >> x;
    minSecurityLevels(a);
}