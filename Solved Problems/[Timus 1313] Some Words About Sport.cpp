#include <iostream>
#include <cstring>
#include <deque>
using namespace std;

bool isValid(int i, int j, int N)
{
	if (i<N && j<N)
		return true;
	else
		return false;
}

int main()
{
	int N;
	cin >> N;
	int arr[N][N];
	for (int i=0; i<N; i++)
		for (int j=0; j<N; j++)
			cin >> arr[i][j];
	bool visited[N][N];
	memset(visited, false, sizeof(visited));
	deque <int> q, enlisted, i, j;
	q.push_back(arr[0][0]);
	i.push_back(0);
	j.push_back(0);
	visited[0][0]=true;
	while (!q.empty())
	{
		enlisted.push_back(arr[i.front()][j.front()]);
		q.pop_front();
		if (isValid(i.front()+1, j.front(), N) && !visited[i.front()+1][j.front()])
		{
			q.push_back(arr[i.front()+1][j.front()]);
			visited[i.front()+1][j.front()]=true;
			i.push_back(i.front()+1);
			j.push_back(j.front());
		}
		if (isValid(i.front(), j.front()+1, N) && !visited[i.front()][j.front()+1])
		{
			q.push_back(arr[i.front()][j.front()+1]);
			visited[i.front()][j.front()+1]=true;
			i.push_back(i.front());
			j.push_back(j.front()+1);
		}
		i.pop_front();
		j.pop_front();
	}
	int n=0;
	for (auto i : enlisted)
	{
		if (n!=0)
			cout << ' ';
		cout << i;
		n=1;
	}
	cout << endl;
}