#include <iostream>

using namespace std;

int N, K;
int object[110][2];
int knapsack[110][100010] = { 0, };

int main()
{
	cin >> N >> K;

	for (int i = 0; i < N; i++)
	{
		cin >> object[i][0] >> object[i][1];
	}

	int W0 = object[0][0];
	int V0 = object[0][1];

	for (int i = 0; i < W0; i++)
	{
		knapsack[0][i] = 0;
	}
	for (int i = W0; i <= K; i++)
	{
		knapsack[0][i] = V0;
	}
	for (int i = 0; i < N; i++)
	{
		knapsack[i][0] = 0;
	}

	for (int i = 1; i < N; i++)
	{
		int nowW = object[i][0];
		int nowP = object[i][1];

		for (int k = 1; k < nowW; k++)
		{
			knapsack[i][k] = knapsack[i - 1][k];
		}
		for (int k = nowW; k <= K; k++)
		{
			int temp = nowP + knapsack[i - 1][k - nowW];
			if (temp > knapsack[i - 1][k])
			{
				knapsack[i][k] = temp;
			}
			else
			{
				knapsack[i][k] = knapsack[i - 1][k];
			}
		}
	}

	cout << knapsack[N - 1][K];

	return 0;
}