#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> park, vector<string> routes) {
    vector<int> answer;

    int h = park.size();
    int w = park[0].length();

    bool MAP[60][60];
    int nowH, nowW;
    for (int i = 0; i < h; i++)
    {
        for (int k = 0; k < w; k++)
        {
            char nowPos = park[i][k];
            if (nowPos == 'X')
            {
                MAP[i][k] = 0;
                continue;
            }
            else
            {
                MAP[i][k] = 1;
            }

            if (nowPos == 'S')
            {
                nowH = i;
                nowW = k;
            }
        }
    }

    int routesSize = routes.size();
    for (int i = 0; i < routesSize; i++)
    {
        char op = routes[i][0];
        int n = routes[i][2] - '0';

        int sign = 1;
        if (op == 'N' || op == 'W') sign = -1;

        if (op == 'N' || op == 'S')
        {
            int newH = nowH + n * sign;
            if (newH < 0 || newH >= h) continue;

            bool flag = 0;
            for (int k = 1; k <= n; k++)
            {
                if (!MAP[nowH + k * sign][nowW])
                {
                    flag = 1;
                    break;
                }
            }
            if (flag) continue;

            nowH = newH;
        }
        else
        {
            int newW = nowW + n * sign;
            if (newW < 0 || newW >= w) continue;

            bool flag = 0;
            for (int k = 1; k <= n; k++)
            {
                if (!MAP[nowH][nowW + k * sign])
                {
                    flag = 1;
                    break;
                }
            }
            if (flag) continue;

            nowW = newW;
        }
    }

    answer.push_back(nowH);
    answer.push_back(nowW);

    return answer;
}