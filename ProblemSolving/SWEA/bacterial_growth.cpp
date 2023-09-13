#include <iostream>
#include <queue>

using namespace std;

struct Position
{
	int x;
	int y;
};

struct NewPosition // priority_queue를 활용하는 BFS에서 사용하기 위한 구조체
{
	int dis; // manhattan 거리
	int x;
	int y;
};

struct Bacteria
{
	int id;
	int size;
	int time;
};

struct TimeCompare // 자연 소멸 정렬을 위한 cmp
{
	bool operator()(Bacteria x, Bacteria y)
	{
		return x.time > y.time; // 소멸 예정 시간의 오름차순으로 정렬
	}
};

struct PutCompare // priority_queue를 활용한 BFS의 cmp 기준
{
	bool operator()(NewPosition x, NewPosition y)
	{
		if (x.dis == y.dis)
		{
			if (x.x == y.x)
			{
				return x.y > y.y; // dis와 x가 모두 같다면 y가 작은 것 우선
			}
			return x.x > y.x; // dis가 같다면 x가 작은 것 우선
		}
		return x.dis > y.dis; // dis가 작은 것 우선
	}
};

Bacteria MAP[210][210]; // 배양기, Bac이 있으면 {id, Bac의 크기, 자연 소멸 예정 시간}, Bac이 없으면 {0, 탐색한 공간, 탐색한 시간}
int MAPSize; // 배양기 크기
int emptySize; // 현재 배양기에서 성장 가능한 공간의 총합
int lastChangeTime; // 최종 변경 시간, (put 성공, kill 성공, 수명에 따른 자연 소멸)할 때의 시간

int dx[4] = { -1, 0, 0, 1 }; // BFS를 위한 방향 배열
int dy[4] = { 0, -1, 1, 0 };

priority_queue<Bacteria, vector<Bacteria>, TimeCompare> lifetime; // 현재 배양기에 있는 Bac의 정보, 소멸 예정 시간의 오름차순으로 정렬

void timeout(int mtime) // 자연 소멸 method, (put, kill, check) method가 호출 시 가장 먼저 호출됨, mtime: (put, kill, check) method의 매개변수 mtime
{
	while (true) // 자연 소멸의 조건을 만족하는 모든 Bac을 삭제함
	{
		Bacteria nowBac = lifetime.top(); // 가장 먼저 수명이 끝나는 Bac 선택

		if (nowBac.time > mtime) break; // 현재 시간(mtime) 기준으로 자연 소멸할 Bac이 없다면 탈출 break

		int nowId = nowBac.id; // 삭제할 id
		int maxSize = nowBac.size; // 삭제할 Bac의 크기
		int nowSize = 0; // 현재 삭제된 Bac의 양

		for (int i = 1; i <= MAPSize; i++) { // MAP 완전 탐색
			for (int k = 1; k <= MAPSize; k++) {
				if (MAP[i][k].id == nowId)
				{
					MAP[i][k] = { 0, 0, 0 }; // MAP 초기화
					nowSize++; // 삭제한 Bac의 양 처리
				}
			}
			if (nowSize == maxSize) break; // 한 줄을 확인할 때마다 모든 Bac이 삭제되었는지 확인, 모두 삭제되었으면 break
		}

		emptySize += maxSize; // 배양기에 남은 성장 공간 갱신
		lastChangeTime = mtime; // 최종 변경 시간 갱신
	}
}

void init(int N)
{
	MAPSize = N; // 배양기의 크기
	for (int i = 1; i <= MAPSize; i++) {
		for (int k = 1; k <= MAPSize; k++) {
			MAP[i][k] = { 0, 0, 0 }; // 배양기 정보 초기화
		}
	}
	emptySize = MAPSize * MAPSize; // 성장 가능한 배양기 공간 초기화, 초기에는 Bac이 없으므로 전체 배양기 크기로 설정
	lastChangeTime = 0; // 최종 변경 시간 초기화

	while (!lifetime.empty()) // Bac 정보 초기화
	{
		lifetime.pop();
	}
}

Position put(int mtime, Position mPos, Bacteria mBac)
{ // 배양기에 Bac을 넣는 method, Bac의 성장이 성공하면 마지막 번식한 위치 return, Bac의 성장이 실패하면 { 0, 0 } return
	timeout(mtime); // 자연 소멸 우선 실행

	Position pos = { 0, 0 }; // 기본 반환 값

	if (mBac.size > emptySize) return pos; // 성장 가능한 남아있는 장소가 성장해야 하는 크기보다 작으면 성장 실패
	if (MAP[mPos.x][mPos.y].id != 0) return pos; // mPos에 다른 Bac이 이미 존재하면 성장 실패
	if (MAP[mPos.x][mPos.y].time >= lastChangeTime && MAP[mPos.x][mPos.y].size < mBac.size) return pos;
	// 마지막으로 MAP이 변경된 시간 이후에 빈 공간을 확인했고, 그 공간이 성장해야하는 크기보다 작다면 성장 실패

	queue<Position> bacQue; // 성장하는 위치 저장
	bool visited[210][210] = { false }; // 방문한 위치 저장

	bacQue.push(mPos); // 첫 위치로 mPos 삽입
	visited[mPos.x][mPos.y] = ture; // 해당 위치 방문

	int maxSize = mBac.size; // 성장해야 하는 크기
	int nowSize = 0; // 현재 성장한 Bac의 양

	bool flag = false; // 성장 가능성

	while (!bacQue.empty()) // bacQue를 모두 확인하면 break
	{
		Position nowPos = bacQue.front(); // 확인할 위치 newPos 설정
		bacQue.pop();

		for (int dir = 0; dir < 4; dir++) { // 상하좌우 확인
			int newX = nowPos.x + dx[dir];
			int newY = nowPos.y + dy[dir];

			if (newX <= 0 || newX > MAPSize || newY <= 0 || newY > MAPSize) continue; //MAP을 벗어나면 continue
			if (MAP[newX][newY].id != 0) continue; // 이미 Bac이 있다면 continue
			if (visited[newX][newY]) continue; // 이미 방문했다면 continue

			bacQue.push({ newX, newY }); // bacQue에 추가
			nowSize++; // 성장한 Bac 양 갱신
			visited[newX][newY] = ture; // 방문 정보 갱신
		}

		if (nowSize >= maxSize)
		{
			flag = true; // 성장 가능 공간이 성장해야하는 공간 보다 크다면 flag를 true로 변경
			break; // 확인 후 while문 break
		}
	}

	if (!flag) // 성장 가능 공간이 부족하여 성장에 실패할 경우
	{
		maxSize = nowSize; // 빈 공간의 크기
		nowSize = 0; // 현재 기록된 공간의 크기

		for (int i = 1; i <= MAPSize; i++) { // 완전탐색
			for (int k = 1; k <= MAPSize; k++) {
				if (visited[i][k]) // 방문한 곳이면 크기 갱신
				{
					MAP[i][k] = { 0, maxSize, mtime }; // Bac이 없으므로 id = 0, 빈공간의 크기 = maxSize, 공간 크기를 확인한 시간 mtime
					nowSize++; // 기록한 공간의 크기 갱신
				}
			}
			if (nowSize == maxSize) break; // 모든 visited를 확인하면 break;
		}

		return pos; //성장에 실패했으므로 { 0, 0 } 반환
	}
	// 성장 가능하여 마지막 성장 위치를 반환해야 하는 경우
	priority_queue<NewPosition, vector<NewPosition>, PutCompare> bacPq; // 성장 가능한 위치 저장, 문제 기준으로 정렬

	int mx = mPos.x; // 초기 위치 정보
	int my = mPos.y;
	bacPq.push({ 0, mx, my });

	nowSize = 0; // nowSize 초기화
	bool visitedPq[210][210] = { false }; // 방문 위치 저장
	visitedPq[mx][my] = true;

	Bacteria putBac = { mBac.id, mBac.size, (mBac.time + mtime) }; // 자연 소멸 예정 시간 저장

	while (!bacPq.empty())
	{
		NewPosition nowPos = bacPq.top(); // 우선 순위가 가장 높은 위치
		bacPq.pop();
		int nowX = nowPos.x;
		int nowY = nowPos.y;
		Map[nowX][nowY] = putBac; // MAP에 Bac 정보 저장

		nowSize++;
		if (nowSize == maxSize) // 성장이 완료되었다면
		{
			pos = { newPos.x, newPos.y }; // 마지막 성장 위치 기억
			break; // while 탈출
		}

		for (int dir = 0; dir < 4; dir++) // 상하좌우 확인
		{
			int newX = nowPos.x + dx[dir]; // 성장 가능 위치를 확인할 좌표
			int newY = nowPos.y + dy[dir];

			if (newX <= 0 || newX > MAPSize || newY <= 0 || newY > MAPSize) continue; // MAP에서 벗어나면 continue
			if (MAP[newX][newY].id != 0) continue; // 다른 Bac가 있으면 continue
			if (visitedPq[newX][newY]) continue; // 이미 방문한 장소면 continue

			int manhattanDis; // manhattan 거리 계산, 절댓값 계산
			if (mx >= newX && my >= newY) manhattanDis = (mx - newX) + (my - newY);
			else if (mx < newX && my >= newY) manhattanDis = (newX - mx) + (my - newY);
			else if (mx >= newX && my < newY) manhattanDis = (mx - newX) + (newY - my);
			else manhattanDis = (newX - mx) + (newY - my);

			bacPq.push({ manhattanDis, newX, newY }); // 성장 가능 위치 저장
			visitedPq[newX][newY] = ture; // 해당 위치 기억
		}
	}

	lifetime.push(putBac); // 현재 배양기에 있는 Bac 정보 추가
	lastChangeTime = mtime; // 최근 변경 시간 갱신
	emptySize -= mBac.size; // 전체 성장 가능 크기 갱신

	return pos; // 위치 반환
}

int kill(int mtime, Position mpos) // 해당 위치(mpos)에 Bac이 있다면 해당 Bac을 모두 삭제하고 id 반환, Bac이 없다면 0 반환
{
	timeout(mtime); // 자연 소멸 우선 실행

	if (MAP[mpos.x][mpos.y].id == 0) return 0; // mpos에 Bac이 없다면 0 반환

	Bacteria nowBac = MAP[mpos.x][mpos.y]; // mpos의 Bac을 nowBac에 저장
	int nowId = nowBac.id; // 삭제할 Bac의 id
	int maxSize = nowBac.size; // 삭제할 Bac의 전체 크기
	int nowSize = 0; // 현재 삭제된 Bac의 크기

	for (int i = 1; i <= MAPSize; i++) { // MAP 완전 탐색
		for (int k = 1; k <= MAPSize; k++) {
			if (MAP[i][k].id == nowId)
			{
				MAP[i][k] = { 0, 0, 0 }; // MAP 초기화 (삭제)
				nowSize++; // 삭제한 Bac의 양 처리
			}
		}
		if (nowSize == maxSize) break; // 한 줄을 확인할 때마다 모든 Bac이 삭제되었는지 확인, 모두 삭제되었으면 break
	}

	emptySize += maxSize; // 배양기의 남은 성장 가능한 공간 갱신
	lastChangeTime = mtime; // 최종 변경 시간 갱신

	return nowId; // 삭제한 Bac의 id 반환
}

int check(int mtime, Position mpos) // 해당 위치의 Bac id 반환, Bac이 없다면 0 반환 
{
	timeout(mtime); // 자연 소멸 우선 처리 

	return MAP[mpos.x][mpos.y].id; // 해당 위치의 Bac id 반환, Bac이 없다면 초기화 값인 0 반환 
}