
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

// ================= GLOBAL LIMITS =================
const int MAX_TRAINS = 5;
const int MAX_PASSENGERS = 100;
const int MAX_WAITING = 100;

// ================= STRUCTURES =================
struct Train {
    int trainNo;
    string trainName;
    string source;
    string destination;
    string departure;
    string arrival;
    int totalSeats;
    int availableSeats;
    float fare;
};

struct Passenger {
    int pnr;
    string name;
    int trainNo;
    int seatNo;
    bool confirmed;
};

struct WaitingPassenger {
    string name;
    int trainNo;
    int pnr;
};

// ================= ARRAYS =================
Train trains[MAX_TRAINS] = {
    {12001, "Shatabdi Express", "Jaipur", "Delhi",
     "06:00", "10:30", 2, 2, 750},

    {12951, "Rajdhani Express", "Delhi", "Mumbai",
     "16:00", "08:00", 2, 2, 1800},

    {12181, "Day Express", "Jaipur", "Ajmer",
     "09:00", "12:00", 2, 2, 250},

    {12301, "Howrah Express", "Delhi", "Kolkata",
     "18:00", "10:00", 2, 2, 1200},

    {12414, "Intercity Express", "Jaipur", "Delhi",
     "14:00", "19:00", 2, 2, 500}
};

Passenger passengers[MAX_PASSENGERS];
WaitingPassenger waitingList[MAX_WAITING];

int passengerCount = 0;
int waitingCount = 0;
int nextPNR = 1001;

// ================= MODULE 1 =================

// Display train details
void displayTrains() {
    cout << "\n================ TRAIN DETAILS ================\n";

    cout << left
         << setw(10) << "Train No"
         << setw(22) << "Train Name"
         << setw(15) << "Source"
         << setw(15) << "Destination"
         << setw(12) << "Departure"
         << setw(12) << "Arrival"
         << setw(10) << "Seats"
         << setw(10) << "Fare" << endl;

    for (int i = 0; i < MAX_TRAINS; i++) {
        cout << left
             << setw(10) << trains[i].trainNo
             << setw(22) << trains[i].trainName
             << setw(15) << trains[i].source
             << setw(15) << trains[i].destination
             << setw(12) << trains[i].departure
             << setw(12) << trains[i].arrival
             << setw(10) << trains[i].availableSeats
             << setw(10) << trains[i].fare
             << endl;
    }
}

// Search train using Linear Search
int searchTrain(int trainNo) {
    for (int i = 0; i < MAX_TRAINS; i++) {
        if (trains[i].trainNo == trainNo)
            return i;
    }
    return -1;
}

// Search train by route
void searchByRoute() {
    string src, dest;

    cout << "Enter Source: ";
    cin >> src;

    cout << "Enter Destination: ";
    cin >> dest;

    bool found = false;

    for (int i = 0; i < MAX_TRAINS; i++) {
        if (trains[i].source == src &&
            trains[i].destination == dest) {

            cout << "\nTrain Found: "
                 << trains[i].trainName
                 << " | Train No: " << trains[i].trainNo
                 << " | Departure: " << trains[i].departure
                 << " | Fare: " << trains[i].fare
                 << " | Available Seats: "
                 << trains[i].availableSeats << endl;

            found = true;
        }
    }

    if (!found)
        cout << "\nNo train found for this route.\n";
}

// ================= MODULE 2 =================

// Book ticket
void bookTicket() {
    int trainNo;
    string name;

    displayTrains();

    cout << "\nEnter Train Number: ";
    cin >> trainNo;

    int index = searchTrain(trainNo);

    if (index == -1) {
        cout << "Invalid train number!\n";
        return;
    }

    cout << "Enter Passenger Name: ";
    cin.ignore();
    getline(cin, name);

    int pnr = nextPNR++;

    if (trains[index].availableSeats > 0) {
        int seatNo = trains[index].totalSeats -
                     trains[index].availableSeats + 1;

        trains[index].availableSeats--;

        passengers[passengerCount++] =
            {pnr, name, trainNo, seatNo, true};

        cout << "\n===== TICKET CONFIRMED =====\n";
        cout << "Passenger : " << name << endl;
        cout << "PNR      : " << pnr << endl;
        cout << "Train    : " << trains[index].trainName << endl;
        cout << "Seat No  : " << seatNo << endl;
        cout << "Fare     : Rs. " << trains[index].fare << endl;
    }
    else if (waitingCount < MAX_WAITING) {
        waitingList[waitingCount++] =
            {name, trainNo, pnr};

        cout << "\nNo seats available.\n";
        cout << "Passenger added to Waiting List.\n";
        cout << "Waiting PNR: " << pnr << endl;
    }
    else {
        cout << "Waiting list is full!\n";
    }
}

// ================= MODULE 3 =================

// Search passenger by PNR
int searchPNR(int pnr) {
    for (int i = 0; i < passengerCount; i++) {
        if (passengers[i].pnr == pnr &&
            passengers[i].confirmed) {
            return i;
        }
    }
    return -1;
}

// Display ticket using PNR
void searchPassenger() {
    int pnr;

    cout << "Enter PNR: ";
    cin >> pnr;

    int index = searchPNR(pnr);

    if (index == -1) {
        cout << "Confirmed ticket not found.\n";
        return;
    }

    Passenger p = passengers[index];
    int t = searchTrain(p.trainNo);

    cout << "\n===== PASSENGER DETAILS =====\n";
    cout << "PNR         : " << p.pnr << endl;
    cout << "Name        : " << p.name << endl;
    cout << "Train Number: " << p.trainNo << endl;
    cout << "Train Name  : " << trains[t].trainName << endl;
    cout << "Seat Number : " << p.seatNo << endl;
    cout << "Fare        : Rs. " << trains[t].fare << endl;
}

// Promote first waiting passenger for a train
void promoteWaitingPassenger(int trainNo) {
    for (int i = 0; i < waitingCount; i++) {
        if (waitingList[i].trainNo == trainNo) {

            int trainIndex = searchTrain(trainNo);

            if (trainIndex == -1)
                return;

            string name = waitingList[i].name;
            int pnr = waitingList[i].pnr;

            int seatNo = trains[trainIndex].totalSeats -
                         trains[trainIndex].availableSeats + 1;

            trains[trainIndex].availableSeats--;

            passengers[passengerCount++] =
                {pnr, name, trainNo, seatNo, true};

            cout << "\nWaiting passenger promoted!\n";
            cout << "Name: " << name << endl;
            cout << "PNR: " << pnr << endl;
            cout << "New Seat: " << seatNo << endl;

            // Remove from waiting list
            for (int j = i; j < waitingCount - 1; j++) {
                waitingList[j] = waitingList[j + 1];
            }

            waitingCount--;
            return;
        }
    }
}

// Cancel ticket
void cancelTicket() {
    int pnr;

    cout << "Enter PNR to cancel: ";
    cin >> pnr;

    int index = searchPNR(pnr);

    if (index == -1) {
        cout << "Ticket not found.\n";
        return;
    }

    int trainNo = passengers[index].trainNo;

    passengers[index].confirmed = false;

    int trainIndex = searchTrain(trainNo);

    if (trainIndex != -1) {
        trains[trainIndex].availableSeats++;
    }

    cout << "Ticket cancelled successfully.\n";

    // First check waiting list
    promoteWaitingPassenger(trainNo);
}

// ================= MODULE 4 =================

// Bubble Sort by train number
void sortByTrainNumber() {
    for (int i = 0; i < MAX_TRAINS - 1; i++) {
        for (int j = 0; j < MAX_TRAINS - i - 1; j++) {
            if (trains[j].trainNo > trains[j + 1].trainNo) {
                Train temp = trains[j];
                trains[j] = trains[j + 1];
                trains[j + 1] = temp;
            }
        }
    }

    cout << "\nTrains sorted by Train Number.\n";
    displayTrains();
}

// Sort by fare
void sortByFare() {
    for (int i = 0; i < MAX_TRAINS - 1; i++) {
        for (int j = 0; j < MAX_TRAINS - i - 1; j++) {
            if (trains[j].fare > trains[j + 1].fare) {
                Train temp = trains[j];
                trains[j] = trains[j + 1];
                trains[j + 1] = temp;
            }
        }
    }

    cout << "\nTrains sorted by Fare.\n";
    displayTrains();
}

// Booking report
void bookingReport() {
    cout << "\n========== BOOKING REPORT ==========\n";

    int confirmed = 0;
    float revenue = 0;

    for (int i = 0; i < passengerCount; i++) {
        if (passengers[i].confirmed) {
            confirmed++;
            int t = searchTrain(passengers[i].trainNo);

            if (t != -1)
                revenue += trains[t].fare;
        }
    }

    cout << "Confirmed Tickets: " << confirmed << endl;
    cout << "Waiting Passengers: " << waitingCount << endl;
    cout << "Estimated Revenue: Rs. " << revenue << endl;
}

// Display waiting list
void displayWaitingList() {
    cout << "\n========== WAITING LIST ==========\n";

    if (waitingCount == 0) {
        cout << "Waiting list is empty.\n";
        return;
    }

    for (int i = 0; i < waitingCount; i++) {
        cout << "Position: " << i + 1
             << " | PNR: " << waitingList[i].pnr
             << " | Name: " << waitingList[i].name
             << " | Train: " << waitingList[i].trainNo
             << endl;
    }
}

// ================= MAIN MENU =================
int main() {
    int choice;

    do {
        cout << "\n=====================================\n";
        cout << " RAILWAY RESERVATION MANAGEMENT SYSTEM\n";
        cout << "=====================================\n";
        cout << "1. Train Details\n";
        cout << "2. Book Ticket\n";
        cout << "3. Cancel Ticket\n";
        cout << "4. Search Passenger by PNR\n";
        cout << "5. Search Train by Route\n";
        cout << "6. Sort Trains by Number\n";
        cout << "7. Sort Trains by Fare\n";
        cout << "8. Booking Report\n";
        cout << "9. View Waiting List\n";
        cout << "0. Exit\n";
        cout << "=====================================\n";

        cout << "Enter Choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                displayTrains();
                break;

            case 2:
                bookTicket();
                break;

            case 3:
                cancelTicket();
                break;

            case 4:
                searchPassenger();
                break;

            case 5:
                searchByRoute();
                break;

            case 6:
                sortByTrainNumber();
                break;

            case 7:
                sortByFare();
                break;

            case 8:
                bookingReport();
                break;

            case 9:
                displayWaitingList();
                break;

            case 0:
                cout << "Thank you for using Railway Reservation System!\n";
                break;

            default:
                cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 0);

    return 0;
}
