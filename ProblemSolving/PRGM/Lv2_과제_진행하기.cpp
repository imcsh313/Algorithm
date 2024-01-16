#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

struct plan
{
    string name;
    int start;
    int playtime;
};

struct compare
{
    bool operator()(plan a, plan b)
    {
        return a.start > b.start;
    }
};

priority_queue<plan, vector<plan>, compare> pq;

vector<string> solution(vector<vector<string>> plans) {
    vector<string> answer;

    int plansSize = plans.size();
    for (int i = 0; i < plansSize; i++)
    {
        int start = (plans[i][1][0] - '0') * 600 + (plans[i][1][1] - '0') * 60 + (plans[i][1][3] - '0') * 10 + (plans[i][1][4] - '0');

        int playtime;
        if (plans[i][2].length() == 1)
        {
            playtime = plans[i][2][0] - '0';
        }
        else if (plans[i][2].length() == 2)
        {
            playtime = (plans[i][2][0] - '0') * 10 + (plans[i][2][1] - '0');
        }
        else
        {
            playtime = 100;
        }

        pq.push({ plans[i][0], start, playtime });
    }

    int lastTime = 0;
    int nowTime = 0;
    int num = 0;
    plan stack[1010];

    while (!pq.empty())
    {
        plan nowPlan = pq.top();
        pq.pop();

        lastTime = nowTime;
        nowTime = nowPlan.start;

        int timing = nowTime - lastTime;

        for (int i = num - 1; i >= 0; i--)
        {
            int checkingPlaytime = stack[i].playtime;

            if (!checkingPlaytime) continue;
            else
            {
                if (checkingPlaytime == timing)
                {
                    stack[i].playtime = 0;
                    answer.push_back(stack[i].name);
                    break;
                }
                else if (checkingPlaytime > timing)
                {
                    stack[i].playtime -= timing;
                    break;
                }
                else
                {
                    timing -= stack[i].playtime;
                    stack[i].playtime = 0;
                    answer.push_back(stack[i].name);
                }
            }
        }

        stack[num] = nowPlan;
        num++;
    }

    for (int i = plansSize - 1; i >= 0; i--)
    {
        if (stack[i].playtime)
        {
            answer.push_back(stack[i].name);
        }
    }

    return answer;
}