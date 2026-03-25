#include <string>
#include <vector>

using namespace std;

long long solution(long long n) 
{
    long long answer = 0;
    bool check = false;
    for(long long i = 1;i<=n;i++)
    {
        if(i*i == n)
        {
            answer = i+1;
            check = true;
            break;
        }
    }
    if(check)
        return answer*answer;
    else
        return -1;
}