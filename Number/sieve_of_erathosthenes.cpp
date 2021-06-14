#include <bits/stdc++.h>
using namespace std;

// n log log n
vector<int> primeNumbers(int n)
{
    vector<int> ans;
    vector<int> sieve(n, true);
    sieve[0]=false;
    sieve[1]= false;
    for (int i = 2; i * i <= n; i++)
    {
        if (sieve[i])
        {
            for (int j = i * i; j <= n; j += i)
            {
                sieve[j] = false;
            }
        }
    }
    for (auto j : sieve)
    {
        if (j == true)
        {
            ans.push_back(j);
        }
    }
    return ans;
}