#include <iostream>
#include <queue>
#include <vector>
#include <utility>
#include <limits.h>
#include <fstream>

using namespace std;

#define ii pair<int, int>

int dijkstra(vector < vector <pair <int, int > > > adj_list, int n, int start_node){
	
	pair <int, int> temp;
	vector <int> distance_list(n+1, INT_MAX);
	priority_queue < ii, vector <ii>, greater <ii> > q;
	int bro;
	temp.first = 0;
	temp.second = start_node;
	ii top;
	q.push(temp);
	int distance;
	int index;
	int d;
	int j;
	distance_list[start_node] = 0;
	while (!q.empty()) {
		top = q.top();
		q.pop();

		index = top.second;
		distance = top.first;

		if(distance == distance_list[index]) {
			for (int i = 0; i < adj_list[index].size(); i++) {
				temp = adj_list[index][i];
				d = temp.first;
				j = temp.second;
				
				if(distance + d < distance_list[j]) {
					distance_list[j] = distance + d;
					q.push(ii(distance_list[j], j));
				}


			}


		}


	}

	return distance_list[n];

}
