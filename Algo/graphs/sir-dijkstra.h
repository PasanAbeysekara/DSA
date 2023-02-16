#pragma once
#include<iostream>
#include <fstream>
#include <queue> 
#include <vector> 
#include <map>  

using namespace std;

class WGraph
{
	int** adjM; 
	int nV;
public:
	void readGraph(string path);
	void Dijkstra(int v);
};

void WGraph::readGraph(string path)
{
	ifstream fin(path);
	int nv, ne;  
	fin >> nv >> ne;
	nV = nv;

	adjM = new int* [nV];

	for (int i = 0; i < nV; i++)  
	{
		adjM[i] = new int[nV];
	}

	for (int i = 0; i < nV; i++)
		for (int j = 0; j < nV; j++)
			adjM[i][j] = -1;
		
	int v1, v2, w;

	for (int i = 0; i < ne; i++)
	{
		fin >> v1 >> v2 >> w;
		adjM[v1][v2] = w;
		adjM[v2][v1] = w;  //Undirected  
	}
}

void WGraph::Dijkstra(int v)
{
	typedef pair<int, int> qn;
	priority_queue<qn, vector<qn>, greater<qn>> Q;  
	map<int, bool> inQueue; 
	map<int, int> dist;  
	map<int, int> prev;  

	for (int i = 0; i < nV; i++)
	{
		inQueue[i] = false;  
		dist[i] = INT_MAX; 
		prev[i] = -1;
	}

	// initialize starting vertex
	Q.push(make_pair(0, v)); 
	inQueue[v] = true;
	dist[v] = 0;

	while (!Q.empty())
	{
		int nv = Q.top().second;
		int nD = Q.top().first; 
		Q.pop();

		for (int i = 0; i < nV; i++)			
		{
			if (adjM[nv][i] >= 0)		//There is an edge	
			{
				int d = nD + adjM[nv][i]; 

				if (inQueue[i] == false)  
				{
					dist[i] = d;
					inQueue[i] = true;
					prev[i] = nv;
					Q.push(make_pair(d, i));
				}

				else if (d < dist[i])
				{
					dist[i] = d;
					prev[i] = nv;
					Q.push(make_pair(d, i));
				}

			}
		}
	}

	for (int i = 1; i < nV; i++)
		cout << i << "--> (" << dist[i] << "," << prev[i] << ")"<<endl;
}
