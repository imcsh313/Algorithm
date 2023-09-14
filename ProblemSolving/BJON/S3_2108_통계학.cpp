#include <iostream>
#include <algorithm>

using namespace std;

short c[500010];
int d[10000];

int main()
{    ios_base::sync_with_stdio(false);    cin.tie(NULL);    cout.tie(NULL);
    int a;    cin >> a;
    if (a == 1)    {        int b;        cin >> b;

        for (int i = 0; i < 3; i++)
        {
            cout << b << '\n';
        }
        cout << 0;

        return 0;
    }

    int sum = 0;

    for (int i = 0; i < a; i++)
    {
        int temp;
        cin >> temp;

        sum += temp;
        c[i] = temp;

        d[temp + 5000]++;
    }

    int avg = sum / a;
    if (sum >= 0)
    {
        if (sum % a > a / 2) avg++;
        cout << avg << '\n';
    }
    else
    {
        sum *= -1;
        if (sum % a > a / 2) avg--;
        cout << avg << '\n';
    }

    sort(c, c + a);
    cout << c[a / 2] << '\n';

    int e = 0;
    int e1 = 5000;
    int e2 = 5000;
    for (int i = 900; i < 9100; i++)
    {
        if (d[i] < e) continue;

        if (d[i] == e)
        {
            if (e2 == 5000) {
                e2 = i - 5000;
            }

            continue;
        }

        if (d[i] > e)
        {
            e = d[i];
            e1 = i - 5000;
            e2 = 5000;
        }
    }
    if (e2 == 5000) cout << e1 << '\n';
    else cout << e2 << '\n';

    cout << (c[a - 1] - c[0]);

    return 0;
}