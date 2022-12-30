#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <map>
#define MAX 10005
using namespace std;
const int INF = 1e9 + 7;

vector< pair<int, int> > graphS[MAX], graphT[MAX];
int distS[MAX], distT[MAX];

void Dijkstra(int s, int dist[], vector< pair<int, int> > (&graph)[MAX]) {
    priority_queue<pair<int, int>, vector< pair<int, int> >, greater< pair<int, int> > > pq;
    pq.push(make_pair(0, s));
    dist[s] = 0;

    while (!pq.empty()) {
        pair<int, int> top = pq.top();
        pq.pop();

        int u = top.second;
        int w = top.first;

        if (w > dist[u]) {
            continue;
        }

        for (pair<int, int> &neighbor : graph[u]) {
            if (w + neighbor.first < dist[neighbor.second]) {
                dist[neighbor.second] = w + neighbor.first;
                pq.push(make_pair(dist[neighbor.second], neighbor.second));
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T, n, m, k, s, t, u, v, d;
    cin >> T;
    assert( T >= 1 && T <= 20);
    while (T--) {
        cin >> n >> m >> k >> s >> t;
        assert( n >= 1 && n <= 10000);
        assert( m >= 1 && m <= 100000);
        assert( k >= 1 && k < 300);
        assert( s >= 1 && s <= n);
        assert( t >= 1 && t <= n);


        for (int i = 1; i <= n; i++) {
            graphS[i].clear();
            graphT[i].clear();
            distS[i] = INF;
            distT[i] = INF;
        }

        for (int i = 0; i < m; i++) {
            cin >> u >> v >> d;
            assert( u >= 1 && u <= n);
            assert( v >= 1 && v <= n);
            assert( d >= 1 && d <= 1000);

            graphS[u].push_back(make_pair(d, v));
            graphT[v].push_back(make_pair(d, u));
        }

        Dijkstra(s, distS, graphS);
        Dijkstra(t, distT, graphT);
        int res = distS[t];

        for (int i = 0; i < k; i++) {
            cin >> u >> v >> d;
            assert( u >= 1 && u <= n);
            assert( v >= 1 && v <= n);
            assert( d >= 1 && d <= 1000);
            int a = distS[u] + d + distT[v];
            int b = distS[v] + d + distT[u];
            res = min(res, min(a, b));
        }

        cout << (res != INF ? res : -1) << endl;
    }
    return 0;
}
