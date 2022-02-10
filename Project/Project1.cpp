#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <vector>
#include <thread>
#include <mutex>

using namespace std;

mutex mtx;

void buy(void *ptr);

class Ticket{
    public:
    int id;
    int c_id;
    int t_id;
    Ticket(int id = -1, int t_id = -1) {
        this->id = id;
        this->t_id = t_id;
    }
    void set_customer(int c_id);
};

class Customer{

    public:
    int id;
    thread* thr;

    Customer(int id  = -1)
    {
        this->id = id;
    }

    void run();
    void wait();

};

class Train{
    public:
    int id;
    vector<Ticket> tickets;
    Train(int i = -1) {
        id = i;
    }
    void journey(Ticket t) {
        tickets.push_back(t);
    }
    void statics();
};

vector<Ticket> tickets;
vector<Train> trains;

int main(int argc, char* argv[])
{

    if (argc != 4) {
        cout << "Args not provided!\n"
             << "Usage: " << argv[0] << " <tickets> <trains> <customers>\n";
        return 1;
    }

    int ticket_num = atoi(argv[1]);
    int train_num = atoi(argv[2]);
    int cust_num = atoi(argv[3]);

    

    for (int i = 0; i < ticket_num; i++) {
        Ticket t(i, rand()%train_num);
        tickets.push_back(t);
    }

    for (int i = 0; i < train_num; i++) {
        trains.push_back(Train(i));
    }

    Customer cust[cust_num];
    for(int i = 0; i < cust_num; i++)
    {
        cust[i] = Customer(i);
        cust[i].run();
    }
   
    for(int i = 0; i < cust_num; i++)
    {
        cust[i].wait();
    }

    for(Train& t : trains)
    {
        t.statics();
    }

    return 0;
}

 void buy(void *ptr){
        Customer *c = (Customer*)ptr;
        while (tickets.size() > 0) {

            mtx.lock();
            
            Ticket t = tickets.back();
            t.set_customer(c->id);
            trains[t.t_id].journey(t);
            tickets.pop_back();
        
            mtx.unlock();
        }
    }


void Train::statics() {
        // train id
        // tickets:
        //  t_id, c_id
        //  t_id, c_id
        //  t_id, c_id....
        cout << "Train Id :" << id << endl << "Tickets:" << endl;

        for (Ticket& t : this->tickets) {
            //t.id
            cout << "\t" << t.t_id << ", " << t.c_id << endl; 
        }
}

void Ticket::set_customer(int c_id){
    {
        this->c_id = c_id;
    }
}
void Customer::run() {

         thr = new thread(buy, this);
        //  thr = &t;
    }

void Customer::wait() {
    thr->join();
    delete thr;
}