#include <iostream>

#define XXX 2134567890

using namespace std;

int N, M, B;
short MAP[510][510];
int total_block = 0; // 넣을 수 있는 최대 블록 수
int ans_time = XXX;
int ans_hight = -1;

void init();
void count_total_block();
void flattening(); // 256~0 다 확인
void ans();

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	init();
	count_total_block();
	flattening();
	ans();

	return 0;
}

void init()
{
	cin >> N >> M >> B;
	for (int i = 0; i < N; i++)
	{
		for (int k = 0; k < M; k++)
		{
			cin >> MAP[i][k];
		}
	}
	/*
	for (int i = 0; i < N; i++)
	{
		for (int k = 0; k < M; k++)
		{
			cout << MAP[i][k] << ' ';
		}
		cout << endl;
	}
	*/
	return;
}

void count_total_block()
{
	for (int i = 0; i < N; i++)
	{
		for (int k = 0; k < M; k++)
		{
			total_block += MAP[i][k];
		}
	}

	total_block += B;

	return;
}

void flattening()
{
	int NM_size = N * M;

	for (int i = 256; i >= 0; i--)
	{
		if (NM_size * i > total_block)
		{
			continue;
		}

		int temp_time = 0;
		for (int j = 0; j < N; j++)
		{
			for (int k = 0; k < M; k++)
			{
				if (MAP[j][k] > i)
				{
					temp_time += (MAP[j][k] - i) * 2;
				}
				else if (MAP[j][k] < i)
				{
					temp_time += i - MAP[j][k];
				}
			}
		}

		if (temp_time < ans_time)
		{
			ans_time = temp_time;
			ans_hight = i;
		}
	}
	return;
}

void ans()
{
	cout << ans_time << ' ' << ans_hight;
	return;
}