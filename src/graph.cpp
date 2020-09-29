#include "graph.h"

Graph::Graph(int n)
{
	N = n;
	arestas = (N * (N - 1)) / 2;

	table = vector<vector<int>>(N, vector<int>(N, 0));
	lanterns = vector<vector<int>>(N, vector<int>(N, 0));
	vertexColor = vector<vector<int>>(N, vector<int>(N, -1));
}

void Graph::Circle()
{

	int temp, a, b;

	int circle[N];
	for (int i = 0; i < N; i++)
		circle[i] = i;

	for (int i = 0; i < N - 1; i++)
	{
		a = circle[N - 1];
		b = circle[0];
		table[a][b] = i + 1;
		table[b][a] = i + 1;
		for (int k = 1; k < N / 2; k++)
		{
			a = circle[k];
			b = circle[N - 1 - k];
			table[a][b] = i + 1;
			table[b][a] = i + 1;
		}
		temp = circle[0];
		for (int j = 0; j < N - 1; j++)
		{
			circle[j] = circle[j + 1];
		}
		circle[N - 2] = temp;
	}

	for (int v = 0; v < N; v++)
		for (int w = 0; w < N; w++)
			vertexColor[v][table[v][w]] = w;
}

bool Graph::isAbsolute()
{
	// Declares two auxiliar data structures
	vector<bool> vertex(N, false);
	for (int i = 1; i < pow(2, N); i++)
	{
		int n = i;
		int j = 0;
		fill(vertex.begin(), vertex.end(), 0);
		while (n > 0 && j < N)
		{
			vertex[j++] = (n & 1);
			n = n >> 1;
		}
		int amount = 0;
		amount = accumulate(vertex.begin(), vertex.end(), amount);
		if (amount % 2 || amount == N || amount <= 2)
			continue;

		vector<bool> acolor(N, false);
		bool absolute = false;
		for (int v = 0; v < N; v++)
		{
			if (vertex[v])
			{
				for (int w = v + 1; w < N; w++)
				{
					if (vertex[w])
						acolor[table[v][w]] = true;
				}
			}
		}
		int Y = 0;
		Y = accumulate(acolor.begin(), acolor.end(), Y);
		if (Y == amount - 1)
		{
			return false;
		}
	}
	return true;
}

bool Graph::isPerfect()
{
	int end, count, w;
	for (int v = 0; v < N; v++)
	{

		end = v;
		for (int c1 = 1; c1 < N; c1++)
			for (int c2 = c1 + 1; c2 < N; c2++)
			{
				count = 0;
				w = v;
				do
				{
					end = vertexColor[vertexColor[w][c1]][c2];
					w = end;
					count += 2;
				} while (w != v);
				if (count < N)
				{
					//cout<<"Not Perfect"<<endl;
					return false;
				}
			}
	}
	//cout<<"Perfect coloring!"<<endl;
	return true;
}

void Graph::toHex()
{
	for (int j = 1; j < N; j++)
	{
		for (int i = 0; i < N; i++)
			if (i < vertexColor[i][j])
				cout << uppercase << hex << i << vertexColor[i][j] << " ";
		cout << " ";
	}
	cout << endl;
}