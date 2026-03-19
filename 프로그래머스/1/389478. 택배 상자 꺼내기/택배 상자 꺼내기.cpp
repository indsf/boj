#include <string>
#include <vector>
#include <iostream>
using namespace std;

int answer_check(int row,int w,int n,int num,vector<vector<int>>&box)
{
    int ans = 0;
    int f_row = -1;
    int f_col = -1;
    for(int i = 0;i<row;i++)
    {
        for(int j = 0;j<w;j++)
        {
            if(box[i][j] == num)
            {
                f_row = i;
                f_col = j;
            }
        }
        if(f_row != -1)
            break;
    }
    for(int i = f_row;i<row;i++)
    {
        if(box[i][f_col] != 0)
            ans++;
    }
    return ans;
}

int solution(int n, int w, int num) 
{
    int answer = 0;
    int boxN = 1;
    int row = n / w;
    if(n%w != 0)
        row += 1;
    vector<vector<int>>box(row,vector<int>(w,0));
    bool check = true; 
    int sum = 0;
    for(int y = 0;y<row;y++)
    {
        if(check)
        {
            for(int x = 0;x<w;x++)
            {                
                if(boxN > n)
                    break;
                box[y][x] = boxN++;
                if(x+1 == w)
                    check = false;
            }  
        }
        else
        {
            for(int x = w-1;x>=0;x--)
            {                
                if(boxN > n)
                    break;
                box[y][x] = boxN++;
                if(x == 0)
                    check = true;
            }  
        }
        
    }
    answer = answer_check(row,w,n,num,box);
    return answer;
}
