#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(int k, int m, vector<int> score) 
{
    int answer = 0;
    int max_score = k;
    sort(score.begin(),score.end());
    
    
   for(int i = score.size();i>=m;i-=m)
   {
       answer += score[i-m] * m;
   }
    return answer;
}