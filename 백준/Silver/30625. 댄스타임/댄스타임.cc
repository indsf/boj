#include <iostream>
using namespace std;

const int sosu = 1000000007;
int n,m;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int dance,dir;
    cin >> n >> m;
    long long zero = 1;
    long long one = 0;
    for(int i = 0;i<n;i++)
    {
        cin >> dance >> dir;
        int good;
        int bad;
        if(dir)
        {
            good = m-1;
            bad = 1;
        }
        else
        {
            good = 1;
            bad = m-1;
        }
        long long d0 = (good*zero)%sosu;
        long long d1 = (good * one + bad * zero) % sosu;

        zero = d0;
        one =  d1;
        
    }
    cout << (zero + one)%sosu << '\n';

    return 0;
}