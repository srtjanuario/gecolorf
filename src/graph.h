#ifndef GECOLORF_GRAPH_H
#define GECOLORF_GRAPH_H

#include <vector>
using namespace std;

class Graph{
	public:
		Graph();	
	private:
		int nVertices;

	vector< vector<int> > table;
	vector< vector<int> > vertexColor;
	vector< vector<int> > lanterns;
};

#endif