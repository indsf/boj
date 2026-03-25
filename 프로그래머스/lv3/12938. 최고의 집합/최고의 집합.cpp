#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int s) 
{
    vector<int> answer;
    if(n > s)
    {
        answer.push_back(-1);
        return answer;
    }
    int cnt = n;
    for(int i = 0;i<cnt;i++)
    {   
        answer.push_back({s/n});
        s -= s/n;
        n--;
    }
    
    return answer;
}