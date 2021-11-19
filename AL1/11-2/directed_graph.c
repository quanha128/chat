/* directed_graph.c */

#include <stdlib.h>
#include <stdio.h>
#include "directed_graph.h"
#include "array_queue.h"

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
}

void graph_print_path(Graph* graph, int from, int to) {
    for(int i = 0; i < graph->size; i++) {
        graph->nodes[i].visited = 0;
        graph->nodes[i].parent = NULL;
    }

    QUEUE queue = queue_construct();
    Node* node = &graph->nodes[from];
    node->visited = 1;
    queue_enqueue(queue, node);
    while(! queue_empty(queue)) {
        node = (Node*)queue_dequeue(queue);

        Edge* edge = node->edges;
        while(edge != NULL) {
            if(! edge->node->visited) {
                queue_enqueue(queue, edge->node);
                edge->node->visited = 1;
                edge->node->parent = node;
            }
            edge = edge->next;
        }
    }    
    queue_free(queue);

    node = &graph->nodes[to];
    while(node != NULL) {
        printf("%d ", node->value);
        node = node->parent;
    }
    printf("\n");
}
