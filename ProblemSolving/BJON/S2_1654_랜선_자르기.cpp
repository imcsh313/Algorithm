#include <iostream>

using namespace std;

int c[10000];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int a, b;
	cin >> a >> b;

	long long sum = 0;

	for (int i = 0; i < a; i++)
	{
		cin >> c[i];
		sum += c[i];
	}

	long long longest = sum / b;

	long long top = longest + 1;
	long long btt = 0;
	long long mid = (top + btt) / 2;

	while (top >= btt)
	{
		long long num = 0;
		mid = (top + btt) / 2;

		for (int k = 0; k < a; k++)
		{
			num += c[k] / mid;
		}

		if (num < b)
		{
			top = mid - 1;
		}
		else if (num > b)
		{
			btt = mid + 1;
		}
		else
		{
			break;
		}
	}

	long long min = mid;
	long long max = min + 100;

	while (min < longest)
	{
		long long minnum = 0;
		long long maxnum = 0;

		for (int k = 0; k < a; k++)
		{
			minnum += c[k] / min;
			maxnum += c[k] / max;
		}

		if (minnum != maxnum)
		{
			break;
		}

		min += 100;
		max += 100;
	}

	if (min == 1)
	{
		cout << 1;
		return 0;
	}

	for (long long i = min - 1; i <= max; i++)
	{
		long long num = 0;

		for (int k = 0; k < a; k++)
		{
			num += c[k] / i;
		}

		if (num < b)
		{
			cout << i - 1;
			return 0;
		}
	}
  
	return 0;
}
