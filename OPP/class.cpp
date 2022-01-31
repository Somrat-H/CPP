#include <iostream>

using namespace std;

class myClass{
    public:
    int num;
    string name;
    void input () {
        printf("enter your number : ");
        cin >> num;
        printf("enter your name : ");
        cin >>  name;
    }
    void print () {
        cout << "Name : " << name << " and Number is : " << num << endl;
    }
};

int main()
{
    myClass myObj;

    myObj.input();
    myObj.print();

    return 0;

}