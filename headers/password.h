#ifndef PASSWORD_H
#define PASSWORD_H

#include<iostream>
using namespace std;

struct passInfo;

bool LoginCheck(string login, string password, char &type, string &ID, passInfo *readfile);
void login(char &type, string &ID);
void edit(string ID);
bool doTheEdit(string login, string password, string ID, passInfo *&head);
string pass();

#endif // PASSWORD_H_INCLUDED
