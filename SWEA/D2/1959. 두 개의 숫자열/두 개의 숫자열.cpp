#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<int>arr;
vector<int>arr1;
int n, m;

int solve()
{
	int ans = 0;
	if (n > m)
	{
		for (int i = 0; i <= n - m; i++)
		{
			int sum = 0;
			for (int k = i; k < i + m; k++)
			{
				sum += arr[k] * arr1[k-i];
			}
			ans = max(sum, ans);
		}
	}
	else
	{
		for (int j = 0; j <= m - n; j++)
		{
			int sum = 0;
			for (int t = j; t < j + n; t++)
			{
				sum += arr[t-j] * arr1[t];
			}
			ans = max(sum, ans);
		}
	}
	return ans;		
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	
	
	for (int i = 0; i < t; i++)
	{
		cin >> n >> m;
		arr.assign(n, 0);
		arr1.assign(m, 0);
		for (int j = 0; j < n; j++)
			cin >> arr[j];

		for (int k = 0; k < m; k++)
			cin >> arr1[k];

		int ans = solve();

		cout << "#" << i + 1 << ' ' << ans << '\n';
	}

	return 0;
};