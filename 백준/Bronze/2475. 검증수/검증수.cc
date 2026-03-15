#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	long long  ans = 0;
	for (int i = 0; i < 5; i++)
	{
		int num;
		cin >> num;
		ans += num * num;
	}
	cout << ans % 10 << '\n';
		
}