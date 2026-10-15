#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
#include <map>

#include "Caller.h"
#include "Emergency Call.h"
#include "Incident.h"
#include "DSU.h"
#include "Call analyzer.h"
#include "Dispatcher.h"

using namespace std;

struct IncidentCompare
{
    bool operator()(Incident a, Incident b)
    {
        return a.getPriority() < b.getPriority();
    }
};

int main()
{
    cout << "====================================\n";
    cout << " EMERGENCY CALL PRIORITY SYSTEM\n";
    cout << "====================================\n";

    // Callers
    Caller c1(101, "Rahul", "9876543210");
    Caller c2(102, "Aman", "9876543211");
    Caller c3(103, "Rohit", "9876543212");
    Caller c4(104, "Priya", "9876543213");

    // Emergency calls
    EmergencyCall call1(
        1, c1, "ClockTower", "Accident",
        "Two cars collided on road",
        9, 10, 10, 100
    );

    EmergencyCall call2(
        2, c2, "ClockTower", "Accident",
        "Multiple vehicles crashed",
        8, 11, 10, 105
    );

    EmergencyCall call3(
        3, c3, "ClockTower", "Accident",
        "Road accident reported",
        7, 10, 11, 110
    );

    EmergencyCall call4(
        4, c4, "Market", "Fire",
        "Building is on fire",
        10, 50, 50, 120
    );

    // Queue
    queue<EmergencyCall> q;

    q.push(call1);
    q.push(call2);
    q.push(call3);
    q.push(call4);

    cout << "\nCalls in queue: " << q.size() << endl;

    // Move calls from queue to vector
    vector<EmergencyCall> calls;

    while (!q.empty())
    {
        calls.push_back(q.front());
        q.pop();
    }

    cout << "Calls processed: " << calls.size() << endl;

    // Hash map
    unordered_map<string, vector<int>> hashMap;

    cout << "\n========== HASH MAP ==========\n";

    for (int i = 0; i < calls.size(); i++)
    {
        string key = CallAnalyzer::createHashKey(calls[i]);

        hashMap[key].push_back(calls[i].getCallId());

        cout << key << " -> Call "
             << calls[i].getCallId() << endl;
    }

    // DSU
    DSU dsu(calls.size());

    for (int i = 0; i < calls.size(); i++)
    {
        for (int j = i + 1; j < calls.size(); j++)
        {
            if (CallAnalyzer::areRelated(calls[i], calls[j]))
            {
                dsu.unite(i, j);
            }
        }
    }

    // Groups
    map<int, vector<int>> groups;

    for (int i = 0; i < calls.size(); i++)
    {
        groups[dsu.find(i)].push_back(i);
    }

    cout << "\n========== INCIDENT GROUPS ==========\n";

    for (auto g : groups)
    {
        cout << "Group: ";

        for (int index : g.second)
        {
            cout << calls[index].getCallId() << " ";
        }

        cout << endl;
    }

    // Create incidents
    vector<Incident> incidents;

    int id = 1;

    for (auto g : groups)
    {
        vector<int> indexes = g.second;

        EmergencyCall first = calls[indexes[0]];

        int severity = 0;

        for (int index : indexes)
        {
            if (calls[index].getSeverity() > severity)
            {
                severity = calls[index].getSeverity();
            }
        }

        int reports = indexes.size();

        int priority =
            CallAnalyzer::calculatePriority(severity, reports);

        Incident incident(
            id,
            first.getEmergencyType(),
            first.getLocation(),
            severity,
            priority
        );

        for (int index : indexes)
        {
            incident.addCall(calls[index].getCallId());

            if (CallAnalyzer::isLowInformation(calls[index]))
            {
                incident.setLowInformation(true);
            }
        }

        incidents.push_back(incident);
        id++;
    }

    // Display incidents
    cout << "\n========== INCIDENTS ==========\n";

    for (Incident incident : incidents)
    {
        incident.display();
    }

    // Priority queue
    priority_queue<
        Incident,
        vector<Incident>,
        IncidentCompare
    > pq;

    for (Incident incident : incidents)
    {
        pq.push(incident);
    }

    cout << "\n========== PRIORITY ==========\n";

    while (!pq.empty())
    {
        Incident incident = pq.top();
        pq.pop();

        cout << "Incident "
             << incident.getIncidentId()
             << " | Priority: "
             << incident.getPriority()
             << endl;
    }

    // Dispatch
    Dispatcher dispatcher;

    for (Incident incident : incidents)
    {
        pq.push(incident);
    }

    cout << "\n========== DISPATCH ==========\n";

    while (!pq.empty())
    {
        Incident incident = pq.top();
        pq.pop();

        dispatcher.dispatch(incident);
    }

    cout << "\nSystem finished.\n";

    return 0;
}
