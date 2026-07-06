#include <iostream>
#include <vector>

using namespace std;
int n;
vector <vector<int>>board;
vector <vector<int>>board_90;
vector <vector<int>>board_18;
vector <vector<int>>board_27;

vector <vector<int>> solve(vector <vector<int>>&board)
{
	vector <vector<int>>tmp(n, vector<int>(n, 0));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j< n; j++)
			tmp[i][j] = board[n-j-1][i];
	}
	return tmp;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);


	int t;
	cin >> t;

	for (int i = 0; i < t; i++)
	{
		cin >> n;
		board.assign(n, vector<int>(n, 0));
		board_90.assign(n, vector<int>(n, 0));
		board_18.assign(n, vector<int>(n, 0));
		board_27.assign(n, vector<int>(n, 0));
		for (int y = 0; y < n; y++)
		{
			for (int x = 0; x < n; x++)
			{
				cin >> board[y][x];
			}
		}
		cout << "#" <<  i + 1 << '\n';
		board_90 = solve(board);
		board_18 = solve(board_90);
		board_27 = solve(board_18);

		for (int k = 0; k < n; k++)
		{
			for (int e = 0; e < n; e++)
				cout << board_90[k][e];
			cout << ' ';

			for (int l = 0; l < n; l++)
				cout << board_18[k][l];
			cout << ' ';

			for (int r = 0; r < n; r++)
				cout << board_27[k][r];
			cout << '\n';
		}
	}
}