#include <iostream>

using namespace std;

int Q; // ����� �� Ƚ��
int N, M; // ��, ��
int P; // �䳢 ��ü ���� ��
int pid_i, pid_t; // �䳢�� ��ȣ, �䳢�� �Ÿ� Ȯ�� ��ȣ
int d_i; // �䳢 �̵� �Ÿ�
int K; // (200) �ݺ� Ƚ��
int S; // �߰� ����
int L; // �谡 �Ǵ� ���

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