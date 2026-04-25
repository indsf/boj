#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;
bool check;
vector<string> answer;
int visit[10001];
int cnt = 0;

void dfs(int cur,vector<vector<string>>&t,string find)
{
    answer.push_back(find);
    if(cur == t.size())
    {
        check = true;
        return ;
    }
    
    for(int i = 0;i < t.size();i++)
    {
        if(find == t[i][0] && !visit[i])
        {
            
            visit[i] = 1;
            dfs(cur+1,t,t[i][1]);
            if(check)
                return;
            visit[i] = 0;
        }                
    }
    answer.pop_back();
}

vector<string> solution(vector<vector<string>> tickets) 
{
    
    cnt = tickets.size()+1;
    sort(tickets.begin(),tickets.end());
    //visit.resize(cnt,0,z);
    dfs(0,tickets,"ICN");
    return answer;
}