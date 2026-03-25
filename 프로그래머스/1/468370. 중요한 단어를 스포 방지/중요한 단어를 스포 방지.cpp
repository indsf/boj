#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int solution(string message, vector<vector<int>> spoiler_ranges) 
{
   
    int cur_idx = 0;
    vector<string>spo;
    set<string>no_spo;
    stringstream ss(message);
    string word;
    while(ss >> word)
    {
        int ft = message.find(word,cur_idx);
        int lt = ft + word.size() -1;
        bool check = false;
        cur_idx = lt + 1;
        for(auto &arr : spoiler_ranges)
        {
            if(ft <= arr[1] && arr[0] <= lt)
            {
                spo.push_back(word);
                check = true;
                break;
            }                           
        }
         if(!check)
                no_spo.insert(word);                    
    }
    
    set<string>import_w;
    for(string word : spo)
    {
        if(!import_w.count(word) && !no_spo.count(word))
            import_w.insert(word);
    }
    return import_w.size();
}