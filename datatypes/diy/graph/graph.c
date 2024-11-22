#include <stdbool.h>

#define SEARCH_BASIS 3
#define SIZE_OF_VERTEXES 10

struct Edge
{
  int from;
  int to;
};

int ord(int v)
{
  return v + 1;
}

struct Graph
{
  int vertexes[SIZE_OF_VERTEXES];
  struct Edge edges[(SIZE_OF_VERTEXES - 1) * (SIZE_OF_VERTEXES) / 2]; // Euler's sum of natural numbers to the n-th number. Since there is no edge for (x, 0), there will be 9 x's and so (x, max(vertexes)) in edges
};

// int n;
// int V[n] = {2, 3, 4, 5, 7, 6, 9, 8, 1, 0...};
// struct Edge edges[] = {};
// int e = (n-1)*(n)/2;
// int ord[n] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, ...};

void topsort(int n, int e, struct Edge edges[], int ord[])
{
  for (int k = 1; k <= SEARCH_BASIS; k++)
  {
    //finde Element v aus V mit ord(v) = i
    for (int j = 0; j < n; j++)
    {
      //falls ord(v) == ord
      if (ord(graph1.vertexes[j]) == k) { ord[k] = V[j]; }
    }
  }
  //first 3 elements found
  //int ord[n] = {1, 2, 3, -1, -1, ...};
  //f�r jedes Element v aus V wird nun gez�hlt wie oft es in einem Element edge von edges auf der rechten Seite auftaucht, das kleinste Element tauch 0 mal auf der rechten Seite auf, das n-te Element aus V n-1 mal.
  for (int k = SEARCH_BASIS; k < n; k++) {
    int x = graph1.vertexes[k];
    int occurencies = 0;
    for (int j = 0; j < SIZE_OF_EDGES; j++)
    {
      if (edges[j].to == x) { ++occurencies; }
    }
    ord[occurencies] = x + 1 ; //e.g. if x has 0 occurencies it must be 0 and since the ruel that ord(v) = ord[v] => ord(0) = 1 = ord[0] 
  }
}

// int ord[n] = {...};

int main()
{
  struct Graph graph1;
  const SIZE_OF_EDGES = (SIZE_OF_VERTEXES - 1) * (SIZE_OF_VERTEXES - 1) / 2;
  graph1.vertexes = { 3, 2, 4, 6, 0, 1, 8, 7, 9, 5 };
  //for every vertex / int value from 0 to (SIZE_OF_EDGES - 1)
  int count = 0;
  for (int i = 0; i < SIZE_OF_VERTEXES; i++)
  {
    //for i = 0 create 0 (x, i)
    //for i = 1 create 1 (x, i) which would be (0, 1)
    for (int j = 0; j < i; j++) {
      struct Edge edge;
      edge.from = j;
      edge.to = i;
      graph1.edges[count] = edge;
      count += 1;
    }
  }
  int order[SIZE_OF_VERTEXES];
  for (int i = 0; i < SIZE_OF_VERTEXES; i++)
  {
    order[i] = -1;
  }
  topsort(SIZE_OF_VERTEXES, SIZE_OF_EDGES, graph1.edges, int order[]);
}
