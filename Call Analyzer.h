#ifndef CALLANALYZER_H
#define CALLANALYZER_H

#include <iostream>
#include <cmath>
#include <string>
#include "EmergencyCall.h"

using namespace std;

class CallAnalyzer
{
public:

    // Calculate distance between two calls
    static double calculateDistance(
        EmergencyCall a,
        EmergencyCall b
    )
    {
        double dx = a.getX() - b.getX();
        double dy = a.getY() - b.getY();

        return sqrt(dx * dx + dy * dy);
    }

    // Check whether two calls are related
    static bool areRelated(
        EmergencyCall a,
        EmergencyCall b
    )
    {
        // Emergency type must be same
        if (a.getEmergencyType() !=
            b.getEmergencyType())
        {
            return false;
        }

        // Check location distance
        double distance =
            calculateDistance(a, b);

        if (distance > 5)
        {
            return false;
        }

        // Check time difference
        int timeDifference =
            abs(a.getTime() - b.getTime());

        if (timeDifference > 15)
        {
            return false;
        }

        return true;
    }

    // Check for low information
    static bool isLowInformation(
        EmergencyCall call
    )
    {
        if (call.getDescription().length() < 10)
        {
            return true;
        }

        if (call.getLocation() == "")
        {
            return true;
        }

        return false;
    }

    // Create key for Hash Map
    static string createHashKey(
        EmergencyCall call
    )
    {
        return call.getEmergencyType()
               + "_"
               + call.getLocation();
    }

    // Calculate priority
    static int calculatePriority(
        int severity,
        int numberOfReports
    )
    {
        int priority =
            severity * 10
            + numberOfReports * 5;

        return priority;
    }
};

#endif
