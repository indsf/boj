#include <iostream>
using namespace std;
int ans = 0;
void solve(int num, int num2)
{
	for (int i = num+1; i <= num2; i++)
	{
		if (i < 2)
			continue;
		bool check = true;
		for (int j = 2; j *j <= i; j++)
		{
			if (i%j == 0)
			{
				check = false;
				break;
			}
		}
		if (check)
			ans++;
	}

}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int num;
	while (true)
	{
		cin >> num;
		if (num == 0)
			break;
		solve(num, num * 2);
		cout << ans << '\n';
		ans = 0;
	}


	return 0;
}