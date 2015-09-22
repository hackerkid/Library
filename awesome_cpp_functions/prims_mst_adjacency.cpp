#include <queue>
#include <iostream>
#include <utility>
#include <limits.h>
#include <fstream>
#define ii pair <int, int>
#define pii pair <int, ii>
using namespace std;

int main()
{

	int distance_matrix[100][100];
	int ans[100][100];
	int already_visited[100];

	

	priority_queue  < pair<int, ii>,	vector <pair < int, ii> >, greater <pair < int, ii> > > prims_prio_q;

	int number_nodes;
	int number_edges;

	int node_1;
	int node_2;
	int temp_weight;

	int final_distance = 0;
	
	pair <int, ii> pair_temp;


	cin >> number_nodes;
	cin >> number_edges;
	for (int i = 0; i < number_nodes; i++) {
		already_visited[i] = -1;
	}

	for (int i = 0; i < number_nodes; i++) {
		for (int j = 0; j < number_nodes; j++) {
			distance_matrix[i][j] = INT_MAX;
			ans[i][j] = INT_MAX;
		}

	}

	for (int i = 0; i <  number_edges; i++) {
		cin >> node_1;
		cin >> node_2;
		cin >> temp_weight;

		distance_matrix[node_1][node_2] = temp_weight;
		distance_matrix[node_2][node_1] = temp_weight;
	}
	
	already_visited[0] = 1;

	for (int i = 0; i < number_nodes; i++) {
		prims_prio_q.push(pii (distance_matrix[0][i],(ii ( 0, i))));
	}

	for (int j = 1; j < number_nodes; j++) {

		do
		{
			pair_temp = prims_prio_q.top();
			prims_prio_q.pop();
			temp_weight = pair_temp.first;
			node_1 = pair_temp.second.first;
			node_2 = pair_temp.second.second;

		} while(already_visited[node_1] != -1 and already_visited[node_2] != -1 and !prims_prio_q.empty());
		ans[node_1][node_2] = temp_weight;
		final_distance += temp_weight;

		if(already_visited[node_1] == -1) {
			for (int i = 0; i < number_nodes; i++) {
				prims_prio_q.push(pii(distance_matrix[node_1][i], ii(node_1, i)));
				already_visited[node_1] = 1;
			}

		}

		else {
			for (int i = 0; i < number_nodes; i++) {
				prims_prio_q.push(pii(distance_matrix[node_2][i], ii(node_2, i)));
				already_visited[node_2] = 1;
			}

		}


	}

	cout << final_distance << endl;

	cout << endl << endl;
	for (int i = 0; i < number_nodes; i++) {
		for (int j = 0; j < number_nodes; j++) {
			if(ans[i][j] != INT_MAX) {
				cout << ans[i][j]<< " ";
			}

			else {
				cout << "INF"<<" ";
			}

		}

		cout << endl;
	}



}

