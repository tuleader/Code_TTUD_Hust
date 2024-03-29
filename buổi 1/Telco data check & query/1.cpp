#include <bits/stdc++.h>
#include <sstream>
using namespace std;

bool checkNumber(string phoneNumber)
{
    if (phoneNumber.length() != 10)
        return false;
    for (auto &c : phoneNumber)
    {
        if(c>'9' || c<'0') return false;
    }
    return true;
}

int countTime(std::string startTime, std::string endTime) {
    int h1, m1, s1, h2, m2, s2;

    std::istringstream startStream(startTime);
    startStream >> h1;
    startStream.ignore();
    startStream >> m1;
    startStream.ignore();
    startStream >> s1;

    std::istringstream endStream(endTime);
    endStream >> h2;
    endStream.ignore();
    endStream >> m2;
    endStream.ignore();
    endStream >> s2;

    return (h2 - h1) * 3600 + (m2 - m1) * 60 + s2 - s1;
}

void readLog(unordered_map<string,pair<int,int>>& dataset, int& totalCall, int& incorrectNumber)
{
    string log, fromNumber, toNumber, date, fromTime, toTime;
    int callTime;

    while (true){
        cin >> log;
        if(log == "#") break;
        totalCall += 1;
        cin >> fromNumber >> toNumber >> date >> fromTime >> toTime;

        if(!checkNumber(fromNumber)) incorrectNumber += 1;

        callTime = countTime(fromTime,toTime);

        if(dataset.count(fromNumber)>0){
            dataset[fromNumber].first +=1;
            dataset[fromNumber].second += callTime;
        }
        else{
            dataset[fromNumber] = make_pair(1,callTime);
        }
    }
}

void processQueries(unordered_map<string,pair<int,int>>& dataset, int& totalCall, int& incorrectNumber)
{
    string log,fromNumber;

    while (true)
    {
        cin >> log;
        if(log == "#") break;
        if (log == "?number_total_calls"){
            cout << totalCall << endl;
        }
        else if(log == "?number_calls_from")
        {
            cin >> fromNumber;
            cout << dataset[fromNumber].first << endl;
        } else if (log == "?count_time_calls_from")
        {
            cin >> fromNumber;
            cout << dataset[fromNumber].second <<endl;
        }
        else{
            if(incorrectNumber != 0) cout << 0 << endl;
            else cout << 1 << endl;
        }
    }
}
int main()
{
    unordered_map<string,pair<int,int>> dataset;
    int totalCall = 0, incorrectNumber = 0;

    readLog(dataset,totalCall,incorrectNumber);
    processQueries(dataset,totalCall,incorrectNumber);

    return 0;
}