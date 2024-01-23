#include <stdio.h>

#define MAX_VERTICES 100

// Graph representation Adjacency Matrix
int adj[MAX_VERTICES][MAX_VERTICES], n, m, q[MAX_VERTICES], visited[MAX_VERTICES], f = -1, r = -1;

// Edge representation
struct edge
{
    int s, d;
};
struct edge e[MAX_VERTICES];

// Function to create Adjacency Matrix
void createadjmatrix(struct edge e[])
{
    int i, j, x, y;
    // Initialise all values to this Adjacency matrix to zero
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            adj[i][j] = 0;
        }
    }

    // Traverse the array of Edges
    for (i = 0; i < m; i++)
    {
        // Find X and Y of Edges as source and destination of the edges
        x = e[i].s;
        y = e[i].d;
        // Update value to 1
        adj[x][y] = 1;
        adj[y][x] = 1; //not required in case of directed graph
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
            printf("%d ", adj[i][j]);
        printf("\n");
    }
}

// Breadth-First Traversal
void bfs(int v)
{
    int i;
    for (i = 0; i < n; i++)
    {
        if (adj[v][i] != 0 && visited[i] == 0)
        {
            r = r + 1;
            q[r] = i;
            visited[i] = 1;
            printf("%d  ", i);
        }
    }
    f = f + 1;
    if (f <= r)
        bfs(q[f]);
}

// Depth-First Traversal
void dfs(int v)
{
    int i;
    for (i = 0; i < n; i++)
    {
        if (adj[v][i] != 0 && visited[i] == 0)
        {
            visited[i] = 1;
            printf("%d  ", i);
            dfs(i);
        }
    }
}

// Search Operation using BFS
void bfsSearch(int start, int target)
{
    f = r = 0;
    q[r] = start;
    visited[start] = 1;
    while (f <= r)
    {
        int current = q[f];
        f++;

        if (current == target)
        {
            printf("Mobile ID %d found at position %d.\n", target, f);
            return;
        }

        int i;
        for (i = 0; i < n; i++)
        {
            if (adj[current][i] != 0 && visited[i] == 0)
            {
                r++;
                q[r] = i;
                visited[i] = 1;
            }
        }
    }

    printf("Mobile ID %d not found.\n", target);
}

// Search Operation using DFS
void dfsSearch(int start, int target)
{
    visited[start] = 1;
    if (start == target)
    {
        printf("Mobile ID %d found.\n", target);
        return;
    }

    int i;
    for (i = 0; i < n; i++)
    {
        if (adj[start][i] != 0 && visited[i] == 0)
        {
            dfsSearch(i, target);
        }
    }
}

// Display Menu
void displayMenu()
{
    printf("\nMenu:\n");
    printf("1. Breadth-First Traversal\n");
    printf("2. Depth-First Traversal\n");
    printf("3. Search Mobile ID using BFS\n");
    printf("4. Search Mobile ID using DFS\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
}

int main()
{
    int i, v, mobileID, choice;
    char ch = 'y';
    m = 0;
    i = 0;

    // Scenario: Mobile Store Management
    // Each mobile is represented by a node in the graph.
    // Edges represent undirected paths between mobiles.

    printf("Enter no of mobiles: ");
    scanf("%d", &n);

    while (ch == 'y')
    {
        printf("Enter source of edge (Mobile ID): ");
        scanf("%d", &e[i].s);
        printf("Enter destination of edge (Mobile ID): ");
        scanf("%d", &e[i].d);
        printf("Do you want to add more edges? (y/n): ");
        fflush(stdin);
        scanf(" %c", &ch);
        m = m + 1;
        i++;
    }

    // Function call to create Adjacency Matrix
    createadjmatrix(e);

    do
    {
        displayMenu();
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            // Breadth-First Traversal
            for (i = 0; i < n; i++)
            {
                visited[i] = 0;
            }
            printf("\nEnter the starting vertex (Mobile ID) for BFS traversal: ");
            scanf("%d", &v);
            f = r = 0;
            q[r] = v;
            printf("\nBreadth-First Traversal is:\n");
            visited[v] = 1;
            printf("%d   ", v);
            bfs(v);
            break;

        case 2:
            // Depth-First Traversal
            for (i = 0; i < n; i++)
            {
                visited[i] = 0;
            }
            printf("\nEnter the starting vertex (Mobile ID) for DFS traversal: ");
            scanf("%d", &v);
            printf("\nDepth-First Traversal is:\n");
            visited[v] = 1;
            printf("%d   ", v);
            dfs(v);
            break;

        case 3:
            // Search using BFS
            for (i = 0; i < n; i++)
            {
                visited[i] = 0;
            }
            printf("\nEnter the starting vertex (Mobile ID) for BFS search: ");
            scanf("%d", &v);
            printf("Enter the Mobile ID for search: ");
            scanf("%d", &mobileID);
            bfsSearch(v, mobileID);
            break;

        case 4:
            // Search using DFS
            for (i = 0; i < n; i++)
            {
                visited[i] = 0;
            }
            printf("\nEnter the starting vertex (Mobile ID) for DFS search: ");
            scanf("%d", &v);
            printf("Enter the Mobile ID for search: ");
            scanf("%d", &mobileID);
            dfsSearch(v, mobileID);
            break;

        case 5:
            printf("Exiting the program.\n");
            break;

        default:
            printf("Invalid choice. Please enter a valid option.\n");
        }

    } while (choice != 5);

    return 0;
}
