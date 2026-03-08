#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<vector<int>> jobs = {{1,2,100},{2,1,19},{3,2,27},{4,1,25},{5,1,15}};
    int n = jobs.size();
    int maxSlots = 0;
    for(auto job : jobs){
        maxSlots = max(maxSlots, job[1]);
    }

    priority_queue<vector<int>,vector<vector<int>>> pq;

    for(auto job : jobs){
        pq.push({job[2],job[1]});
    }
    
    vector<int> slots(maxSlots+1,0);
    int job_count = 0;
    int total_profit = 0;
    while(!pq.empty()){
        auto job = pq.top();
        pq.pop();

        for(int i = job[1]-1;i>=0;i--){
            if(slots[i] == 0){
                slots[i] = job[0];
                job_count++;
                total_profit += job[0];
                break;
            }
        }
    }

    cout<<"Maximum number of Jobs: "<<job_count<< endl;
    cout<<"Total Max Profit: "<<total_profit<<endl;

    return 0;
}