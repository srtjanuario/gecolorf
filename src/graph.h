#ifndef GECOLORF_GRAPH_H
#define GECOLORF_GRAPH_H


#include <vector>
#include <numeric>
#include <iostream>
using namespace std;

class Graph{
	public:
		Graph(int n);	
		void Circle();

		bool isPerfect();
		bool isAbsolute();

		void toHex();

		int getN(){return N;};
		void setN(int n){N=n;};

	private:
		int N;
		int arestas;
		

	vector< vector<int> > table;
	vector< vector<int> > vertexColor;
	vector< vector<int> > lanterns;

};

#endif