#include <iostream>

using namespace std;

#define CMP(x, y) (((x) < (y)) ? -1 : ((x) > (y)) ? 1 : 0)
// x가 더 크면 1, x가 더 작으면 -1, 서로 같으면 0

int compare(int, int);

int main()
{
	int a, b;

	cin >> a >> b;

	cout << CMP(a, b) << endl;
	cout << (((a) < (b)) ? -1 : ((a) > (b)) ? 1 : 0) << endl;
	cout << compare(a, b) << endl;

	switch (CMP(a, b))
	{
	case -1:
		cout << -1 << endl;
		break;
	case 1:
		cout << 1 << endl;
		break;
	default:
		cout << 0 << endl;
	}

	return 0;
}

int compare(int x, int y)
{
	if (x < y) return -1;
	if (x > y) return 1;
	return 0;
}