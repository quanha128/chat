/* graph_test.c */

#include <stdio.h>
#include "undirected_graph.h"

int main(int argc, char* argv[]) {
    Graph* graph = graph_construct(8);
    
    graph_set_value(graph, 0, 1);
    graph_set_value(graph, 1, 2);
    graph_set_value(graph, 2, 3);
    graph_set_value(graph, 3, 4);
    graph_set_value(graph, 4, 5);
    graph_set_value(graph, 5, 6);
    graph_set_value(graph, 6, 7);
    graph_set_value(graph, 7, 8);
    
    graph_add_edge(graph, 0, 1);
    graph_add_edge(graph, 0, 3);
    graph_add_edge(graph, 0, 6);
    graph_add_edge(graph, 1, 3);
    graph_add_edge(graph, 2, 5);
    graph_add_edge(graph, 4, 7);
    
    graph_print_connected_components(graph);

    if(graph_has_closed_path(graph)) {
        printf("This graph contians a closed path.\n");
    } else {
        printf("This graph does not contian a closed path.\n");
    }

    graph_free(graph);
}