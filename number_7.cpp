#include <iostream>
#include <vector>

using namespace std;
struct Student{
    string name;
    string GroupId;
    vector<unsigned> Ratings;
    vector<string> subject;
};

struct Group
{
    string Id;
    vector<Student> studentsInGroup;
};

vector<Group> Groups(vector<Student>&students) {
    vector<Group> GroupsOfStudents;
    int count_1_0 = 0;

    for (const Student&student : students) {
        for (Group&group : GroupsOfStudents) {
            if (student.GroupId == group.Id) {
                group.studentsInGroup.push_back(student);
                count_1_0 += 1;
                break;
            }
        }
        if (count_1_0 == 0) {
            Group newgroup;
            newgroup.studentsInGroup.push_back(student);
            newgroup.Id = student.GroupId;
            GroupsOfStudents.push_back(newgroup);
        }
        count_1_0 = 0;
    }
    return GroupsOfStudents;
}

void student_data(const Student&student) {
    cout << "Name: " << student.name << '\n' << "Группа: " << student.GroupId << endl;
}

void subj_rate(const Student&student) {
    for (int i = 0; i < student.subject.size(); ++i) {
        cout << student.subject[i] << ": " << student.Ratings[i] << endl;
    }
}


int main() {
    unsigned long n;
    Student student1;
    Student student2;
    Student student3;
    student1.name = "John";
    student1.GroupId = "IU";
    student1.Ratings = {5, 5, 5, 5};
    student1.subject = {"Algosi", "Math", "PE", "History"};
    student2.name = "Doe";
    student2.GroupId = "SM";
    student2.Ratings = {4, 4, 3, 3};
    student2.subject = {"Algosi", "Math", "PE", "History"};
    student3.name = "Alex";
    student3.GroupId = "IU";
    student3.Ratings = {5, 4, 5, 4};
    student3.subject = {"Algosi", "Math", "PE", "History"};

    std::vector<Student> students = {student1, student2, student3};

    vector<Group> GroupsOfStudents = Groups(students);

    for (const Group& curgroup : GroupsOfStudents) {
        cout << "<<<" << "Группа: " << curgroup.Id << ">>>" << '\n' << endl;
        for (const Student&student : curgroup.studentsInGroup) {
            student_data(student);
            subj_rate(student);
            cout << '\n';
        }
    }
    return 0;
}
