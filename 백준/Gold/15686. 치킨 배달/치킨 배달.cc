#include <iostream>
#include <vector>
#include <queue>
#include <math.h>
#include <algorithm>
#include <climits>
using namespace std;
//int board[52][13];
vector<pair<int, int>>chicken;
vector<pair<int, int>>home;
vector<pair<int, int>>choose;
int n, m;

int ans = INT_MAX;

int dis_save()
{
	int sum = 0;
	for (int i = 0; i < home.size(); i++)
	{
		int hy = home[i].first;
		int hx = home[i].second;
		int mn = INT_MAX;
		for (int j = 0; j < choose.size(); j++)
		{
			int cy = choose[j].first;
			int cx = choose[j].second;
			int dir = abs(hy - cy) + abs(hx - cx);
			mn = min(mn, dir);
		}
		sum += mn;
	}
	return sum;
}

void solve(int idx,int cnt)
{
	if (cnt == m)
	{
		ans = min(ans,dis_save());
		return;
	}
	if (idx == chicken.size())
		return;

	choose.push_back(chicken[idx]);
	solve(idx + 1, cnt + 1);
	choose.pop_back();

	solve(idx + 1, cnt);
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int val;
			cin >> val;
			if (val == 2)
				chicken.push_back({ i+1,j+1 });
			else if (val == 1)
				home.push_back({ i+1,j+1 });
		}
	}
	solve(0, 0);
	cout << ans << '\n';
		
	return 0;
}