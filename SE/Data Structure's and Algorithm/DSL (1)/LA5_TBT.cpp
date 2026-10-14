#include"iostream"
#include"queue"
using namespace std;

class Node
{
public:
    int l,r;
    char key;
    
    Node *left; 
    Node *right;
    
    Node (int data = -1)
    {
        left = NULL;
        right = NULL;
        l = 0;
        r = 0;
        key = data;
    }
    
};

class TBT{
public:
    Node *root, *head;
    
    TBT()
    {
        head = new Node;
        head->left = head;
        head->right = head;
        head->r = 1;
        root = NULL;
    }

    //No need of this function in the assignment
    Node* buildTree()
    { 
        char data;
        
        cout<<"Enter Data = "; //Asking data for new node
        cin>>data;
        
        Node* temp = new Node(data);//Creating node with input data
        
        if(data=='-')//BASE CASE
        {
            return NULL;
        }//To end the path
        
        cout<<"Enter data for left part of "<<data<<endl;
        temp->left = buildTree();//Will continue until data!=-1
        
        cout<<"Enter data for right part of "<<data<<endl;
        temp->right = buildTree();
        
        return temp;
    }

    void insert(char data)
    {
        Node *new_node = new Node(data);
        if(root==NULL)
        {
            root = new_node;
            root->left = head;
            root->right = head;
            head->left=root;
            head->l = 1;
        }
        else
        {
            Node *temp = root;
            while(temp)
            {
                if(new_node->key < temp->key)
                {
                    if(temp->l==0)
                    {
                        new_node->left = temp->left;
                        new_node->right = temp;
                        
                        temp->l=1;
                        temp->left = new_node;
                        return;
                    }
                    temp = temp->left;
                
                }
                else
                {
                    if(temp->r==0)
                    {
                        new_node->right = temp->right;
                        new_node->left = temp;
                        
                        temp->r=1;
                        temp->right = new_node;
                        return;
                    
                    }
                    
                    temp = temp->right;
                }
            }
        }
    }

    void BFS()
    {
        queue<Node* > q;
        q.push(root);
        q.push(NULL);
        
        while(!q.empty())
        {
                Node* temp = q.front();
                q.pop();
                if(temp==NULL)
                {
                    cout<<endl;
                    if(!q.empty())
                    { 
                        q.push(NULL);
                    }
                }
                else{
                    cout<<temp->key<<"  ";
                    if(temp->l==1) q.push(temp->left);
                    if(temp->r==1) q.push(temp->right);
                }
        }
    }

    //Recursive Inorder to verify whether inorder traversed through threads is correct or not
    void inorderTraversal(Node* root)
    {
            if(root==NULL)
            { 
                return;
            }

            inorderTraversal(root->left); //L
            cout<<root->key<<" ";          //D
            inorderTraversal(root->right); //R
    }

    Node* inorderSucc(Node* ptr)
    {
        Node* succ = ptr->right;
        if(ptr->r==1)
        {
            while(succ->l==1)
            {
                succ = succ->left;
            }
        }
        return succ;
    }

    void inorder()
    {
        Node* temp = head;
        do{
            temp = inorderSucc(temp);
            if(temp!=head)
            {
                cout<<temp->key<<" ";
            }
        }while(temp!=head);
    }
};

int main()
{
    TBT t;
    char d;
    for(int i=0;i<9;i++)
    {
        cout<<"KEY - ";
        cin>>d;
        t.insert(d);
    }
    t.BFS();
    t.inorder();
    return 0;
}