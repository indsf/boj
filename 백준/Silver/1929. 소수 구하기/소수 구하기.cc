#include <iostream>
using namespace std;

int m,n;

void solve()
{
    for(int i = m;i<=n;i++)
    {
        if(i< 2)
            continue;
        bool check = true;
        for(int j = 2;j*j<=i;j++)
        {
            if(i%j == 0)
            {
                check = false;
                break;
            }
        }
        if (check)
        cout << i << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> m >> n;
    solve();
    return 0;
}