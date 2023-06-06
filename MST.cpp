/*
 * MST.cpp
 *
 *  Created on: Jun 5, 2023
 *      Author: Dinithi Liyanage
 */

/*
 * SSSP.cpp
 *
 *  Created on: Jun 1, 2023
 *      Author: Dinithi Liyanage
 */

#include <iostream>
#include <vector>
#include<limits>
using namespace std;

//Find the next index with the minimum distance
int minDistance(vector<int> distance, vector<bool> visited){
	int min = INT_MAX;
	int min_index;
	for(int  i=0; i<6; i++){
		if(distance[i] <= min && visited[i] == false){
			min = distance[i];
			min_index = i;
		}
	}
	return min_index;
}

//Return the parents of each node from a selected source node
vector<int> Prim(int source, vector<vector<int>> adj){
	vector<bool> visited(6, false);
	vector<int> distance(6, numeric_limits<int>::max());
	vector<int> parent(6);
	distance[source] = 0;
	int vertex = source;
	while(visited[vertex] == false){
		for(int i =0; i<6; i++){
			if(adj[vertex][i] < distance[i] && visited[i] == false && adj[vertex][i] >0){
				distance[i] = adj[vertex][i];
				parent[i] = vertex;
				//Update parent
			}
		}
		visited[vertex] = true;
		vertex = minDistance(distance, visited);
	}
	return parent;
}

int main(){
	vector<vector<int>> adj = {
	{0, 3,  0, 0, 0,  1},
	{3, 0,  2, 1, 10, 0},
	{0, 2,  0, 3, 0,  10},
	{0, 1,  3, 0, 5,  0},
	{0, 10, 0, 5, 0,  4},
	{1, 0,  5, 0, 4,  0}};

	vector<int> Parent = Prim(0, adj);


	//Find the total cost of each edge in the MST
	int cost = 0;
	for(int i=0; i<6; i++){
		if(adj[i][Parent[i]] > 0){
			cout << Parent[i] << " - " << i << " \t"<< adj[i][Parent[i]] << " \n";
			cost += adj[i][Parent[i]];
		}
	}
	cout<<"Minimum Spanning tree cost:"<<cost<<endl;
	return 0;
}





