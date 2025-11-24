#include <stdlib.h>
#include <stdio.h>

struct Node{
    struct Node * next;
    int val;
};
struct Node * removeNode(struct Node * ptr , int key)
{
    if(ptr == NULL) {return NULL; }
    struct Node * head = ptr;
    struct Node * prev = NULL;
    while(ptr != NULL)
    {
        if(ptr->val == key)
        {
            if(prev == NULL)
            {
                head = ptr->next;
                free(ptr);
                return head;
            }
            else{
                prev->next = ptr->next;
                free(ptr);
                return head;
            }
        }
        prev = ptr;
        ptr = ptr->next;
    }
    return head;
}
