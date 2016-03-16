//#include <iostream>
//#include <queue>
//#include <vector>
//#include <functional>
//#include "Astar15puzzle.h"
//
//using namespace std;
//
//#define PII pair<int,int>
//#define MP make_pair
//#define fcin freopen("std.in","r",stdin)
//#define fcout freopen("std.out","w",stdout)
//
//
//int main() {
//	fcin;
//	fcout;
//	vector<vector<int> > initialConfig;
//	vector<vector<int> > finalConfig;
//	vector<vector<int> > v;
//	cin >> N >> M;
//	v.resize(N);
//	finalConfig.resize(N);
//	//checkpoints.resize(N);
//	//parent.resize(N);
//	for (int i = 0; i < N; i++) {
//		v[i].resize(M);
//		finalConfig[i].resize(M);
//		//checkpoints[i].resize(M);
//		//parent[i].resize(M);
//	}
//	int time = 1;
//	for (int i = 0; i < N; i++) {
//		for (int j = 0; j < M; j++) {
//			cin >> v[i][j];
//			//checkpoints[i][j] = v[i][j];
//			finalConfig[i][j] = time%(N*M);
//			time++;
//			//parent[i][j] = MP(0, 0);
//		}
//	}
//	cout << N << "," << M << endl;
//	//display = v;
//	initialConfig = v;
//	cout << Astar(v, initialConfig, finalConfig) << endl;
//	//printChain(v, parent, MP(N - 1, M - 1));
//	//cout << visitedNodes;
//	return 0;
//}