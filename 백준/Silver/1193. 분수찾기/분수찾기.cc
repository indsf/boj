#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int x;
	cin >> x;
	int i = 1;
	while (x > i)
	{
		x -= i;
		i++;
	}
	if (i % 2 == 0)	
		cout << x << '/' << (i+1)-x << '\n';	
	else
		cout << (i + 1) - x << '/' << x << '\n';

	return 0;
}