/* undirected_graph.c */

#include <stdlib.h>
#include <stdio.h>
#include "undirected_graph.h"

Graph* graph_construct(int size) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->nodes = (Node*)malloc(sizeof(Node) * size);
    graph->size = size;
    for(int i = 0; i < size; i++) {
        graph->nodes[i].value = 0;
        graph->nodes[i].edges = NULL;
    }
    return graph;
}

void graph_free_edge(Edge* edge) {
    if(edge != NULL) {
        graph_free_edge(edge->next);
        free(edge);
    }
}

void graph_free(Graph* graph) {
    for(int i = 0; i < graph->size; i++) {
        graph_free_edge(graph->nodes[i].edges);
    }
    free(graph->nodes);
    free(graph);
}

void graph_set_value(Graph* graph, int index, NodeType value) {
    graph->nodes[index].value = value;
}

void graph_add_edge(Graph* graph, int from, int to) {
    Edge* edge1 = (Edge*)malloc(sizeof(Edge));
    Edge* edge2 = (Edge*)malloc(sizeof(Edge));

    edge1->next = NULL;
    edge1->node = &graph->nodes[to];
    if(graph->nodes[from].edges == NULL) {
        graph->nodes[from].edges = edge1;
    } else {
        Edge* tail = graph->nodes[from].edges;
        while(tail->next != NULL) {
            tail = tail->next;
        }
        tail->next = edge1;
    }

    edge2->next = NULL;
    edge2->node = &graph->nodes[from];
    if(graph->nodes[to].edges == NULL) {
        graph->nodes[to].edges = edge2;
    } else {
        Edge* tail = graph->nodes[to].edges;
        while(tail->next != NULL) {
            tail = tail->next;
        }
        tail->next = edge2;
    }
}

void graph_dfs1(Node* node) {
    node->visited = 1;
    printf("%d ", node->value);
    Edge* edge = node->edges;
    while(edge != NULL) {
        if(edge->node != node->parent) {
            if(! edge->node->visited) {
                edge->node->parent = node;
                graph_dfs1(edge->node);
            }
        }
        edge = edge->next;
    }
}

void graph_print_connected_components(Graph* graph) {
    for(int i = 0; i < graph->size; i++) {
        graph->nodes[i].visited = 0;
        graph->nodes[i].parent = NULL;
    }

    for(int i = 0; i < graph->size; i++) {
        if(! graph->nodes[i].visited) {
            graph_dfs1(&graph->nodes[i]);
            printf("\n");
        }
    }
}

int graph_dfs2(Node* node) {
    node->visited = 1;
    Edge* edge = node->edges;
    while(edge != NULL) {
        if(edge->node != node->parent) {
            if(edge->node->visited) {
                return 1;
            } 
            edge->node->parent = node;
            if(graph_dfs2(edge->node)) {
                return 1;
            }
        }
        edge = edge->next;
    }
    return 0;
}

int graph_has_closed_path(Graph* graph) {
    for(int i = 0; i < graph->size; i++) {
        graph->nodes[i].visited = 0;
        graph->nodes[i].parent = NULL;
    }

    for(int i = 0; i < graph->size; i++) {
        if(! graph->nodes[i].visited) {
            if(graph_dfs2(&graph->nodes[i])) {
                return 1;
            }
        }
    }

    return 0;
}
