#include <stdio.h>

#define SIZE 64

struct Edge {
    int from;
    int to;
};

int main()
{
    int a, b;
    int i, j;
    int count = 0;
    int is_tree_res[SIZE] = { 0 };
    int num_nodes_with_incoming_edge;
    int num_edges;
    int num_nodes;
    int nodes_with_incoming_edge[SIZE];
    int nodes_appeared[SIZE];
    struct Edge edges[SIZE];
    int is_tree;
    
    while (1) {
        is_tree = 1;
        num_nodes_with_incoming_edge = 0;
        num_edges = 0;
        num_nodes = 0;
        for (i = 0; i < SIZE; i++) {
            nodes_appeared[i] = 0;
        }
        
        scanf("%d %d", &a, &b);
        if (a == -1 && b == -1)
            break;
        
        while (1) {
            if (a == 0 && b == 0)
                break;
            
            if (a == b) {
                is_tree = 0;
                break;
            }
            
            edges[num_edges].from = a;
            edges[num_edges].to = b;
            num_edges++;
            
            for (i = 0; i < num_nodes_with_incoming_edge; i++) {
                if (nodes_with_incoming_edge[i] == b) {
                    is_tree = 0;
                    break;
                }
            }
            if (!is_tree)
                break;
            
            nodes_with_incoming_edge[num_nodes_with_incoming_edge] = b;
            num_nodes_with_incoming_edge++;
            
            if (!nodes_appeared[a]) {
                num_nodes++;
                nodes_appeared[a] = 1;
            }
            if (!nodes_appeared[b]) {
                num_nodes++;
                nodes_appeared[b] = 1;
            }
            
            scanf("%d %d", &a, &b);
        }
        
        if (num_edges > 0) {
            if (is_tree && (num_nodes - 1 != num_edges || num_nodes != num_nodes_with_incoming_edge + 1)) {
                is_tree = 0;
            }
            
            // Check if connected
            int visited[SIZE] = { 0 };
            
            for (i = 0; i < num_nodes_with_incoming_edge; i++) {
                visited[nodes_with_incoming_edge[i]] = 1;
            }
            
            int root = -1;
            for (i = 1; i < num_nodes; i++) {
                if (nodes_appeared[i] && !visited[i]) {
                    root = i;
                    break;
                }
            }
            
            if (root == -1) {
                is_tree = 0;
            } else {
                for (i = 1; i < SIZE; i++) {
                    visited[i] = 0;
                }
                
                visited[0] = 1;
                visited[root] = 1;
                int stack[SIZE];
                int stack_size = 1;
                stack[0] = root;
                int stack2[SIZE];
                int stack2_size = 0;
                int *stack1p = stack;
                int *stack2p = stack2;
                int *stack1_sizep = &stack_size;
                int *stack2_sizep = &stack2_size;
                
                while (*stack1_sizep) {
                    for (i = 0; i < *stack1_sizep; i++) {
                        for (j = 0; j < num_edges; j++) {
                            if (edges[j].from == stack1p[i]) {
                                visited[edges[j].to] = 1;
                                stack2p[*stack2_sizep] = edges[j].to;
                                (*stack2_sizep)++;
                            }
                        }
                    }
                    
                    int *stack_temp = stack1p;
                    int *size_temp = stack1_sizep;
                    stack1p = stack2p;
                    stack1_sizep = stack2_sizep;
                    stack2p = stack_temp;
                    stack2_sizep = size_temp;
                    *stack2_sizep = 0;
                }
                
                for (i = 1, j = num_nodes; j > 0 && i < SIZE; i++) {
                    if (nodes_appeared[i]) {
                        if (!visited[i]) {
                            is_tree = 0;
                            break;
                        }
                        j--;
                    }
                }
            }
        }
        
        
        is_tree_res[count] = is_tree;
        count++;
        
        // Read off the rest of input
        while (a != 0 || b != 0) {
            scanf("%d %d", &a, &b);
        }
    }
    
    for (i = 0; i < count; i++) {
        if (is_tree_res[i]) {
            printf("Case %d is a tree.\n", i + 1);
        } else {
            printf("Case %d is not a tree.\n", i + 1);
        }
    }
    
    return 0;
}
