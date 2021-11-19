/* undirected_graph.h */

typedef int NodeType;

typedef struct Edge {
    struct Node* node;
    struct Edge *next;
} Edge;

typedef struct Node {
    NodeType value;
    Edge* edges;
    int visited;
    struct Node* parent;
} Node;

typedef struct Graph {
    Node* nodes;
    int size;
} Graph;

Graph* graph_construct(int size);
void graph_free(Graph* graph);

void graph_set_value(Graph* graph, int index, NodeType value);
void graph_add_edge(Graph* graph, int from, int to);

void graph_print_connected_components(Graph* graph);
int graph_has_closed_path(Graph* graph);