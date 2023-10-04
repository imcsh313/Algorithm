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

int Q; // 명령의 총 횟수
int N, M; // 행, 열
int P; // 토끼 전체 마리 수
int pid_i, pid_t; // 토끼의 번호, 토끼의 거리 확대 번호
int d_i; // 토끼 이동 거리
int K; // (200) 반복 횟수
int S; // 추가 점수
int L; // 배가 되는 배수

int finSum = 0; // 마지막에 더할 점수

priority_queue<rabbit, vector<rabbit>, compareRabbit> AllAboutRabbit;
vector<rabbit> moving_rabbit;
int rabbitDistance[10000010] = 0;

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
			cout << "정의되지 않은 입력 오류\n";
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
		AllAboutRabbit.push({0, {0, 0, 0}, pid, 0});
		rabbitDistance[pid] = d;
	}

	return;
}

void func_200()
{
	cout << "func_200 start!\n";

	cin >> K >> S;

	for(int i = 0; i < K; i++)
	{
		// 토끼 선별
		// nowRabbit에 저장 후 pop
		// moving_rabbit에 토끼 추가
		// 4개의 위치 구하기
			// 벗어나면 뒤로 돌아오는 로직
		// 위치 최종 선정
		// 최종 추가 점수 finSum에 행+열 추가

		// nowRabbit 수치 변경
			// 해당 토끼 점수 빼기
			// 이동 횟수 +1
			// 위치 변경
		// nowRabbit push
	}

	// moving_rabbit 중 1등 선정
	// 해당 토끼 수련회 점수 S 추가
	
	return;
}

void func_300()
{
	cout << "func_300 start!\n";

	cin >> pid_t >> L;

	rabbitDistance[pid_t] *= L;

	return;
}

void func_400()
{
	cout << "func_400 start!\n";

	// AllAboutRabbit을 하나씩 뽑으면서 점수 최고점 선정
	// 최종 점수 finSum 추가
	// 해당 점수 출력
	
	return;
}
