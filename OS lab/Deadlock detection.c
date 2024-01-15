#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100

// Structure to represent a node in the graph
struct Node {
    int index;
    char resource[20];
    struct Node* next;
};

// Function to add an edge to the graph
void addEdge(struct Node* graph[], int u, int v, char resource[]) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->index = v;
    strcpy(newNode->resource, resource);
    newNode->next = graph[u];
    graph[u] = newNode;
}

// Function to detect deadlock using depth-first search
int detectDeadlockUtil(struct Node* graph[], int node, int visited[], int stack[], int stackIndex) {
    if (visited[node] == 0) {
        visited[node] = 1;
        stack[stackIndex] = node;
        stackIndex++;

        struct Node* temp = graph[node];
        while (temp != NULL) {
            if (!visited[temp->index]) {
                if (detectDeadlockUtil(graph, temp->index, visited, stack, stackIndex))
                    return 1;
            } else if (visited[temp->index] == 1) {
                printf("Deadlock Detected! Cycle: ");
                for (int i = stackIndex - 1; i >= 0; i--) {
                    printf("%d ", stack[i]);
                }
                printf("\n");
                return 1;
            }
            temp = temp->next;
        }
    }
    visited[node] = 2;
    return 0;
}

// Function to detect deadlock in the given graph
void detectDeadlock(struct Node* graph[], int numNodes) {
    int visited[MAX_NODES] = {0};
    int stack[MAX_NODES];
    int stackIndex = 0;

    for (int i = 0; i < numNodes; i++) {
        if (!visited[i]) {
            if (detectDeadlockUtil(graph, i, visited, stack, stackIndex)) {
                printf("\n");
            }
        }
    }
}

int main() {
    int numNodes, numEdges;

    printf("Enter the number of nodes: ");
    scanf("%d", &numNodes);

    struct Node* graph[MAX_NODES];
    for (int i = 0; i < MAX_NODES; i++) {
        graph[i] = NULL;
    }

    printf("Enter the number of edges: ");
    scanf("%d", &numEdges);

    printf("Enter the edges (node1 node2 resource_name):\n");
    for (int i = 0; i < numEdges; i++) {
        int u, v;
        char resource[20];
        scanf("%d %d %s", &u, &v, resource);
        addEdge(graph, u, v, resource);
    }

    printf("\nDeadlock Detection:\n");
    detectDeadlock(graph, numNodes);

    return 0;
}
