#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer;

    int sequenceSize = sequence.size();

    int start = sequenceSize - 1;
    int startValue = sequence[start];
    int end = sequenceSize - 1;
    int endValue = sequence[end];
    //int sum = startValue;
    int sum = 0;

    for (int i = sequenceSize - 1; i >= 0; i--)
    {
        start = i;
        startValue = sequence[start];
        sum += startValue;

        if (sum == k)
        {
            cout << "wow";
            if (startValue != endValue)
            {
                answer.push_back(start);
                answer.push_back(end);
                return answer;
            }

            int flag = sequence[i];
            for (int k = 1; k <= i; k++)
            {
                if (sequence[i - k] == flag) continue;

                answer.push_back(start - k + 1);
                answer.push_back(end - k + 1);
                return answer;
            }
            answer.push_back(0);
            answer.push_back(end - start);
            return answer;
        }
        else if (sum < k)
        {
            continue;
        }
        else
        {
            while (true)
            {
                sum -= endValue;
                end--;
                endValue = sequence[end];

                if (sum == k)
                {
                    if (startValue != endValue)
                    {
                        answer.push_back(start);
                        answer.push_back(end);
                        return answer;
                    }

                    int flag = sequence[i];
                    for (int k = 1; k <= i; k++)
                    {
                        if (sequence[i - k] == flag) continue;

                        answer.push_back(start - k + 1);
                        answer.push_back(end - k + 1);
                        return answer;
                    }

                    answer.push_back(0);
                    answer.push_back(end - start);
                    return answer;
                }
                else if (sum < k)
                {
                    break;
                }
                else
                {
                    continue;
                }
            }
        }
    }

    return answer;
}