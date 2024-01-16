#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> wallpaper) {
    vector<int> answer;

    int wallpaperSize = wallpaper.size();
    int wallpaperLength = wallpaper[0].length();

    int lux = 100;
    int luy = 100;
    int rdx = -1;
    int rdy = -1;

    for (int i = 0; i < wallpaperSize; i++)
    {
        for (int k = 0; k < wallpaperLength; k++)
        {
            if (wallpaper[i][k] == '.') continue;

            if (i < lux) lux = i;
            if (k < luy) luy = k;

            if (i > rdx) rdx = i;
            if (k > rdy) rdy = k;
        }
    }

    rdx++;
    rdy++;

    answer.push_back(lux);
    answer.push_back(luy);
    answer.push_back(rdx);
    answer.push_back(rdy);

    return answer;
}