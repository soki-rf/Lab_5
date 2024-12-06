#include <iostream>
#include <vector>
#include <string>

struct Student {
    std::string name;
    std::string GroupId;
    std::vector<unsigned> Ratings;
    std::vector<std::string> Subjects;

};

size_t CountExcellent(const std::vector<Student>& students) {
    size_t count = 0;
    int cnt;
    cnt = 0;
    unsigned long n = students.size();
    for (int i = 0; i < n; ++i) {
        cnt = 0;
        for (int j = 0; j < students[i].Ratings.size(); ++j) {
            if (students[i].Ratings[j] == 5) {
                ++cnt;
            }
        }
        if (cnt == students[i].Ratings.size()) {
            ++count;
        }
    }
    return count;
}

int main() {
    unsigned long n;
    Student student1;
    Student student2;
    Student student3;
    student1.name = "John";
    student1.Ratings = {5, 5, 5, 5};
    student2.name = "Doe";
    student2.Ratings = {4, 4, 3, 3};
    student3.name = "Alex";
    student3.Ratings = {5, 4, 5, 4};

    std::vector<Student> students = { student1, student2, student3 };

    size_t count = CountExcellent(students);

    std::cout << count << std::endl;

    return 0;
}
