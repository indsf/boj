#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
vector<pair<int,int>>d;
vector<int>visit;
int ans = 0;


void solve(vector<pair<int,int>>&d,int k,int cur)
{
    ans = max(cur,ans);
    
    for(int i = 0;i<d.size();i++)
    {
        if(!visit[i] && d[i].first <= k)
        {
            visit[i] = 1;
            solve(d,k-d[i].second,cur+1);   
            visit[i] = 0;
        }
    }
}

int solution(int k, vector<vector<int>> dungeons) 
{
    for(int i = 0;i<dungeons.size();i++)
    {
        d.push_back({dungeons[i][0],dungeons[i][1]});
    }
    visit.assign(dungeons.size(),0);
    solve(d,k,0);
    
    return ans;
    
}