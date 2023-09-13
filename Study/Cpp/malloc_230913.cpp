#include <iostream>

using namespace std;

int main()
{
	int i, * pi;
	float f, * pf;

	pi = (int*)malloc(sizeof(int));
	pf = (float*)malloc(sizeof(float));

	*pi = 1024;
	*pf = 3.14;

	cout << *pi << ' ' << *pf;

	free(pi);
	free(pf);

	return 0;
}