#include <iostream>

using namespace std;

struct posision
{
	int x;
	int y;
};

int N, M, K;
int MAP[15][15];
int remain_player_num;
bool remain_player[15];
int ans_moving = 0;

void init();
void moving();
void escape(int x);
// 회전();
// fin();

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	init();
	//	for(K번)
	// {
	// moving();
	// 
	// if(!remain_player_num)
	// {
	//	break;
	// }
	// 
	// 회전();
	//	}
	// fin();
	return 0;
}

void init()
{
	cin >> N >> M >> K;

	for (int i = 0; i < N; i++)
	{
		for (int k = 0; k < N; k++)
		{
			cin >> MAP[i][k];
		}
	}

	for (int i = 0; i < M; i++)
	{
		// map으로 저장, key는 들어온 순서(i), value는 {x, y}
		// 좌표는 -1씩 해서 0,0으로 시작
		// 출구 좌표 계산시 +1 필수!

		// remain_player[i] = false;
	}

	// cin >> 출구 좌표

	//	남은 참가자 = M

	return;
}

// void moving()
// {
// for(M번)
//	if 탈출했니? == true면 continue;
//	if 상하좌우 모두 벽? continue;
//	
//	if 상하가 가까워지고 && 그곳에 벽이 없 -> 이동, ans_moving++, 출구 ? escape(M);
//	else if 좌우가 가까워지고 && 그곳에 벽이 없 -> 이동, ans_moving++,  출구? escape(M);
// 
//	
// }

// void escape(int x)
// {
//	remain_player[x] = true
//	remain_player_num--;
// }

// 회전()
// {
// 정사각형 찾기
// 정사각형 내구도 감소
// 정사각형 돌리기
// }

// fin()
// {
//
// }