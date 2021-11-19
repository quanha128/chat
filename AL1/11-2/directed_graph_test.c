/* directed_graph_test.c */

#include <stdio.h>
#include "directed_graph.h"

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
    graph_add_edge(graph, 0, 2);
    graph_add_edge(graph, 1, 4);
    graph_add_edge(graph, 1, 5);
    graph_add_edge(graph, 2, 3);
    graph_add_edge(graph, 2, 4);
    graph_add_edge(graph, 3, 6);
    graph_add_edge(graph, 5, 7);
    
    graph_print_path(graph, 0, 7);

    graph_free(graph);
}