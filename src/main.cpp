// User Libraries
#include "graph.h"
#include "colormod.h"
#include "prints.h"
#include "utils.h"

// STL
#include <iostream>
#include <cassert>
#include <ctime>
#include <climits>
#include <tuple>
#include <utility>
#include <vector>
#include <algorithm>
#include <fstream>
#include <cstdlib>
#include <string>
#include <random>
#include <set>
using namespace std;

int N = 14;
const int total = 1025;

void printLanterns(int v, int w);

// random generator function:
int myrandom(int i) { return std::rand() % i; }
int contagem = 0;
int arestas;

Graph g;
int table[total][total];
int vertexColor[total][total];
int lanterns[total][total];

// Variable inicialization
void start()
{
	arestas = (N * (N - 1)) / 2;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			table[i][j] = 0;
			lanterns[i][j] = 0;
			vertexColor[i][j] = -1;
		}
	}
}

void printLanterns()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cout << setw(3) << lanterns[i][j];
		}
		cout << endl;
	}
}

void printFactorizationsICD()
{
	for (int j = 1; j < N; j++)
	{
		cout << j;
		for (int i = 0; i < N; i++)
		{
			if (i < vertexColor[i][j])
				switch (j)
				{
				case 1:
					cout << setw(6) << one << i + 1 << " " << vertexColor[i][j] + 1 << deff;
					break;
				case 2:
					cout << setw(6) << two << i + 1 << " " << vertexColor[i][j] + 1 << deff;
					break;
				case 3:
					cout << setw(6) << three << i + 1 << " " << vertexColor[i][j] + 1 << deff;
					break;
				case 4:
					cout << setw(6) << four << i + 1 << " " << vertexColor[i][j] + 1 << deff;
					break;
				case 5:
					cout << setw(6) << five << i + 1 << " " << vertexColor[i][j] + 1 << deff;
					break;
				case 6:
					cout << setw(6) << six << i + 1 << " " << vertexColor[i][j] + 1 << deff;
					break;
				case 7:
					cout << setw(6) << seven << "\e[1m" << i + 1 << " " << vertexColor[i][j] + 1 << defb << "\e[0m";
					break;
				case 8:
					cout << setw(6) << eight << i << " " << vertexColor[i][j] << defb << "\e[0m";
					break;
				case 9:
					cout << setw(6) << nine << "\e[1m" << i << " " << vertexColor[i][j] << defb << "\e[0m";
					break;
				default:
					cout << setw(6) << deff << i << " " << vertexColor[i][j] << deff;
					break;
				}
		}
		cout << endl;
	}
}

void printFactorizationsHCD()
{
	for (int j = 1; j < N; j++)
	{
		cout << char(64 + j) << "\t";
		for (int i = 0; i < N; i++)
		{
			if (i < vertexColor[i][j])
				switch (j)
				{
				case 1:
					if (i != 0)
						cout << one << i << vertexColor[i][j] << deff;
					else
						cout << one << vertexColor[i][j] << deff;
					break;
				case 2:
					if (i != 0)
						cout << two << i << vertexColor[i][j] << deff;
					else
						cout << two << vertexColor[i][j] << deff;
					break;
				case 3:
					if (i != 0)
						cout << three << i << vertexColor[i][j] << deff;
					else
						cout << three << vertexColor[i][j] << deff;
					break;
				case 4:
					if (i != 0)
						cout << four << i << vertexColor[i][j] << deff;
					else
						cout << four << vertexColor[i][j] << deff;
					break;
				case 5:
					if (i != 0)
						cout << five << i << vertexColor[i][j] << deff;
					else
						cout << five << vertexColor[i][j] << deff;
					break;
				case 6:
					if (i != 0)
						cout << six << i << vertexColor[i][j] << deff;
					else
						cout << six << vertexColor[i][j] << deff;
					break;
				case 7:
					if (i != 0)
						cout << seven << "\e[1m" << i << vertexColor[i][j] << defb << "\e[0m";
					else
						cout << seven << "\e[1m" << vertexColor[i][j] << defb << "\e[0m";
					break;
				case 8:
					if (i != 0)
						cout << eight << "\e[1m" << i << vertexColor[i][j] << defb << "\e[0m";
					else
						cout << eight << "\e[1m" << vertexColor[i][j] << defb << "\e[0m";
					break;
				case 9:
					if (i != 0)
						cout << nine << "\e[1m" << i << vertexColor[i][j] << defb << "\e[0m";
					else
						cout << nine << "\e[1m" << vertexColor[i][j] << defb << "\e[0m";
					break;
					break;
				default:
					if (i != 0)
						cout << deff << i << vertexColor[i][j] << deff;
					else
						cout << deff << vertexColor[i][j] << deff;
					break;
				}
		}
		cout << endl;
	}
}

// Print results
void print()
{
	cout << "NxN table:" << endl;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			//cout<<setw(4)<<table[i][j];
			switch (table[i][j])
			{
			case 1:
				cout << setw(3) << one << table[i][j] << deff;
				break;
			case 2:
				cout << setw(3) << two << table[i][j] << deff;
				break;
			case 3:
				cout << setw(3) << three << table[i][j] << deff;
				break;
			case 4:
				cout << setw(3) << four << table[i][j] << deff;
				break;
			case 5:
				cout << setw(3) << five << table[i][j] << deff;
				break;
			case 6:
				cout << setw(3) << six << table[i][j] << deff;
				break;
			case 7:
				cout << setw(3) << deff << seven << table[i][j] << deff;
				break;
			case 8:
				cout << setw(3) << deff << eight << table[i][j] << deff;
				break;
			case 9:
				cout << setw(3) << deff << nine << table[i][j] << deff;
				break;
			default:
				cout << setw(3) << deff << table[i][j];
				break;
			}
		}
		cout << endl;
	}
}

void print3(){
	for(int j=1; j < N; j++){
		for(int i=0; i < N; i++)
			if( i < vertexColor[i][j])
				cout<<uppercase<<hex<<i<<vertexColor[i][j]<<" ";
		cout<<" ";
	}
	cout<<endl;
}

void print2()
{
	cout << "Vertices x colors table:" << endl;
	for (int i = 0; i < N; i++)
	{
		for (int j = 1; j < N; j++)
		{
			switch (j)
			{
			case 1:
				cout << setw(3) << one << vertexColor[i][j];
				break;
			case 2:
				cout << setw(3) << two << vertexColor[i][j];
				break;
			case 3:
				cout << setw(3) << three << vertexColor[i][j];
				break;
			case 4:
				cout << setw(3) << four << vertexColor[i][j];
				break;
			case 5:
				cout << setw(3) << five << vertexColor[i][j];
				break;
			default:
				cout << setw(3) << deff << vertexColor[i][j];
				break;
			}
		}
		cout << endl;
	}
}

bool isPerfect()
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

// Checking function
bool isAbsolut()
{
	// Declares two auxiliar data structures
	vector<bool> vertex(N,false);
	for (int i = 1; i < pow(2,N); i++)
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
		amount = accumulate(vertex.begin(),vertex.end(),amount);
		if(amount % 2 || amount == N || amount <= 2)
			continue;	

		vector<bool> acolor (N,false);
		bool absolute = false;
		for(int v = 0; v < N; v++){
			if(vertex[v]){
				for(int w = v+1; w < N; w++){
					if(vertex[w])
						acolor[table[v][w]] = true;
				}
			}
		}
		int Y = 0;
		Y = accumulate(acolor.begin(),acolor.end(),Y);
		if(Y == amount -1){
			// cout<<endl;
			// for(auto v: vertex)
			// 	cout<<v<<" ";
			// cout<<endl;
			// for(auto a: acolor)
			// 	cout<<a<<" ";
			// cout<<endl;
			return false;
		}
	}
	return true;
}

// Checking function
bool isBright()
{
	int n1, n2;
	int count = 0;
	int maxcount = count;
	int mincount = N;
	int pivot;
	for (int v = 0; v < N; v++)
		for (int w = v + 1; w < N; w++)
			for (int c = 1; c < N; c++)
				if (c != table[v][w])
				{
					pivot = vertexColor[v][c];
					count = 0;
					do
					{
						n1 = vertexColor[v][c];
						n2 = vertexColor[w][c];
						c = table[v][n2];
						count++;
					} while (n2 != pivot);
					maxcount = max(count, maxcount);
					mincount = min(count, mincount);
					if (count < N - 2)
					{
						// printLanterns(v,w);
						// print();
						// print2();
						// printf("%d %d\n",v,w);
						//cout<<count<<endl;
						return false;
					}
				}
	//cout<<"Bright found for N equals to "<<N<<endl;
	// cout<<"Largest lantern: "<<maxcount<<endl;
	// cout<<"Smallest lantern: "<<mincount<<endl;
	return true;
}

// Checking function
bool isMiserable()
{
	int n1, n2;
	int count = 0;
	int maxcount = count;
	int mincount = N;
	int pivot;
	for (int v = 0; v < N; v++)
		for (int w = v + 1; w < N; w++)
			for (int c = 1; c < N; c++)
				if (c != table[v][w])
				{
					pivot = vertexColor[v][c];
					count = 0;
					do
					{
						n1 = vertexColor[v][c];
						n2 = vertexColor[w][c];
						c = table[v][n2];
						count++;
					} while (n2 != pivot);
					maxcount = max(count, maxcount);
					// if(maxcount == 4)
					// 	cout<<v<<" "<<w<<endl;
					mincount = min(count, mincount);
					if (count >= N - 2)
					{
						// cout<<v<<" "<<w<<endl;
						return false;
					}
				}
	// cout<<mincount<<" "<<maxcount<<endl;
	// cout<<"Miserable found for N equals to "<<N<<endl;
	// cout << "Largest lantern: " << maxcount << endl;
	// cout << "Smallest lantern: " << mincount << endl;
	return true;
}

void countLanterns()
{
	int n1, n2;
	int count = 0;
	int maxcount = count;
	int mincount = N;
	int pivot;

	bool usedColor[N];
	for (int c = 1; c < N; c++)
		usedColor[c] = false;

	for (int v = 0; v < N; v++)
		for (int w = v + 1; w < N; w++)
		{
			for (int d = 1; d < N; d++)
				usedColor[d] = false;
			for (int c = 1; c < N; c++)
				if (c != table[v][w] && !usedColor[c])
				{
					usedColor[c] = true;
					pivot = vertexColor[v][c];
					count = 0;
					do
					{
						n1 = vertexColor[v][c];
						n2 = vertexColor[w][c];
						c = table[v][n2];
						usedColor[c] = true;
						count++;
					} while (n2 != pivot);
					maxcount = max(count, maxcount);
					mincount = min(count, mincount);
					lanterns[v][w]++;
					lanterns[w][v]++;
				}
		}
}

void printLanterns(int v, int w)
{

	int count = 0;
	int pivot;
	int n1, n2, n3;
	for (int c = 1; c < N; c++)
	{
		if (c != table[v][w])
		{
			pivot = vertexColor[v][c];
			count = 0;
			do
			{
				n1 = vertexColor[v][c];
				n2 = vertexColor[w][c];
				c = table[v][n2];
				count++;
			} while (n2 != pivot);
			if (count == 2 && n1 < n2)
			{
				cout << setw(5) << v << endl;
				print('/', table[v][n1], 5);
				print('\\', table[v][n2], 3);
				cout << endl;
				print(char(table[v][n1] + 64), table[v][n1], 4);
				print(char(table[v][n2] + 64), table[v][n2], 5);
				cout << endl;
				print('/', table[v][n1], 3);
				print('\\', table[v][n2], 7);
				cout << endl;
				cout << n1 << setw(8) << n2 << endl;
				print('\\', table[w][n1], 3);
				print('/', table[w][n2], 7);
				cout << endl;
				print(char(table[w][n1] + 64), table[w][n1], 4);
				print(char(table[w][n2] + 64), table[w][n2], 5);
				cout << endl;
				print('\\', table[w][n1], 5);
				print('/', table[w][n2], 3);
				cout << endl;
				cout << setw(5) << w << endl
					 << endl;
			}
			if (count == 3)
			{
				n1 = vertexColor[v][c];
				n3 = vertexColor[w][c];
				n2 = vertexColor[w][table[v][n3]];
				if (n1 < n2 && n1 < n3)
				{
					cout << setw(5) << v << endl;
					print('/', table[v][n1], 5);
					print('|', table[v][n2], 2);
					print('\\', table[v][n3], 2);
					cout << endl;
					print(char(table[v][n1] + 64), table[v][n1], 4);
					print(char(table[v][n2] + 64), table[v][n2], 3);
					print(char(table[v][n3] + 64), table[v][n3], 3);
					cout << endl;
					print('/', table[v][n1], 3);
					print('|', table[v][n2], 4);
					print('\\', table[v][n3], 4);
					cout << endl;
					cout << n1 << setw(4) << n2 << setw(4) << n3 << endl;
					print('\\', table[w][n1], 3);
					print('|', table[w][n2], 4);
					print('/', table[w][n3], 4);
					cout << endl;
					print(char(table[w][n1] + 64), table[w][n1], 4);
					print(char(table[w][n2] + 64), table[w][n2], 3);
					print(char(table[w][n3] + 64), table[w][n3], 3);
					cout << endl;
					print('\\', table[w][n1], 5);
					print('|', table[w][n2], 2);
					print('/', table[w][n3], 2);
					cout << endl;
					cout << setw(5) << w << endl
						 << endl;
				}
			}
		}
	}
	cout<<flush;
}

bool isSafe(int c, pair<int, int> aresta)
{
	if (
		vertexColor[aresta.first][c] == -1 &&
		vertexColor[aresta.second][c] == -1 &&
		table[aresta.first][aresta.second] == 0 &&
		table[aresta.second][aresta.first] == 0)
		return true;
	else
		return false;
}

void insertColor(int c, pair<int, int> aresta)
{
	contagem++;
	vertexColor[aresta.first][c] = aresta.second;
	vertexColor[aresta.second][c] = aresta.first;
	table[aresta.first][aresta.second] = c;
	table[aresta.second][aresta.first] = c;
	//if(contagem == arestas)
	//  print();
}

void deleteColor(int c, pair<int, int> aresta)
{
	contagem--;
	vertexColor[aresta.first][c] = -1;
	vertexColor[aresta.second][c] = -1;
	table[aresta.first][aresta.second] = 0;
	table[aresta.second][aresta.first] = 0;
}

pair<int, int> proxima(pair<int, int> aresta)
{
	aresta.second++;
	if (aresta.second == N)
	{
		aresta.second = aresta.first + 2;
		aresta.first++;
	}
	return aresta;
}

// Brute force function
bool buildRandom(pair<int, int> aresta)
{
	if (contagem == arestas)
	{
		//if(isPerfect())
		//print();
		//if(isBright() && !isPerfect())
		return true;
	}

	vector<int> cor(N - 1, 0);
	for (int c = 1; c < N; c++)
		cor[c - 1] = c;

	// random_shuffle(cor.begin(), cor.end());

	for (int c = 0; c < N - 1; c++)
		if (isSafe(cor[c], aresta))
		{
			insertColor(cor[c], aresta);
			if (buildRandom(proxima(aresta)))
				return true;
			deleteColor(cor[c], aresta);
		}
	return false;
}

// Brute force function
bool buildMiserable(pair<int, int> aresta)
{
	if (contagem == arestas)
	{
		//if(isPerfect())
		//print();
		//if(isBright() && !isPerfect())
		if (isMiserable())
			return true;
	}

	for (int c = 1; c < N; c++)
		if (isSafe(c, aresta))
		{
			insertColor(c, aresta);
			if (buildMiserable(proxima(aresta)))
				return true;
			deleteColor(c, aresta);
		}
	return false;
}

void Canonical()
{
	int n = N / 2;
	int a, b;
	for (int i = 1; i <= N - 1; i++)
	{
		a = i % (2 * n - 1);
		b = 2 * n - 1;
		table[a][b] = i;
		table[b][a] = i;
		vertexColor[a][table[a][b]] = b;
		vertexColor[b][table[b][a]] = a;
		for (int k = 1; k <= n - 1; k++)
		{
			a = (i + k) % (2 * n - 1);
			b = (2 * n - 1 + (i - k) % (2 * n - 1)) % (2 * n - 1);

			table[a][b] = i;
			table[b][a] = i;
			vertexColor[a][table[a][b]] = b;
			vertexColor[b][table[b][a]] = a;
		}
	}
}

void Circle()
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

void makeList()
{
	cout << "N \t Bri? \t Mis? \t Per?" << endl;
	for (N = 4; N <= 1024; N += 2)
	{
		cout << N << " \t ";
		start();
		Canonical();
		if (isBright())
			cout << "Yes \t ";
		else
			cout << "No \t ";

		if (isMiserable())
			cout << "Yes \t ";
		else
			cout << "No \t ";

		if (isPerfect())
			cout << "Yes \t ";
		else
			cout << "No \t ";
		cout << endl;
	}
	exit(0);
}

int convertToInteger(char c){
	switch(c){
		case '0':
		case '1':
		case '2':
		case '3':
		case '4':
		case '5':
		case '6':
		case '7':
		case '8':
		case '9':
			return c - '0';
		break;

		case 'A':
		case 'B':
		case 'C':
		case 'D':
		case 'E':
		case 'F':
		case 'G':
			return c - 'A' + 10;
		break;

		default:
			return 0;
	}
}

int main(int argc, char* argv[])
{
	// Circle();
	// print();
	// print2();
	// print3();
	// return 0;

	int F;
	string factor;
	ifstream arquivo;
	if(argc > 1)
		arquivo.open(argv[1]);
	else
		cout<<"Need input file"<<endl;
	arquivo >> N >> F;
	int ca = 0;
	int cm = 0;
	int cp = 0;
	int cb = 0;

	vector<int> va,vm,vp,vb,boring;

	for (int i = 0; i < F; i++)
	{
		for(int j = 0; j < N-1; j++){
			int v,w,c;
			for(int k = 0; k < N; k+=2){
				arquivo>>factor;
				// cout<<factor<<endl;
				v = convertToInteger(factor[0]);
				w = convertToInteger(factor[1]);
				// printf("%d%d ",v,w);
				// cout<<" ";
				c = j+1;
				table[v][w] = c;
				table[w][v] = c;
				vertexColor[v][c] = w;
				vertexColor[w][c] = v;
			}
		}
		// cout<<endl;
		// print();
		// print2();
		
		bool a = isAbsolut();
		bool m = isMiserable();
		bool p = isPerfect();
		bool b = isBright();

		ca+=a;
		cm+=m;
		cp+=p;
		cb+=b;

		if(a) va.push_back(i+1);
		if(m) vm.push_back(i+1);
		if(p) vp.push_back(i+1);
		if(b) vb.push_back(i+1);

		if(!(a || m || p || b)) //boring.push_back(i+1);
			cout <<"Factorization "<<i+1<<" is boring"<<endl;
		if(m && p && b)
			cout <<"Factorization "<<i+1<<" is miserable, perfect and bright"<<endl;
		if(p && b && a)
			cout <<"Factorization "<<i+1<<" is absolute, perfect and bright"<<endl;
		else if(m && p)
			cout <<"Factorization "<<i+1<<" is miserable and perfect"<<endl;
		else if(m && b)
			cout <<"Factorization "<<i+1<<" is miserable and bright"<<endl;
		else if(p && b)
			cout <<"Factorization "<<i+1<<" is perfect and bright"<<endl;
		else if(p && a)
			cout <<"Factorization "<<i+1<<" is perfect and absolute"<<endl;
		else if(m)
			cout <<"Factorization "<<i+1<<" is miserable"<<endl;
		else if(p)
			cout <<"Factorization "<<i+1<<" is perfect"<<endl;
		else if(b )
			cout <<"Factorization "<<i+1<<" is bright"<<endl;
		else 
			if(a)
				cout <<"Factorization "<<i+1<<" is absolute"<<endl;
	}
	// cout<<"Absolut = "<<ca<<" ( ";
	// for(int i=0; i < va.size(); i++){
	// 	cout<<va[i]<<" ";
	// 	if(i < va.size()-1)
	// 		cout<<", ";
	// }
	// cout<<")"<<endl;

	// cout<<"Bright = "<<cb<<" ( ";
	// for(int i=0; i < vb.size(); i++){
	// 	cout<<vb[i]<<" ";
	// 	if(i < vb.size()-1)
	// 		cout<<", ";
	// }
	// cout<<")"<<endl;

	// cout<<"Miserable = "<<cm<<" ( ";
	// for(int i=0; i < vm.size(); i++){
	// 	cout<<vm[i]<<" ";
	// 	if(i < vm.size()-1)
	// 		cout<<", ";
	// }
	// cout<<")"<<endl;

	// cout<<"Perfect = "<<cp<<" ( ";
	// for(int i=0; i < vp.size(); i++){
	// 	cout<<vp[i]<<" ";
	// 	if(i < vp.size()-1)
	// 		cout<<", ";
	// }
	// cout<<")"<<endl;

	// cout<<"Boring = "<<boring.size()<<" ( ";
	// for(int i=0; i < boring.size(); i++){
	// 	cout<<boring[i]<<" ";
	// 	if(i < boring.size()-1)
	// 		cout<<", ";
	// }
	// cout<<")"<<endl;

	return 0;

	Circle();
	cout << __LINE__ << endl;

	cout << __LINE__ << endl;
	if (isBright())
		cout << "isBright" << endl;
	else
		cout << "Not" << endl;
	cout << __LINE__ << endl;
	isMiserable();
	cout << __LINE__ << endl;

	printFactorizationsICD();

	char answer;
	int format;
	int v, w;
	cout << red << "\nLes Miserables!\n"
		 << deff;
	cout << "Tell me the number of vertices: ";
	cin >> N;
	std::srand(unsigned(std::time(0)));
	start();
	pair<int, int> aresta(0, 1);

	if (buildRandom(aresta))
	{
		// if(buildMiserable(aresta)){
		if (isPerfect())
		{
			cout << magenta << "\e[1;4m-->This factorization is also perfect<--\e[0m" << deff << endl;
		}
		else
			cout << nine << "\e[1;4m-->This factorization is NOT perfect<--\e[0m" << deff << endl;

		cout << endl;
		cout << "Choose your output format: \n";
		cout << green << "1 - W.D. Wallis, Introduction to Combinatorial Designs." << endl;
		cout << blue << "2 - Charles J. Colbourn and Jeffrey H. Dinitz, Handbook of Combinatorial Designs." << deff << endl;
		cout << "Choose wisely ("
			 << green << 1 << deff << "/"
			 << blue << 2 << deff << "): ";
		cin >> format;
		if (format == 1)
			printFactorizationsICD();
		else
			printFactorizationsHCD();
		cout << endl;
	}
	else
	{
		cout << "Fail " << N << endl;
		print();
	}

	cout << "Do you want to print some lanterns (Y/N)? ";
	cin >> answer;

	if (answer == 'Y' || answer == 'y')
	{
		cout << nine << "Take a look at the table below to see how many lanterns there are between two vertices." << deff << endl;
		countLanterns();
		printLanterns();
		do
		{
			cout << "\nGive me the first vertex (-1 to exit): ";
			cin >> v;
			if (v == -1)
				break;
			cout << "Now give me the second vertex (-1 to exit): ";
			cin >> w;
			if (w == -1)
				break;
			if (v == w || v < 0 || w < 0 || v >= N || w > N)
				cout << red << "\nThe first and second vertices must be different and range between 0 and " << N - 1 << ". Please, try again!\n"
					 << deff << endl;
			else
			{
				cout << "Printing some lanterns... " << endl;
				printLanterns(v, w);
			}
		} while (true);
	}
	cout << "Bye... \n";
	return 0;
}