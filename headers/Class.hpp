#pragma once

#include <string>
#include <filesystem>

#include "List.hpp"

namespace Backend
{
	class Student;
	class Course;
	
	class Class
	{
	public:
		static bool loadClasses();
		static void saveClasses();
		static void clearClasses();
		
		static bool createClass(const std::string &id);
	    static bool deleteClass(const std::string &id);
		
		Class();
		Class(const std::string &nID);

		const std::string& getID() const;
		List<Student*>& students();
		const List<Student*>& students() const;
		List<Course*>& courses();
		const List<Course*>& courses() const;

		void setID(const std::string &nID);
		
		bool addStudent(Student *nStudent);
		bool removeStudent(Student *student);

		bool addCourse(Course *course);
		bool removeCourse(Course *course);
		
	private:
		static void loadOneClass(const std::filesystem::path &path);
		static void saveOneClass(Class *currClass);
	
		std::string id_;
		List<Student*> students_;
		List<Course*> courses_;
	};
}
