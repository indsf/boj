#include <iostream>
using namespace std;
long long a[101][10] = { 0 };
int mod = 1000000000;
long long ans = 0;
void solve(int n)
{
	for (int i = 1; i <= 9; i++)
		a[0][i] = 1;

	for (int i = 1; i <= n; i++)
	{
		a[i][0] = a[i - 1][1];
		a[i][9] = a[i - 1][8];
		for (int j = 1; j < 9;j++)
		{
			a[i][j] = (a[i - 1][j - 1] + a[i - 1][j + 1]) % mod;
		}
	}
	
	for (int i = 0; i < 10; i++)
	{
		ans = (ans + a[n - 1][i]) % mod;
	}
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n;
	cin >> n;
	solve(n);
	cout << ans << '\n';
	return 0;
}

