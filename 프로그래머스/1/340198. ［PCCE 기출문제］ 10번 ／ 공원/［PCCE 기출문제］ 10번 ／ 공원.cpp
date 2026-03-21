#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int n,m;

bool  check(int y,int x,int size,vector<vector<string>>&cpmat)
{
    bool check = true;
    if(y+size>n || x+size>m)
        return false;
    for(int i = y;i< y+size;i++)
    {
        for(int j = x;j<x+size;j++)
        {
             if(cpmat[i][j] != "-1")
                return false;
        }
           
    }
    if(check)
        return true;
}


int solution(vector<int> mats, vector<vector<string>> park) 
{
    //int answer = 0;
    n = park.size();
    m = park[0].size();
    sort(mats.begin(),mats.end(),greater<int>());
    for(int size : mats)
    {
         if(size > n || size > m)
            continue;
        for(int i = 0;i<=(n-size);i++)
        {
           
            for(int j = 0;j<=(m-size);j++)
            {
                if(check(i,j,size,park))
                    return size;
            }
        }
    }
    
    
    return -1;
}
