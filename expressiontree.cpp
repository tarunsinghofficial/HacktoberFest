// C++ program for expression tree  
#include <bits/stdc++.h>  
using namespace std ;  
/* The below class node is defined as a node of a binary tree consists  
of left child and the right child, along with the pointer next which points to the next node */  
  
class node   
{  
public:  
    char info ;  
    node* l ;  
    node* r ;  
    node* nxt = NULL ;  
    node ( char c )  
    {  
        this->info = c ;  
        l = NULL ;  
        r = NULL ;  
    }  
    node()  
    {  
        l = NULL ;  
        r = NULL ;  
    }  
    friend class Stack ;  
    friend class tree ;  
} ;  
class Stack   
{  
    node* head = NULL ;  
  
public:  
    void push ( node* ) ;  
    node* pop() ;  
    friend class tree ;  
} ;  
class tree   
{  
public:  
    void inorder ( node* x )  
    {  
        // cout<<"Tree in InOrder Traversal is: "<<endl;  
        if ( x == NULL )  
            return ;  
        else   
        {  
            inorder ( x->l ) ;  
            cout << x->info << " " ;  
            inorder ( x->r ) ;  
        }  
    }  
} ;  
  
void Stack::push( node* x )  
{  
    if ( head == NULL )   
    {  
        head = x ;  
    }  
    // We are inserting here nodes at the top of the stack [following LIFO principle]  
    else   
    {  
        x->nxt = head ;  
        head = x ;  
    }  
}  
node* Stack::pop()  
{  
    // Poping out the top most [ pointed with head ] element  
    node* p = head ;  
    head = head->nxt ;  
    return p ;  
}  
int main()  
{  
    string str = "XYZ*+W/" ;  
    // If you wish take input from user:  
    //cout << "Insert Postorder Expression: " << endl;  
    //cin >> s;  
    Stack s ;  
    tree t ;  
    node *p, *q, *re;  
    int n = str.length() ;  
    for ( int i = 0 ; i < n ; i++ )   
    {  
          
  
        if ( str[ i ] == '+' || str[ i ] == '-' || str[ i ] == '*' || str[ i ] == '/' || str[ i ] == '^')   
        {  
            re = new node( str[i] ) ;  
            p = s.pop() ;  
            q = s.pop() ;  
            re->l = q ;  
            re->r = p ;  
            s.push(re) ;  
        }  
        else   
        {  
            re = new node( str[ i ] ) ;  
            s.push(re) ;  
        }  
    }  
    cout << " The Inorder Traversal of Expression Tree: " ;  
    t.inorder(re) ;  
    return 0 ;  
}  
