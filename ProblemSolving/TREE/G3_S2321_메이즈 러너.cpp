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
// ȸ��();
// fin();

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	init();
	//	for(K��)
	// {
	// moving();
	// 
	// if(!remain_player_num)
	// {
	//	break;
	// }
	// 
	// ȸ��();
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
		// map���� ����, key�� ���� ����(i), value�� {x, y}
		// ��ǥ�� -1�� �ؼ� 0,0���� ����
		// �ⱸ ��ǥ ���� +1 �ʼ�!

		// remain_player[i] = false;
	}

	// cin >> �ⱸ ��ǥ

	//	���� ������ = M

	return;
}

// void moving()
// {
// for(M��)
//	if Ż���ߴ�? == true�� continue;
//	if �����¿� ��� ��? continue;
//	
//	if ���ϰ� ��������� && �װ��� ���� �� -> �̵�, ans_moving++, �ⱸ ? escape(M);
//	else if �¿찡 ��������� && �װ��� ���� �� -> �̵�, ans_moving++,  �ⱸ? escape(M);
// 
//	
// }

// void escape(int x)
// {
//	remain_player[x] = true
//	remain_player_num--;
// }

// ȸ��()
// {
// ���簢�� ã��
// ���簢�� ������ ����
// ���簢�� ������
// }

// fin()
// {
//
// }