#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
vector<pair<int,int>>d;
vector<int>visit;
int ans = 0;
int max_ans = 0;

void solve(vector<pair<int,int>>&d,int k,int cur)
{
    if(ans > max_ans)
        max_ans = ans;
    
    if(cur == d.size())
        return ;
    
    for(int i = 0;i<d.size();i++)
    {
        if(!visit[i] && d[i].first <= k)
        {
            visit[i] = 1;
            ans++;
            solve(d,k-d[i].second,cur+1);   
            ans--;
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
    
    return max_ans;
    
}