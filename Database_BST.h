#pragma once
#include <iostream>
#include <string>
#include <string.h>
#include "Database_BST_Node.h"
using namespace std;

class Database_BST
{
public:
    Database_BST_Node *root=NULL;

    void createBSTList(string _dir, string _name, int _num);
    void printOrder(Database_BST_Node *curNode);
};