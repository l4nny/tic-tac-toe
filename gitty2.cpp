#include<iostream>
#include<vector>
using namespace std;
#define MAX_ELEMENTS 100005
int n = 0;
int arr[MAX_ELEMENTS];
int index = 0;
vector<int> parent;
vector<int> cap;
vector<long long> sum;
int find(int x) {
	if (x != parent[x]) parent[x] = find(parent[x]);
	return parent[x];
}

void Func_union(int x, int y) {
	int rootX = find(x);
	int rootY = find(y);

	if (rootX != rootY) {
		parent[y] = rootX;
		parent[rootY] = rootX;
		cap[rootX] += cap[rootY];
		sum[rootX] += sum[rootY];
	}
}

void Func_move(int x, int y) {
	int rootX = find(x);
	int rootY = find(y);

	if (rootX != rootY) {
		parent[x] = rootY;
		cap[rootY]++;
		cap[rootX]--;
		sum[rootY] += x;
		sum[rootX] -= x;
	}
}

void result(int x) {
	int root = find(x);
	cout << cap[root] << " " << sum[root]<<'\n';
}
int main() {
	int n,m,command,p,q;
	cin >> n >> m;
	parent.resize(n + 1);
	cap.resize(n + 1, 1);
	sum.resize(n + 1, 0);
	for (int i = 1; i <= n; i++) {
		parent[i] = i;
		sum[i] = i;
	}
	while (m--) {
		cin >> command;
		if (command == 1) {
			cin >> p >> q;
			Func_union(p, q);
		}
		else if (command == 2) {
			cin >> p >> q;
			Func_move(p, q);
		}
		else if (command == 3) {
			cin >> p;
			result(p);
		}
	}
	
/*
5 7
1 1 2
1 1 3
1 4 5
2 2 4
2 3 4
3 1
3 2

*/
