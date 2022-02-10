#include <iostream>
#include <stdlib.h>

using namespace std;

#define SUBJECT 3

class Student
{
    private:
    string name;
    int roll;
    int physics, math, biology;
    int totallNumber = 0, average;

    public:
    void input();
    void print();
};

int main()
{
    int n;

    cout << "enter number of student" << endl;
    cin >> n;

    Student * student = new Student[n];

    for(int i = 0 ; i < n; i++){
      cout << "Student " << i+1 << endl;    
      student[i].input();
    }

    for(int i = 0 ; i < n; i++){
      cout << "Student " << i+1 << endl;    
      student[i].print();
    }

    delete [] student;

    return 0;
}

void Student::input(){
    cout << "enter name\n";
    cin >> name;
    cout << "enter your roll\n";
    cin >> roll;
    cout << "Enter your physics number : \n";
    cin >> physics;
    cout << "Enter your math number : \n";
    cin >> math;
    cout << "Enter your biology number : \n";
    cin >> biology;
}

void Student::print(){
    cout << "Name : " <<  name << endl << "Roll : " << roll << endl;
    totallNumber = physics + math + biology;
    average = totallNumber / SUBJECT;
    cout << "Totall Number : " << totallNumber << endl << "Average : " << average << endl; 
}