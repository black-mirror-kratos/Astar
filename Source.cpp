#include <iostream>
#include <queue>
#include <vector>
#include <functional>
#include "Astar.h"

using namespace std;

#define PII pair<int,int>
#define MP make_pair
#define fcin freopen("std.in","r",stdin)
#define fcout freopen("std.out","w",stdout)


int main() {
	fcin;
	fcout;
	vector<vector<char> > v;
	cin >> N >> M;
	v.resize(N);
	checkpoints.resize(N);
	parent.resize(N);
	for (int i = 0; i < N; i++) {
		v[i].resize(M);
		checkpoints[i].resize(M);
		parent[i].resize(M);
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> v[i][j];
			checkpoints[i][j] = false;
			parent[i][j] = MP(0, 0);
		}
	}
	cout << N << "," << M << endl;
	display = v;
	cout << Astar(v, MP(0, 0), MP(N - 1, M - 1)) << endl;
	printChain(v, parent,MP(N - 1, M - 1));
	//cout << visitedNodes;
}