#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <sstream>
#include <iostream>
#include <cmath>
using namespace std;

map<string,int>r_in; //차량번호 : 입차시간
map<string,int>r_tt; //차량번호 : 누적시간
    

struct bill
{
    int h;
    string num;
    int check;
};

int convert_t(string s)
{
    int h =  stoi(s.substr(0,2))*60;
    int t = stoi(s.substr(3));
    return h + t;
}

vector<int> sol(vector<int> &f,vector<bill>&t_solve)
{
    for(int i = 0;i<t_solve.size();i++)
    {
        int t = t_solve[i].h;
        string n = t_solve[i].num;
        int check = t_solve[i].check;
        
        if(check == 1)        
            r_in[n] = t;        
        else
        {
            r_tt[n] += (t - r_in[n]);
            r_in.erase(n);
        }
        
    }
    
    int end_t = convert_t("23:59");
    for(auto iter = r_in.begin();iter != r_in.end();iter++)
    {
        string s = iter->first;
        int t = iter->second;
        r_tt[s] += (end_t -t);
    }
    
    int base_t = f[0];
    int base_m = f[1];
    int sec_t = f[2];
    int sec_m = f[3];
    vector<int>ans;
    for(auto iter = r_tt.begin();iter != r_tt.end();iter++)
    {
        string c_n = iter->first;
        int t_t = iter->second;
        if(t_t <= base_t)
            ans.push_back(base_m);
        else
        {
            int tmp_c =  t_t - base_t;
            int cal = base_m + ceil((double)tmp_c/sec_t) * sec_m;
            ans.push_back(cal);
        }            
    }
    return ans;
}

vector<int> solution(vector<int> fees, vector<string> records) 
{
    struct bill b;
    vector<bill>t_record(records.size());
    for(int i = 0;i<records.size();i++)
    {
        vector<string>tmp;
        stringstream ss(records[i]);
        string wd;
        while(getline(ss,wd,' '))
            tmp.push_back(wd);
        
        t_record[i].h = convert_t(tmp[0]);
        t_record[i].num = tmp[1];
        if(tmp[2] == "IN")    
            t_record[i].check = 1;
        else
            t_record[i].check = 0;
        
    }
    
    vector<int>answer;
    answer = sol(fees,t_record);
    return answer;
}