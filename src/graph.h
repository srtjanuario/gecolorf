#ifndef GECOLORF_GRAPH_H
#define GECOLORF_GRAPH_H


#include <vector>
#include <numeric>
using namespace std;

class Graph{
	public:
		Graph();	
		void Circle();
		bool isPerfect();
		bool isAbsolute();
	private:
		int N;
		int arestas;

	vector< vector<int> > table;
	vector< vector<int> > vertexColor;
	vector< vector<int> > lanterns;

	
};

#endif