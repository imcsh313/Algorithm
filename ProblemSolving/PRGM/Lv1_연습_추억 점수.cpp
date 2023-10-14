#include <string>
#include <vector>
#include <map>

using namespace std;

map<string, int> MAP;

vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo) {
    int a = name.size();
    for (int i = 0; i < a; i++)
    {
        string b = name[i];
        MAP[b] = yearning[i];
    }

    vector<int> answer;

    int c = photo.size();
    for (int i = 0; i < c; i++)
    {
        int temp = 0;
        int d = photo[i].size();
        for (int k = 0; k < d; k++)
        {
            temp += MAP[photo[i][k]];
        }
        answer.push_back(temp);
    }

    return answer;
}