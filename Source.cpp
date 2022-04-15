#include <iostream>
#include <fstream>
#include <queue>
#include <stack>

using namespace std;

ifstream fin("date.in");

typedef pair<int, int> intPair;

const int INF = 1000;

void Dijkstra(int srs, int nrVf, vector<vector<intPair>>& lAdj, vector<int>& dist, vector<int>& parinte) {
	priority_queue<intPair, vector<intPair>, greater<intPair>> q;
	parinte = vector<int>(nrVf, -1);
	dist = vector<int>(nrVf, INF);
	dist[srs] = 0;

	q.push(make_pair(srs, 0));
	while (!q.empty()) {
		int curent = q.top().first;
		int distCurent = q.top().second;
		q.pop();
		for (auto& muchie : lAdj[curent]) {
			int dest = muchie.first;
			int pondere = muchie.second;
			if (dist[curent] + pondere < dist[dest]) {
				dist[dest] = dist[curent] + pondere;
				parinte[dest] = curent;
				q.push(make_pair(dest, dist[dest]));
			}
		}
	}
}

int main()
{
	int nrVf{ 0 }, nrM{ 0 }, srs{ 0 };
	fin >> nrVf >> nrM >> srs;
	vector<vector<intPair>> lAdj(nrVf);

	while (nrM) {
		int x, y, pond;
		fin >> x >> y >> pond;
		lAdj[x].push_back(make_pair(y, pond));
		nrM--;
	}

	vector<int> dist, parinte;

	Dijkstra(srs, nrVf, lAdj, dist, parinte);

	for (int i = 0; i < nrVf; ++i) {
		if (dist[i] == INF)
			cout << "INF ";
		else cout << dist[i] << " ";
	}

	return 0;
}