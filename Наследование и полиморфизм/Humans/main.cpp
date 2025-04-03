#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include "Student.h"
#include "Teacher.h"

using namespace std;

void saveStudentsToFile(const vector<Student>& students, const string& studentFile);
void saveTeachersToFile(const vector<Teacher>& teachers, const string& teacherFile);

int main() {
    vector<Student> students = {
        Student("Ilya", "Abramov", "Aleksandrovich", {5, 2, 4, 4, 5, 2, 3}),
        Student("Vladislav", "Bazyak", "Sergeevich", {4, 3, 2, 2, 4, 3, 4}),
        Student("Kirill", "Besedin", "", {3, 4, 4, 1, 2, 4, 2, 4}),
        Student("Maxim", "Vill", "Sergeevich", {2, 5, 4, 5, 2 ,3, 5, 3, 2, 5, 4, 2, 5}),
        Student("Fedor", "Vorobiev", "", {5, 3, 4, 2, 4}),
        Student("Yaroslav", "Grachev", "", {4, 2, 4}),
        Student("Bael", "Dzhantaev", "", {3, 4, 4}),
        Student("Aleksei", "Dmitriev", "", {2, 3, 4}),
        Student("Artem", "Erocki", "", {3, 3, 4}),
        Student("Maxim", "Kiselev", "", {4, 2, 4}),
        Student("Nikita", "Klepalov", "", {3, 5, 4}),
        Student("Vladimir", "Kremlev", "", {2, 2, 4}),
        Student("Fedor", "Kuznetsov", "", {3, 3, 4}),
        Student("Evgeny", "Lyakin", "", {4, 4, 4}),
        Student("Matvey", "Morozov", "", {5, 4, 4}),
        Student("Maxim", "Nesterov", "", {4, 2, 4}),
        Student("Veronika", "Prosvetova", "", {2, 3, 4}),
        Student("Danil", "Rogalnikov", "", {2, 5, 4}),
        Student("Maxim", "SiZOV", "", {5, 5, 4}),
        Student("Marina", "Simonova", "", {4, 3, 4}),
        Student("Ivan", "Tolkachev", "", {3, 2, 4}),
        Student("Mikhail", "Trofimov", "", {2, 5, 4}),
        Student("Daniil", "Uliskin", "", {4, 2, 4, 2, 5, 2, 3, 5}),
        Student("Artur", "Horoshev", "", {4, 4, 4, 4, 6, 5}),
        Student("Anton", "Chistuhin", "", {2, 3, 4, 2,5, 4,2, 3}),
        Student("Sergey", "Shagin", "", {3, 2, 4, 5, 4}),
    };

    vector<Teacher> teachers = {
        Teacher("Danil", "Anufrev", "Alekseevich", ASSISTANT, {"mathemathical analysis"}),
        Teacher("Lubov", "Bondareva", "Vasilievna", ASSOCIATE_PROFESSOR, {"programming languages", "professional activity"}),
        Teacher("", "Gutova", "", ASSOCIATE_PROFESSOR, {"discrete mathemathics"}),
        Teacher("Ivan", "Duvanov", "Olegovich", ASSISTANT, {"programming languages", "operation system", "informatics"}),
        Teacher("Sergey", "Karabcov", "Nikolaevich", HEAD_OF_DEPARTMENT, {"computer network"}),
        Teacher("Valeria", "Lavrova", "Igorevna", ASSISTANT, {"informatics"}),
        Teacher("Mikhail", "Los", "Aleksandrovich", ASSISTANT, {"architecture of computer systems"}),
        Teacher("Aleksey", "Medvedev", "", PROFESSOR, {"algebra & geometry", "profile mathematics"}),
        Teacher("Aleksandr", "Pasutin", "", ASSISTANT, {"professional activity"}),
        Teacher("", "Stepanov", "", HEAD_OF_DEPARTMENT, {"informatics"}),
        Teacher("", "Titov", "", ASSOCIATE_PROFESSOR, {"physics"}),
        Teacher("Vladimir", "Torgulkin", "Vladimirovich", SENIOR_LECTURER, {"operation system"}),
        Teacher("", "Chebotarev", "", SENIOR_LECTURER, {"architecture of computer systems"}),
        Teacher("Aleksandr", "Chueshev", "Victorovich", ASSOCIATE_PROFESSOR, {"mathemathical analysis"}),
        Teacher("", "Shirokih", "", ASSISTANT, {"english language"}),
    };

    saveStudentsToFile(students, "students.txt"); // Humans\cmake-build-debug
    saveTeachersToFile(teachers, "teachers.txt"); // Humans\cmake-build-debug


    cout << "Human output" << endl;
    Human human("Maxim", "Vill", "Sergeevich");
    cout << "Surname and initials: " << human.getSurnameAndInitials() << endl;
    cout << "Fullname: " << human.getFullName() << endl;

    cout << '\n';

    cout << "Student output" << endl;
    vector<int> scores = {5, 3};
    Student student("Ilya", "Abramov", "", scores);
    student.addScore(2);
    cout << "Average score: " << student.getAverageScore() << endl;
    cout << "Short info: " << student.getShortStudentInfo() << endl;
    cout << "Full info: " << student.getFullStudentInfo() << endl;

    cout << '\n';

    cout << "Teacher output" << endl;
    vector<string> subjects = {"OS", "Programming languages"};
    Teacher teacher("Ivan", "Duvanov", "Olegovich", SENIOR_LECTURER, subjects);
    teacher.addSubject("Informatics");
    cout << teacher.getShortTeacherInfo() << endl;
    cout << teacher.getFullTeacherInfo() << endl;

    cout << '\n';

    cout << "Averge score > 4" << endl;
    for (const auto& student : students) {
        if (student.getAverageScore() > 4) {
            cout << student.getShortStudentInfo() << endl;
        }
    }

    cout << '\n';

    cout << "Averge score < 3" << endl;
    for (const auto& student : students) {
        if (student.getAverageScore() < 3) {
            cout << student.getShortStudentInfo() << endl;
        }
    }
    cout << '\n';

    cout << "Student with the most scores" << endl;
    cout << "Error" << endl;
    cout << '\n';

    cout << "All associate professors" << endl;
    for (const auto& teacher : teachers) {
        if (teacher.getPosition() == ASSOCIATE_PROFESSOR) {
            cout << teacher.getShortTeacherInfo() << endl;
        }
    }
    cout << '\n';

    cout << "Professor with the most subjects" << endl;
    cout << "Error" << endl;
    cout << '\n';

    cout << "All Informatics teacher" << endl;
    for (const auto& teacher : teachers) {
        if (teacher.teachesSubject("informatics")) {
            cout << teacher.getFullTeacherInfo() << endl;
        }
    }

    return 0;
}

void saveStudentsToFile(const vector<Student>& students, const string& studentFile) {
    ofstream file(studentFile);
    if (!file.is_open()) {
        cerr << "Not open!" << endl;
        return;
    }

    for (const auto& student : students) {
        file << student.getFullStudentInfo() << endl;
    }

    file.close();
}
void saveTeachersToFile(const vector<Teacher>& teachers, const string& teacherFile) {
    ofstream file(teacherFile);
    if (!file.is_open()) {
        cerr << "Not open!" << endl;
        return;
    }

    for (const auto& teacher : teachers) {
        file << teacher.getFullTeacherInfo() << endl;
    }

    file.close();
}