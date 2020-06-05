#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
const int SIZE = 7;
int i, j;
bool *visited = new bool[SIZE];
int map[SIZE][SIZE];
void DFS(int st, int finish)
{
	int r;
	cout << st + 1 << " ";
	visited[st] = true;
	for (r = 0; r <= SIZE; r++)
	{
		if ((map[st][r] != 0) && (!visited[r]))
			DFS(r, finish);
	}
}
int main()
{
	srand(time(nullptr));
	setlocale(LC_ALL, "Rus");
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = i; j < SIZE; j++)
		{
			if (i == j)
				map[i][j] = 1;
			else
			{
				map[i][j] = rand() % 2;
				map[j][i] = map[i][j];
			}
		}
	}
	int start, finish;
	cout << "Ìàòðèöÿ çâÿçê³â ì³æ ì³ñòàìè: " << endl;
	for (i = 0; i < SIZE; i++)
	{
		visited[i] = false;
		for (j = 0; j < SIZE; j++)
			cout << " " << map[i][j];
		cout << endl;
	}
	cout << "Ñòàðò >> ";
	cin >> start;
	cout << "Ô³í³ø >> ";
	cin >> finish;
	cout << "Ïîðÿäîê îáõîäó: ";
	DFS(start - 1, finish - 1);
	bool isWay = false;
	if (visited[finish-1] == true)
		cout << "²ñíóº øëÿõ ì³æ ì³ñòàìè!\n";
	else
		cout << "Øëÿõ ì³æ ì³ñòàìè â³äñóòí³é!\n";
	delete[]visited;
	system("pause");
	return 0;
}
