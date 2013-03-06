/*graph.h*/
typedef struct edge *ptrtoedge;

typedef struct graph *graph;

graph getgraph(void);

void printgraph(graph g);

void printtopsortorder(graph g);