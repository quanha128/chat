/* directed_graph.c */

#include <stdlib.h>
#include <stdio.h>
#include "directed_graph.h"
#include "priority_queue.h"

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

void graph_add_edge(Graph* graph, int from, int to, int weight) {
    Edge* edge1 = (Edge*)malloc(sizeof(Edge));

    edge1->next = NULL;
    edge1->node = &graph->nodes[to];
    edge1->weight = weight;
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

int graph_node_compare(T a, T b) {
    Node* node1 = (Node*)a;
    Node* node2 = (Node*)b;

    return node1->weight - node2->weight;
}

void graph_print_dijkstra(Graph* graph, int from, int to) {
    for(int i = 0; i < graph->size; i++) {
        graph->nodes[i].visited = 0;
        graph->nodes[i].weight = 0;
        graph->nodes[i].parent = NULL;
    }

    priority_queue* queue = priority_queue_construct(graph_node_compare);
    Node* node = &graph->nodes[from];
    priority_queue_enqueue(queue, node);
    for(;;) {
        node = (Node*)priority_queue_dequeue(queue);
        if(node == NULL) {
            break;
        }
        if(node->visited) {
            continue;
        }
        node->visited = 1;

        Edge* edge = node->edges;
        while(edge != NULL) {
            if(! edge->node->visited) {
                if((edge->node->weight == 0) || (edge->node->weight > node->weight + edge->weight)) {
                    edge->node->weight = node->weight + edge->weight;
                    edge->node->parent = node;
                    priority_queue_enqueue(queue, edge->node);
                }
            }
            edge = edge->next;
        }
    }    
    priority_queue_free(queue);

    node = &graph->nodes[to];
    while(node != NULL) {
        if(node->parent != NULL) {
            printf("%d <= ", node->value);
        } else {
            printf("%d\n", node->value);
        }
        
        node = node->parent;
    }
}
