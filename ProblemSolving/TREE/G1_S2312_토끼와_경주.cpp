#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct position
{
	int sum;
	int x;
	int y;
};

struct rabbit
{
	int movingCount;
	position position;
	int id;
	int dis;
	long long score;
};

struct compareRabbit
{
	bool operator()(rabbit x, rabbit y)
	{
		if (x.movingCount == y.movingCount)
		{
			if (x.position.sum == y.position.sum)
			{
				if (x.position.x == y.position.x)
				{
					if (x.position.y == y.position.y)
					{
						return x.id > y.id;
					}
					return x.position.y > y.position.y;
				}
				return x.position.x > y.position.x;
			}
			return x.position.sum > y.position.sum;
		}
		return x.movingCount > return y.movingCount;
	}
};

int Q; // ����� �� Ƚ��
int N, M; // ��, ��
int P; // �䳢 ��ü ���� ��
int pid_i, pid_t; // �䳢�� ��ȣ, �䳢�� �Ÿ� Ȯ�� ��ȣ
int d_i; // �䳢 �̵� �Ÿ�
int K; // (200) �ݺ� Ƚ��
int S; // �߰� ����
int L; // �谡 �Ǵ� ���

int finSum = 0; // �������� ���� ����

priority_queue<rabbit, vector<rabbit>, compareRabbit> AllAboutRabbit;
vector<rabbit> moving_rabbit;

void func_100();
void func_200();
void func_300();
void func_400();

int main()
{
	cin >> Q;

	for (int i = 0; i < Q; i++)
	{
		int temp;
		cin >> temp;

		switch (temp)
		{
		case 100:
			func_100();
			break;
		case 200:
			func_200();
			break;
		case 300:
			func_300();
			break;
		case 400:
			func_400();
			break;
		default:
			cout << "���ǵ��� ���� �Է� ����\n";
			return 1;
		}
	}

	return 0;
}

void func_100()
{
	cout << "func_100 start!\n";

	cin >> N >> M >> P;

	int pid, d;
	for (int i = 0; i < P; i++)
	{
		cin >> pid >> d;
		AllAboutRabbit.push({0, }) //ing-------------------
	}

	return;
}

void func_200()
{
	cout << "func_200 start!\n";
	return;
}

void func_300()
{
	cout << "func_300 start!\n";
	return;
}

void func_400()
{
	cout << "func_400 start!\n";
	return;
}