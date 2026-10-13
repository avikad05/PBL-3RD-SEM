#ifndef DISPATCHER_H
#define DISPATCHER_H

#include <iostream>
#include "Incident.h"
#include "ResponseTeam.h"

using namespace std;

class Dispatcher
{
private:

    AmbulanceTeam ambulance;
    PoliceTeam police;
    FireTeam fire;

public:

    Dispatcher()
        : ambulance(1),
          police(2),
          fire(3)
    {
    }

    void dispatch(Incident incident)
    {
        cout << "\n******** DISPATCH ********\n";

        cout << "Incident ID: "
             << incident.getIncidentId()
             << endl;

        cout << "Type: "
             << incident.getEmergencyType()
             << endl;

        if (incident.getEmergencyType()
            == "Accident")
        {
            ambulance.respond();
        }

        else if (incident.getEmergencyType()
                 == "Fire")
        {
            fire.respond();
        }

        else if (incident.getEmergencyType()
                 == "Crime")
        {
            police.respond();
        }

        else
        {
            cout << "General emergency team dispatched."
                 << endl;
        }

        cout << "*************************\n";
    }
};

#endif
