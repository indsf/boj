#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int n;
int  main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	
	int ans = 0;
	for (int i = 5; i <= n; i*=5)
	{
		ans += (n / i);
	}
	cout << ans << '\n';

	return 0;
}