#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Ticket {
public:
    int ticketID;
    string name;
    int age;
    string trainName;
    bool isBooked;

    Ticket() : ticketID(0), name(""), age(0), trainName(""), isBooked(false) {}

    void bookTicket(int id, string pName, int pAge, string tName) {
        ticketID = id;
        name = pName;
        age = pAge;
        trainName = tName;
        isBooked = true;
        cout << "\nTicket booked successfully! ID: " << ticketID << endl;
    }

    void displayTicket() {
        if (isBooked) {
            cout << "\n--- Ticket Details ---";
            cout << "\nID: " << ticketID << " | Name: " << name << " | Age: " << age;
            cout << " | Train: " << trainName << endl;
        }
    }

    void cancel() {
        isBooked = false;
        cout << "\nTicket ID " << ticketID << " cancelled." << endl;
    }
};

int main() {
    vector<Ticket> bookings(100); // System capacity for 100 tickets
    int choice, count = 0;

    while (true) {
        cout << "\n--- Railway Reservation System ---";
        cout << "\n1. Book Ticket\n2. View Bookings\n3. Cancel Ticket\n4. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        if (choice == 1) {
            string name, tName;
            int age;
            cout << "Enter Name: "; cin >> name;
            cout << "Enter Age: "; cin >> age;
            cout << "Enter Train Name: "; cin >> tName;
            bookings[count].bookTicket(count + 101, name, age, tName);
            count++;
        } 
        else if (choice == 2) {
            for (int i = 0; i < count; i++) bookings[i].displayTicket();
        } 
        else if (choice == 3) {
            int id;
            cout << "Enter Ticket ID to cancel: "; cin >> id;
            for (int i = 0; i < count; i++) {
                if (bookings[i].ticketID == id) bookings[i].cancel();
            }
        } 
        else break;
    }
    return 0;
}
