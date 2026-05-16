#include <iostream>
#include <vector>
#include <string>
using namespace std;

int solve(vector<vector<int>>&farm,int n)
{
    int ans = 0;
    int st = n/2;
    int lt = n/2;
    bool check = false;
    for(int i = 0;i<n;i++)
    {
        for(int j = st;j<=lt;j++)
            ans += farm[i][j];
    
        if(!check)
        {
            st--;
            lt++;
            if(st == 0 && lt == n-1)
                check = true;
        }
        else
        {
            st++;
            lt--;
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
    for(int i = 0;i<t;i++)
    {
        int n;
        cin >> n;
        vector<vector<int>>farm(n,vector<int>(n,0));
        for(int y = 0;y<n;y++)
        {   
            string s;
            cin >> s;
            for(int x = 0;x<s.size();x++)
            {
                int a = s[x] - '0';
                farm[y][x] = a;
            }
                
        }
        int answer = solve(farm,n);
        cout << "#" << i+1 << ' ' << answer << '\n';
    }

    return 0;
}