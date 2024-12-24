#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <string>

using namespace std;

class WaterDistributionNetwork {
public:
    void AddPipeline(const string& from, const string& to, int cost) {
        graph[from].emplace_back(cost, to);
        graph[to].emplace_back(cost, from); // Undirected graph
    }

    int QueryMinimumCost() {
        if (graph.empty()) return 0;

        // Prim's algorithm
        unordered_map<string, bool> inMST;
        priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>> pq;

        // Start from an arbitrary node, here we take the first node from the graph
        string startNode = graph.begin()->first;
        pq.emplace(0, startNode); // Cost, Node
        int totalCost = 0;

        while (!pq.empty()) {
            auto top = pq.top();
            pq.pop();
            int cost = top.first;
            string node = top.second;

            if (inMST[node]) continue; // If already in MST, skip it

            inMST[node] = true; // Include this node in MST
            totalCost += cost;

            // Add all edges from this node to the priority queue
            for (const auto& edge : graph[node]) {
                int edgeCost = edge.first;
                string neighbor = edge.second;
                if (!inMST[neighbor]) {
                    pq.emplace(edgeCost, neighbor);
                }
            }
        }

        return totalCost;
    }

private:
    unordered_map<string, vector<pair<int, string>>> graph; // Adjacency list
};

int main() {
    WaterDistributionNetwork network;

    // Example input
    network.AddPipeline("Station1", "Home2", 10);
    network.AddPipeline("Home2", "Home3", 5);
    // Add more pipelines as needed...

    // Query the minimum cost to connect all nodes
    int minimumCost = network.QueryMinimumCost();
    cout << minimumCost << endl; // Expected output: 15

    return 0;
}