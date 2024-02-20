#include <iostream>
#include <string>
#include <queue>

using namespace std;

struct abc
{
	string a;
	string b;
};

struct compare
{
	bool operator()(abc x, abc y)
	{
		return x.a >= y.a;
	}
};

priority_queue<abc, vector<abc>, compare> c;
abc cc[100010];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int a, b;
	cin >> a >> b;
	
	for (int i = 0; i < a; i++)
	{
		string d, e;
		cin >> d >> e;

		c.push({ d, e });
	}

	for (int i = 0; i < a; i++)
	{
		cc[i] = c.top();
		c.pop();
	}

	for (int i = 0; i < b; i++)
	{
		string d;
		cin >> d;

		int e = 0;
		int f = a - 1;
		int mid = (e + f) / 2;
		while (1)
		{
			mid = (e + f) / 2;
			if (cc[mid].a == d)
			{
				cout << cc[mid].b << '\n';
				break;
			}
			else if (cc[mid].a < d)
			{
				e = mid + 1;
				continue;
			}
			else
			{
				f = mid - 1;
				continue;
			}
		}
	}

	return 0;
}
