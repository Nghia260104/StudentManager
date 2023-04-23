#pragma once

#include <string>

#include "List.hpp"

namespace Backend
{
	class Student;
	
	class Class
	{
	public:
		Class();
		Class(const std::string &nID);

		static bool loadClasses(const std::string &classesPath);

		const std::string& getID() const;
		const List<Student*>& getStudents() const;

		void setID(const std::string &nID);
		bool addStudent(Student *nStudent);

	private:
		std::string id_;
		List<Student*> students_;
	};
}
