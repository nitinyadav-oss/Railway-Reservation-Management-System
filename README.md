
Railway Reservation Management System (DSA in C++)

A terminal-based Railway Reservation Management System developed in C++ with a focus on Data Structures and Algorithms (DSA) concepts. The system allows users to view train details, search trains by route, book and cancel tickets, manage waiting lists, sort train records, and generate booking reports.

👥 Team Members

Roll Number| Student Name
25egjit020| nitin yadav 
25egjit022| Radha Krishna Parashar


🧠 DSA Concepts Demonstrated

Concept| Implementation in Code
Arrays| Arrays store train records, passenger records, and waiting-list passengers.
Structures| "Train", "Passenger", and "WaitingPassenger" structures represent railway entities and booking data.
Linear Search| Searches trains using train number and passengers using PNR.
Bubble Sort| Sorts trains by train number and fare.
Queue / FIFO Concept| Waiting-list passengers are processed in arrival order for a particular train.
Functions| Separate functions manage train details, bookings, cancellations, searching, sorting, and reports.

Note: This version demonstrates arrays, structures, linear search, bubble sort, and FIFO-based waiting-list management using arrays. It does not use advanced data structures such as trees, graphs, or hashing.

📌 4-Module Breakdown

Module 1: Train Details Module

- Display Train Details: Displays registered trains along with train number, train name, source, destination, departure time, arrival time, fare, and seat availability.
- Search Train by Number: Finds a train using its unique train number through Linear Search.
- Search Train by Route: Searches trains based on source and destination stations.
- Train Information: Maintains train details using an array of structures.

Module 2: Ticket Booking Module

- Book Ticket: Accepts the train number and passenger name to initiate a reservation.
- Seat Allocation: Assigns a seat number if seats are available.
- PNR Generation: Generates a unique PNR number for every booking attempt.
- Seat Availability: Decreases the available seat count after a confirmed booking.
- Waiting List: Adds passengers to the waiting list when no seats are available.
- Booking Confirmation: Displays passenger details, train information, PNR, seat number, and fare.

Module 3: Cancellation and Search Module

- Cancel Ticket: Cancels an active reservation using the Passenger Name Record (PNR).
- PNR Search: Searches confirmed passenger records using Linear Search.
- Seat Restoration: Restores the available seat count after a confirmed ticket is cancelled.
- Waiting List Promotion: Promotes a waiting-list passenger when a seat becomes available after cancellation.
- Passenger Details: Displays the passenger's booking information and associated train details.

Module 4: Sorting and Reports Module

- Sort by Train Number: Sorts train records in ascending order using Bubble Sort.
- Sort by Fare: Sorts train records in ascending order of fare using Bubble Sort.
- Booking Report: Displays the number of confirmed tickets, waiting-list passengers, and estimated booking revenue.
- Waiting List Report: Displays waiting-list passengers with their position, PNR, name, and train number.

🚀 How to Compile and Run

1. Prerequisites

- C++ compiler such as GCC ("g++"), MinGW, or Clang.
- Terminal or an IDE such as Visual Studio Code.
- Basic knowledge of C++.

2. Compilation

Open the terminal in the project directory and run:

g++ -std=c++11 main.cpp -o railway

3. Execution

Windows:

railway.exe

Linux / macOS:

./railway

💻 Sample Program Menu

==================================================
       RAILWAY RESERVATION MANAGEMENT SYSTEM
==================================================

 [Module 1: Train Details]
   1. Train Details

 [Module 2: Ticket Booking]
   2. Book Ticket

 [Module 3: Cancellation and Search]
   3. Cancel Ticket
   4. Search Passenger by PNR
   5. Search Train by Route

 [Module 4: Sorting and Reports]
   6. Sort Trains by Number
   7. Sort Trains by Fare
   8. Booking Report
   9. View Waiting List

   0. Exit
==================================================
Enter Choice:

🧪 Testing Checklist

Test Case| Expected Result
Display train details| All registered train details are displayed.
Search a valid train number| Matching train details are returned.
Search an invalid train number| Appropriate error message is displayed.
Search a valid route| Matching trains are displayed.
Book an available seat| Ticket is confirmed and a PNR is generated.
Book tickets until seats are full| Available seats become zero.
Book a ticket on a full train| Passenger is added to the waiting list.
Search using a valid PNR| Passenger and ticket details are displayed.
Search using an invalid PNR| Ticket not found message is displayed.
Cancel an active ticket| Ticket is cancelled and seat availability is updated.
Cancel ticket when waiting list exists| First eligible waiting passenger is promoted.
Sort trains by number| Trains are arranged in ascending train-number order.
Sort trains by fare| Trains are arranged in ascending fare order.
Generate booking report| Confirmed bookings, waiting passengers, and estimated revenue are displayed.
View waiting list| Waiting passengers and their positions are displayed.

⚠️ Current Limitations

- Train and passenger records are stored in memory and are lost when the program exits.
- The system supports a maximum of 5 trains, 100 passenger records, and 100 waiting-list entries.
- Each train has a predefined number of seats.
- Train information is predefined in the program.
- The current version does not include file handling or database connectivity.
- The waiting list is implemented using arrays rather than the STL Queue data structure.
- Seat allocation is basic and does not maintain a complete individual seat map.
- Revenue reports are basic and intended for demonstration.
- The system is a simulation and is not connected to the actual Indian Railway reservation system.

🔮 Future Improvements

- Implement file handling to store train and passenger records permanently.
- Use STL Queue for efficient waiting-list management.
- Implement Binary Search after sorting train numbers.
- Add date-wise train reservations.
- Improve seat allocation using a dedicated seat matrix.
- Add passenger validation and input handling.
- Add sorting by departure time.
- Implement dynamic data structures such as Linked Lists.
- Add a train and passenger management interface.
- Divide the project into separate header (".h") and source (".cpp") files.
- Improve booking reports and revenue analysis.

🎯 Conclusion

The Railway Reservation Management System is a C++ console-based project developed to demonstrate the practical implementation of Data Structures and Algorithms.

The project covers four major modules: Train Details Management, Ticket Booking, Cancellation and Search, and Sorting and Reports.

It demonstrates how arrays, structures, Linear Search, Bubble Sort, and FIFO-based waiting-list logic can be applied to build a basic railway reservation application.

This project helps students understand the practical use of DSA concepts while developing a structured, modular, and menu-driven C++ program.

Developed for academic and educational purposes.
