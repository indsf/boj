#include <vector>
#include <iostream>

using namespace std;
int visited[10] = {0};

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    answer.push_back(arr[0]);
    for(int i = 1;i<arr.size();i++)
    {
        
        int before = arr[i-1];
        if(arr[i] != before)
            answer.push_back(arr[i]);
//         if(!visited[arr[i]])
//         {
//             visited[arr[i]] = 1;
//             cout << arr[i] << '\n';
//             answer.push_back(arr[i]);
           
//         }          
    }        

    return answer;
}