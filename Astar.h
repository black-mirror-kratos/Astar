#pragma once
#include <iostream>
#include <queue>
#include <vector>
#include <functional>

using namespace std;

#define PII pair<int,int>
#define MP make_pair
#define fcin freopen("std.in","r",stdin)
#define fcout freopen("std.out","w",stdout)

int dof = 4;
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
int N;
int M;
vector<vector<bool> > checkpoints;
vector<vector<PII> > parent;
vector<vector<char>> display;
//int visitedNodes = 0;


//--------------------------------------------------------------------------------------------------------------------
double H(PII a, PII b) {
	int deltaX = abs(a.first - b.first);
	int deltaY = abs(a.second - b.second);
	//return deltaX + deltaY;
	return sqrt(deltaX*deltaX + deltaY*deltaY);
}
bool isFeasible(PII loc) {
	if (loc.first < 0 || loc.first >= N || loc.second < 0 || loc.second >= M)
		return false;
	return true;
}
void visit(PII loc) {
	checkpoints[loc.first][loc.second] = true;
	display[loc.first][loc.second] = 'o';
	//visitedNodes++;
	//cout << "visited it *" << checkpoints[loc.first][loc.second] << "* " << checkpoints[loc.first][loc.second] << endl;
}
bool isVisited(PII loc) {
	return checkpoints[loc.first][loc.second];
}
void parentize(PII loc, PII father) {
	parent[loc.first][loc.second] = father;
}
class Compare
{
public:
	bool operator()(pair<pair<double, int>, pair<PII, double> > n1, pair<pair<double, int>, pair<PII, double> > n2) {
		if (n1.first.first != n2.first.first)
			return n1.first.first > n2.first.first;
		return n1.first.second < n2.first.second;
	}
};
//---------------------------------------------------------------------------------------------------------------------------


double Astar(vector<vector<char> > &v, PII start, PII end) {
	priority_queue<pair<pair<double, int>, pair<PII, double> >, vector<pair<pair<double, int>, pair<PII, double>>>, Compare> pq;
	double G = 0.0;
	int index = 0;
	double huristicParameter = G + H(start, end);
	pq.push(MP(MP(huristicParameter, index), MP(start, G)));
	visit(start);

	while (!pq.empty()) {
		PII curEnding = pq.top().second.first;
		double curG = pq.top().second.second;
		int curIndex = pq.top().first.second;
		pair<double, int> test = pq.top().first;
		//cout << curIndex << endl;
		//cout <<"from queue : "<< curEnding.first << "," << curEnding.second <<", "<< pq.top().first.first<< endl;
		if (curEnding.first == end.first && curEnding.second == end.second) { cout << "finished! *" << end.first << "," << end.second << "* " << endl; return curG; }
		pq.pop();

		for (int i = 0; i < dof; i++) {
			int newX = curEnding.first + dx[i];
			int newY = curEnding.second + dy[i];
			PII newEnding = MP(newX, newY);
			//cout << "newEnding : " << newEnding.first << "," << newEnding.second << endl;
			if (isFeasible(newEnding) && v[newX][newY] != '#' && !isVisited(newEnding)) {
				visit(newEnding);
				parentize(newEnding, curEnding);
				//cout << "newEnding went through : " << newEnding.first << "," << newEnding.second << endl;
				double newG = curG + 0.7*1.0;
				//cout << newG << endl;
				double newHuristicParameter = newG + H(newEnding, end);
				int newIndex = curIndex + 1;
				pq.push(MP(MP(newHuristicParameter, newIndex), MP(newEnding, newG)));
			}

		}
	}
	return INT_MAX;
}


void printChain(vector<vector<char>> &v, vector<vector<PII>> &parent, PII end) {
	PII iter = end;
	while (iter != MP(0, 0)) {
		display[iter.first][iter.second] = '+';
		iter = parent[iter.first][iter.second];
	}

	/*for (int i = 0; i < N; i++) {
	for (int j = 0; j < M; j++) {
	cout << parent[i][j].first << "," << parent[i][j].second << " ";
	}
	cout << endl;
	}*/

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << display[i][j] << " ";
		}
		cout << endl;
	}
}