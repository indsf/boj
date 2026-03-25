#include<string>
#include <iostream>

using namespace std;

void    check(string s,int *r,int *l)
{   
    int even_check = 0;
    for(int i = 0;s[i] != '\0';i++)
    {
        if(s[i] == '(')
        {
            even_check++;
        }
        else if(s[i] == ')')
        {
            if(even_check)
                even_check--;
            else
                (*r)++;
        }
    }
    *l = even_check;
}

bool solution(string s)
{
    bool answer = true;

    int r = 0;
    int l = 0;
    check(s,&r,&l);
    
    if(r == 0 && l == 0)        
        return answer;
    else
        return !answer;
}