#include <iostream>
#include <climits>
using namespace std;

// Function to find the vertex with the minimum key value, which is not yet in the MST
int msti(int key[], bool mst[], int V)
{
    int min = INT_MAX, minindex;
    for (int i = 0; i < V; i++)
    {
        if (!mst[i] && key[i] < min)
        {
            min = key[i];
            minindex = i;
        }
    }
    return minindex;
}

// Function to print the edges of the MST and calculate the total weight
void printmst(int adj[][10], int parent[], int V)
{
    int totalCost = 0;
    cout << "Edges in the MST using Prim's Algorithm:\n";
    for (int i = 1; i < V; i++)  // Start from 1 because vertex 0 has no parent
    {
        int u = parent[i];
        int v = i;
        int weight = adj[u][v];
        cout << "[" << u << "] ----- [" << v << "] : " << weight << endl;
        totalCost += weight;
    }
    cout << "Total Cost of MST: " << totalCost << endl;
}

// Function to implement Prim's algorithm for MST
void primmst(int adj[][10], int V)
{
    int key[V], parent[V];
    bool mst[V];
    
    // Initialize the key values and set all vertices as not included in the MST
    for (int i = 0; i < V; i++)
    {
        key[i] = INT_MAX;
        mst[i] = false;
        parent[i] = -1;  // Initialize parent array to -1
    }
    
    key[0] = 0;  // Start from vertex 0

    // Loop for all vertices in the graph
    for (int count = 0; count < V; count++)  
    {
        // Get the vertex with the minimum key value not yet in MST
        int u = msti(key, mst, V);  
        mst[u] = true;  // Include this vertex in MST

        // Update the key and parent for adjacent vertices
        for (int v = 0; v < V; v++)
        {
            // If there is an edge and vertex v is not in MST, and edge weight is less than current key
            if (adj[u][v] != 0 && !mst[v] && adj[u][v] < key[v])
            {
                parent[v] = u;  // Update parent
                key[v] = adj[u][v];  // Update key value to the edge weight
            }
        }
    }

    // Print the MST edges and their total weight
    printmst(adj, parent, V);
}

int main()
{
    int V;

    // Input number of vertices
    cout << "Enter the number of vertices: ";
    cin >> V;

    int adj[10][10]; // Adjacency matrix (assuming max 10 vertices)

    // Input adjacency matrix (weights of edges)
    cout << "Enter the adjacency matrix (0 for no edge, enter weight for existing edges):\n";
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (i == j) {
                adj[i][j] = 0;  // No loopbacks, distance to itself is 0
            } else {
                cout << "Enter the weight for edge between vertex " << i << " and vertex " << j << ": ";
                cin >> adj[i][j];
                // For undirected graph, make the matrix symmetric
                // if (adj[i][j] != 0) {
                //     adj[j][i] = adj[i][j];  // Mirror the weight for symmetry
                // }
            }
        }
    }

    // Run Prim's algorithm to find the MST and print the result
    primmst(adj, V);

    return 0;
}
