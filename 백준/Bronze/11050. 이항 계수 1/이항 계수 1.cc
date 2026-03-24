#include<iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n,k;
    cin >> n >> k;
    int sum = 1;
    int mod = 1;
    for(int i = 0;i<k;i++)
    {
        sum *= n;
        mod *= i+1;
        n--;
    }
    cout << sum / mod << '\n';

    return 0;

}