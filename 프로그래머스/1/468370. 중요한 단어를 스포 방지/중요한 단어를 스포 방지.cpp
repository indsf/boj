#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int solution(string message, vector<vector<int>> spoiler_ranges) 
{
    stringstream ss(message);
    string word;
    vector<string>spo;
    set<string>no_spo;
    int cur_idx = 0;
    while(ss >> word)
    {
        int ft = message.find(word,cur_idx);
        int lt = ft + word.size() - 1;
        bool check = true;
        cur_idx = lt + 1;
        for(auto &spo_r : spoiler_ranges)
        {
            if(ft <= spo_r[1] && spo_r[0] <= lt)
            {
                spo.push_back(word);
                check = false;
                break;
            }                            
        }
        if(check)
            no_spo.insert(word);
    }
    
    set<string>import_word;
    for(string str : spo)
    {
        if(!import_word.count(str) && !no_spo.count(str))
            import_word.insert(str);
    }
    
    return import_word.size();
}