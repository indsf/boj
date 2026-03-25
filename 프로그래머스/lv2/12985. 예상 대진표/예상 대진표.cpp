#include <iostream>


using namespace std;

int solution(int n, int a, int b)
{
    int answer = 0;
    
    while(n != 0)
    {        
        int len = abs(a-b);
        
        answer++;       
        a = (a/2)+ (a%2);
        b = (b/2)+ (b%2);
        if(a==b)
            break;
        
        n /= 2;        
    }

    
    return answer;
}