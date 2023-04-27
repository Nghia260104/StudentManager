#include "password.h"

const int max_value = 20;

struct passInfo
{
    passInfo *next;
    string login;
    string password;
    char type;
    string ID;
};

bool LoginCheck(string login, string password, char &type, string &ID, passInfo *readfile)
{
    while(readfile != nullptr)
    {
        if (password == readfile->password && login == readfile->login)
            return true;
        readfile = readfile->next;
    }
    return false;
}

void ReadPassword(passInfo *&readfile)
{
    ifstream fi;
    fi.open("password.txt");
    if(fi.is_open() == false)
    {
        cout << "Error cannot open file.";
        return;
    }
    passInfo *dummyNode;
    passInfo *temp;
    dummyNode->next = readfile;
    passInfo *cur = dummyNode;
    while (!fi.eof())
    {
        temp = new passInfo;
        temp->next = nullptr;
        fi >> temp->login >> temp->password >> temp->type >> temp->ID;
        cur->next = temp;
        cur = cur->next;
    }
    temp = dummyNode;
    dummyNode = dummyNode->next;
    delete dummyNode;
    fi.close();
    readfile = dummyNode;
}

void clear(passInfo *&readfile)
{
    passInfo *temp;
    while (readfile != nullptr)
    {
        temp = readfile;
        readfile = readfile->next;
        delete temp;
    }
}


void login(char &type, string &ID)
{
    string login, password;
    cout << "Enter your account name: ";
    cin >> login;
    cout << "Enter your password: ";
    password = pass();
    passInfo *readfile = nullptr;
    ReadPassword(readfile);
    if(LoginCheck(login, password, type, ID, readfile) == true)
        cout << "Login successful! " << type << " " << ID << endl;
    clear(readfile);
}

bool doTheEdit(string login, string password, string ID, passInfo *head)
{
    passInfo *readfile = head;
    while (readfile != nullptr)
    {
        if(readfile->login == login)
        {
            cout << "Username already exists. Please try again:\n";
                return true;
        }
        readfile = readfile->next;
    }
    readfile = head;
    while (readfile != nullptr)
    {
        if(readfile->ID == ID)
        {
            readfile->login = login;
            readfile->password = password;
            cout << "Change username and password successfully.\n";
            return false;
        }
        readfile = readfile->next;
    }
    cout << "Change username and password fail. Please try again;\n";
    return true;
}

void edit(string ID)
{
    char type;
    int i;
    string temp_ID;
    string new_login, new_password;
    passInfo *readfile;
    ReadPassword(readfile);
    do
    {
        cout << "Do you want to change your username and password:\n";
        cout << "1. Yes. 0. No.:\n";
        cin >> i;
        if (i == 0)
            break;
        cout << "Enter your new account name: ";
        cin >> new_login;
        cout << "Enter your new password: ";
        new_password = pass();
    }
    while (doTheEdit(new_login, new_password, ID, readfile));
    clear(readfile);
}

string pass()
{
    char *password = new char[max_value];
    int i = 0;
    while((password[i]=getch() ) != '\n' && password[i] != '\r' && i < (max_value - 1))
    {
        if (password[i] != '\b')
        {
            putchar('*');
            i++;
        }
        else
            if( i != 0)
            {
                putchar('\b');
                putchar(' ');
                putchar('\b');
                i--;
            }
    }
    if (i < (max_value - 1))
    {
        password[i] = '\0';
        cout << '\n';
        string s = password;
        delete password;
        return s;
    }
    else
    {
        cout << "\nPassword exceeded the maximun number of characters allow.\n Please try again: ";
        return pass();
    }
}
