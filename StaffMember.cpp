#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include "StaffMember.hpp"
#include "Student.hpp"
#include "BackendGlobal.hpp"

using namespace Backend;

bool StaffMember::loadStaffMembers()
{
	std::ifstream fi;
	fi.open(ACCOUNTS_PATH + "/staff members.csv");

	if (!fi.is_open())
	{
		return 0;
	}

	std::string line;
	std::stringstream streamLine;
	while (std::getline(fi, line))
	{
		streamLine.str(line);
		
		std::string no, firstName, lastName, gender, dateOfBirth, socialID;
		readCSV(streamLine, no);
		readCSV(streamLine, firstName);
		readCSV(streamLine, lastName);
		readCSV(streamLine, gender);
		readCSV(streamLine, dateOfBirth);
		readCSV(streamLine, socialID);
		
		g_staffMembers.push_back(StaffMember(socialID));
		StaffMember &currStaffMember = g_staffMembers.back();
		g_accounts.push_back(&currStaffMember);
		currStaffMember.setFirstName(firstName);
		currStaffMember.setLastName(lastName);
		currStaffMember.setGender(gender);
		currStaffMember.setDateOfBirth(dateOfBirth);
	}

	return 1;
}

void StaffMember::readCSV(std::stringstream &streamLine, std::string &word)
{
	std::string tmp;
	if (std::getline(streamLine, tmp, ','))
	{
		word = tmp;
	}
}

StaffMember::StaffMember()
{}

StaffMember::StaffMember(const std::string &nSocialID)
{
	setSocialID(nSocialID);
}

void StaffMember::setSocialID(const std::string &nSocialID)
{
	socialID_ = nSocialID;
	username_ = socialID_;
}

bool StaffMember::createStudent(const std::string &studentID) const
{
	if (g_students.find_if(
			[&studentID](const Student &student) -> bool
			{
				return student.getID() == studentID;
			})
		!= g_students.end())
	{
		return 0;
	}
	
	g_students.push_back(Student(studentID));
	g_accounts.push_back(&g_students.back());
	return 1;
}

void StaffMember::deleteStudent(const std::string &studentID) const
{
	g_accounts.remove_if(
		[&](const Account *student) -> bool
		{
			return reinterpret_cast<const Student*>(student)->getID() == studentID;
		});

	g_students.remove_if(
		[&](const Student &student) -> bool
		{
			return student.getID() == studentID;
		});
}

bool StaffMember::createSchoolYear(int startYear) const
{
	if (g_schoolYears.find_if(
			[=](const SchoolYear &schoolYear) -> bool
			{
				return schoolYear.getStartYear() == startYear;
			})
		!= g_schoolYears.end())
	{
		return 0;
	}

	g_schoolYears.push_back(SchoolYear(startYear));
	return 1;
}

bool StaffMember::deleteSchoolYear(int startYear) const
{
	auto currSchoolYear = g_schoolYears.find_if(
		[&](const SchoolYear &schoolYear) -> bool
		{
			return schoolYear.getStartYear() == startYear;
		});

	if (currSchoolYear == g_schoolYears.end())
	{
		return 0;
	}
	
	for (auto iSemester = currSchoolYear->semesters().begin();
		 iSemester != currSchoolYear->semesters().end();
		 ++iSemester)
	{
		deleteSemester(iSemester->getID(); startYear);
	}

	g_schoolYears.erase(currSchoolYear);

	return 1;
}

bool StaffMember::createSemester(int id, int schoolStartYear) const
{
	auto currSchoolYear = g_schoolYears.find_if(
		[&](const SchoolYear &schoolYear) -> bool
		{
			return schoolYear.getStartYear() == schoolStartYear;
		});

	if (currSchoolYear == g_schoolYears.end())
	{
		return 0;
	}
	
	g_semesters.push_back(Semester(id, &*currSchoolYear));
	currSchoolYear->addSemester(&g_semesters.back());
	return 1;
}

bool StaffMember::deleteSemester(int id, int schoolStartYear) const
{
    auto currSemester = g_semesters.find_if(
		[&](const Semester &semester) -> bool
		{
			return semester.schoolYear()->getStartYear() == schoolStartYear
				&& semester.getID() == id;
		});

	if (currSemester == g_semesters.end())
	{
		return 0;
	}

    currSemester->schoolYear()->removeSemester(&*currSemester);
	g_courses.remove_if(
		[&](const Course &course) -> bool
		{
			return course.semester() == &*currSemester;
		});
	g_semesters.erase(currSemester);

	return 1;
}

bool StaffMember::createCourse(const std::string &id) const
{
	auto currCourse = g_courses.find_if(
		[&](const Course &course) -> bool
		{
			return course.getID() == id;
		});

	if (currCourse != g_courses.end())
	{
		return 0;
	}
	
	g_courses.push_back(Course(id));
	return 1;
}

bool StaffMember::deleteCourse(const std::string &id) const
{
	auto currCourse = g_courses.find_if(
		[&](const Course &course) -> bool
		{
			return course.getID() == id;
		});

	if (currCourse == g_courses.end())
	{
		return 0;
	}

	currCourse->semester()->removeCourse(&*currCourse);
	
	for (auto iStudent = currCourse->studentInfos().begin();
		 iStudent != currCourse->studentInfos().end();
		 ++iStudent)
	{
		iStudent->student->courseInfos().remove_if(
			[&](const Student::CourseInfo &courseInfo) -> bool
			{
				return courseInfo.course == &*currCourse;
			});
	}

	g_courses.erase(currCourse);
	
	return 1;
}

bool StaffMember::createClass(const std::string &id) const
{
	if (g_classes.find_if(
			[&](const Class &currClass) -> bool
			{
				return currClass.getID() == id;
			})
		!= g_classes.end())
	{
		return 0;
	}

	g_classes.push_back(Class(id));
	return 1;
}

void StaffMember::deleteClass(const std::string &id) const
{
	auto currClass = g_classes.find_if(
		[&](const Class &class_) -> bool
		{
			return class_.getID() == id;
		});

	if (currClass == g_classes.end())
	{
		return 0;
	}
	
	for (auto iStudent = currClass->students.begin();
		 iStudent != currClass->students.end();
		 ++iStudent)
	{
		iStudent->getClass() = nullptr;
	}

	g_classes.erase(currClass);
	
	return 1;
}
