#include <iostream>
#include <string>
#include <vector>

using namespace std;

long long a[500010];
long long b[500010];
long long c[500010];

long long solution(vector<int> sequence) {
    long long answer = 0;

    int sequenceSize = sequence.size();
    for (int i = 0; i < sequenceSize; i++)
    {
        long long pm = 1;
        if (i % 2) pm = -1;

        a[i] = (long long)sequence[i] * pm;
    }

    b[0] = a[0];
    long long bmin = b[0];
    long long bmax = b[0];
    long long bnow;
    for (int i = 1; i < sequenceSize; i++)
    {
        bnow = b[i - 1] + a[i];
        b[i] = bnow;

        if (bnow < bmin) bmin = bnow;
        if (bnow > bmax) bmax = bnow;
    }

    c[sequenceSize - 1] = a[sequenceSize - 1];
    long long cmin = c[sequenceSize - 1];
    long long cmax = c[sequenceSize - 1];
    long long cnow;
    for (int i = sequenceSize - 2; i >= 0; i--)
    {
        cnow = c[i + 1] + a[i];
        c[i] = cnow;

        if (cnow < cmin) cmin = cnow;
        if (cnow > cmax) cmax = cnow;
    }

    long long totalsum = b[sequenceSize - 1];
    long long maxsum = bmax + cmax - totalsum;
    long long minsum = bmin + cmin - totalsum;

    if (maxsum < 0) maxsum *= -1;
    if (minsum < 0) minsum *= -1;

    if (maxsum > minsum) answer = maxsum;
    else answer = minsum;

    return answer;
}