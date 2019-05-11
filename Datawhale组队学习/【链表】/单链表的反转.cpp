typedef struct node_s{
    int item;
    struct node_s* next;
}node_t;

node_t* reverse_list(node_t* head)
{
    node_t* n=head;
    head=NULL;
    while(n){
      node_t* m=m; 
      n=n->next;              
      m-next=head;
      head=m;
    }
    return head;
 }
