#include <string>
#include <vector>

using namespace std;

struct video
{
    int video_len;
    int pos;
    int start;
    int end;    
};

int time_convert(string time)
{
    int h = stoi(time.substr(0,2));
    int m = stoi(time.substr(3,2));
    return h*60 + m;    
}

string time_ans(int time)
{
    int h = time / 60;
    int m = time % 60;
    //cout << h << ' ' << m << '\n';
    string hh = (h < 10 ? "0" : "") + to_string(h);
    string mm = (m < 10 ? "0" : "") + to_string(m);
    return hh+":"+mm;    
}
void skip_open(int start,int end, int *cur)
{
    if (start <= *cur && *cur <= end)
        *cur = end;
}

void command_exec(int video_time,int start,int end,int *cur,string cmd)
{
    if(cmd == "prev")
    {
        (*cur) -= 10;
        if((*cur) < 0)
            (*cur) = 0;
    }
    else if(cmd == "next")
    {
        (*cur) += 10;
        if((*cur) > video_time)        
            (*cur) = video_time;    
    }
    if(start <= (*cur) && (*cur) <= end)
            (*cur) = end;
}

string solution(string video_len, string pos, string op_start, string op_end, vector<string> commands) {
    string answer = "";
    
    video Video_state;
    
    Video_state.video_len = time_convert(video_len);
    Video_state.pos = time_convert(pos);
    Video_state.start = time_convert(op_start);
    Video_state.end = time_convert(op_end);
    
    skip_open(Video_state.start,
              Video_state.end,
              &Video_state.pos);
    for(int i = 0;i<commands.size();i++)
    {
   
        command_exec(Video_state.video_len,
                      Video_state.start,
                      Video_state.end,
                      &Video_state.pos,
                      commands[i]);      
        
    }      
    answer = time_ans(Video_state.pos);
    return answer;
}
    