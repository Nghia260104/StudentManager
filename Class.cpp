#include <fstream>
#include <filesystem>

#include "Class.hpp"
#include "Student.hpp"
#include "BackendGlobal.hpp"

using namespace Backend;

bool Class::loadClasses()
{
	std::filesystem::path path(CLASSES_PATH);

	if (!std::filesystem::exists(path))
	{
		std::filesystem::create_directories(path);
		return 0;
	}

	for (auto file: std::filesystem::directory_iterator(path))
	{
		g_classes.push_back(Class(toString(file.path().stem())));
		loadOneClass(file.path());
	}
	return 1;
}

void Class::loadOneClass(const std::filesystem::path &path)
{
	Class &currClass = g_classes.back();
	std::ifstream fi(path);
	std::string studentID;
	while (fi >> studentID)
	{
		for (auto it = g_students.begin(); it != g_students.end(); ++it)
		{
			if (it->getID() == studentID)
			{
				currClass.addStudent(&*it);
				break;
			}
		}
	}
}

Class::Class()
{}

Class::Class(const std::string &nID)
{
	setID(nID);
}

const std::string& Class::getID() const
{
	return id_;
}

const List<Student*>& Class::getStudents() const
{
	return students_;
}

void Class::setID(const std::string &nID)
{
	id_ = nID;
}

bool Class::addStudent(Student *nStudent)
{
	if (students_.find(nStudent) == students_.end())
	{
		return 0;
	}
	
	students_.push_back(nStudent);
	nStudent->class_ = this;
	return 1;
}
