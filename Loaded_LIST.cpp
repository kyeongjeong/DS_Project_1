#include "Loaded_LIST.h"
using namespace std;

void Loaded_LIST::createList(string _dir, string _name, int _num)
{
    Loaded_LIST_Node *newNode = new Loaded_LIST_Node;
    newNode->Down = NULL;
    newNode->Next = NULL;
    newNode->dir = _dir;
    newNode->name = _name;
    newNode->num = _num;
    newNode->isDir = false;

    // if there any node exist
    if (head == NULL)
    {
        Loaded_LIST_Node *dirNode = new Loaded_LIST_Node;
        dirNode->dir = _dir;
        dirNode->isDir = true;
        head = dirNode;

        dirNode->Next = newNode;
        return;
    }

    Loaded_LIST_Node *curNode = head;
    Loaded_LIST_Node *prevNode = head;
    bool flag = true;
    while (curNode->dir != newNode->dir)
    {
        // if directory Node is not exist
        if (curNode->Down == NULL)
        {
            flag = false;
            break;
        }
        prevNode = curNode;
        curNode = curNode->Down;
    }

    if (flag == false)
    {
        Loaded_LIST_Node *dirNode = new Loaded_LIST_Node;
        dirNode->dir = _dir;
        dirNode->isDir = true;
        prevNode->Down = dirNode;

        dirNode->Next = newNode;
        return;
    }

    while (curNode->Next != NULL)
        curNode = curNode->Next;

    curNode->Next = newNode;
}

int Loaded_LIST::countNode()
{
    Loaded_LIST_Node *curNode = head;
    Loaded_LIST_Node *prevNode = head;
    int count = 0;

    while (prevNode != NULL)
    {
        curNode = prevNode;
        while (curNode->Next != NULL)
        {
            count++;
            curNode = curNode->Next;
        }

        if (prevNode->Down != NULL)
        {
            curNode = curNode->Down;
            return count;
        }

        else
            return count;
    }
}

void Loaded_LIST::delNode()
{
    Loaded_LIST_Node *curNode = head;
    Loaded_LIST_Node *prevNode = head;

    while (curNode->isDir == false)
    {
        prevNode->Next = curNode->Next;
    }
}

bool Loaded_LIST::delSpecNode(string _dir, string _name)
{
    Loaded_LIST_Node *curNode = head;
    Loaded_LIST_Node *prevNode = head;

    while (curNode->dir != _dir && curNode !=0)
    {
        prevNode = curNode;
        curNode = curNode->Down;
    }

    while (curNode->name != _name && curNode !=0)
    {
        prevNode = curNode;
        curNode = curNode->Next;
    }

    if(curNode == NULL)
            return false;

    prevNode->Next = curNode->Next;
    delete[] curNode;
    return true;
}

void Loaded_LIST::createNode(string _dir, string _name, int _num)
{
    Loaded_LIST_Node *newNode = new Loaded_LIST_Node;

    newNode->Down = NULL;
    newNode->Next = NULL;
    newNode->dir = _dir;
    newNode->name = _name;
    newNode->num = _num;
    newNode->isDir = false;

    Loaded_LIST_Node *curNode = head;
    curNode=head;

    while(curNode->dir != newNode->dir)
        curNode=curNode->Down;

    while(curNode->Next != NULL)
        curNode=curNode->Next;
    
    curNode->Next = newNode;
}

void Loaded_LIST::allNode(Database_BST* D_LIST)
{
    Loaded_LIST_Node *curNode = head;
    Loaded_LIST_Node *prevNode = head;
    while(prevNode != NULL)
    {
        curNode=prevNode;
        while(curNode != NULL)
        {
            if(curNode->isDir == false)
                D_LIST->createBSTList(curNode->dir, curNode->name, curNode->num);         
            curNode=curNode->Next;
        }
        prevNode=prevNode->Down;
    }
}