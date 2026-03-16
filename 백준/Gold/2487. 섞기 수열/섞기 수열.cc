#include <iostream>
using namespace std;

int a[20001] = {0};
int visited[20001] = {0};
int n;

void input()
{
    cin >> n;
    for(int i = 1;i<=n;i++)
        cin >> a[i];
}

int gcd(int x,int y)
{
    if(y != 0)    
        return gcd(y,x%y);    
    else
        return x;
}

long long lcm(long long x, long long y)
{
	return x / gcd(x, y)*y;
}

int repeat_cnt(int n,int cnt)
{
    
    if(visited[n])
        return cnt;
    else
    {
        visited[n] = 1;
        return repeat_cnt(a[n],cnt+1);
    }
}

void solve()
{
    int res = 1;
    for(int i = 1;i<n+1;i++)
    {
        if(visited[i])
            continue;
        else        
            res = lcm(res,repeat_cnt(i,0));        
    }
    cout << res << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    input();
    solve();

    return 0;
}
