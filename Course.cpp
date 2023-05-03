#include <fstream>
#include <sstream>

#include "Course.hpp"
#include "Student.hpp"
#include "BackendGlobal.hpp"

using namespace Backend;

/* static functions */

bool Course::loadCourses(const std::filesystem::path &path, Semester *semester)
{
	if (!std::filesystem::exists(path))
	{
		return 0;
	}

	for (auto courseFile: std::filesystem::directory_iterator(path))
	{
		loadOneCourse(courseFile.path(), semester);
	}
	return 1;
}

void Course::loadOneCourse(const std::filesystem::path &courseFile, Semester *semester)
{
	std::string courseFileStem = toString(courseFile.stem());
	std::cerr << courseFileStem << std::endl;
	g_courses.push_back(Course(courseFileStem, semester));

	std::ifstream fi(courseFile);
	loadOneCourseGeneral(fi, semester);
	loadOneCourseStudents(fi);
}

void Course::loadOneCourseGeneral(std::ifstream &fi, Semester *semester)
{
	Course &currCourse = g_courses.back();
	
	std::string line, word;

	/* course name
	 * teacher name
	 * max number of studentInfos
	 * number of credits
	 * MON,S1 */

	if (std::getline(fi, line))
	{
		std::cerr << line << std::endl;
		currCourse.setCourseName(line);
	}
	if (std::getline(fi, line))
	{
		std::cerr << line << std::endl;
		currCourse.setTeacherName(line);
	}
	if (std::getline(fi, line))
	{
		std::cerr << line << std::endl;
		currCourse.setMaxStudents(std::stoi(line));
	}
	if (std::getline(fi, line))
	{
		std::cerr << line << std::endl;
		currCourse.setNumberOfCredits(std::stoi(line));
	}

	/* MON,S1 */
	if (std::getline(fi, line))
	{
		std::stringstream streamLine(line);
		std::getline(streamLine, word, ',');
		std::cerr << word << std::endl;
		currCourse.session().day = word;
		std::getline(streamLine, word, ',');
		std::cerr << word << std::endl;
		currCourse.session().type = word;
	}
}

void Course::loadOneCourseStudents(std::ifstream &fi)
{
	Course &currCourse = g_courses.back();
	
	std::stringstream streamLine;
	std::string line, word;
	
	/* Read studentInfos' information
	 * Each line's content has the form of:
	 * ID,totalMark,finalMark,midtermMark,otherMark */
	while (std::getline(fi, line))
	{
		streamLine.str(line);
		
		std::getline(streamLine, word, ','); // read student ID
		/* find the student whose ID is word */
		for (auto it = g_students.begin(); it != g_students.end(); ++it)
		{
			if (it->getID() == word)
			{
				currCourse.addStudent(&*it);
				break;
			}
		}
		
		StudentInfo &recentlyAddedStudent = currCourse.studentInfos().back();
		
		std::getline(streamLine, word, ',');
		recentlyAddedStudent.student->setID(word);
		
		std::getline(streamLine, word, ',');
		recentlyAddedStudent.totalMark = std::stof(word);

		std::getline(streamLine, word, ',');
		recentlyAddedStudent.finalMark = std::stof(word);

		std::getline(streamLine, word, ',');
		recentlyAddedStudent.midtermMark = std::stof(word);
		
		std::getline(streamLine, word, ',');
		recentlyAddedStudent.otherMark = std::stof(word);
	}
}

/* struct Session */

std::string Course::Session::getTime() const
{
	std::string res = this->day + " " + this->type + " ";
	std::string time;
	if (this->type == "S1")
	{
		time = "7:30";
	}
	else if (this->type == "S2")
	{
		time = "9:30";
	}
	else if (this->type == "S3")
	{
		time = "13:30";
	}
	else
	{
		time = "15:30";
	}
	return res += "(" + time + ")";
}

/* constructors */

Course::Course()
	: semester_(nullptr), maxStudents_(DEFAULT_MAX_STUDENTS)
{
	session_.day = session_.type = "NOT SET";
}

Course::Course(const std::string &nID, Semester *semester)
	: Course()
{
	setID(nID);
	/* filePath_ = semester_->getDirectoryPath() + id_ + ".csv"; */
	semester->addCourse(this);
}

/* getters */

const std::string& Course::getID() const
{
	return id_;
}

Semester*& Course::semester()
{
	return semester_;
}

Semester* const& Course::semester() const
{
	return semester_;
}
	
const std::string& Course::getCourseName() const
{
	return courseName_;
}

const std::string& Course::getTeacherName() const
{
	return teacherName_;
}

int Course::getMaxStudents() const
{
	return maxStudents_;
}

int Course::getNumberOfCredits() const
{
	return numberOfCredits_;
}

/* setters */

void Course::setID(const std::string &nID)
{
	id_ = nID;
}

void Course::setCourseName(const std::string &nCourseName)
{
	courseName_ = nCourseName;
}

void Course::setTeacherName(const std::string &nTeacherName)
{
	teacherName_ = nTeacherName;
}

void Course::setMaxStudents(int nMaxStudents)
{
	maxStudents_ = nMaxStudents;
}

void Course::setNumberOfCredits(int nNumberOfCredits)
{
	numberOfCredits_ = nNumberOfCredits;
}

/* struct accessors */

List<Course::StudentInfo>& Course::studentInfos()
{
	return studentInfos_;
}

const List<Course::StudentInfo>& Course::studentInfos() const
{
	return studentInfos_;
}

Course::Session& Course::session()
{
	return session_;
}

const Course::Session& Course::session() const
{
	return session_;
}

/* student list modifiers */

bool Course::addStudent(Student *nStudent)
{
	if (studentInfos_.size() == maxStudents_ ||
		studentInfos_.find_if(
			[=](const StudentInfo &studentInfo) -> bool
			{
				return nStudent == studentInfo.student;
			}) != studentInfos_.end())
	{
		return 0;
	}

	StudentInfo nStudentInfo;
	nStudentInfo.student = nStudent;
	studentInfos_.push_back(nStudentInfo);
	nStudent->courseInfos().push_back({this, &nStudentInfo});
	return 1;
}

bool Course::removeStudent(Student *student)
{
	auto currStudentInfo = studentInfos().find_if(
		[&](const StudentInfo &studentInfo) -> bool
		{
			return studentInfo.student == student;
		});

	if (currStudentInfo == studentInfos().end())
	{
		return 0;
	}

	currStudentInfo->student->courseInfos().remove_if(
		[&](const Student::CourseInfo &courseInfo) -> bool
		{
			return courseInfo.course == this;
		});

	studentInfos().erase(currStudentInfo);

	return 1;
}
