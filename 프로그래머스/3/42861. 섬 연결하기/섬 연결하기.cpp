#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    
    // 1. 인접 리스트 만들기 (무방향 그래프)
    // 섬의 번호가 0부터 n-1까지이므로 n 크기로 선언합니다.
    vector<pair<int, int>> adj[101]; 
    for (auto& edge : costs) {
        int u = edge[0];
        int v = edge[1];
        int w = edge[2];
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    // 2. 방문 체크 및 우선순위 큐 준비
    vector<bool> visited(n, false);
    // {비용, 노드번호} 순으로 저장 (비용이 작은 것이 먼저 나오도록 최소 힙 설정)
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    // 3. 시작점 설정 (0번 섬부터 시작)
    // 비용 0으로 0번 섬을 큐에 넣습니다.
    pq.push({0, 0});

    while (!pq.empty()) {
        int dist = pq.top().first;
        int curr = pq.top().second;
        pq.pop();

        // 이미 방문한 섬이라면 무시 (더 짧은 경로로 이미 연결됨)
        if (visited[curr]) continue;

        // 방문 도장 쾅! 비용을 정답에 추가
        visited[curr] = true;
        answer += dist;

        // 현재 섬과 연결된 다른 섬들을 확인
        for (auto& next_edge : adj[curr]) {
            int next_node = next_edge.first;
            int next_dist = next_edge.second;

            // 아직 연결되지 않은 섬이라면 큐에 삽입
            if (!visited[next_node]) {
                pq.push({next_dist, next_node});
            }
        }
    }

    return answer;
}