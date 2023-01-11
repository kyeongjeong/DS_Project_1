#include "Database_BST.h"
using namespace std;

void Database_BST::createBSTList(string _dir, string _name, int _num)
    {
        Database_BST_Node *newNode= new Database_BST_Node;
        newNode->dir=_dir;
        newNode->name=_name;
        newNode->num=_num;
        newNode->left=NULL;
        newNode->right=NULL;

        if(root==NULL)
        {
            root=newNode;
            return;
        }

        Database_BST_Node *curNode=root;
        Database_BST_Node *prevNode=root;

        while(curNode != NULL)
        {
            if(newNode->num < curNode->num)
            {
                if(curNode->left == NULL)
                {
                    curNode->left=newNode;
                    return;
                }
                curNode=curNode->left;
            }

            else
            {
                if(curNode->right == NULL)
                {
                    curNode->right=newNode;
                    return;
                }
                curNode=curNode->right;
            }
        }
    }

    void Database_BST::printOrder(Database_BST_Node *curNode)
    {
       printOrder(curNode->left);
       cout<<curNode->dir<<" / "<<curNode->name<<" / "<<curNode->num<<endl;
       printOrder(curNode->right);
    }