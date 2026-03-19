#include <string>
#include <vector>
using namespace std;

int gcd(int a,int b)
{
    if(b == 0)    
        return a;
    return gcd(b,a%b);
}

int lcm(int a,int b)
{
    return a / gcd(a,b) * b;
}

int solution(vector<vector<int>> signals) 
{
    int n = signals.size();
    //vector<int>sig_cur(n,0);

    int max_t = 1;
    for(int i = 0;i<n;i++)
    {
        int g = signals[i][0];
        int y = signals[i][1];
        int r = signals[i][2];
        int c = g+y+r;
        max_t = lcm(max_t,c);        
    }
    
    for(int t = 1;t<=max_t;t++)
    {
        bool check = true;  
        for(int i = 0;i<n;i++)
        {   
            int g = signals[i][0];
            int y = signals[i][1];
            int r = signals[i][2];        
            int c = g + y + r;

            int pos = (t-1) % c;
            if(!(g <= pos && pos < g + y))
            {
                check = false;
                break;
            }
        }
        if(check)        
            return t;
    }
    //cout << t << '\n';
    return -1;
}