#include <iostream>
#include <string>
#include <vector>

using namespace std;

long long solution(int R1, int R2) {
    long long answer = 0;

    long long r1 = (long long)R1;
    long long r2 = (long long)R2;

    long long rr1 = r1 * r1;
    long long rr2 = r2 * r2;

    long long max = r2;
    long long min = r1;

    for (long long i = 0; i < r2; i++)
    {
        long long ii = i * i;

        while (true)
        {
            if ((max * max + ii) > rr2)
            {
                max--;
                continue;
            }

            break;
        }

        while (true && (min > 0))
        {
            if ((min * min + ii) >= rr1)
            {
                min--;
                continue;
            }

            break;
        }

        answer += max - min;
    }

    return answer * 4;
}