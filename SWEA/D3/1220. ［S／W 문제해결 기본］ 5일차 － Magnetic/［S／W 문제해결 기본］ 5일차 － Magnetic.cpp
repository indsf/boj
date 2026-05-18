#include <iostream>
#include <vector>
using namespace std;

int solve(vector<vector<int>>&arr)
{
    int ans = 0;
    for(int i = 0;i<arr.size();i++)
    {
        vector<int>tmp(arr.size(),0);
        
        for(int j = 0;j<arr[i].size();j++)
        {
            tmp[j] = arr[j][i];
        }
        

        bool check = false;
        for(int k = 0;k<tmp.size();k++)
        {
            if(tmp[k] == 1 && !check)
            {
                check = true;
            }

            if(check && tmp[k] == 2)
            {
                ans++;
                check = false;
            }
                
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
        int num;
        cin >> num;
        vector<vector<int>>arr(num,vector<int>(num,0));
        for(int y = 0;y<num;y++)
        {
            for(int x = 0;x<num;x++)
                cin >> arr[y][x];
        }
        int ans = solve(arr);
        cout << "#" << i+1 << ' ' << ans << '\n';
    }

    return 0;
}