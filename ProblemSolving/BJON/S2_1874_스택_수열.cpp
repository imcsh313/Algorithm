#include <iostream>
#include <vector>

using namespace std;

int a[100010];
int c[100010];

int main()
{
    int b; // 전체 숫자 횟수
    cin >> b;

    for (int i = 0; i < b; i++)
    {
        cin >> c[i];
        a[i + 1] = 0;
    }

    int last = 0;
    vector<char> v;
    for (int i = 0; i < b; i++)
    {
        int now = c[i];

        if (last < now)
        {
            for (int k = last + 1; k <= now; k++)
            {
                switch (a[k])
                {
                case 0:
                    a[k] = 1;
                    v.push_back('+');
                    break;
                case 2:
                    break;
                default:
                    cout << "NO";
                    return 0;
                }
            }

            a[now] = 2;
            v.push_back('-');
        }
        else if (last > now)
        {
            for (int k = last - 1; k > now; k--)
            {
                switch (a[k])
                {
                case 2:
                    break;
                default:
                    cout << "NO";
                    return 0;
                }
            }

            a[now] = 2;

            v.push_back('-');
        }

        last = c[i];
    }

    int d = v.size();
    for (int i = 0; i < d; i++)
    {
        cout << v[i] << '\n';
    }

    return 0;
}