#include <bits/stdc++.h>
using namespace std;

void answer(int n, int op, int cl, string res, vector<string> &ans)
{
    if (op + cl == 2 * n)
    {
        ans.push_back(res);
    }
    if (op < n)
    {
        answer(n, op + 1, cl, res + "(", ans);
    }
    if (cl < op)
    {
        answer(n, op, cl + 1, res + ")", ans);
    }
}

vector<string> generateParenthesis(int n)
{
    vector<string> ans;
    string res = "";
    if (n > 0)
    {
        answer(n, 0, 0, res, ans);
    }
    return ans;
}