#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
// #include<math.h>

using namespace std;

class Logger{
public:
    Logger(int TimeStamp, string message){
        this->time = TimeStamp;
        this->msg = message;
    }
    int time;
    string msg;
};


vector<string> verifyMessages(vector<Logger> logger){
    unordered_map<string, int> mp;
    vector<string> res;
    for (int i = 0; i < logger.size(); i++){
        if (mp.find(logger[i].msg) != mp.end()){
            if (abs(mp[logger[i].msg] - logger[i].time) >= 10){
                mp[logger[i].msg] = logger[i].time;
                res.push_back("true");
            }
            else res.push_back("false");
        }
        else{
            res.push_back("true");
            mp[logger[i].msg] = logger[i].time;
        }
    }
    return res;
}

int main(){
    vector<Logger> logger;
    int n;
    cin>>n;
    for (int i = 0; i < n; i++){
        int newtime;
        string newmsg;
        cin>>newtime;
        cin>>newmsg;
        logger.emplace_back(newtime, newmsg);
    }

    vector<string> res;
    res = verifyMessages(logger);
    for (int i = 0; i < n; i++){
        cout<<res[i]<<"\t";
    }
    return 0;
}