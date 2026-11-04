#include <iostream>
#include <vector>

struct Edge {
    int start;
    int end;
    int weight;
};

// Adjacency Matrix
void displayMatrix(const std::vector<Edge>& edges, int vertices) {
    int matrix[10][10] = {};

    for (const Edge& edge : edges) {
        matrix[edge.start][edge.end] = edge.weight;
    }

    std::cout << "\nADJACENCY MATRIX\n\n";

    std::cout << "    ";
    for (int i = 0; i < vertices; i++) {
        std::cout << i << "   ";
    }
    std::cout << "\n";

    for (int i = 0; i < vertices; i++) {
        std::cout << i << " | ";

        for (int j = 0; j < vertices; j++) {
            std::cout << matrix[i][j] << "   ";
        }

        std::cout << "\n";
    }
}

// Adjacency List
struct AdjNode {
    int value;
    int weight;
    AdjNode* next;
};

class Graph {
private:
    int vertices;

public:
    AdjNode** head;

    Graph(int vertices) {
        this->vertices = vertices;

        head = new AdjNode*[vertices];

        for (int i = 0; i < vertices; i++) {
            head[i] = nullptr;
        }
    }

    void addEdge(int start, int end, int weight) {
        AdjNode* newNode = new AdjNode;

        newNode->value = end;
        newNode->weight = weight;
        newNode->next = head[start];

        head[start] = newNode;
    }

    void displayList() {
        std::cout << "\nADJACENCY LIST\n\n";

        for (int i = 0; i < vertices; i++) {
            std::cout << i << " -> ";

            AdjNode* current = head[i];

            while (current != nullptr) {
                std::cout << "("
                          << current->value
                          << ", "
                          << current->weight
                          << ") ";

                current = current->next;
            }

            std::cout << "\n";
        }
    }

    ~Graph() {
        for (int i = 0; i < vertices; i++) {
            AdjNode* current = head[i];

            while (current != nullptr) {
                AdjNode* temp = current;
                current = current->next;
                delete temp;
            }
        }

        delete[] head;
    }
};

int main() {

    // Graph edges from the activity
    Edge edges[] = {
        {0, 1, 2},
        {0, 2, 4},
        {1, 4, 3},
        {2, 3, 2},
        {3, 1, 4},
        {4, 3, 3}
    };

    int vertices = 6;
    int edgeCount = sizeof(edges) / sizeof(edges[0]);

    // Adjacency Matrix
    std::vector<Edge> edgeList;

    for (int i = 0; i < edgeCount; i++) {
        edgeList.push_back(edges[i]);
    }

    displayMatrix(edgeList, vertices);
    
    // Adjacency List
    Graph graph(vertices);

    for (int i = 0; i < edgeCount; i++) {
        graph.addEdge(
            edges[i].start,
            edges[i].end,
            edges[i].weight
        );
    }

    graph.displayList();

    return 0;
}