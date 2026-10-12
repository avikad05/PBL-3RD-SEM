#ifndef CALLER_H
#define CALLER_H

#include <iostream>
#include <string>
using namespace std;

class Caller
{
private:
    int callerId;
    string name;
    string phone;

public:

    Caller()
    {
        callerId = 0;
        name = "";
        phone = "";
    }

    Caller(int id, string n, string p)
    {
        callerId = id;
        name = n;
        phone = p;
    }

    int getCallerId()
    {
        return callerId;
    }

    string getName()
    {
        return name;
    }

    string getPhone()
    {
        return phone;
    }

    void display()
    {
        cout << "Caller ID: " << callerId << endl;
        cout << "Name: " << name << endl;
        cout << "Phone: " << phone << endl;
    }
};

#endif