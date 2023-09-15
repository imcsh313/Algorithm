#include <iostream>
#include <cmath>

#define MAX_SIZE 101
#define SWAP(x, y, t) ((t) = (x), (x) = (y), (y) = (t))

using namespace std;

void Selection_Sort(int list[], int);

int main()
{
	int list[MAX_SIZE];

	int n;
	cout << "정렬을 진행할 갯수를 정해주세요. (1 <= n <= 100): ";
	cin >> n;

	if (n < 1 || n > 100)
	{
		cout << "불가능한 범위입니다.";
		return 0;
	}

	for (int i = 0; i < n; i++)
	{ // 난수 생성
		list[i] = rand() % 1000;
		cout << list[i] << ' ';
	}
	cout << endl;

	Selection_Sort(list, n);

	for (int i = 0; i < n; i++)
	{
		cout << list[i] << ' ';
	}

	return 0;
}

void Selection_Sort(int list[], int n)
{
	for (int i = 0; i < n; i++)
	{
		int min = i;
		for (int k = i; k < n; k++)
		{
			if (list[k] < list[min])
			{
				min = k;
			}
		}

		int temp;
		SWAP(list[i], list[min], temp);
	}
}