#include <iostream>
using namespace std;
int n,m;
int dance,dir;
int ans = 0;
const int sosu = 1000000007;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;

    /*
    댄스타임에서는 최대 한 번까지 올바르지 않은 춤을 추더라도
    해당 라운드를 통과할 수 있다

    우진이 앞을 보고 춤을 추면 호영이는 우진과 같은 춤을 춰야 한다.
    우진이 뒤를 보고 춤을 추면 호영이는 우진과 다른 춤을 춰야 한다.

    4(라운드 개수) 4(춤 종류)  
    1(춤 종류) 0 (앞) 1
    3(춤 종류) 1 (뒤) 3
    2(춤 종류) 0 (앞) 2
    4(춤 종류) 1 (뒤) 3

    현재 시점에서 좋은 결과 
    안좋은 결과

    good = 1;
    bad = m-1
    d[0] = god * 1;(좋은결과)
    d[1] = d[0]*bad + d[1] * good (현재 한번틀려도 되는 경우에수 1번 틀렸어서 안되는 경우의 수 )

    */
    
    int good,bad;    
    long long zero = 1;
    long long one = 0;
    for(int i = 0;i<n;i++)
    {
        cin >> dance >> dir;
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
        long long dp0 = (zero * good) % sosu;
        long long dp1 = (zero * bad + one * good) % sosu;
        zero = dp0;
        one = dp1;
    }    
    cout << (zero + one) % sosu << '\n';

    return 0;
}