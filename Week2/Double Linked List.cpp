#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *next;
    Node *prev;
};
//chèn vào đầu danh sách
struct Node *push(struct Node *head_ref, int new_data)
{
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = (head_ref);
    new_node->prev = NULL;
    if ((head_ref) != NULL)
        (head_ref)->prev = new_node;
    (head_ref) = new_node;
    return head_ref;
}
//thêm vào cuối danh sách
struct Node *append(struct Node *head_ref, int new_data)
{
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    struct Node *last = head_ref;
    new_node->data = new_data;
    new_node->next = NULL;
    if (head_ref == NULL)
    {
        new_node->prev = NULL;
        head_ref = new_node;
        return head_ref;
    }
    while (last->next != NULL)
        last = last->next;
    last->next = new_node;
    new_node->prev = last;
    return head_ref;
}
//thêm vào sau một phần tử
struct Node *insertAfter(struct Node *prev_node, int new_data)
{
    if (prev_node == NULL)
    {
        cout << "the given previous node cannot be NULL";
        return NULL;
    }
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = prev_node->next;
    prev_node->next = new_node;
    new_node->prev = prev_node;
    if (new_node->next != NULL)
        new_node->next->prev = new_node;
    return new_node;
}
//xóa đầu danh sách
struct Node *deleteNode(struct Node *head_ref, struct Node *del)
{
    if (head_ref == NULL || del == NULL)
        return head_ref;
    if (head_ref == del)
        head_ref = del->next;
    if (del->next != NULL)
        del->next->prev = del->prev;
    if (del->prev != NULL)
        del->prev->next = del->next;
    free(del);
    return head_ref;
}
//xóa cuối danh sách
struct Node *deleteLastNode(struct Node *head_ref)
{
    if (head_ref == NULL)
        return head_ref;
    struct Node *last = head_ref;
    while (last->next != NULL)
        last = last->next;
    if (last->prev != NULL)
        last->prev->next = NULL;
    else
        head_ref = NULL;
    free(last);
    return head_ref;
}
//xóa sau một phần tử
struct Node *deleteAfter(struct Node *prev_node)
{
    if (prev_node == NULL || prev_node->next == NULL)
        return prev_node;
    struct Node *del = prev_node->next;
    prev_node->next = del->next;
    if (del->next != NULL)
        del->next->prev = prev_node;
    free(del);
    return prev_node;
}
//duyệt danh sách từ đầu đến cuối
void printList(struct Node *node)
{
    struct Node *last;
    cout << "\nTraversal in forward direction \n";
    while (node != NULL)
    {
        cout << " " << node->data << " ";
        last = node;
        node = node->next;
    }
    cout << "\nTraversal in reverse direction \n";
    while (last != NULL)
    {
        cout << " " << last->data << " ";
        last = last->prev;
    }
}
//duyệt danh sách từ cuối đến đầu
void printListReverse(struct Node *node)
{
    struct Node *last;
    while (node != NULL)
    {
        last = node;
        node = node->next;
    }
    cout << "\nTraversal in reverse direction \n";
    while (last != NULL)
    {
        cout << " " << last->data << " ";
        last = last->prev;
    }
}