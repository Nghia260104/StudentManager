#include "addStudent.h"
using namespace std;
int row(string clas){
	fstream Student;
	Student.open(clas,ios::in);
	int count=0;
	while(!Student.eof()){
	string t;	
	getline(Student,t);
	count++;
}
return count;
}
void addStudent(string schoolYear,student &st){
	string folder="",text="";
	int x=stoi(schoolYear);
	x++;	
	std::string t = std::to_string(x);
	folder=folder+schoolYear+"-"+t;
	cout<<folder;
	text=folder+".txt";
	fstream InF;
	InF.open("addStudent.txt",ios::in);
	if(!InF.fail()){
		fstream check;
		check.open(text,ios::in);
		if(!check.fail()){
		int choose;	
		cout<<"\n\t\t\t============\n\t=Get from your file (0)____Enter from the keyboard (1) =\n\t";
		cin>>choose;
		if(choose){
		cout<<"ID: "; cin>>st.ID;
		cout<<"First name: "; cin>>st.Fname;
		cout<<"Last name: "; cin>>st.Lname;
		cout<<"Gender: ";cin>>st.gender;
		cout<<"Student class: "; cin>>st.clas;	
		cout<<"Date of birth year of birth: "<<endl;
		cout<<"Date: "; cin>>st.date_of_birth;
		string sd=st.clas;
		sd=sd+".txt";
		folder=folder+"/"+sd;
		fstream stu;
		stu.open(folder,ios::in);
		if(!stu.fail())	{
			fstream add;
			add.open(folder,ios::app);
			add<<"\n"<<row(folder)+1<<" "<<st.ID<<" "<<st.Fname<<" "<<st.Lname<<" "<<" "<<st.gender<<" "<<st.date_of_birth;
			cout<<"Add student succesfull!";
		}	
		else {
			cout<<"Class does not exist";	
				}	
		}	
		else{
			string sd[2];
			int w=0;
			while(!InF.eof()){
				getline(InF,sd[w++]);
			}
			sd[0]=sd[0]+".txt";
			folder=folder+"/"+sd[0];
			fstream stu;
			stu.open(folder,ios::in);
			if(!stu.fail())	{
			fstream add;
			add.open(folder,ios::app);
			add<<"\n"<<row(folder)+1<<" "<<sd[1];
			cout<<"Add student succesfull!";
			}	
			else {
			cout<<"Class does not exist";	
				}	
		}	
		}
		else{
		cout<<"School year does not exist";	
		}
	}
else{	
		InF.open("addStudent.txt",ios::app);
		cout<<"Please enter student information into the file addStudent.txt";
	}
}
int main(){
	student st;
	string year;
	cout<<"Enter year:";
	cin>>year;
	{  
	addStudent(year,st);
	}
	return 0;
}
