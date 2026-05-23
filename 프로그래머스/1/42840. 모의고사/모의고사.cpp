#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
vector<int>h1 = {1, 2, 3, 4, 5};
vector<int>h2 = {2, 1, 2, 3, 2, 4, 2, 5};
vector<int>h3 = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<int> tmp(3,0);

    for(int i = 0;i<answers.size();i++)
    {
        if(h1[i % h1.size()] == answers[i])
            tmp[0] += 1;
        
        if(h2[i % h2.size()] == answers[i])
            tmp[1] += 1;
        if(h3[i % h3.size()] == answers[i])
            tmp[2] += 1;      
    }
    int ans = *max_element(tmp.begin(),tmp.end());    
    for(int i = 0;i<tmp.size();i++)
    {
        if(ans == tmp[i])
            answer.push_back({i+1});
    }
    
    return answer;
}