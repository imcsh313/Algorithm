#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

struct abc
{
    int a;
    int b;
};

struct compare
{
    bool operator()(abc a, abc b)
    {
        if (a.b == b.b)
        {
            return a.a > b.a;
        }

        return a.b > b.b;
    }
};

priority_queue<abc, vector<abc>, compare> pq;

int solution(vector<vector<int>> targets) {
    int answer = 0;

    int targetsSize = targets.size();
    for (int i = 0; i < targetsSize; i++)
    {
        pq.push({ targets[i][0], targets[i][1] });
    }

    int endtime = -1;
    for (int i = 0; i < targetsSize; i++)
    {
        abc x = pq.top();
        pq.pop();

        if (x.a < endtime) continue;

        answer++;
        endtime = x.b;
    }

    return answer;
}