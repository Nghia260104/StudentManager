#include <codecvt>

#include "BackendGlobal.hpp"

using namespace Backend;

const std::string Backend::DATA_PATH = "./Data";
const std::string Backend::SCHOOL_YEARS_PATH = Backend::DATA_PATH + "/School Years";
const std::string Backend::CLASSES_PATH = Backend::DATA_PATH + "/Classes";
const std::string Backend::ACCOUNTS_PATH = Backend::DATA_PATH + "/Accounts";

Account *Backend::activeUser = nullptr;
Semester *Backend::activeSemester = nullptr;

List<SchoolYear> Backend::g_schoolYears;
List<Semester> Backend::g_semesters;
List<Course> Backend::g_courses;
List<Class> Backend::g_classes;
List<Student> Backend::g_students;
List<StaffMember> Backend::g_staffMembers;
List<Account*> Backend::g_accounts;

bool Backend::loadData()
{
	if (!SchoolYear::loadSchoolYears())
	{
		std::cerr << "Load data unsuccessful" << std::endl;
		return 0;
	}

	std::cerr << "Load data successful" << std::endl;
	/* if (!Classes::loadClasses())
	 * {
	 * 	return 0;
	 * }
	 * 
	 * if (!loadAccounts())
	 * {
	 * 	return 0;
	 * } */

	return 1;
}

/* bool loadAccounts()
 * {
 * 	Admin::loadAdmin();
 * 	Student::loadStudents();
 * 	StaffMember::loadStaffMembers();
 * } */

std::string Backend::toString(const std::wstring &wstring)
{
	std::wstring_convert<std::codecvt_utf8<wchar_t>> convert;
	return convert.to_bytes(wstring);
}
