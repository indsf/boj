#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
vector<int>sosus;
int sum = 0;

void check()
{
    for(int i = 2;i<=sum;i++)
    {
        bool check = true;
        for(int j = 2;j*j<=i;j++)
        {
            if(i % j == 0)
                check = false;
        }
        if(check)
            sosus.push_back(i);
    }
}


int solution(vector<int> nums) 
{    
    
    int answer = 0;
    sort(nums.begin(),nums.end());
    
    for(int i = nums.size()-3;i<nums.size();i++)    
        sum += nums[i];
    
    check();
    for(int i = 0;i<nums.size();i++)
    {
        for(int j = i+1;j<nums.size();j++)
        {
            for(int k = j+1;k<nums.size();k++)
            {
                int total = nums[i] + nums[j] + nums[k];
                   
                if(find(sosus.begin(),sosus.end(),total) != sosus.end())
                    answer++;
            }
        }
    }

    return answer;
}