#include <bits/stdc++.h>
using namespace std;

int main()
{
	//code
	int t;
	cin >> t;
	while (t--)
	{
		long long int N;
		cin >> N;
		if (N == 0)
		{
			cout << "NO" << endl;
		}
		else
		{
			if ((N & (N - 1)) == 0)
			{
				cout << "YES" << endl;
			}
			else
			{
				cout << "NO" << endl;
			}
		}
	}
	return 0;
}