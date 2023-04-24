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
Admin Backend::g_admin;
List<Account*> Backend::g_accounts;

bool Backend::loadData()
{
	if (!loadAccounts())
	{
		return 0;
	}

	/* if (!Classes::loadClasses())
	 * {
	 * 	return 0;
	 * }
	 * 
	 * if (!SchoolYear::loadSchoolYears())
	 * {
	 * 	return 0;
	 * } */

	return 1;
}

bool Backend::loadAccounts()
{
	g_accounts.push_back(&g_admin);
	std::filesystem::path path(ACCOUNTS_PATH);

	if (!std::filesystem::exists(path))
	{
		std::filesystem::create_directories(path);
		return 0;
	}

	Admin::loadAdmin();
	StaffMember::loadStaffMembers();
	Student::loadStudents();

	return 1;
}

std::string Backend::toString(const std::wstring &wstring)
{
	std::wstring_convert<std::codecvt_utf8<wchar_t>> convert;
	return convert.to_bytes(wstring);
}
