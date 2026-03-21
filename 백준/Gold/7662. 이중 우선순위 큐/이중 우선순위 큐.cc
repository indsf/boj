#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>
#include <set>
using namespace std;
multiset<int>dq;

void cmd_exec(string s, int val)
{
	if (s == "I")
		dq.insert(val);
	else if (s == "D" && val == 1 && !dq.empty())
	{
		auto it = dq.end();
		it--;
		dq.erase(it);
	}
	else if (s == "D" && val == -1 && !dq.empty())
		dq.erase(dq.begin());
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--)
	{
		int num;
		cin >> num;
		dq.clear();
		for (int i = 0; i < num; i++)
		{
			string cmd;
			int val;
			cin >> cmd >> val;
			cmd_exec(cmd, val);
		}
		if (!dq.empty())
		{
			auto it = dq.end();
			it--;
			cout << (*it) << ' ' << (*dq.begin()) << '\n';
		}
			
		else
			cout << "EMPTY" << '\n';

	}
	return 0;
}
