#include <string>
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

long long solution(int k, int d) 
{
    long long answer = 0;
    long long dd = 1LL * d * d;
    for(long long x = 0;x<=d;x+=k)
    {
        long long maxY = sqrt(dd - (x*x));    
        answer += maxY / (long long)k+1;        
            
    }
    return answer;
}