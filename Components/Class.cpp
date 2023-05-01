#include "Class.h"

Class::Class(SchoolYear* ptrSchoolYear, const std::string& name, const Vector<Student*>& students) {
    this->ptrSchoolYear = nullptr;
    this->name = name;
    this->students = students;
}

void Class::set(SchoolYear* ptrSchoolYear, const std::string& name, const Vector<Student*>& students) {
    this->ptrSchoolYear = ptrSchoolYear;
    this->name = name;
    this->students = students;
}

void Class::update(SchoolYear* ptrSchoolYear) {
    this->ptrSchoolYear = ptrSchoolYear;
}

void Class::update(const std::string& name) {
    this->name = name;
}

void Class::addStudent(Student& student){
    Student *ptrStudent = &student;
    students.append(ptrStudent);
    student.ptrClass = this;
}

void Class::removeStudent(Student& student){
    for (int i = 0; i < this->students.size(); ++i)
        if (*students[i] == student)
            students.remove(&students[i]);
    student.ptrClass = nullptr;
}

void Class::removeAllStudent() {
    for (int i = 0; i < students.size(); i++) {
        students[i]->ptrClass = nullptr;
    }
    students.~Vector();
}

Student* Class::getStudent(const std::string& studentID) {
    for (int i = 0; i < students.size(); i++)
        if (students[i]->ID == studentID)
            return students[i];
    return nullptr;
}

Vector<std::string> Class::getListCourse() {
    Vector<std::string> listCourse(0);
    for (int i = 0; i < students.size(); i++)
        for (int j = 0; j < students[i]->scoreboards.size(); j++)
            if (listCourse.find(students[i]->scoreboards[j]->ptrCourse->ID) == nullptr)
                listCourse.append(students[i]->scoreboards[j]->ptrCourse->ID);
    return listCourse;
}

void Class::displayScoreboardScreen(const Semester& semester){
    Vector<std::string> listCourse = getListCourse();
    int nCourse = listCourse.size();
    const int noMaxLength = 4;
    const int idMaxLength = 10;
    const int fullNameMaxLength = 20;
    const int courseIdMaxLength = 10;
    const int gpaMaxLength = 10;
    std::cout << "Scoreboard of class " << name << std::endl;
    std::cout << std::setw(noMaxLength) << std::left << "No";
    std::cout << std::setw(idMaxLength) << std::left << "ID";
    std::cout << std::setw(fullNameMaxLength) << std::left << "Fullname";
    for (int i = 0; i < nCourse; i++)
        std::cout << std::setw(courseIdMaxLength) << std::left << listCourse[i];
    std::cout << std::setw(gpaMaxLength) << std::left << "GPA";
    std::cout << std::setw(gpaMaxLength) << std::left << "OverallGPA";
    std::cout << std::endl;
    for (int i = 0; i < students.size(); i++)
    {
        std::cout << std::setw(noMaxLength) << std::left << i + 1;
        std::cout << std::setw(idMaxLength) << std::left << students[i]->ID;
        std::cout << std::setw(fullNameMaxLength) << std::left << students[i]->name.get();
        for (int j = 0; j < nCourse; j++)
        {
            bool found = false;
            int score = -1;
            for (int k = 0; k < students[i]->scoreboards.size(); k++)
                if (students[i]->scoreboards[k]->ptrCourse->ID == listCourse[j])
                {
                    found = true;
                    score = students[i]->scoreboards[k]->total;
                    break;
                }
            if (found)
                std::cout << std::setw(courseIdMaxLength) << std::left << score;
            else
                std::cout << std::setw(courseIdMaxLength) << std::left << "x";      
        }
        std::cout << std::setw(gpaMaxLength) << std::left << students[i]->getGPA(semester);
        std::cout << std::setw(gpaMaxLength) << std::left << students[i]->getGPA();
        std::cout << std::endl;
    }
}

void Class::displayScoreboardFile(const Semester& semester, std::ofstream& ofs){
    Vector<std::string> listCourse = getListCourse();
    int nCourse = listCourse.size();
    ofs << "Scoreboard of class," << name << std::endl;
    ofs << "No,ID,Fullname,";
    for (int i = 0; i < nCourse; i++)
        ofs << listCourse[i] << ",";
    ofs << "GPA,OverallGPA";
    ofs << std::endl;
    for (int i = 0; i < students.size(); i++)
    {
        ofs << i + 1 << "," << students[i]->ID << "," << students[i]->name.get() << ",";
        for (int j = 0; j < nCourse; j++)
        {
            bool found = false;
            int score = -1;
            for (int k = 0; k < students[i]->scoreboards.size(); k++)
                if (students[i]->scoreboards[k]->ptrCourse->ID == listCourse[j])
                {
                    found = true;
                    score = students[i]->scoreboards[k]->total;
                    break;
                }
            if (found)
                ofs << score << ",";
            else
                ofs << "x,";
        }
        ofs << students[i]->getGPA(semester) << "," << students[i]->getGPA();
        ofs << std::endl;
    }
}

bool operator==(const Class& classA, const Class& classB) {
    if (classA.name != classB.name) 
        return false;
    if (classA.ptrSchoolYear != classB.ptrSchoolYear)
        return false;
    return true;
}