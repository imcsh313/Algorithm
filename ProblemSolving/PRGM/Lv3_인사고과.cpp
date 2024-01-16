#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

struct abc
{
    int a;
    int b;
    int c;
};

struct compare1
{
    bool operator()(abc x, abc y)
    {
        if (x.a == y.a)
        {
            return x.b > y.b;
        }

        return x.a < y.a;
    }
};

struct compare2
{
    bool operator()(abc x, abc y)
    {
        return x.c < y.c;
    }
};

priority_queue<abc, vector<abc>, compare1> pq1;
priority_queue<abc, vector<abc>, compare2> pq2;

int solution(vector<vector<int>> scores) {
    int answer = 1;

    int scoresSize = scores.size();
    for (int i = 0; i < scoresSize; i++)
    {
        int temp1 = scores[i][0];
        int temp2 = scores[i][1];
        pq1.push({ temp1, temp2, temp1 + temp2 });
    }

    int answerA = scores[0][0];
    int answerB = scores[0][1];
    int answerC = answerA + answerB;

    int bmax = -1;
    while (!pq1.empty())
    {
        abc now = pq1.top();
        pq1.pop();

        if (now.a == answerA && now.b == answerB && answerB < bmax) return -1;

        if (now.b < bmax) continue;

        bmax = now.b;
        pq2.push(now);
    }

    while (!pq2.empty())
    {
        abc now = pq2.top();
        pq2.pop();

        if (now.c == answerC) return answer;

        answer++;
    }

    return answer;
}