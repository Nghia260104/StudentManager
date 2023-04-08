#include "StaffMember.hpp"
#include "Student.hpp"
#include "BackendGlobal.hpp"

using namespace Backend;

StaffMember::StaffMember()
{}

StaffMember::StaffMember(const std::string &nSocialID)
{
	socialID_ = nSocialID;
}

bool StaffMember::createStudent(const std::string &studentID) const
{
	if (g_students.find_if(
			[&studentID](const Student &student) -> bool
			{
				return student.getID() == studentID;
			}))
	{
		return 0;
	}
	
	g_students.push_back(Student(studentID));
	return 1;
}
