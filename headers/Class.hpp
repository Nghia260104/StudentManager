#pragma once

#include <string>

#include "List.hpp"

namespace Backend
{
	class Student;
	
	class Class
	{
	public:
		static bool loadClasses();
		
		Class();
		Class(const std::string &nID);

		const std::string& getID() const;
		const List<Student*>& getStudents() const;

		void setID(const std::string &nID);
		bool addStudent(Student *nStudent);

	private:
		static void loadOneClass(const std::filesystem::path &path);
		
		std::string id_;
		List<Student*> students_;
	};
}
