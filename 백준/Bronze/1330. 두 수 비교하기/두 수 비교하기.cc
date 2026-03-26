#include <iostream>
using namespace std;
int a, b;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> a >> b;

	if (a < b)
		cout << '<' << '\n';
	else if(a > b)
		cout << '>' << '\n';
	else
		cout << "==" << '\n';
	return 0;
}