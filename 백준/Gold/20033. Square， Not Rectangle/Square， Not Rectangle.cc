#include <iostream>
using namespace std;

int sqr[300001] = {0};
int n;

void input()
{
    cin >> n;
    for(int i = 0;i<n;i++)
        cin >> sqr[i];
}

bool check(int mid)
{
    int len = 0;
    for(int i = 0;i<n;i++)
    {
        if(sqr[i] >= mid)
        {
            len++;
            if(len >= mid)
                return true;            
        }
        else        
            len = 0;        
    }
    return false;
}

void even_find()
{    
    long long ans = 1;
    int al = 1;
    int ar = n;
    while(al <= ar)
    {
        int mid = (al+ar) / 2; //3        
        if(check(mid))
        {
            ans = mid;
            al = mid+1;
        }
        else
            ar = mid-1;                        
    }
    cout << ans << '\n';
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    input();
    even_find();
    return 0;
}
