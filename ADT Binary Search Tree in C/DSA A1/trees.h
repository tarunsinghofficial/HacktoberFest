//trees

typedef struct Node
{
    int mis;
    char name[255];
    struct Node *left;
    struct Node *right;
    struct Node* lf_parent;
    struct Node* rt_parent;
    struct Node* parent;
} Node;

void init(Node **root);
void insert(Node **tree, int val, char s[]);
void inorder(Node *root);
Node *search(Node *root, int val);
Node *minValue(Node *root);
Node *deleteNode(Node *root, int d);
void _deleteTree( Node* Node);
void destroyTree( Node** Node_ref);
void postorder(Node *root);
void level(Node *root, int lev);
