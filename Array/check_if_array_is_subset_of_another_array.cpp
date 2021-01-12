#include <bits/stdc++.h>
using namespace std;
int main()
{
    //code
    int t;
    cin >> t;
    while (t--)
    {
        int m, n;
        cin >> n >> m;
        int arr[n], arr1[m];
        map<int, int> mp, mp1;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            mp[arr[i]]++;
        }
        for (int i = 0; i < m; i++)
        {
            cin >> arr1[i];
            mp1[arr1[i]]++;
        }
        int flag = 0;
        for (auto j : mp1)
        {
            if (mp.count(j.first) > 0)
            {
                if ((mp[j.first] - j.second) < 0)
                {
                    flag = 1;
                    break;
                }
                else
                {
                    flag = 0;
                }
            }
            else
            {
                flag = 1;
                break;
            }
        }
        if (flag == 1)
        {
            cout << "No" << endl;
        }
        else
        {
            cout << "Yes" << endl;
        }
    }
    return 0;
}