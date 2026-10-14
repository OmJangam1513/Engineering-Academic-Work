#include <iostream>
#include <string>
using namespace std;

class Node 
{
    public:
        Node *left;
        Node *right;
        string key;
        string value;
        
        Node(string Data, string meaning)
        {
            key = Data;
            value = meaning;
            left = NULL;
            right = NULL;
        }
};

class Linkedlist
{
    public:
        Node *root;
        
        Linkedlist()
        {
            root = NULL;
        }
        
        bool compare_strings_alphabetically(string &Data, string &RootKey)
        {   
            int minLength = std::min(Data.length(), RootKey.length());

            // Compare character based on ASCII values
            for (int i = 0; i < minLength; ++i)
            {
                if (Data[i] < RootKey[i]) 
                {
                    return true;                 // 1st string is smaller lexiographically
                } 
                else if (Data[i] > RootKey[i]) 
                {
                    return false;                // 2nd string is smaller lexiographically
                }
            }

            // If the strings are equal up to the length of the shorter one
            if (Data.length() < RootKey.length()) 
            {
                return true;                     // 1st string is smaller lexiographically
            } 
            else if (Data.length() > RootKey.length()) 
            {
                return false;                    // 2nd string is smaller lexiographically
            }

            return false;
        }
        
        void Insertion(string Data, string meaning)
        {
            Node *newNode = new Node(Data, meaning);
            Node *temp = root;
            
            if (root == NULL) 
            {
                root = newNode;  
            }
            else
            {
                Node *   parent = NULL;
                
                while (temp != NULL)
                {
                    if (compare_strings_alphabetically(newNode->key, temp->key))
                    {
                        temp = temp->left;
                    }
                    else if (compare_strings_alphabetically(temp->key, newNode->key))
                    {
                        temp = temp->right;
                    }
                    else
                    {
                        cout << "Duplicate key: "<< newNode->key << endl;
                        return; 
                    }
                    
                    parent = temp;
                }
                
                
                if (compare_strings_alphabetically(newNode->key, parent->key))
                {
                    parent->left = newNode;  
                }           
                else 
                {
                    parent->right = newNode;  
                }
            }
        }
        
        void Search(Node *root, const string &key) 
        {
            Node *temp = root;

            while (temp != NULL) 
            {
                if (key == temp->key) 
                {
                    cout << "Node " << key << " : " << temp->value << " found in the tree." << endl;
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
        
        void DisplayMenu()
        {
            int choice;
            string key, meaning;

            do
            {
                
                cout << "\nMenu:\n";
                cout << "1. Insert new entry\n";
                cout << "2. Search for an entry\n";
                cout << "3. Exit\n";
                cout << "Enter your choice: ";
                cin >> choice;

                switch (choice)
                {
                    case 1:
                        
                        cout << "Enter word (key): ";
                        cin >> key;
                        cout << "Enter meaning: ";
                        cin >> meaning; 
                        Insertion(key, meaning);
                        cout << "Entry inserted successfully!\n";
                        break;

                    case 2:

                        cout << "Enter word to search: ";
                        cin >> key;
                        Search(root, key);
                        break;

                    case 3:
                       
                        cout << "Exiting the program.\n";
                        break;

                    default:
                        cout << "Invalid choice. Please try again.\n";
                }

            } while (choice != 3);  
        }
};

int main()
{
    Linkedlist dict;
    dict.DisplayMenu();  

    return 0;
}