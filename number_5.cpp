#include <iostream>
#include <vector>
#include <string>

struct Student {
    std::string name;
    std::string GroupId;
    std::vector<unsigned> Ratings;
    std::vector<std::string> Subjects;

};

std::vector<Student> VectorMathExcellent(const std::vector<Student>& students) {
    std::vector<Student> bots;
    unsigned long n;
    n = students.size();
    for (int i = 0; i < n; ++i) {
        if (students[i].Ratings[1] == 5) {
            bots.push_back(students[i]);
        }
    }
    return bots;
}

int main() {
    unsigned long n;
    Student student1;
    Student student2;
    Student student3;
    student1.name = "John";
    student1.Ratings = {5, 5, 5, 5};
    student1.Subjects = {"Algosi", "Math", "PE", "History"};
    student2.name = "Doe";
    student2.Ratings = {4, 4, 3, 3};
    student2.Subjects = {"Algosi", "Math", "PE", "History"};
    student3.name = "Alex";
    student3.Ratings = {5, 4, 5, 4};
    student3.Subjects = {"Algosi", "Math", "PE", "History"};

    std::vector<Student> students = { student1, student2, student3 };
    std::vector<Student> bots = VectorMathExcellent(students);

    for (int i = 0; i < bots.size(); ++i) {
        std::cout << bots[i].name << std::endl;
    }

    return 0;
}
