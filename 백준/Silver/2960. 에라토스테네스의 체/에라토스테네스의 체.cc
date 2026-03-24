#include <iostream>
using namespace std;

int a[1001] = {0};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n,k;
    cin >> n >> k;
    int cnt = 0;
    bool check = false;
    int ans = 0;
    for(int i = 2;i<=n;i++)
    {
        for(int j = i;j<=n;j+=i)
        {
            if(!a[j])
                a[j] = 1;
            else
                continue;
            cnt++;
            if(cnt == k)
            {
                check = true;
                ans = j;
                break;
            }                
        }
        if(check)
            break;
    }
    cout << ans << '\n';

    return 0;
}