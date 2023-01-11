#pragma once
#include <iostream>
#include <string>
#include "Loaded_LIST_Node.h"
#include "Database_BST_Node.h"
#include "Database_BST.h"
using namespace std;

class Loaded_LIST
{
public:
    Loaded_LIST_Node *head = NULL;

    void createList(string _dir, string _name, int _num);
    int countNode();
    void delNode();
    bool delSpecNode(string _dir, string _name);
    void createNode(string _dir, string _name, int _num);
    void allNode(Database_BST* D_LIST);
};