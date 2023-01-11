#pragma once
#include <iostream>
#include <string>
using namespace std;

class Loaded_LIST_Node
{
public:
    int num;
    string dir, name;
    Loaded_LIST_Node *Down, *Next;
    bool isDir;
};