#include <iostream>
#include <string>
using namespace std;

int solve(string &s)
{
    
    for(int i = 0;i<s.size()/2;i++)
    {
        
        if(s[i] != s[s.size()-1-i])
            return 0;
    }

    return 1;
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    for(int i = 0;i<t;i++)
    {
        string s;
        cin >> s;
        int ans = solve(s);
        cout << "#" << i+1 << ' ' << ans << '\n';
    }
    return 0;
}
