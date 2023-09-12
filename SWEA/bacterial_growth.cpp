#include <iostream>
#include <queue>

using namespace std;

struct Position
{
	int x;
	int y;
};

struct NewPosition // priority_queue�� Ȱ���ϴ� BFS���� ����ϱ� ���� ����ü
{
	int dis; // manhattan �Ÿ�
	int x;
	int y;
};

struct Bacteria
{
	int id;
	int size;
	int time;
};

struct TimeCompare // �ڿ� �Ҹ� ������ ���� cmp
{
	bool operator()(Bacteria x, Bacteria y)
	{
		return x.time > y.time; // �Ҹ� ���� �ð��� ������������ ����
	}
};

struct PutCompare // priority_queue�� Ȱ���� BFS�� cmp ����
{
	bool operator()(NewPosition x, NewPosition y)
	{
		if (x.dis == y.dis)
		{
			if (x.x == y.x)
			{
				return x.y > y.y; // dis�� x�� ��� ���ٸ� y�� ���� �� �켱
			}
			return x.x > y.x; // dis�� ���ٸ� x�� ���� �� �켱
		}
		return x.dis > y.dis; // dis�� ���� �� �켱
	}
};

Bacteria MAP[210][210]; // ����, Bac�� ������ {id, Bac�� ũ��, �ڿ� �Ҹ� ���� �ð�}, Bac�� ������ {0, Ž���� ����, Ž���� �ð�}
int MAPSize; // ���� ũ��
int emptySize; // ���� ���⿡�� ���� ������ ������ ����
int lastChangeTime; // ���� ���� �ð�, (put ����, kill ����, ���� ���� �ڿ� �Ҹ�)�� ���� �ð�

int dx[4] = { -1, 0, 0, 1 }; // BFS�� ���� ���� �迭
int dy[4] = { 0, -1, 1, 0 };

priority_queue<Bacteria, vector<Bacteria>, TimeCompare> lifetime; // ���� ���⿡ �ִ� Bac�� ����, �Ҹ� ���� �ð��� ������������ ����

void timeout(int mtime) // �ڿ� �Ҹ� method, (put, kill, check) method�� ȣ�� �� ���� ���� ȣ���, mtime: (put, kill, check) method�� �Ű����� mtime
{
	while (true) // �ڿ� �Ҹ��� ������ �����ϴ� ��� Bac�� ������
	{
		Bacteria nowBac = lifetime.top(); // ���� ���� ������ ������ Bac ����

		if (nowBac.time > mtime) break; // ���� �ð�(mtime) �������� �ڿ� �Ҹ��� Bac�� ���ٸ� Ż�� break

		int nowId = nowBac.id; // ������ id
		int maxSize = nowBac.size; // ������ Bac�� ũ��
		int nowSize = 0; // ���� ������ Bac�� ��

		for (int i = 1; i <= MAPSize; i++) { // MAP ���� Ž��
			for (int k = 1; k <= MAPSize; k++) {
				if (MAP[i][k].id == nowId)
				{
					MAP[i][k] = { 0, 0, 0 }; // MAP �ʱ�ȭ
					nowSize++; // ������ Bac�� �� ó��
				}
			}
			if (nowSize == maxSize) break; // �� ���� Ȯ���� ������ ��� Bac�� �����Ǿ����� Ȯ��, ��� �����Ǿ����� break
		}

		emptySize += maxSize; // ���⿡ ���� ���� ���� ����
		lastChangeTime = mtime; // ���� ���� �ð� ����
	}
}

void init(int N)
{
	MAPSize = N; // ������ ũ��
	for (int i = 1; i <= MAPSize; i++) {
		for (int k = 1; k <= MAPSize; k++) {
			MAP[i][k] = { 0, 0, 0 }; // ���� ���� �ʱ�ȭ
		}
	}
	emptySize = MAPSize * MAPSize; // ���� ������ ���� ���� �ʱ�ȭ, �ʱ⿡�� Bac�� �����Ƿ� ��ü ���� ũ��� ����
	lastChangeTime = 0; // ���� ���� �ð� �ʱ�ȭ

	while (!lifetime.empty()) // Bac ���� �ʱ�ȭ
	{
		lifetime.pop();
	}
}

Position put(int mtime, Position mPos, Bacteria mBac)
{ // ���⿡ Bac�� �ִ� method, Bac�� ������ �����ϸ� ������ ������ ��ġ return, Bac�� ������ �����ϸ� { 0, 0 } return
	timeout(mtime); // �ڿ� �Ҹ� �켱 ����

	Position pos = { 0, 0 }; // �⺻ ��ȯ ��

	if (mBac.size > emptySize) return pos; // ���� ������ �����ִ� ��Ұ� �����ؾ� �ϴ� ũ�⺸�� ������ ���� ����
	if (MAP[mPos.x][mPos.y].id != 0) return pos; // mPos�� �ٸ� Bac�� �̹� �����ϸ� ���� ����
	if (MAP[mPos.x][mPos.y].time >= lastChangeTime && MAP[mPos.x][mPos.y].size < mBac.size) return pos;
	// ���������� MAP�� ����� �ð� ���Ŀ� �� ������ Ȯ���߰�, �� ������ �����ؾ��ϴ� ũ�⺸�� �۴ٸ� ���� ����

	queue<Position> bacQue; // �����ϴ� ��ġ ����
	bool visited[210][210] = { false }; // �湮�� ��ġ ����

	bacQue.push(mPos); // ù ��ġ�� mPos ����
	visited[mPos.x][mPos.y] = ture; // �ش� ��ġ �湮

	int maxSize = mBac.size; // �����ؾ� �ϴ� ũ��
	int nowSize = 0; // ���� ������ Bac�� ��

	bool flag = false; // ���� ���ɼ�

	while (!bacQue.empty()) // bacQue�� ��� Ȯ���ϸ� break
	{
		Position nowPos = bacQue.front(); // Ȯ���� ��ġ newPos ����
		bacQue.pop();

		for (int dir = 0; dir < 4; dir++) { // �����¿� Ȯ��
			int newX = nowPos.x + dx[dir];
			int newY = nowPos.y + dy[dir];

			if (newX <= 0 || newX > MAPSize || newY <= 0 || newY > MAPSize) continue; //MAP�� ����� continue
			if (MAP[newX][newY].id != 0) continue; // �̹� Bac�� �ִٸ� continue
			if (visited[newX][newY]) continue; // �̹� �湮�ߴٸ� continue

			bacQue.push({ newX, newY }); // bacQue�� �߰�
			nowSize++; // ������ Bac �� ����
			visited[newX][newY] = ture; // �湮 ���� ����
		}

		if (nowSize >= maxSize)
		{
			flag = true; // ���� ���� ������ �����ؾ��ϴ� ���� ���� ũ�ٸ� flag�� true�� ����
			break; // Ȯ�� �� while�� break
		}
	}

	if (!flag) // ���� ���� ������ �����Ͽ� ���忡 ������ ���
	{
		maxSize = nowSize; // �� ������ ũ��
		nowSize = 0; // ���� ��ϵ� ������ ũ��

		for (int i = 1; i <= MAPSize; i++) { // ����Ž��
			for (int k = 1; k <= MAPSize; k++) {
				if (visited[i][k]) // �湮�� ���̸� ũ�� ����
				{
					MAP[i][k] = { 0, maxSize, mtime }; // Bac�� �����Ƿ� id = 0, ������� ũ�� = maxSize, ���� ũ�⸦ Ȯ���� �ð� mtime
					nowSize++; // ����� ������ ũ�� ����
				}
			}
			if (nowSize == maxSize) break; // ��� visited�� Ȯ���ϸ� break;
		}

		return pos; //���忡 ���������Ƿ� { 0, 0 } ��ȯ
	}
	// ���� �����Ͽ� ������ ���� ��ġ�� ��ȯ�ؾ� �ϴ� ���
	priority_queue<NewPosition, vector<NewPosition>, PutCompare> bacPq; // ���� ������ ��ġ ����, ���� �������� ����

	int mx = mPos.x; // �ʱ� ��ġ ����
	int my = mPos.y;
	bacPq.push({ 0, mx, my });

	nowSize = 0; // nowSize �ʱ�ȭ
	bool visitedPq[210][210] = { false }; // �湮 ��ġ ����
	visitedPq[mx][my] = true;

	Bacteria putBac = { mBac.id, mBac.size, (mBac.time + mtime) }; // �ڿ� �Ҹ� ���� �ð� ����

	while (!bacPq.empty())
	{
		NewPosition nowPos = bacPq.top(); // �켱 ������ ���� ���� ��ġ
		bacPq.pop();
		int nowX = nowPos.x;
		int nowY = nowPos.y;
		Map[nowX][nowY] = putBac; // MAP�� Bac ���� ����

		nowSize++;
		if (nowSize == maxSize) // ������ �Ϸ�Ǿ��ٸ�
		{
			pos = { newPos.x, newPos.y }; // ������ ���� ��ġ ���
			break; // while Ż��
		}

		for (int dir = 0; dir < 4; dir++) // �����¿� Ȯ��
		{
			int newX = nowPos.x + dx[dir]; // ���� ���� ��ġ�� Ȯ���� ��ǥ
			int newY = nowPos.y + dy[dir];

			if (newX <= 0 || newX > MAPSize || newY <= 0 || newY > MAPSize) continue; // MAP���� ����� continue
			if (MAP[newX][newY].id != 0) continue; // �ٸ� Bac�� ������ continue
			if (visitedPq[newX][newY]) continue; // �̹� �湮�� ��Ҹ� continue

			int manhattanDis; // manhattan �Ÿ� ���, ���� ���
			if (mx >= newX && my >= newY) manhattanDis = (mx - newX) + (my - newY);
			else if (mx < newX && my >= newY) manhattanDis = (newX - mx) + (my - newY);
			else if (mx >= newX && my < newY) manhattanDis = (mx - newX) + (newY - my);
			else manhattanDis = (newX - mx) + (newY - my);

			bacPq.push({ manhattanDis, newX, newY }); // ���� ���� ��ġ ����
			visitedPq[newX][newY] = ture; // �ش� ��ġ ���
		}
	}

	lifetime.push(putBac); // ���� ���⿡ �ִ� Bac ���� �߰�
	lastChangeTime = mtime; // �ֱ� ���� �ð� ����
	emptySize -= mBac.size; // ��ü ���� ���� ũ�� ����

	return pos; // ��ġ ��ȯ
}

int kill(int mtime, Position mpos) // �ش� ��ġ(mpos)�� Bac�� �ִٸ� �ش� Bac�� ��� �����ϰ� id ��ȯ, Bac�� ���ٸ� 0 ��ȯ
{
	timeout(mtime); // �ڿ� �Ҹ� �켱 ����

	if (MAP[mpos.x][mpos.y].id == 0) return 0; // mpos�� Bac�� ���ٸ� 0 ��ȯ

	Bacteria nowBac = MAP[mpos.x][mpos.y]; // mpos�� Bac�� nowBac�� ����
	int nowId = nowBac.id; // ������ Bac�� id
	int maxSize = nowBac.size; // ������ Bac�� ��ü ũ��
	int nowSize = 0; // ���� ������ Bac�� ũ��

	for (int i = 1; i <= MAPSize; i++) { // MAP ���� Ž��
		for (int k = 1; k <= MAPSize; k++) {
			if (MAP[i][k].id == nowId)
			{
				MAP[i][k] = { 0, 0, 0 }; // MAP �ʱ�ȭ (����)
				nowSize++; // ������ Bac�� �� ó��
			}
		}
		if (nowSize == maxSize) break; // �� ���� Ȯ���� ������ ��� Bac�� �����Ǿ����� Ȯ��, ��� �����Ǿ����� break
	}

	emptySize += maxSize; // ������ ���� ���� ������ ���� ����
	lastChangeTime = mtime; // ���� ���� �ð� ����

	return nowId; // ������ Bac�� id ��ȯ
}

int check(int mtime, Position mpos) // �ش� ��ġ�� Bac id ��ȯ, Bac�� ���ٸ� 0 ��ȯ 
{
	timeout(mtime); // �ڿ� �Ҹ� �켱 ó�� 

	return MAP[mpos.x][mpos.y].id; // �ش� ��ġ�� Bac id ��ȯ, Bac�� ���ٸ� �ʱ�ȭ ���� 0 ��ȯ 
}