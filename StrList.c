#include "StrList.h"
#include <stdio.h>
#include <string.h>


typedef struct _node {
    char* _data;
    struct _node* _next
} Node;

struct _StrList {
    Node* _head;
    size_t _size;
};


StrList* StrList_alloc()
{
    StrList* p = (StrList*)malloc(sizeof(StrList));
    p->_head = NULL;
    p->_size = 0;

    return p;
}

//Check if the StrList is empty
int isEmpty(const StrList* StrList) 
{
    return StrList == NULL || StrList->_head == NULL;
}

void Node_free(Node* node) 
{
    free(node->_data);
	free(node);
}

void StrList_free(StrList* StrList)
{
    int flag = isEmpty(StrList);
    if (flag)
    {
        return;
    }
    Node* p1 = StrList->_head;
    Node* p2;
    while (p1)
    {
        p2 = p1;
        p1 = p1->_next;
        Node_free(p2);
    }
    free(StrList);
}

size_t StrList_size(const StrList* StrList)
{
    return StrList->_size;
}

static Node* createNode(const char* data) 
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode != NULL) 
    {
        newNode->_data = strdup(data); 
        newNode->_next = NULL;
    }
    return newNode;
}


void StrList_insertLast(StrList* StrList, const char* data)
{
    Node* newNode = createNode(data);
    int flag = isEmpty(StrList);
    if (flag) 
    {
        StrList->_head = newNode;
    } 
    else 
    {
        Node* current = StrList->_head;
        while (current->_next != NULL) 
        {
            current = current->_next;
        }
        current->_next = newNode;
    }
    StrList->_size++;
}

void StrList_insertAt(StrList* StrList, const char* data,int index)
{
    if (StrList == NULL || index < 0 || index > StrList->_size)
    {
        return;
    }

    if (index == 0) 
    {
        Node* newNode = createNode(data);
        if (newNode == NULL)
        {
            return;
        }

        newNode->_next = StrList->_head;
        StrList->_head = newNode;
        StrList->_size++;

        return;
    }
    int i;
    Node* current = StrList->_head;
    for (i = 0; i < index - 1; i++) 
    {
        current = current->_next;
    }
    Node* newNode = createNode(data);
    if (newNode == NULL)
    {
        return;
    }
    newNode->_next = current->_next;
    current->_next = newNode;
    StrList->_size++;
}

char* StrList_firstData(const StrList* StrList)
{
    int flag = isEmpty(StrList);
    if (flag)
    {
        return NULL;
    }

    return StrList->_head->_data;
}

void StrList_print(const StrList* StrList)
{
    int flag = isEmpty(StrList);
    if (flag)
    {
        return;
    }

    Node* current = StrList->_head;
    while (current != NULL) 
    {
        printf("%s ", current->_data);
        current = current->_next;
    }
    printf("\n");
}

void StrList_printAt(const StrList* Strlist,int index)
{
    if (Strlist == NULL || index < 0 || index >= Strlist->_size)
    {
        return;
    }

    int i;
    Node* current = Strlist->_head;
    for (i = 0; i < index; i++) 
    {
        current = current->_next;
    }
    printf("%s\n", current->_data);
}

int StrList_printLen(const StrList* Strlist)
{
    int flag = isEmpty(Strlist);
    if (flag)
    {
        return 0;
    }

    int len = 0;
    Node* current = Strlist->_head;
    while (current != NULL) 
    {
        len += strlen(current->_data);
        current = current->_next;
    }

    return len;
}

int StrList_count(StrList* StrList, const char* data)
{
    int flag = isEmpty(StrList);
    if (flag)
    {
        return 0;
    }

    int count = 0, isCmp;
    Node* current = StrList->_head;
    while (current != NULL)
    {
        isCmp = strcmp(current->_data, data);
        if (isCmp == 0)
        {
            count++;
        }
        current = current->_next;
    }

    return count;
}

void StrList_remove(StrList* StrList, const char* data)
{
    int flag = isEmpty(StrList);
    if (flag)
    {
        return;
    }

    Node* current = StrList->_head;
    Node* prev = NULL;
    int isCmp;

    while (current != NULL) 
    {
        isCmp = strcmp(current->_data, data);
        if (isCmp == 0) 
        {
            if (prev == NULL) 
            {
                StrList->_head = current->_next;
                Node_free(current);
                current = StrList->_head;
            } 
            else 
            {
                prev->_next = current->_next;
                Node_free(current);
                current = prev->_next;
            }
            StrList->_size--;
        } 

        else 
        {
            prev = current;
            current = current->_next;
        }
    }
}

void StrList_removeAt(StrList* StrList, int index)
{
    int flag = isEmpty(StrList);
    if (flag || index < 0 || index >= StrList->_size)
    {
        return;
    }

    Node* current = StrList->_head;
    Node* prev = NULL;
    int i;

    for (i = 0; i < index; i++) 
    {
        prev = current;
        current = current->_next;
    }

    if (prev == NULL) 
    {
        StrList->_head = current->_next;
    } 
    else 
    {
        prev->_next = current->_next;
    }
    Node_free(current);
    StrList->_size--;
}

int StrList_isEqual(const StrList* StrList1, const StrList* StrList2)
{
    if ((StrList1 == NULL || StrList2 == NULL) && (StrList1->_size != StrList2->_size))
    {
        return 0;
    }

    Node* current1 = StrList1->_head;
    Node* current2 = StrList2->_head;
    int isCmp = strcmp(current1->_data, current2->_data);

    while (current1 != NULL && current2 != NULL) 
    {
        if (isCmp != 0)
        {
            return 0;
        }

        current1 = current1->_next;
        current2 = current2->_next;
    }

    return 1;
}

StrList* StrList_clone(const StrList* StrList)
{
    int flag = isEmpty(StrList);
    if (flag)
    {
        return NULL;
    }

    struct _StrList* newList = StrList_alloc();
    if (newList == NULL)
    {
        return NULL;
    }

    Node* current = StrList->_head;
    while (current != NULL) 
    {
        StrList_insertLast(newList, current->_data);
        current = current->_next;
    }

    return newList;
}

//Function to swap two strings
static void swap(char** str1, char** str2) 
{
    char* tmp = *str1;
    *str1 = *str2;
    *str2 = tmp;
}

void StrList_reverse( StrList* StrList)
{
    int flag = isEmpty(StrList);
    if (flag || StrList->_head->_next == NULL)
    {
        return;
    }

    Node* prev = NULL;
    Node* next = NULL;
    Node* current = StrList->_head;

    while (current != NULL) 
    {
        next = current->_next;
        current->_next = prev;
        prev = current;
        current = next;
    }

    StrList->_head = prev;
}

void StrList_sort( StrList* StrList)
{
    int flag = isEmpty(StrList);
    if (flag || StrList->_head->_next == NULL)
    {
        return;
    }

    Node* current = StrList->_head;
    Node* index = NULL;
    int isCmp;

    while (current != NULL) 
    {
        index = current->_next;

        while (index != NULL) 
        {
            isCmp = strcmp(current->_data, index->_data);
            if (isCmp > 0) 
            {
                swap(&(current->_data), &(index->_data));
            }
            index = index->_next;
        }
        current = current->_next;
    }
}

int StrList_isSorted(StrList* StrList)
{
    int flag = isEmpty(StrList);
    if (flag || StrList->_head->_next == NULL)
    {
        return 1;
    }

    Node* current = StrList->_head;
    int isCmp;

    while (current->_next != NULL) 
    {
        isCmp = strcmp(current->_data, current->_next->_data);
        if (isCmp > 0)
        {
            return 0;
        }

        current = current->_next;
    }

    return 1;
}