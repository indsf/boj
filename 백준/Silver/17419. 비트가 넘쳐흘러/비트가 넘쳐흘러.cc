#include <iostream>
#include <string>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);


    int n;
    string s;
    cin >> n;
    cin >> s;
    int ans = 0;
    for(int i = 0;i<s.size();i++)
    {
        if(s[i] == '1')
            ans++;
    }
    cout << ans << '\n';
    
    return 0;
}
