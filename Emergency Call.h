#ifndef EMERGENCYCALL_H
#define EMERGENCYCALL_H

#include <iostream>
#include <string>
#include "Caller.h"

using namespace std;

class EmergencyCall
{
private:
    int callId;
    Caller caller;

    string location;
    string emergencyType;
    string description;

    int severity;

    // Coordinates for checking nearby calls
    double x;
    double y;

    // Time of call in minutes
    int time;

public:

    EmergencyCall()
    {
        callId = 0;
        severity = 0;
        x = 0;
        y = 0;
        time = 0;
    }

    EmergencyCall(
        int id,
        Caller c,
        string loc,
        string type,
        string desc,
        int sev,
        double xPos,
        double yPos,
        int t
    )
    {
        callId = id;
        caller = c;
        location = loc;
        emergencyType = type;
        description = desc;
        severity = sev;
        x = xPos;
        y = yPos;
        time = t;
    }

    int getCallId()
    {
        return callId;
    }

    Caller getCaller()
    {
        return caller;
    }

    string getLocation()
    {
        return location;
    }

    string getEmergencyType()
    {
        return emergencyType;
    }

    string getDescription()
    {
        return description;
    }

    int getSeverity()
    {
        return severity;
    }

    double getX()
    {
        return x;
    }

    double getY()
    {
        return y;
    }

    int getTime()
    {
        return time;
    }

    void display()
    {
        cout << "\n-----------------------------\n";
        cout << "Call ID: " << callId << endl;

        cout << "Caller: " << caller.getName() << endl;

        cout << "Location: " << location << endl;

        cout << "Emergency Type: "
             << emergencyType << endl;

        cout << "Description: "
             << description << endl;

        cout << "Severity: "
             << severity << "/10" << endl;

        cout << "Time: "
             << time << " minutes" << endl;

        cout << "-----------------------------\n";
    }
};

#endif
