#include<iostream>
#include<vector>
using namespace std;
void DFS(const vector<vector<int>>& graph, vector<bool>& visited, int node) {
	visited[node] = true;

	for (int i = 0; i < graph.size(); i++) {
		if (graph[node][i] == 1 && !visited[i]) DFS(graph, visited, i);
	}

}

int Connect(const vector<vector<int>>& graph) {
	int numNodes = graph.size();
	vector <bool> visited(numNodes, false);
	DFS(graph, visited, 0);
	for (bool isVisited : visited) {
		if (!isVisited) {
			return -1;
		}
	}
	return 1;
}
int main(){
	int n;
	cin >> n;
	vector<vector<int>> graph(n, vector<int>(n, 0));
	int i=0, j=0;
	for (i; i < n; i++) {
		for (j=0; j < n; j++) {
			cin >> graph[i][j];
		}
	}
	int answer = Connect(graph);
	cout << answer << '\n';
}

/*
 0 1 2 3 4
0
1
2
3
4
*/