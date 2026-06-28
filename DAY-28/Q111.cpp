//Write a program to Create ticket booking system. 

#include <iostream>
#include <cstring>
using namespace std;

int main() {
    const int MAX = 50;   // max trains
    const int TMAX = 200; // max bookings

    int   trainNo[MAX];
    char  trainName[MAX][50];
    char  from[MAX][30];
    char  to[MAX][30];
    char  depTime[MAX][10];  // departure time e.g. "10:30"
    int   totalSeats[MAX];
    int   availSeats[MAX];
    float fare[MAX];
    int   totalTrains = 0;

    int   bookingId[TMAX];
    int   bTrainNo[TMAX];
    char  pName[TMAX][50];
    int   pAge[TMAX];
    char  pGender[TMAX][10];
    int   seatsBooked[TMAX];
    float totalFare[TMAX];
    int   totalBookings = 0;
    int   nextBookingId = 1001;

    int choice;

    do {
        cout << "\n====== TICKET BOOKING SYSTEM ======\n";
        cout << "1.  Add Train\n";
        cout << "2.  Display All Trains\n";
        cout << "3.  Search Train\n";
        cout << "4.  Book Ticket\n";
        cout << "5.  Cancel Ticket\n";
        cout << "6.  View Booking Details\n";
        cout << "7.  View All Bookings\n";
        cout << "8.  Check Seat Availability\n";
        cout << "9.  Delete Train\n";
        cout << "0.  Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            if (totalTrains >= MAX) {
                cout << "Train list full!\n";
            } else {
                cout << "Enter Train Number   : "; cin >> trainNo[totalTrains];

                int dup = 0;
                for (int i = 0; i < totalTrains; i++)
                    if (trainNo[i] == trainNo[totalTrains]) { dup = 1; break; }

                if (dup) {
                    cout << "Train number already exists!\n";
                } else {
                    cin.ignore();
                    cout << "Enter Train Name     : "; cin.getline(trainName[totalTrains], 50);
                    cout << "Enter From Station   : "; cin.getline(from[totalTrains], 30);
                    cout << "Enter To Station     : "; cin.getline(to[totalTrains], 30);
                    cout << "Enter Departure Time : "; cin.getline(depTime[totalTrains], 10);
                    cout << "Enter Total Seats    : "; cin >> totalSeats[totalTrains];
                    cout << "Enter Fare per Seat  : "; cin >> fare[totalTrains];
                    availSeats[totalTrains] = totalSeats[totalTrains];
                    totalTrains++;
                    cout << "Train added successfully!\n";
                }
            }
        }

        else if (choice == 2) {
            if (totalTrains == 0) {
                cout << "No trains available.\n";
            } else {
                cout << "\n--- Train List ---\n";
                cout << "No.\tName\t\tFrom\t\tTo\t\tTime\tSeats\tFare\n";
                cout << "-------------------------------------------------------------------\n";
                for (int i = 0; i < totalTrains; i++) {
                    cout << trainNo[i]          << "\t"
                         << trainName[i]        << "\t\t"
                         << from[i]             << "\t\t"
                         << to[i]               << "\t\t"
                         << depTime[i]          << "\t"
                         << availSeats[i] << "/" << totalSeats[i] << "\t"
                         << "Rs." << fare[i]    << "\n";
                }
            }
        }

        else if (choice == 3) {
            char sf[30], st[30];
            cin.ignore();
            cout << "Enter From Station : "; cin.getline(sf, 30);
            cout << "Enter To Station   : "; cin.getline(st, 30);

            int found = 0;
            cout << "\n--- Available Trains ---\n";
            for (int i = 0; i < totalTrains; i++) {
                if (strcmp(from[i], sf) == 0 && strcmp(to[i], st) == 0) {
                    cout << "Train No  : " << trainNo[i]    << "\n";
                    cout << "Name      : " << trainName[i]  << "\n";
                    cout << "Departure : " << depTime[i]    << "\n";
                    cout << "Seats     : " << availSeats[i] << " available\n";
                    cout << "Fare      : Rs." << fare[i]    << " per seat\n";
                    cout << "----------------------------\n";
                    found = 1;
                }
            }
            if (!found) cout << "No trains found for this route.\n";
        }

        else if (choice == 4) {
            if (totalBookings >= TMAX) {
                cout << "Booking list full!\n";
            } else {
                int tno, seats;
                cout << "Enter Train Number      : "; cin >> tno;

                int ti = -1;
                for (int i = 0; i < totalTrains; i++)
                    if (trainNo[i] == tno) { ti = i; break; }

                if (ti == -1) {
                    cout << "Train not found!\n";
                } else {
                    cout << "Available Seats         : " << availSeats[ti] << "\n";
                    cout << "Enter Number of Seats   : "; cin >> seats;

                    if (seats <= 0) {
                        cout << "Invalid seat count!\n";
                    } else if (seats > availSeats[ti]) {
                        cout << "Not enough seats! Only " << availSeats[ti] << " available.\n";
                    } else {
                        cin.ignore();
                        cout << "Enter Passenger Name    : "; cin.getline(pName[totalBookings], 50);
                        cout << "Enter Passenger Age     : "; cin >> pAge[totalBookings];
                        cout << "Enter Gender (M/F/O)    : "; cin >> pGender[totalBookings];

                        bookingId[totalBookings]   = nextBookingId++;
                        bTrainNo[totalBookings]    = tno;
                        seatsBooked[totalBookings] = seats;
                        totalFare[totalBookings]   = seats * fare[ti];
                        availSeats[ti]            -= seats;

                        cout << "\n===== BOOKING CONFIRMED =====\n";
                        cout << "Booking ID  : " << bookingId[totalBookings] << "\n";
                        cout << "Passenger   : " << pName[totalBookings]     << "\n";
                        cout << "Train       : " << trainName[ti]            << " (" << tno << ")\n";
                        cout << "From → To   : " << from[ti] << " → " << to[ti] << "\n";
                        cout << "Departure   : " << depTime[ti]              << "\n";
                        cout << "Seats       : " << seats                    << "\n";
                        cout << "Total Fare  : Rs." << totalFare[totalBookings] << "\n";
                        cout << "=============================\n";

                        totalBookings++;
                    }
                }
            }
        }

        else if (choice == 5) {
            int bid;
            cout << "Enter Booking ID to cancel: "; cin >> bid;

            int bi = -1;
            for (int i = 0; i < totalBookings; i++)
                if (bookingId[i] == bid) { bi = i; break; }

            if (bi == -1) {
                cout << "Booking not found!\n";
            } else {
                for (int i = 0; i < totalTrains; i++) {
                    if (trainNo[i] == bTrainNo[bi]) {
                        availSeats[i] += seatsBooked[bi];
                        break;
                    }
                }
                cout << "Booking " << bid << " for " << pName[bi]
                     << " cancelled. Rs." << totalFare[bi] << " refunded.\n";

                for (int i = bi; i < totalBookings - 1; i++) {
                    bookingId[i]   = bookingId[i+1];
                    bTrainNo[i]    = bTrainNo[i+1];
                    pAge[i]        = pAge[i+1];
                    seatsBooked[i] = seatsBooked[i+1];
                    totalFare[i]   = totalFare[i+1];
                    strcpy(pName[i],    pName[i+1]);
                    strcpy(pGender[i],  pGender[i+1]);
                }
                totalBookings--;
            }
        }

        else if (choice == 6) {
            int bid;
            cout << "Enter Booking ID: "; cin >> bid;

            int found = 0;
            for (int i = 0; i < totalBookings; i++) {
                if (bookingId[i] == bid) {
                    char tname[50] = "Unknown"; char frm[30] = "", tos[30] = "", dep[10] = "";
                    for (int j = 0; j < totalTrains; j++) {
                        if (trainNo[j] == bTrainNo[i]) {
                            strcpy(tname, trainName[j]);
                            strcpy(frm,   from[j]);
                            strcpy(tos,   to[j]);
                            strcpy(dep,   depTime[j]);
                            break;
                        }
                    }
                    cout << "\n===== BOOKING DETAILS =====\n";
                    cout << "Booking ID  : " << bookingId[i]   << "\n";
                    cout << "Passenger   : " << pName[i]       << "\n";
                    cout << "Age         : " << pAge[i]        << "\n";
                    cout << "Gender      : " << pGender[i]     << "\n";
                    cout << "Train       : " << tname << " (" << bTrainNo[i] << ")\n";
                    cout << "Route       : " << frm << " → " << tos << "\n";
                    cout << "Departure   : " << dep             << "\n";
                    cout << "Seats       : " << seatsBooked[i] << "\n";
                    cout << "Total Fare  : Rs." << totalFare[i]<< "\n";
                    cout << "===========================\n";
                    found = 1;
                    break;
                }
            }
            if (!found) cout << "Booking not found!\n";
        }
        else if (choice == 7) {
            if (totalBookings == 0) {
                cout << "No bookings found.\n";
            } else {
                cout << "\n--- All Bookings ---\n";
                cout << "BID\tTrain\tPassenger\t\tSeats\tFare\n";
                cout << "-------------------------------------------------------\n";
                for (int i = 0; i < totalBookings; i++) {
                    cout << bookingId[i]   << "\t"
                         << bTrainNo[i]   << "\t"
                         << pName[i]      << "\t\t"
                         << seatsBooked[i]<< "\t"
                         << "Rs." << totalFare[i] << "\n";
                }
            }
        }

        else if (choice == 8) {
            int tno;
            cout << "Enter Train Number: "; cin >> tno;
            int found = 0;
            for (int i = 0; i < totalTrains; i++) {
                if (trainNo[i] == tno) {
                    cout << "\nTrain    : " << trainName[i] << "\n";
                    cout << "Route    : " << from[i] << " → " << to[i] << "\n";
                    cout << "Total    : " << totalSeats[i] << " seats\n";
                    cout << "Booked   : " << (totalSeats[i] - availSeats[i]) << " seats\n";
                    cout << "Available: " << availSeats[i] << " seats\n";
                    if (availSeats[i] == 0)
                        cout << "Status   : FULL\n";
                    else if (availSeats[i] <= totalSeats[i] / 4)
                        cout << "Status   : ALMOST FULL\n";
                    else
                        cout << "Status   : AVAILABLE\n";
                    found = 1;
                    break;
                }
            }
            if (!found) cout << "Train not found!\n";
        }

        else if (choice == 9) {
            int tno;
            cout << "Enter Train Number to delete: "; cin >> tno;
            int di = -1;
            for (int i = 0; i < totalTrains; i++)
                if (trainNo[i] == tno) { di = i; break; }

            if (di == -1) {
                cout << "Train not found!\n";
            } else if (totalSeats[di] != availSeats[di]) {
                cout << "Cannot delete! " << (totalSeats[di] - availSeats[di])
                     << " seat(s) still booked on this train.\n";
            } else {
                for (int i = di; i < totalTrains - 1; i++) {
                    trainNo[i]      = trainNo[i+1];
                    totalSeats[i]   = totalSeats[i+1];
                    availSeats[i]   = availSeats[i+1];
                    fare[i]         = fare[i+1];
                    strcpy(trainName[i], trainName[i+1]);
                    strcpy(from[i],      from[i+1]);
                    strcpy(to[i],        to[i+1]);
                    strcpy(depTime[i],   depTime[i+1]);
                }
                totalTrains--;
                cout << "Train deleted successfully!\n";
            }
        }

        else if (choice != 0) {
            cout << "Invalid choice!\n";
        }

    } while (choice != 0);

    cout << "Thank you for using Ticket Booking System!\n";
    return 0;
}
