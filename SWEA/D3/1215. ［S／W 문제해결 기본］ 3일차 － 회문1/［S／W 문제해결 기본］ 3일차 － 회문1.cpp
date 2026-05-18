#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solve(vector<vector<string>>&arr,int len)
{
    int ans = 0;
    for(int i = 0;i<arr.size();i++)
    {
        string tmp;
        int idx = 0;
        for(int j = 0;j<arr[i].size();j++)
            tmp += arr[i][j];        
        
        for(int k = 0;k<=tmp.size()-len;k++)
        {
            string com = tmp.substr(k,len);
            string reserve = com;
            reverse(reserve.begin(),reserve.end());     
            if(com == reserve)
                ans++;
        }

        tmp = "";
        for(int j = 0;j<arr[i].size();j++)
            tmp += arr[j][i];

        for(int k = 0;k<=tmp.size()-len;k++)
        {
            string com = tmp.substr(k,len);
            string reserve = com;
            reverse(reserve.begin(),reserve.end());     
            if(com == reserve)
                ans++;
        }
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    for(int i = 0;i<10;i++)
    {
        int len;
        cin >> len;
        vector<vector<string>>arr(8,vector<string>(8,""));
        for(int j = 0;j<8;j++)
        {
            string s;
            cin >> s;
            for(int k = 0;k<s.size();k++)
                arr[j][k] = s[k];
        }
        int ans = solve(arr,len);
        cout << "#" << i+1 << ' ' << ans << '\n';
    }

    return 0;
}