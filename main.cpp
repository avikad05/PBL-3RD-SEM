#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
#include <map>

#include "Caller.h"
#include "EmergencyCall.h"
#include "Incident.h"
#include "DSU.h"
#include "CallAnalyzer.h"
#include "Dispatcher.h"

using namespace std;


// Function to compare incidents
struct IncidentCompare
{
    bool operator()(Incident a, Incident b)
    {
        return a.getPriority() <
               b.getPriority();
    }
};


int main()
{
    cout << "========================================\n";
    cout << " FAKE EMERGENCY CALL DETECTION SYSTEM\n";
    cout << "========================================\n";


    // =====================================
    // 1. CREATE CALLERS
    // =====================================

    Caller caller1(
        101,
        "Rahul",
        "9876543210"
    );

    Caller caller2(
        102,
        "Aman",
        "9876543211"
    );

    Caller caller3(
        103,
        "Rohit",
        "9876543212"
    );

    Caller caller4(
        104,
        "Priya",
        "9876543213"
    );


    // =====================================
    // 2. CREATE EMERGENCY CALLS
    // =====================================

    EmergencyCall call1(
        1,
        caller1,
        "ClockTower",
        "Accident",
        "Two cars collided on road",
        9,
        10,
        10,
        100
    );

    EmergencyCall call2(
        2,
        caller2,
        "ClockTower",
        "Accident",
        "Multiple vehicles crashed",
        8,
        11,
        10,
        105
    );

    EmergencyCall call3(
        3,
        caller3,
        "ClockTower",
        "Accident",
        "Road accident reported",
        7,
        10,
        11,
        110
    );

    EmergencyCall call4(
        4,
        caller4,
        "Market",
        "Fire",
        "Building is on fire",
        10,
        50,
        50,
        120
    );


    // =====================================
    // 3. QUEUE
    // =====================================

    queue<EmergencyCall> incomingCalls;

    incomingCalls.push(call1);
    incomingCalls.push(call2);
    incomingCalls.push(call3);
    incomingCalls.push(call4);

    cout << "\nCalls added to Queue: "
         << incomingCalls.size()
         << endl;


    // =====================================
    // 4. MOVE CALLS FROM QUEUE TO VECTOR
    // =====================================

    vector<EmergencyCall> allCalls;

    while (!incomingCalls.empty())
    {
        EmergencyCall currentCall =
            incomingCalls.front();

        incomingCalls.pop();

        allCalls.push_back(currentCall);
    }


    cout << "Calls processed from Queue: "
         << allCalls.size()
         << endl;


    // =====================================
    // 5. HASH MAP
    // =====================================

    unordered_map<
        string,
        vector<int>
    > hashMap;


    cout << "\n========== HASH MAP ANALYSIS ==========\n";

    for (int i = 0; i < allCalls.size(); i++)
    {
        string key =
            CallAnalyzer::createHashKey(
                allCalls[i]
            );

        hashMap[key].push_back(
            allCalls[i].getCallId()
        );

        cout << "Key: " << key
             << " -> Call ID: "
             << allCalls[i].getCallId()
             << endl;
    }


    // =====================================
    // 6. DSU
    // =====================================

    DSU dsu(allCalls.size());


    for (int i = 0; i < allCalls.size(); i++)
    {
        for (int j = i + 1;
             j < allCalls.size();
             j++)
        {
            if (CallAnalyzer::areRelated(
                    allCalls[i],
                    allCalls[j]))
            {
                dsu.unite(i, j);
            }
        }
    }


    // =====================================
    // 7. GROUP CALLS USING DSU
    // =====================================

    map<int, vector<int>> groups;

    for (int i = 0;
         i < allCalls.size();
         i++)
    {
        int root = dsu.find(i);

        groups[root].push_back(i);
    }


    cout << "\n========== INCIDENT GROUPS ==========\n";

    for (auto group : groups)
    {
        cout << "Group: ";

        for (int index : group.second)
        {
            cout << "Call "
                 << allCalls[index].getCallId()
                 << " ";
        }

        cout << endl;
    }


    // =====================================
    // 8. CREATE INCIDENTS
    // =====================================

    vector<Incident> incidents;

    int incidentId = 1;

    for (auto group : groups)
    {
        vector<int> callIndexes =
            group.second;

        // Take first call as main information
        EmergencyCall firstCall =
            allCalls[callIndexes[0]];


        int highestSeverity = 0;

        for (int index : callIndexes)
        {
            if (allCalls[index].getSeverity()
                > highestSeverity)
            {
                highestSeverity =
                    allCalls[index].getSeverity();
            }
        }


        int numberOfReports =
            callIndexes.size();


        int priority =
            CallAnalyzer::calculatePriority(
                highestSeverity,
                numberOfReports
            );


        Incident incident(
            incidentId,
            firstCall.getEmergencyType(),
            firstCall.getLocation(),
            highestSeverity,
            priority
        );


        // Add calls to incident
        for (int index : callIndexes)
        {
            incident.addCall(
                allCalls[index].getCallId()
            );
        }


        // Check low information
        for (int index : callIndexes)
        {
            if (CallAnalyzer::isLowInformation(
                    allCalls[index]))
            {
                incident.setLowInformation(true);
            }
        }


        incidents.push_back(incident);

        incidentId++;
    }


    // =====================================
    // 9. DISPLAY INCIDENTS
    // =====================================

    cout << "\n========== DETECTED INCIDENTS ==========\n";

    for (int i = 0;
         i < incidents.size();
         i++)
    {
        incidents[i].display();
    }


    // =====================================
    // 10. PRIORITY QUEUE
    // =====================================

    priority_queue<
        Incident,
        vector<Incident>,
        IncidentCompare
    > priorityQueue;


    for (int i = 0;
         i < incidents.size();
         i++)
    {
        priorityQueue.push(
            incidents[i]
        );
    }


    cout << "\n========== PRIORITY QUEUE ==========\n";

    while (!priorityQueue.empty())
    {
        Incident highestPriority =
            priorityQueue.top();

        priorityQueue.pop();

        cout << "Incident "
             << highestPriority.getIncidentId()
             << " | Priority = "
             << highestPriority.getPriority()
             << endl;
    }


    // =====================================
    // 11. DISPATCH
    // =====================================

    Dispatcher dispatcher;


    cout << "\n========== DISPATCHING ==========\n";

    // Recreate priority queue
    for (int i = 0;
         i < incidents.size();
         i++)
    {
        priorityQueue.push(
            incidents[i]
        );
    }


    while (!priorityQueue.empty())
    {
        Incident incident =
            priorityQueue.top();

        priorityQueue.pop();

        dispatcher.dispatch(incident);
    }


    cout << "\n========================================\n";
    cout << " SYSTEM FINISHED SUCCESSFULLY\n";
    cout << "========================================\n";


    return 0;
}
