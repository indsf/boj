#include <iostream>
#include <string>
#include <vector>
using namespace std;

int n;
vector<int>heart_pos(2);
vector<int>body_pos(5);
int board[1005][1005] = {0};

void input()
{
    for(int i = 0;i<n;i++)
    {
        string s;
        cin >> s;
        for(int j = 0;s[j] != 0;j++)
        {
            if(s[j] == '*')
                board[i][j] = 1;
            else
                board[i][j] = 0;
        }
    }
}
void heart_find()
{
    bool check = false;
    for(int i = 0;i<n;i++)
    {
        for(int j = 0;j<n;j++)
        {
            if(board[i][j] == 1)
            {                
                heart_pos[0] = i+1;
                heart_pos[1] = j;
                check = true;         
            }                
        }
        if(check)
            break;
    }    
}

void body_find()
{
    int l_arm = 0;
    int r_arm = 0;
    int body = 0;
    int l_leg = 0;
    int r_leg = 0;
    for(int i = 0;i<heart_pos[1];i++)
    {
        if(board[heart_pos[0]][i] == 1)
            l_arm++;        
    }
    body_pos[0] = l_arm;
    for(int i = heart_pos[1]+1;i<n;i++)
    {
        if(board[heart_pos[0]][i] == 1)
            r_arm++;        
    }
    body_pos[1] = r_arm;
    for(int i = heart_pos[0]+1;i<n;i++)
    {
        if(board[i][heart_pos[1]] == 1)
            body++;            
    }
    body_pos[2] = body;
    int st = heart_pos[0]+body+1;
    for(int i = st;i<n;i++)
    {
        if(board[i][heart_pos[1]-1] == 1)
            l_leg++;
    }
    for(int i = st;i<n;i++)
    {
        if(board[i][heart_pos[1]+1] == 1)
            r_leg++;
    }
    body_pos[3] = l_leg;
    body_pos[4] = r_leg;
    
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;

    input();
    heart_find();
    body_find();
    for(int i = 0;i<heart_pos.size();i++)
    {
        cout << heart_pos[i] + 1;
        if(i+1 != heart_pos.size())
            cout << ' ';
    }
    cout << '\n';
    for(int i = 0;i<body_pos.size();i++)
    {
        cout << body_pos[i];
        if(i+1 != body_pos.size())
            cout << ' ';
    }
    // for(int i = 0;i<n;i++)
    // {
    //     for(int j = 0;j<n;j++)
    //         cout << board[i][j] << ' ';
    //     cout << '\n';
    // }
    return 0;
}
