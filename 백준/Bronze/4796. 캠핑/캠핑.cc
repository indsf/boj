#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);


    int l,p,v;
    int ans = 0;
    int cnt = 1;
    while(true)
    {
        cin >> l >> p >> v;
        if(l == 0 && p == 0 && v == 0)
            break;
        ans = ((v / p) * l);
        int div = + (v%p);
        if(l < div)
          ans += l;
        else
          ans += div;
        cout << "Case " << cnt << ": " << ans << '\n';
        cnt++;
    }
    
    return 0;
}