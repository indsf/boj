#include <string>
#include <vector>
#include <sstream>
#include <queue>
#include <iostream>
using namespace std;
int dy[4] = {0,1,-1,0};
int dx[4] = {1,0,0,-1};

queue<pair<int,int>>pos;

void solve(vector<vector<string>>&p,int dir,int st)
{
    int y = pos.front().first;
    int x = pos.front().second;
    int vy = y;
    int vx = x;
    for(int i = 0;i<st;i++)
    {
        vy+=dy[dir];
        vx+=dx[dir];
        if(vy < 0 || vy >= p.size() || vx < 0 || vx >= p[0].size() || p[vy][vx] == "X")
        {
            vy = y;
            vx = x;
            return ;
        }            
    }
    pos.pop();
    pos.push({vy,vx});    
}

vector<int> solution(vector<string> park, vector<string> routes) {
    vector<int> answer;
    vector<vector<string>>p(park.size(),vector<string>(park[0].size(),""));
    //vector<pair<int,int>>pos;
    for(int i = 0;i<park.size();i++)
    {
        string s = park[i];
        for(int j = 0;j<s.size();j++)
        {
            if(s[j] == 'S')
            {
                pos.push({i,j});
                p[i][j] = s[j];
            }
            p[i][j] = s[j];            
        }
    }
        
    for(string cmd : routes)
    {
        stringstream ss(cmd);
        char op;
        int dir = 0;
        int st;
        ss >> op >> st;
        if(op == 'E')
            dir = 0;
        if(op == 'W')
            dir = 3;
        if(op == 'S')
            dir = 1;
        if(op == 'N')
            dir = 2;
        solve(p,dir,st);
    }        
    
    int y = pos.front().first;
    int x = pos.front().second;
    pos.pop();
    return {y,x};
}