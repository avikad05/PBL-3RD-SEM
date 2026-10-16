
#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
#include <map>
#include <string>

#include "Caller.h"
#include "EmergencyCall.h"
#include "Incident.h"
#include "DSU.h"
#include "CallAnalyzer.h"
#include "Dispatcher.h"

using namespace std;

// Compare incidents according to priority
struct IncidentCompare
{
    bool operator()(Incident a, Incident b)
    {
        return a.getPriority() < b.getPriority();
    }
};

int main()
{
    cout << "========================================\n";
    cout << " FAKE EMERGENCY CALL DETECTION SYSTEM\n";
    cout << "========================================\n";

    // 1. TAKE DYNAMIC INPUT

    int n;

    cout << "\nEnter number of emergency calls: ";
    cin >> n;

    if (n <= 0)
    {
        cout << "Invalid number of calls.\n";
        return 0;
    }

    vector<EmergencyCall> allCalls;

    queue<EmergencyCall> incomingCalls;

    for (int i = 0; i < n; i++)
    {
        cout << "\n========== CALL " << i + 1
             << " ==========\n";

        int callerId = 101 + i;
        int callId = i + 1;

        string name, phone;
        string location, emergencyType, description;

        int severity;
        int x, y, time;

        cout << "Enter caller name: ";
        cin >> ws;
        getline(cin, name);

        cout << "Enter phone number: ";
        getline(cin, phone);

        cout << "Enter location name: ";
        getline(cin, location);

        cout << "Enter emergency type (Accident/Fire/Crime/Medical): ";
        getline(cin, emergencyType);

        cout << "Enter emergency description: ";
        getline(cin, description);

        cout << "Enter severity (1-10): ";
        cin >> severity;

        if (severity < 1 || severity > 10)
        {
            cout << "Invalid severity. Please enter 1-10.\n";
            return 0;
        }

        cout << "Enter location X coordinate: ";
        cin >> x;

        cout << "Enter location Y coordinate: ";
        cin >> y;

        cout << "Enter report time (numeric value): ";
        cin >> time;

        // Create caller
        Caller caller(
            callerId,
            name,
            phone
        );

        // Create emergency call
        EmergencyCall call(
            callId,
            caller,
            location,
            emergencyType,
            description,
            severity,
            x,
            y,
            time
        );

        // Add call to incoming queue
        incomingCalls.push(call);
    }

    cout << "\nCalls added to Queue: "
         << incomingCalls.size() << endl;

    // 2. MOVE CALLS FROM QUEUE TO VECTOR

    while (!incomingCalls.empty())
    {
        EmergencyCall currentCall = incomingCalls.front();

        incomingCalls.pop();

        allCalls.push_back(currentCall);
    }

    cout << "Calls processed from Queue: "
         << allCalls.size() << endl;

    // 3. HASH MAP

    unordered_map<string, vector<int>> hashMap;

    cout << "\n========== HASH MAP ANALYSIS ==========\n";

    for (int i = 0; i < (int)allCalls.size(); i++)
    {
        string key = CallAnalyzer::createHashKey(allCalls[i]);

        hashMap[key].push_back(allCalls[i].getCallId());

        cout << "Key: " << key
             << " -> Call ID: "
             << allCalls[i].getCallId()
             << endl;
    }

    // 4. DSU: FIND RELATED CALLS

    DSU dsu(allCalls.size());

    for (int i = 0; i < (int)allCalls.size(); i++)
    {
        for (int j = i + 1; j < (int)allCalls.size(); j++)
        {
            if (CallAnalyzer::areRelated(
                    allCalls[i],
                    allCalls[j]))
            {
                dsu.unite(i, j);
            }
        }
    }

    // 5. GROUP CALLS USING DSU

    map<int, vector<int>> groups;

    for (int i = 0; i < (int)allCalls.size(); i++)
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

    // 6. CREATE INCIDENTS

    vector<Incident> incidents;

    int incidentId = 1;

    for (auto group : groups)
    {
        vector<int> callIndexes = group.second;

        EmergencyCall firstCall = allCalls[callIndexes[0]];

        int highestSeverity = 0;

        for (int index : callIndexes)
        {
            if (allCalls[index].getSeverity() > highestSeverity)
            {
                highestSeverity = allCalls[index].getSeverity();
            }
        }

        int numberOfReports = callIndexes.size();

        // Calculate priority automatically
        int priority = CallAnalyzer::calculatePriority(
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
            incident.addCall(allCalls[index].getCallId());
        }

        // Check for low-information reports
        for (int index : callIndexes)
        {
            if (CallAnalyzer::isLowInformation(allCalls[index]))
            {
                incident.setLowInformation(true);
            }
        }

        incidents.push_back(incident);

        incidentId++;
    }

    // 7. DISPLAY INCIDENTS

    cout << "\n========== DETECTED INCIDENTS ==========\n";

    for (int i = 0; i < (int)incidents.size(); i++)
    {
        incidents[i].display();
    }

    // 8. PRIORITY QUEUE

    priority_queue<
        Incident,
        vector<Incident>,
        IncidentCompare
    > priorityQueue;

    for (int i = 0; i < (int)incidents.size(); i++)
    {
        priorityQueue.push(incidents[i]);
    }

    cout << "\n========== PRIORITY QUEUE ==========\n";

    while (!priorityQueue.empty())
    {
        Incident highestPriority = priorityQueue.top();

        priorityQueue.pop();

        cout << "Incident "
             << highestPriority.getIncidentId()
             << " | Priority = "
             << highestPriority.getPriority()
             << endl;
    }

    // 9. DISPATCH INCIDENTS

    Dispatcher dispatcher;

    cout << "\n========== DISPATCHING ==========\n";

    // The previous queue is empty, so fill it again
    for (int i = 0; i < (int)incidents.size(); i++)
    {
        priorityQueue.push(incidents[i]);
    }

    while (!priorityQueue.empty())
    {
        Incident incident = priorityQueue.top();

        priorityQueue.pop();

        dispatcher.dispatch(incident);
    }

    cout << "\n========================================\n";
    cout << " SYSTEM FINISHED SUCCESSFULLY\n";
    cout << "========================================\n";

    return 0;
}
