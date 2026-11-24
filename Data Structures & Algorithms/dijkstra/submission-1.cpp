class Solution {
public:
    template <typename T>
    using min_heap = priority_queue<T, vector<T>, greater<T>>;
    typedef pair<int,int> pii;
    unordered_map<int, int> shortestPath(int n, vector<vector<int>>& edges, int src) {
    min_heap<pii> pq;
    unordered_map<int,int> dist;
    // fill the map with initial values
    for (size_t i = 0; i < n; i++){
        dist[i] = INT_MAX;
    }

    dist[src] = 0;
    pq.push({0,src});
    while (!pq.empty()){
        int v = pq.top().second;
        int d = pq.top().first;
        pq.pop();

        for (auto e : edges){
            if (e[0] != v) continue;
            int weight = e[2];
            int adjNode = e[1];

            if (dist[adjNode] > weight + d){
                dist[adjNode] = weight + d;
                pq.push({dist[adjNode], adjNode});
            }
        }
    }
    for (int i = 0; i < dist.size(); i++){
        if (dist[i] == INT_MAX){
            dist[i] = -1;
        }
    }
    return dist;
    }
};
