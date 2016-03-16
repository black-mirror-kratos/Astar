//#pragma once
//#include <iostream>
//#include <queue>
//#include <vector>
//#include <functional>
//
//using namespace std;
//
//#define PII pair<int,int>
//#define MP make_pair
//#define fcin freopen("std.in","r",stdin)
//#define fcout freopen("std.out","w",stdout)
//
//int dof = 4;
//int dx[4] = { 1, -1, 0, 0 };
//int dy[4] = { 0, 0, 1, -1 };
//int N;
//int M;
//vector<vector<vector<int>>> checkpoints;
//vector<vector<PII> > parent;
//vector<vector<char>> display;
////int visitedNodes = 0;
//
//
////--------------------------------------------------------------------------------------------------------------------
//PII searchMAT(vector<vector<int> > &a, int val) {
//	int r = N;
//	int c = M;
//	for (int i = 0; i < r; i++) {
//		for (int j = 0; j < c; j++) {
//			if (a[i][j] == val) return MP(i, j);
//		}
//	}
//	cout << "fault in MatrixCompare Search" << endl;
//	return MP(-1, -1);
//}
//double H(vector<vector<int> > &a, vector<vector<int> > &b) {
//	double dist = 0.0;
//	int r = N;
//	int c = M;
//	for (int i = 0; i < r; i++) {
//		for (int j = 0; j < c; j++) {
//			PII locB = searchMAT(b, a[i][j]);
//			int deltaX = abs(i - locB.first);
//			int deltaY = abs(j - locB.second);
//			dist += deltaX + deltaY + 0.0;
//		}
//	}
//	return dist;
//}
//
//bool isFeasible(PII loc) {
//	if (loc.first < 0 || loc.first >= N || loc.second < 0 || loc.second >= M)
//		return false;
//	return true;
//}
//void visit(vector<vector<int> > &loc) {
//	checkpoints.push_back(loc);
//	//display[loc.first][loc.second] = 'o';
//	//visitedNodes++;
//	//cout << "visited it *" << checkpoints[loc.first][loc.second] << "* " << checkpoints[loc.first][loc.second] << endl;
//}
//bool isVisited(vector<vector<int> > &loc) {
//	for (auto i : checkpoints) {
//		if (i == loc) return true;
//	}
//	return false;
//}
//void parentize(PII loc, PII father) {
//	parent[loc.first][loc.second] = father;
//}
//
//PII findTracker(vector<vector<int>> &a) {
//	int r = N;
//	int c = M;
//	for (int i = 0; i < r; i++) {
//		for (int j = 0; j < c; j++) {
//			if (a[i][j] == 0) return MP(i, j);
//		}
//	}
//}
//bool isEqual(vector<vector<int>> &a, vector<vector<int>> &b) {
//	if (H(a, b) == 0.0) return true;
//	return false;
//}
//class Compare
//{
//public:
//	bool operator()(pair<pair<double, int>, pair<vector<vector<int> >, double> > n1, pair<pair<double, int>, pair<vector<vector<int> >, double> > n2) {
//		if (n1.first.first != n2.first.first)
//			return n1.first.first > n2.first.first;
//		return n1.first.second < n2.first.second;
//	}
//};
//
//void printMat(vector<vector<int>> &a) {
//	int r = N;
//	int c = M;
//	for (int i = 0; i < r; i++) {
//		for (int j = 0; j < c; j++) {
//			cout << a[i][j] << " ";
//		}
//		cout << endl;
//	}
//}
////---------------------------------------------------------------------------------------------------------------------------
//
//
//double Astar(vector<vector<int> > &v, vector<vector<int> > &start, vector<vector<int> > &end) {
//	priority_queue<pair<pair<double, int>, pair<vector<vector<int> >, double> >, vector<pair<pair<double, int>, pair<vector<vector<int> >, double>>>, Compare> pq;
//	double G = 0.0;
//	int index = 0;
//	double huristicParameter = G + H(start, end);
//	pq.push(MP(MP(huristicParameter, index), MP(start, G)));
//	visit(start);
//
//	while (!pq.empty()) {
//		vector<vector<int> > curEnding = pq.top().second.first;
//		PII curTracker = findTracker(curEnding);
//		double curG = pq.top().second.second;
//		int curIndex = pq.top().first.second;
//		//pair<double, int> test = pq.top().first;
//		//cout << curIndex << endl;
//		//cout <<"from queue : "<< curEnding.first << "," << curEnding.second <<", "<< pq.top().first.first<< endl;
//		if (isEqual(curEnding, end)) { cout << "finished! *"; printMat(curEnding); return curG/0.1; }
//		pq.pop();
//
//		for (int i = 0; i < dof; i++) {
//			int newX = curTracker.first + dx[i];
//			int newY = curTracker.second + dy[i];
//			PII newTracker = MP(newX, newY);
//			vector<vector<int> > newEnding = curEnding;
//			//cout << "newEnding : " << newEnding.first << "," << newEnding.second << endl;
//			if (isFeasible(newTracker)) {
//				swap(newEnding[newX][newY], newEnding[curTracker.first][curTracker.second]);
//				if (!isVisited(newEnding)) {
//					visit(newEnding);
//					//parentize(newEnding, curEnding);
//					//cout << "newEnding went through : " << newEnding.first << "," << newEnding.second << endl;
//					double newG = curG + 0.1*1.0;
//					//cout << newG << endl;
//					double newHuristicParameter = newG + H(newEnding, end);
//					int newIndex = curIndex + 1;
//					pq.push(MP(MP(newHuristicParameter, newIndex), MP(newEnding, newG)));
//				}
//			}
//
//		}
//	}
//	return INT_MAX;
//}
//
//
//void printChain(vector<vector<char>> &v, vector<vector<PII>> &parent, PII end) {
//	PII iter = end;
//	while (iter != MP(0, 0)) {
//		display[iter.first][iter.second] = '+';
//		iter = parent[iter.first][iter.second];
//	}
//
//	/*for (int i = 0; i < N; i++) {
//	for (int j = 0; j < M; j++) {
//	cout << parent[i][j].first << "," << parent[i][j].second << " ";
//	}
//	cout << endl;
//	}*/
//
//	for (int i = 0; i < N; i++) {
//		for (int j = 0; j < M; j++) {
//			cout << display[i][j] << " ";
//		}
//		cout << endl;
//	}
//}