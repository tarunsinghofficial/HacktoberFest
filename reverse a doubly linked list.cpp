

 #include<bits/stdc++.h>
 using namespace std;


struct Node {
	int data;
	struct Node* next;
	struct Node* prev;
};

void append(struct Node** head_ref, int new_data)
{
	struct Node* new_node
		= (struct Node*)malloc(sizeof(struct Node));

	struct Node* last = *head_ref; /* used in step 5*/

	/* 2. put in the data */
	new_node->data = new_data;

	/* 3. This new node is going to be the last node, so
		make next of it as NULL*/
	new_node->next = NULL;

	/* 4. If the Linked List is empty, then make the new
		node as head */
	if (*head_ref == NULL) {
		new_node->prev = NULL;
		*head_ref = new_node;
		return;
	}

	/* 5. Else traverse till the last node */
	while (last->next != NULL)
		last = last->next;

	/* 6. Change the next of last node */
	last->next = new_node;

	/* 7. Make last node as previous of new node */
	new_node->prev = last;

	return;
}



 // } Driver Code Ends
//User function Template for C

struct Node* reverseDLL(struct Node * head)
{
	Node* crt = head;
	Node* nxt;
	Node* prev = head->prev;

 while(crt->next!=head)
 {
   nxt = crt->next;
   crt->next = prev;
   prev = crt;
   crt = nxt;

	 }

	 if(crt!=head)
	 {
	 	crt->next =prev;
	 	prev = crt;
		}
 Node* newhead = prev;
 return newhead;
}

// { Driver Code Starts.

void displayList(struct Node* node)
{
    struct Node* last;
    while (node != NULL) {
        printf("%d ", node->data);
        last = node;
        node = node->next;
    }
}

int main()
{   int t;
    scanf("%d", &t);
    while (t--){
  	  struct Node* head = NULL;
  	  int n;
  	  scanf("%d",&n);
	  for(int i = 0; i<n; i++){
	     int k;
	     scanf("%d",&k);
	     append(&head,k);}
	  head = reverseDLL(head);
	  displayList(head);
	  printf("\n");
    }
	return 0;
}
  // } Driver Code Ends
