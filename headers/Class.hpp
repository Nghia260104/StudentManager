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
		List<Student*>& students();
		const List<Student*>& students() const;

		void setID(const std::string &nID);
		
		bool addStudent(Student *nStudent);
		bool removeStudent(Student *student);

	private:
		static void loadOneClass(const std::filesystem::path &path);
		
		std::string id_;
		List<Student*> students_;
	};
}
