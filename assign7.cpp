#include <iostream>
#include <algorithm>
using namespace std;

struct Edge
{
    int src, dest, weight;
};

int parent[100], rankArray[100];

// Find function with path compression
int find(int x)
{
    if (parent[x] == x)
    {
        return x;
    }
    else
    {
        return parent[x] = find(parent[x]);
    }
}

// Union function using union by rank
void unionAll(int x, int y)
{
    int xroot = find(x), yroot = find(y);
    if (rankArray[xroot] > rankArray[yroot])
    {
        parent[yroot] = xroot;
    }
    else if (rankArray[yroot] > rankArray[xroot])
    {
        parent[xroot] = yroot;
    }
    else
    {
        parent[yroot] = xroot;
        rankArray[xroot]++;
    }
}

// Comparison function to sort edges by weight
bool compare(Edge a, Edge b)
{
    return a.weight < b.weight;
}

// Kruskal's algorithm
void kruskal(Edge edges[], int V, int E)
{
    // Initialize parent and rank arrays
    for (int i = 0; i < V; i++)
    {
        parent[i] = i;
        rankArray[i] = 0;
    }

    // Sort edges by weight
    sort(edges, edges + E, compare);

    int minCost = 0;
    cout << "Edges in the MST:\n";

    for (int i = 0; i < E; i++)
    {
        int x = find(edges[i].src);
        int y = find(edges[i].dest);

        // If including this edge does not form a cycle
        if (x != y)
        {
            unionAll(x, y);
            cout << "Edge: " << edges[i].src << " - " << edges[i].dest << " with weight " << edges[i].weight << endl;
            minCost += edges[i].weight;
        }
    }

    cout << "Total weight of MST: " << minCost << endl;
}

int main()
{
    int V, E;
    cout << "Enter the number of vertices and edges: ";
    cin >> V >> E;

    Edge edges[E];
    cout << "Enter the edges (src dest weight):\n";
    for (int i = 0; i < E; i++)
    {
        cout << "SRC: ";
        cin >> edges[i].src;
        cout << "DEST: ";
        cin >> edges[i].dest;
        cout << "WEIGHT: ";
        cin >> edges[i].weight;
    }

    kruskal(edges, V, E);
    return 0;
}