#include <iostream>
#include <vector>
#include <string>

struct Student {
    std::string name;
    std::string GroupId;
    std::vector<unsigned> Ratings;
    std::vector<std::string> Subjects;

};

std::vector<std::string> GroupsId(const std::vector<Student>& students) {
    std::vector<std::string> groups;
    unsigned long n = students.size();
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < groups.size(); ++j) {
            if (students[i].GroupId == groups[j]) {
                cnt++;
                break;
            }
        }
        if (cnt != 1) {
            groups.push_back(students[i].GroupId);
        }
        cnt = 0;
    }
    return groups;
}

int main() {
    unsigned long n;
    Student student1;
    Student student2;
    Student student3;
    student1.name = "John";
    student1.GroupId = "IU";
    student1.Ratings = {5, 5, 5, 5};
    student1.Subjects = {"Algosi", "Math", "PE", "History"};
    student2.name = "Doe";
    student2.GroupId = "SM";
    student2.Ratings = {4, 4, 3, 3};
    student2.Subjects = {"Algosi", "Math", "PE", "History"};
    student3.name = "Alex";
    student3.GroupId = "IU";
    student3.Ratings = {5, 4, 5, 4};
    student3.Subjects = {"Algosi", "Math", "PE", "History"};

    std::vector<Student> students = { student1, student2, student3 };
    std::vector<std::string> groups = GroupsId(students);

    for (int i = 0; i < groups.size(); ++i) {
        std::cout << groups[i] << std::endl;
    }

    return 0;
}
