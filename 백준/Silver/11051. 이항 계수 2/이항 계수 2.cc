#include <iostream>
using namespace std;

int d[1002][1002] = {0};
int mod = 10007;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n,k;

    
    for(int i = 1;i<=1001;i++)
    {
        d[i][0] = 1;
        d[i][i] = 1;
        for(int j = 1;j<i;j++)
        {
            d[i][j] = (d[i-1][j-1] + d[i-1][j])%mod;
        }        
    }

    cin >> n >> k;
    cout << d[n][k] << '\n';
    return 0;
}