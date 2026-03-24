#include <iostream>

using namespace std;
int m,n,x,y;


int gcd(int a,int b)
{
    if(b != 0)    
        return gcd(b,a%b);    
    else
        return a;
}

long long lcm(int x,int y)
{
    return x / gcd(x,y) * y;
}

long long solve()
{
    if(m == x)
        x = 0;
    if(n == y)
        y = 0;
    long long max_repeat = lcm(m,n);
    //cout << max_repeat << '\n';
    for(long long i = x;i<=max_repeat;i+=m)
    {
        if(i == 0)
            continue;
        if((i%n == y))
            return i;
    }
    return -1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    /*
     x < M 이면 x' = x + 1
     y < N이면 y' = y + 1
    */
    for(int i =0;i<t;i++)
    {
        cin >> m >> n >> x >> y;
        cout << solve() << '\n';
    }
    return 0;
}