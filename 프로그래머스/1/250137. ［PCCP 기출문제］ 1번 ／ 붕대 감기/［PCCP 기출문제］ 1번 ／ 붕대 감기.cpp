#include <string>
#include <vector>

using namespace std;

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) 
{
    int answer = 0;

    
    int worrier = health;
    
    int last_attack = attacks[attacks.size()-1][0];
    
    int time_m = bandage[0];
    int eat_m = bandage[1];
    int bonus_m = bandage[2];
    
    int cur_idx = 0;
    int combo_atk = 0;

    for(int i = 1;i<=last_attack;i++)
    {
        if(i == attacks[cur_idx][0])
        {
            worrier -= attacks[cur_idx][1];
            combo_atk = 0;
            if(worrier <= 0)
            {
                answer = -1;
                return answer;
            }
            cur_idx++;
        }
        else
        {
            worrier += eat_m;
            combo_atk++;
            if(combo_atk == time_m)
            {
                worrier += bonus_m;
                combo_atk = 0;
            }
            if(worrier > health)            
                worrier =  health;            
        }
    }    
    answer = worrier;
    
    return answer;
}