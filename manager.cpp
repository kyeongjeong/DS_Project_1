#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <stdlib.h>

#include "Loaded_LIST_Node.h"
#include "Loaded_LIST.h"
#include "Database_BST_Node.h"
#include "Database_BST.h"

using namespace std;

int main(int argc, char **argv)
{
    fstream fs1, fs2, fs3;
    Loaded_LIST L_List;
    Database_BST D_List;

    fs2.open("command.txt");
    fs3.open("log.txt");
   
    while (1)
    {
        string command;
        fs2 >> command;

        if (command == "LOAD")
        {
            fs1.open("img_files/filesnumbers.csv");
            string str, name, num, dir;

            if (!fs1.is_open())
            {
                fs3 << "=======ERROR=======" << endl;
                fs3 << "100" << endl;
                fs3 << "===================" << endl;
            }

            fs3 << "=======LOAD=======" << endl;
            while (!fs1.eof())
            {
                getline(fs1, str);
                stringstream ss(str);

                getline(ss, num, ',');
                if(num[0] == '\xEF' && num[1] == '\xBB' && num[2] == '\xBF')
                    num.erase(0,3);
                
                char number[50];
                strcpy(number, num.c_str());
                int numbers=atoi(number);

                getline(ss, name);

                L_List.createList("img_files", name, numbers);
                fs3 << "img_files / "<<name<<" / "<<numbers<<endl;
            }
            fs3 << "===================" << endl;

            fs1.close();
        }


        else if (command == "ADD")
        {
            string new_dir, new_csv;
            string buf;
            string str, name, num;

            fs2 >> new_dir >> new_csv;           
            buf=new_dir+"/"+new_csv;
            char *buf2 = new char[100];
            strcpy(buf2, buf.c_str());
            
            fs1.open(buf2);
            if (!fs1.is_open() || L_List.head==NULL)
            {
                fs3 << "=======ERROR=======" << endl;
                fs3 << "200" << endl;
                fs3 << "===================" << endl;
            }

            while (!fs1.eof())
            {
                getline(fs1, str);
                stringstream ss(str);

                getline(ss, num, ',');
                if(num[0] == '\xEF' && num[1] == '\xBB' && num[2] == '\xBF')
                    num.erase(0,3);
                
                char number[50];
                strcpy(number, num.c_str());
                int numbers=atoi(number);

                getline(ss, name);
                L_List.createList(new_dir, name, numbers);
            }

            fs3 << "=======ADD=======" << endl;
            fs3 << "SUCCESS" << endl;
            fs3 << "===================" << endl;

            fs1.close();
        }

        else if(command=="MODIFY")
        {
            string dir, name, num, str, buf1;
            
            fs2>>dir;
            getline(fs2, str);
            stringstream ss(str);
            getline(ss, buf1, '"');
            getline(ss, name, '"');
            if(name[0] == '\xEF' && name[1] == '\xBB' && name[2] == '\xBF')
                    name.erase(0,3);
            getline(ss, num);

            char number[50];
            strcpy(number, num.c_str());
            int numbers=atoi(number);

            bool flag=L_List.delSpecNode(dir, name);
            if (flag == false)
            {
                fs3 << "=======ERROR=======" << endl;
                fs3 << "300" << endl;
                fs3 << "===================" << endl;
            }

            L_List.createNode(dir, name, numbers);

            fs3 << "=======MODIFY=======" << endl;
            fs3 << "SUCCESS" << endl;
            fs3 << "===================" << endl;
        }

        else if(command=="MOVE")
        {
            if(L_List.head==NULL)
            {
                fs3 << "=======ERROR=======" << endl;
                fs3 << "400" << endl;
                fs3 << "===================" << endl;
            }         
            L_List.allNode(&D_List);

            fs3 << "=======MOVE=======" << endl;
            fs3 << "SUCCESS" << endl;
            fs3 << "===================" << endl;
        }

        else if(command=="PRINT")
        {
            if(D_List.root==NULL)
            {
                fs3 << "=======ERROR=======" << endl;
                fs3 << "500" << endl;
                fs3 << "===================" << endl;
            }

            D_List.printOrder(D_List.root);
            
            fs3 << "=======PRINT=======" << endl;
            fs3 << "SUCCESS" << endl;
            fs3 << "===================" << endl;
        }

        fs3<<endl<<endl<<endl;
    }
    fs2.close();
    fs3.close();
}