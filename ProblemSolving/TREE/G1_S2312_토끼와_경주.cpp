#include <iostream>

using namespace std;

int Q; // 명령의 총 횟수
int N, M; // 행, 열
int P; // 토끼 전체 마리 수
int pid_i, pid_t; // 토끼의 번호, 토끼의 거리 확대 번호
int d_i; // 토끼 이동 거리
int K; // (200) 반복 횟수
int S; // 추가 점수
int L; // 배가 되는 배수

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