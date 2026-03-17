#include <iostream>
using namespace std;

int n;

void solve()
{
    for(int i = 2;i*i<=n;i++)
    {
        while(n%i == 0)
        {            
            cout << i << '\n';
            n /= i;    
        }        
    }
    if(n != 1)
        cout << n << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;

    solve();


    return 0;
}