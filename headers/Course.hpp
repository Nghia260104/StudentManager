#pragma once

#include <string>
#include <filesystem>

#include "List.hpp"

namespace Backend
{
	class Semester;
	class Student;
	
	class Course
	{
	public:
		static bool loadCourses(const std::filesystem::path &path, Semester *semesters);
		
		struct StudentInfo
		{
			Student *student;
			float totalMark, finalMark, midtermMark, otherMark;
		};

		struct Session
		{
			std::string day, type;
			std::string getTime() const;
		};
		
		Course();
		Course(const std::string &nID, Semester *semesterr);

		/* getters */
		const std::string& getID() const;
		const std::string& getCourseName() const;
		const std::string& getTeacherName() const;
		int getMaxStudents() const;
		int getNumberOfCredits() const;

		/* setters */
		void setID(const std::string &nID);
		void setCourseName(const std::string &nCourseName);
		void setTeacherName(const std::string &nTeacherName);
		void setMaxStudents(int nMaxStudents);
		void setNumberOfCredits(int nNumberOfCredits);

		/* struct accessors */
		List<StudentInfo>& studentInfos();
		const List<StudentInfo>& studentInfos() const;
		Session& session();
		const Session& session() const;

		/* student list modifiers */
		bool addStudent(Student *nStudent);
		bool removeStudent(const std::string &studentID);

	private:
		static void loadOneCourse(const std::filesystem::path &courseFile, Semester *semester);
		static void loadOneCourseGeneral(const std::filesystem::path &courseFile, Semester *semester);
		static void loadOneCourseStudents(const std::filesystem::path &courseFile);
		
		const int DEFAULT_MAX_STUDENTS = 50;
		
		std::string id_, courseName_, teacherName_;
		int maxStudents_, numberOfCredits_;
		Semester *semester_;
		List<StudentInfo> studentInfos_;
		/* std::filesystem::path path_; */
		Session session_;

		friend class Semester;
	};
}
