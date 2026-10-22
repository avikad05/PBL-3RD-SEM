# PBL-3RD-SEM

# Emergency Call Detection and Priority Routing System

## 1. Overview

The **Emergency Call Detection and Priority Routing System** is a C++-based project designed to organize incoming emergency reports, identify duplicate or related calls, group them into incidents, and prioritize incidents according to their urgency and severity.

The system uses Data Structures and Algorithms (DSA) and Object-Oriented Programming (OOP) concepts to help dispatchers identify critical incidents and select appropriate emergency response teams.

## 2. Problem Statement

During emergencies, multiple people may report the same incident with different or incomplete information. Processing every report separately can create confusion, waste resources, and delay emergency responses.

The project aims to organize emergency reports, identify related calls, consolidate them into incidents, and prioritize them for efficient response management.

## 3. Objectives

- Process incoming emergency reports in an organized manner.
- Identify duplicate, related, and incomplete reports.
- Group related reports into a single incident.
- Calculate incident priority based on urgency and severity.
- Maintain incidents in priority order.
- Assist in selecting suitable emergency response teams.
- Apply DSA and OOP concepts to a real-world problem.

## 4. Purpose, Features and Modules

### Purpose

The purpose of the project is to demonstrate how data structures and object-oriented programming can improve the organization and prioritization of emergency reports.

### Key Features

- **Emergency Report Management:** Stores and processes incoming reports.
- **Duplicate Detection:** Identifies reports with matching details using a hash map.
- **Low-Information Detection:** Flags reports that contain insufficient information.
- **Incident Grouping:** Groups related reports using Graph and Disjoint Set Union (DSU) concepts.
- **Priority Management:** Places higher-priority incidents ahead of lower-priority incidents.
- **Response Team Selection:** Selects an appropriate team according to the emergency type.
- **Incident Monitoring:** Supports tracking incident details and dispatch status through the system workflow.

### Major Modules

1. **Emergency Call Module:** Stores caller details, location, emergency type, description, severity, and timestamp.
2. **Queue Manager:** Manages incoming reports in FIFO order.
3. **Call Analyzer:** Checks report information and identifies related or incomplete reports.
4. **Incident Manager:** Groups related reports and maintains consolidated incident information.
5. **Priority Manager:** Organizes incidents according to their calculated priority.
6. **Dispatcher:** Selects and assigns the appropriate response team.
7. **Response Team Module:** Represents ambulance, police, and fire response teams.

## 5. System Workflow

The system follows this processing sequence:

1. Receive an emergency report.
2. Store the report in the incoming queue.
3. Analyze its information and check for duplicate or related reports.
4. Identify relationships between reports.
5. Group related reports into incidents.
6. Create or update the corresponding incident.
7. Calculate the incident's priority.
8. Insert the incident into the priority queue.
9. Select the highest-priority incident for processing.
10. Assign a suitable response team.

**Data Flow:** Incoming Reports → Queue → Call Analysis → Relationship Detection → Incident Grouping → Incident Creation/Update → Priority Queue → Dispatch → Response Team.

## 6. Data Structures and Algorithms (DSA)

The project uses the following data structures:

| Data Structure | Purpose |
|---|---|
| Queue | Processes incoming emergency reports in FIFO order. |
| Hash Map | Supports fast lookup and duplicate-report identification. |
| Graph | Represents relationships between related reports. |
| Disjoint Set Union (DSU) | Groups connected reports into the same incident. |
| Priority Queue | Organizes incidents according to priority for dispatching. |

These structures help organize reports, reduce repeated processing, and manage incident priorities efficiently.

## 7. Object-Oriented Programming (OOP)

The project uses C++ classes to represent the major components of the system.

- **Encapsulation:** Keeps related data and operations within classes.
- **Inheritance:** Supports specialized response team classes derived from a common base class.
- **Polymorphism:** Allows common operations to be implemented differently for different response teams, where applicable.
- **Abstraction:** Separates the responsibilities of call analysis, incident management, and dispatching.
- **STL:** Provides standard data structures and utilities for implementing the system.

### Important Classes

- `EmergencyCall` – Stores emergency report details.
- `Caller` – Stores caller information.
- `Incident` – Represents a consolidated incident.
- `CallAnalyzer` – Analyzes reports and identifies relationships.
- `Dispatcher` – Handles response-team assignment.
- `ResponseTeam` – Represents the common response-team structure.
- `DSU` – Supports grouping related reports.

## 8. Technology Stack

| Technology | Purpose |
|---|---|
| C++ | Core application development |
| C++ STL | Implementation of queues, hash maps, and priority queues |
| Graph and DSU | Relationship detection and incident grouping |
| Object-Oriented Programming | Modular and maintainable code |
| Visual Studio Code | Development environment |
| Git | Version control |
| GitHub | Source-code hosting and team collaboration |

The current prototype is console-based and does not require an external database, network API, or real-time GPS integration.

## 9. Team Members and Contributions

**Team Name:** NOVEXA

| Team Member | Role | Contribution |
|---|---|---|
| Avika Dixit | Team Lead | Data structure implementation and incident grouping |
| Harshita Bisht | Developer | Emergency report handling and call analysis |
| Saksham Mittal | Developer | Project design and system workflow |
| Nitin Singh Bhandari | Developer | Incident prioritization and response-team implementation |

## 10. Current Project Status

The project has a working prototype that uses predefined emergency-call inputs. Its core functionality has been tested using predefined test cases.

### Phase I — Planning and Design

- Problem identification and requirement analysis.
- Selection of suitable data structures.
- System architecture and workflow design.
- Identification of major classes and modules.

**Status:** Completed.

### Phase II — Core Implementation

- Queue-based emergency report handling.
- Hash-map-based duplicate identification.
- Call analysis and low-information detection.
- Incident priority management.
- Basic response-team selection and dispatch.
- Testing of the static-input prototype.
- Replace predefined inputs with dynamic user input.
- Connect and improve report and incident updates.

**Status:** Core prototype implemented; some integration and incident-grouping tasks remain in progress.

### Phase III — Planned Development

- Develop and improve the UI/UX dashboard.
- Complete integration and testing.

**Status:** Planned and in progress as development continues.

## 11. Setup and Installation

### Prerequisites

- A C++ compiler, such as GCC or MinGW.
- Visual Studio Code or another C++ development environment.
- Git installed on your system.

### Step 1: Clone the Repository

```bash
git clone https://github.com/avikad05/PBL-3RD-SEM.git
```

### Step 2: Open the Project Folder

```bash
cd PBL-3RD-SEM
```

### Step 3: Compile the Program

If `main.cpp` is the main source file and the required headers are in the same directory:

```bash
g++ main.cpp -o emergency_system
```

### Step 4: Run the Program

On Linux or macOS:

```bash
./emergency_system
```

On Windows:

```bash
emergency_system.exe
```

**Note:** These commands assume that `main.cpp` includes the required implementation files and that the project can be built from that source file alone. If additional `.cpp` files are present, include them in the compilation command.

## 12. Features to Be Used / Further Development

The following features are planned or require further development:

- Dynamic emergency-report input.
- Improved incident creation and updating.
- More complete integration of report analysis and incident grouping.
- An interactive UI/UX dashboard.
- Improved monitoring of incident and dispatch status.
- Additional test cases for incomplete, duplicate, and conflicting reports.

## 13. Project Roadmap

| Phase | Planned Work | Status |
|---|---|---|
| Phase I | Requirements, planning, and system architecture | Completed |
| Phase II | Core C++ modules and static-input prototype | Core implementation completed |
| Phase III | Dynamic input and improved interaction | In progress/planned |
| Phase III | Module integration and dashboard development | In progress |
| Final Stage | Comprehensive testing and documentation | Pending completion |

## 14. Future Scope

The project can be extended with the following improvements:

- **Graphical Dashboard:** Display incoming reports, incidents, and their priority levels.
- **Database Integration:** Store incident history and caller information persistently.
- **Location Integration:** Use real-time location services to support incident matching.
- **Advanced Similarity Detection:** Improve identification of related reports using more detailed matching rules.
- **Notifications:** Notify the appropriate response teams about assigned incidents.
- **Performance Evaluation:** Test the system with larger datasets and measure processing time and grouping accuracy.
- **Real-Time Integration:** Explore integration with authorized emergency-service systems, subject to operational and security requirements.

These are potential extensions, not capabilities of the current prototype.

## 15. Repository Structure

The following is the logical structure of the main project files. Actual filenames and directories should match the repository.

```text
PBL-3RD-SEM/
│
├── main.cpp
├── Caller.h
├── EmergencyCall.h
├── Incident.h
├── DSU.h
├── CallAnalyzer.h
├── ResponseTeam.h
├── Dispatcher.h
└── README.md
```

### Main File Descriptions

- `main.cpp` – Runs the program and coordinates emergency-report processing using predefined inputs in the current prototype.
- `Caller.h` – Stores caller information.
- `EmergencyCall.h` – Defines emergency-call details.
- `Incident.h` – Represents a consolidated incident and its priority information.
- `DSU.h` – Provides operations for grouping related reports.
- `CallAnalyzer.h` – Analyzes reports, checks their information, and supports incident prioritization.
- `ResponseTeam.h` – Defines the emergency response-team structure.
- `Dispatcher.h` – Handles response-team selection and assignment.
- `README.md` – Documents the project, setup, features, and development progress.

## 16. Expected Outcomes

The expected outcome is a functional C++ prototype capable of processing emergency reports, identifying related calls, consolidating incidents, prioritizing urgent situations, and supporting response-team assignment.

The project demonstrates the practical application of DSA and OOP concepts in an emergency-response management scenario.

## 17. Repository Link

GitHub Repository: https://github.com/avikad05/PBL-3RD-SEM/

**Project:** Emergency Call Detection and Priority Routing System  
**Team:** NOVEXA  
**Language:** C++
