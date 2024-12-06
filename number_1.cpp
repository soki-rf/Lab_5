#include <iostream>
#include <vector>
#include <string>


struct Student {
    std::string name;
    std::string GroupId;
    std::vector<unsigned> Ratings;
    std::vector<std::string> Subjects;

};

void SortByName(std::vector<Student>&students) {
    unsigned long n;
    int i, j;
    n = students.size();
    Student buf;
    for (i =0; i < n; ++i) {
        for (j = 0; j < n; ++j) {
            if (int(students[i].name[0]) < int(students[j].name[0])) {
                buf = students[i];
                students[i] = students[j];
                students[j] = buf;
            }
        }
    }
}

int main() {
    unsigned long n;
    Student student1;
    Student student2;
    Student student3;
    student1.name = "John";
    student2.name = "Doe";
    student3.name = "Alex";

    std::vector<Student> students = { student1, student2, student3 };
    n = students.size();

    std::cout << "Before Sorting" << std::endl;
    for (int i = 0; i < n; ++i) {
        std::cout << students[i].name << " ";
    }
    std::cout << std::endl;


    SortByName(students);


    std::cout << "After Sorting" << std::endl;
    for (int i = 0; i < n; ++i) {
        std::cout << students[i].name << " ";
    }

    return 0;
}
