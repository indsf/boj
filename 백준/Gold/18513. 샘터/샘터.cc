#include <iostream>
#include <set>
#include <queue>
using namespace std;
int dx[2] = {-1,1};
int n,k;
long long result;
queue<int>q;
set<int>visit;

long long bfs()
{
    int no_angry = 1;
    while(!q.empty())
    {
        int size = q.size();
        for(int j = 0;j<size;j++)
        {
            int x = q.front();
            q.pop();
            for(int i = 0;i<2;i++)
            {
                int vx = x + dx[i];
                if(visit.count(vx))
                    continue;
                q.push(vx);
                visit.insert(vx);
                result += no_angry;
                if(!--k)
                    return result;
            }
        }
        no_angry++;
    }
    return result;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> k;

    for(int i = 0;i<n;i++)
    {
        int num;

        cin >> num;
        q.push(num);        
        visit.insert(num);
    }
    long long ans = bfs();
    cout << ans << '\n';
    return 0;
}

