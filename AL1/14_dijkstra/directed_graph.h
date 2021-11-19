/* directed_graph.h */

typedef int NodeType;

typedef struct Edge {
    struct Node* node;
    struct Edge *next;
    int weight;
} Edge;

typedef struct Node {
    NodeType value;
    Edge* edges;
    int visited;
    int weight;
    struct Node* parent;
} Node;

typedef struct Graph {
    Node* nodes;
    int size;
} Graph;

typedef Node* T;

Graph* graph_construct(int size);
void graph_free(Graph* graph);

void graph_set_value(Graph* graph, int index, NodeType value);
void graph_add_edge(Graph* graph, int from, int to, int weight);

void graph_print_dijkstra(Graph* graph, int from, int to);

