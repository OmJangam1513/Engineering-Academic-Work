#include <iostream>
using namespace std;

class Node
{
    public:
    int key;
    Node *left;
    Node *right;

    Node(int Data) {
        key = Data;
        left = NULL;
        right = NULL;
    }

};

class Linkedlist 
{
public:
	Node *root;

	Linkedlist() {
		root = NULL;
	}


	void Insertion(int Data) {
		Node *newNode = new Node(Data);
		
		if (root == NULL)
		{
			root = newNode;
		}
		else 
		{
			Node *temp = root;
			Node *parent = NULL;


			while (temp != NULL)
			{
				parent = temp;
				if (newNode->key < temp->key)
				{
					temp = temp->left;
				} 
				else if (newNode->key > temp->key)
				{
					temp = temp->right;
				}
			}


			if (newNode->key < parent->key)
			{
				parent->left = newNode;
			} 
			else 
			{
				parent->right = newNode;
			}
		}
	}


	void Search(Node *temp, int key) 
	{
		while (temp != NULL)
		{
			if (key == temp->key)
			{
				cout << "Node " << key << "found in the tree." << endl;
				return;
			}
			else if (key < temp->key)
			{
				temp = temp->left;
			} 
			else
			{
				temp = temp->right;
			}
		}
		cout << "Node " << key << " not found in the tree." << endl;
	}


	Node* Delete(Node *temp, int key)
	{
		
		if (temp == NULL)
		{
			return temp;
		}

	
		
		if (key < temp->key)
		{
			temp->left = Delete(temp->left, key);
		} 
		else if(key > temp->key) 
		{
			temp->right = Delete(temp->right, key);
		} 
		else
		{
            // Here three case scenario occurs
            // Only 1 right Node to the deleting Node
			if (temp->left == NULL)
			{
				Node *tempNode = temp->right;
				delete temp;
				return tempNode;
			} 
			else if (temp->right == NULL)// Only 1 left Node to the deleting Node
			{
				Node *tempNode = temp->left;
				delete temp;
				return tempNode;
			}
			else // The Node has both left and Right Node 
			{
                // We Find the Minimum Value Node from Right Subtree of the Deleting Node. 
				Node *tempNode = FindMin(temp->right);
				temp->key = tempNode->key;
			    temp->right = Delete(temp->right, tempNode->key);
			}
		}
		return temp;
	}


	Node* FindMin(Node* temp)
	{
		while (temp && temp->left != NULL)
		{
			temp = temp->left;
		}
		return temp;
	}


	int Height(Node *temp)
	{
		if (temp == NULL)
		{
			return -1;
		}

		int leftHeight = Height(temp->left);
		int rightHeight = Height(temp->right);

		return 1 + max(leftHeight, rightHeight);
	}


	int ShortestPath(Node* temp, int key, int pathLength)
	{

		if (temp == NULL)
		{
			return -1;
		}
		if (temp->key == key) 
		{
			return pathLength;
		}
		if (key < temp->key)
		{
			return ShortestPath(temp->left, key, pathLength + 1);
		}
		else
		{
			return ShortestPath(temp->right, key, pathLength + 1);
		}
	}


	int LongestPath(Node* temp)
	{
		if (temp == NULL)
		{
			return 0;
		}

		int leftHeight = LongestPath(temp->left);
		int rightHeight = LongestPath(temp->right);

		return 1 + max(leftHeight, rightHeight);
	}


	void DisplayHeight()
	{
		cout << "Height of the tree: " << Height(root) << endl;
	}


	void Inorder(Node* temp)
	{
		if (temp != NULL)
		{
			Inorder(temp->left);
			cout << temp->key << " ";
			Inorder(temp->right);
		}
	}

	void Preorder(Node* temp)
	{
		if (temp != NULL)
		{
			cout << temp->key << " ";
			Preorder(temp->left);
			Preorder(temp->right);
		}
	}


	void Postorder(Node* temp)
	{
		if (temp != NULL)
		{
			Postorder(temp->left);
			Postorder(temp->right);
			cout << temp->key << " ";
		}
	}


	void DisplayMenu()
	{
		int choice, value, key;
		int pathLength;

		do{
		    cout << "===========Menu==========="<<endl;
			cout << "1. Insert new entry"<<endl;
			cout << "2. Search for an entry"<<endl;
			cout << "3. Delete an entry"<<endl;
			cout << "4. Find minimum node"<<endl;
			cout << "5. Display the height of the tree"<<endl;
			cout << "6. Find shortest path to a node"<<endl;
			cout << "7. Find longest path in the tree"<<endl;
			cout << "8. Exit"<<endl;
			cout << "9. Inorder Traversal"<<endl;
			cout << "10. Preorder Traversal"<<endl;
			cout << "11. Postorder Traversal"<<endl;
			cout << "Enter your choice: "<<endl;
			cin >> choice;

			switch (choice)
			{
			case 1:
			    cout<<"=================================================="<<endl;
				cout << "Enter the number to be entered at node: ";
				cin >> value;
				Insertion(value);
				cout<<"=================================================="<<endl;
				break;
			case 2:
			    cout<<"=================================================="<<endl;
				cout << "Enter number to search: ";
				cin >> key;
				Search(root, key);
				cout<<"=================================================="<<endl;
				break;
			case 3:
			    cout<<"=================================================="<<endl;
				cout << "Enter number to delete: ";
				cin >> key;
				root = Delete(root, key);
				cout << "Node deleted successfully!" << endl;
				cout<<"=================================================="<<endl;
				break;
			case 4:
			    cout<<"=================================================="<<endl;
				if (root == NULL) 
				{
					cout << "Tree is empty." << endl;
				} 
				else 
				{
					Node* minNode = FindMin(root);
					cout << "Minimum node in the tree is: " << minNode->key << endl;
				
				}
				cout<<"=================================================="<<endl;
				break;
			case 5:
			    cout<<"=================================================="<<endl;
				DisplayHeight();
				cout<<"=================================================="<<endl;
				break;
			case 6:
			    cout<<"=================================================="<<endl;
				cout << "Enter number to find the shortest path: ";
				cin >> key;
				pathLength = ShortestPath(root, key, 0);
				if (pathLength == -1)
				{
					cout << "Node not found in the tree.\n";
				} 
				else 
				{
					cout << "Shortest path to node " << key << " is: " << pathLength << endl;
				}
				cout<<"=================================================="<<endl;
				break;
			case 7:
			    cout<<"=================================================="<<endl;
				cout << "Longest path in the tree is: " << LongestPath(root) << endl;
				cout<<"=================================================="<<endl;
				break;
			case 8:
			    cout<<"=================================================="<<endl;
				cout << "Exit" << endl;
				cout<<"=================================================="<<endl;
				break;
			case 9:
			    cout<<"=================================================="<<endl;
				cout << "Inorder Traversal: ";
				Inorder(root);
				cout << endl;
				cout<<"=================================================="<<endl;
				break;
			case 10:
			    cout<<"=================================================="<<endl;
				cout << "Preorder Traversal: ";
				Preorder(root);
				cout << endl;
				cout<<"=================================================="<<endl;
				break;
			case 11:
			    cout<<"=================================================="<<endl;
				cout << "Postorder Traversal: ";
				Postorder(root);
				cout << endl;
				cout<<"=================================================="<<endl;
				break;
			default:
			    cout<<"=================================================="<<endl;
				cout << "Invalid Input. Please re-enter the choice." << endl;
				cout<<"=================================================="<<endl;
			}
			
		} while (choice != 8);
	}

};

int main()
{
	Linkedlist tree;
	tree.DisplayMenu();

	return 0;
}