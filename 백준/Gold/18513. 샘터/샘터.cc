#include <iostream>
#include <set>
#include <queue>
using namespace std;

queue<int>q;
set<int>visit;
int dx[2] = {-1,1};
int n,k;
long long ans;

long long bfs()
{
    int unluck = 1;
    while(!q.empty())
    {
        int size = q.size();
        for(int i = 0;i<size;i++)
        {
            int val = q.front();
            q.pop();
            for(int j = 0;j<2;j++)
            {
                int vx = val + dx[j];
                if(visit.count(vx))
                    continue;
                q.push(vx);
                visit.insert(vx);
                ans += unluck;
                if(!--k)
                    return ans;
            }
        }
        unluck++;
    }
    return ans;
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
    cout << bfs() << '\n';
    return 0;
}
