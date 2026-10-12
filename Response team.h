#ifndef RESPONSETEAM_H
#define RESPONSETEAM_H

#include <iostream>
#include <string>

using namespace std;

class ResponseTeam
{
protected:
    int teamId;
    string teamType;
    bool available;

public:

    ResponseTeam(
        int id,
        string type
    )
    {
        teamId = id;
        teamType = type;
        available = true;
    }

    virtual void respond()
    {
        cout << "Response team is responding."
             << endl;
    }

    string getTeamType()
    {
        return teamType;
    }

    bool isAvailable()
    {
        return available;
    }

    void setAvailable(bool value)
    {
        available = value;
    }

    virtual ~ResponseTeam()
    {
    }
};


// Ambulance Team

class AmbulanceTeam : public ResponseTeam
{
public:

    AmbulanceTeam(int id)
        : ResponseTeam(id, "Ambulance")
    {
    }

    void respond() override
    {
        cout << "Ambulance team dispatched."
             << endl;
    }
};


// Police Team

class PoliceTeam : public ResponseTeam
{
public:

    PoliceTeam(int id)
        : ResponseTeam(id, "Police")
    {
    }

    void respond() override
    {
        cout << "Police team dispatched."
             << endl;
    }
};


// Fire Team

class FireTeam : public ResponseTeam
{
public:

    FireTeam(int id)
        : ResponseTeam(id, "Fire")
    {
    }

    void respond() override
    {
        cout << "Fire brigade dispatched."
             << endl;
    }
};

#endif