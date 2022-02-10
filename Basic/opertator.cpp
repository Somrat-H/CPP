#include <iostream>

using namespace std;
class Name{

    public:
     int* x;
     int* y;

    public:
    Name(int a = 0, int b = 0) {
        x = new int;
        *x = a;
        y = new int;
        *y = b;
        cout << *x << " " << *y << endl;
    }
    ~Name(){
        delete x;
        delete y; 
    }
    int add()
    {
        return *x+*y;
    }
    void print() {
        cout << *x << "\t" << *y << endl;
    }

    bool operator > (const Name& n) {
        ///
        return x > n.x;
    }
};

int main()
{
    Name* a[10];

    for(int i = 0; i < 10; i++)
    {
        a[i] = new Name(rand() % 10, rand() % 10);
    }

    // for(int i = 0; i < 10; i++)
    // {
    //     cout << a[i].add() << endl;
    // }
    
    //sorting the add() value

    for(int i = 0; i < 10 -1; i++)
    {
        for(int j = 0; j < 10 -i -1; j++)
        {
            if( *(a[j]) > *(a[j+1]) ){

                int temp = *(a[j]->x);
                *(a[j]->x) = *(a[j+1]->x);
                *(a[j+1]->x) = temp;

                int temp1 = *(a[j]->y);
                *(a[j]->y) = *(a[j+1]->y);
                *(a[j+1]->y) = temp1;
            } 
        }
    }

    for(int i = 0; i < 10; i++)
    {
        // cout << *(a[i].x) << " " << *(a[i].y) <<endl;
        a[i]->print();
    }

    for (int i = 0; i < 10; i++) {
        delete a[i];
    }

    return 0;
}