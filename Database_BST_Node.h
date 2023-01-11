#pragma once
#include <iostream>
#include <string>
using namespace std;

class Database_BST_Node
{
public:
    string dir, name;
    int num;
    Database_BST_Node *left;
    Database_BST_Node *right;
};