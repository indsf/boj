#include <iostream>
using namespace std;

void solve(int n)
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

    int n;
    cin >> n;
    solve(n);
    return 0;
}