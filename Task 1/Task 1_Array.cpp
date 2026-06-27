#include <iostream>
#include <string>
using namespace std;

struct Student{
    string id;
    string name;
    string course;
    int age;
};

int main() {

    Student student[5];
    student[0].id = "24007271";
    student[0].name = "Reeyan";
    student[0].course = "IT";
    student[0].age = 25;

    student[1].id = "24006463";
    student[1].name = "Ananda";
    student[1].course = "CS";
    student[1].age = 18;

    student[2].id = "24006464";
    student[2].name = "Briana";
    student[2].course = "IT";
    student[2].age = 20;

    student[3].id = "24006465";
    student[3].name = "Caiden";
    student[3].course = "SE";
    student[3].age = 19;

    student[4].id = "24006466";
    student[4].name = "Delara";
    student[4].course = "DS";
    student[4].age = 21;

    for (int i = 0; i < 5; i++) {
        cout << student[i].id << endl;
        cout << student[i].name << endl;
        cout << student[i].course << endl;
        cout << student[i].age << endl;
        cout << endl;
    }






    return 0;
}