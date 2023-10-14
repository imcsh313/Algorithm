#include <string>
#include <vector>
#include <map>

using namespace std;

map<string, int> MAP;

vector<string> solution(vector<string> players, vector<string> callings) {
    int a = players.size();
    for (int i = 0; i < a; i++)
    {
        string b = players[i];
        MAP[b] = i;
    }

    int c = callings.size();
    for (int i = 0; i < c; i++)
    {
        string d = callings[i];
        int e = MAP[d];
        string f = players[e - 1];

        players[e - 1] = d;
        players[e] = f;
        MAP[d]--;
        MAP[f]++;
    }

    return players;
    //vector<string> answer;
    //return answer;
}

/* 2차 시도 - 오답
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <queue>

using namespace std;

map<string, int> rank1;

struct cmp
{
    bool operator()(string x, string y)
    {
        return rank1[x] < rank1[y];
        //return x.length() < y.length();
    }
};

vector<string> solution(vector<string> players, vector<string> callings) {
    //map<string, int> rank;

    int b = players.size();
    for(int i = 0; i < b; i++)
    {
        string c = players[i];
        //cout << c;
        rank1[c] = b - i;
    }

    int a = callings.size();
    for(int i = 0; i < a; i++)
    {
        string d = callings[i];
        rank1[d]++;
    }

    priority_queue<string, vector<string>, cmp> answerQueue;
    for(int i = 0; i < b; i++)
    {
        answerQueue.push(players[i]);
    }

    vector<string> answer;
    for(int i = 0; i < b; i++)
    {
        string e = answerQueue.top();
        answerQueue.pop();

        answer.push_back(e);
    }
    return answer;
}
*/

/* 1차 시도 - 시간 초과
#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    int a = callings.size();
    //cout << a;
    int c = players.size();

    for (int i = 0; i < a; i++)
    {
        string b = callings[i];
        for (int k = 0; k < c; k++)
        {
            if (players[k] != b) continue;
            //cout << b << endl;

            string d = players[k - 1];
            players[k - 1] = b;
            players[k] = d;

            break;
        }
    }

    //vector<string> answer;
    return players;
}
*/