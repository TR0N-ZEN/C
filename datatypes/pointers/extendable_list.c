#include <stdio.h>

//typedef struct nodes * pointer_to_node;
typedef struct nodes
{
    int value;
    struct nodes * next;
} Node;

int idx(Node node, int depth)
{
    if (depth == 0) { return node.value; }
    --depth;
    Node next_node = *(node.next); // *(node.next) <=> node->next oder?
    return idx(next_node, depth);
}

int main()
{
    int b = 5;
    Node nodelist[b];
    for (int a = 0; a < b; a++)
    {
        nodelist[a].value = a;
        //nodelist[a].next = NULL;
        if (a > 0)
        {
            nodelist[a-1].next = &(nodelist[a]);
        }
        
    }
    for (int a = 0; a < b; a++)
    {
        printf("%i %i \n", nodelist[a].value, (*nodelist[a].next).value); // (*nodelist[a].next).value <=> (nodelist[a]->next).value
    }
    printf("%i", idx(nodelist[1], 2));
}