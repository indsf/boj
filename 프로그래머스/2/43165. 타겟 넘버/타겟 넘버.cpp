#include <string>
#include <vector>

using namespace std;

int ans;

void dfs(vector<int>&n,int cur,int target,int val)
{
    if(cur == n.size())
    {
        if(target == val)        
            ans++;                    
        return ;
    }
    
        
    dfs(n,cur+1,target,val+n[cur]);
    dfs(n,cur+1,target,val-n[cur]);
        
        
 
}

int solution(vector<int> numbers, int target) {
    //int answer = 0;
    dfs(numbers,0,target,0);
    return ans;
}