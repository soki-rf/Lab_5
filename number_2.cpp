#include <iostream>
#include <vector>
#include <string>

struct Student {
    std::string name;
    std::string GroupId;
    std::vector<unsigned> Ratings;
    std::vector<std::string> Subjects;

};

double average(std::vector<unsigned> &r) {
    int n = r.size();
    double sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += r[i];
    }
    return sum / n;
}

void SortByRating(std::vector<Student>& students) {
    Student buf;
    double ww;
    std::vector<double> ratings;
    unsigned long n;
    double sum;
    n = students.size();
    for (int i = 0; i < n; ++i) {
        sum = average(students[i].Ratings);
        ratings.push_back(sum);
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (ratings[i] > ratings[j]) {
                buf = students[i];
                students[i] = students[j];
                students[j] = buf;
                ww = ratings[i];
                ratings[i] = ratings[j];
                ratings[j] = ww;
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
    student1.Ratings = {5, 5, 5, 4};
    student2.name = "Doe";
    student2.Ratings = {4, 4, 3, 3};
    student3.name = "Alex";
    student3.Ratings = {5, 4, 5, 4};

    std::vector<Student> students = { student1, student2, student3 };
    n = students.size();

    std::cout << "Before Sorting" << std::endl;
    for (int i = 0; i < n; ++i) {
        std::cout << students[i].name << " ";
    }
    std::cout << std::endl;


    SortByRating(students);


    std::cout << "After Sorting" << std::endl;
    for (int i = 0; i < n; ++i) {
        std::cout << students[i].name << " ";
    }

    return 0;
}
