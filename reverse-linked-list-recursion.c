#include<stdio.h>
#include<malloc.h>

struct node 
{
  int data;
  struct node * next;
};

//Global head pointer
struct node * head = NULL;

//function prototyping
struct node * create_node(int);
void insert_begin(int);
struct node * reverse_list_recursion(struct node * );
void print();

int main() 
{
  /* Create some nodes and insert data into them */

  insert_begin(10);
  insert_begin(90);
  insert_begin(31);
  insert_begin(78);
  insert_begin(99);

  printf("Linked List before reversed: \n");
  print();
  head = reverse_list_recursion(head);
  printf("Linked List after reversed:  \n");
  print();

  return 0;
}

struct node * create_node(int data) 
{
  struct node * new_node = (struct node * ) malloc(sizeof(struct node));
  if (new_node == NULL) 
  {
    printf("Memory can't be allocated for new node");
    return NULL;
  } else 
  {
    new_node -> data = data;
    new_node -> next = NULL;
    return new_node;
  }
}

void insert_begin(int data) 
{
  struct node * new_node = create_node(data);
  if (new_node != NULL) 
  {
    new_node -> next = head;
    head = new_node;
  }
}

struct node * reverse_list_recursion(struct node * head) 
{
    
  // if only one node or the last node of the list
  if (head == NULL || head -> next == NULL) 
  {
    return head;
  }

  //create new head of the reversed list
  struct node * new_head = reverse_list_recursion(head -> next);

  //update the next pointer of the current node
  head -> next -> next = head;

  //make current node as the last node
  head -> next = NULL;

  //return the new head node of the reversed list
  return new_head;
}

void print() 
{
    struct node * temp = head;
    while (temp != NULL) 
    {
      printf("%d  ", temp -> data);
      temp = temp -> next;
    }
    printf("\n”);
}
