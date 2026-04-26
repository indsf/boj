#include <string>
#include <vector>

using namespace std;

//int visit[22];

int dfs(int cur,int val,int target,vector<int>&numbers)
{
    if(cur == numbers.size())
    {
        if(val == target)
        {
            val = 1;
            return val;
        }
            
        else 
        {
            val = 0;
            return val;
        }            
    }
        
    
    return dfs(cur+1,val+numbers[cur],target,numbers) + dfs(cur+1,val-numbers[cur],target,numbers);
            

}

int solution(vector<int> numbers, int target) 
{
    int answer = 0;
    answer = dfs(0,0,target,numbers);
    return answer;
}