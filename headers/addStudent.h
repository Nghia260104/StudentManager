#include <iostream>
#include <fstream>
#include <string>

using namespace std;
struct course{
	string namecouse;
	double* score[11];
	char* rank={NULL}; 
	course * next,*prev,*data;  
};
struct student {
	string No;
	string ID;
	string Fname;
	string Lname;
	string clas;
	string gender;
	string date_of_birth;
	string social_ID;
	double fMark;
	double midMark;
	double oMark;
	double toMark;
	student* pNext;
	
};
int row(student &s,string clas);
void addStudent(string schoolYear,student&st);
