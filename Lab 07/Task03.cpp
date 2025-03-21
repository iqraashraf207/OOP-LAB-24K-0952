//Name: Iqra Ashraf
//Roll number: 24K-0952

#include <iostream>
#include <string>
using namespace std;

class Ticket {
protected:
    int ticketID;
    string passengerName;
    double price;
    string date;
    string destination;

public:
    Ticket(int id, string name, double pr, string d, string dest) : ticketID(id), passengerName(name), price(pr), date(d), destination(dest) {}
    
    virtual void reserve() {
        cout << "Ticket reserved for " << passengerName << " on " << date << " to " << destination << endl;
    }
    
    virtual void cancel() {
        cout << "Ticket cancelled for " << passengerName << endl;
    }
    
    virtual void displayTicketInfo() const {
        cout << "Ticket ID: " << ticketID << endl;
        cout << "Passenger Name: " << passengerName << endl;
        cout << "Price: " << price << endl;
        cout << "Date: " << date << endl;
        cout << "Destination: " << destination << endl;
    }
    
};

class FlightTicket : public Ticket {
private:
    string airlineName;
    string flightNumber;
    string seatClass;

public:
    FlightTicket(int id, string name, double pr, string d, string dest, string airline, string num, string seat) : Ticket(id, name, pr, d, dest), airlineName(airline), flightNumber(num), seatClass(seat) {}
    
    void displayTicketInfo() {
        Ticket::displayTicketInfo();
        cout << "Airline: " << airlineName << endl;
        cout << "Flight Number: " << flightNumber << endl;
        cout << "Seat Class: " << seatClass << endl;
    }
};

class TrainTicket : public Ticket {
private:
    string trainNumber;
    string coachType;
    string departureTime;

public:
    TrainTicket(int id, string name, double pr, string d, string dest, string num, string coach, string time) : Ticket(id, name, pr, d, dest), trainNumber(num), coachType(coach), departureTime(time) {}
    
    void reserve() {
        cout << "Train ticket reserved for " << passengerName << ". Seat auto assigned." << endl;
    }
};

class BusTicket : public Ticket {
private:
    string busCompany;
    string seatNumber;

public:
    BusTicket(int id, string name, double pr, string d, string dest, string company, string num) : Ticket(id, name, pr, d, dest), busCompany(company), seatNumber(num) {}
    
    void cancel() {
        cout << "Bus ticket cancelled for " << passengerName << ". Last minute regund available." << endl;
    }
};

class ConcertTicket : public Ticket {
private:
    string artistName;
    string venue;
    string seatType;

public:
    ConcertTicket(int id, string name, double p, string d, string dest, string artist, string v, string type) : Ticket(id, name, p, d, dest), artistName(artist), venue(v), seatType(type) {}
    
    void displayTicketInfo() {
        Ticket::displayTicketInfo();
        cout << "Artist: " << artistName << endl;
        cout << "Venue: " << venue << endl;
        cout << "Seat Type: " << seatType << endl;
    }
};

int main() {
    FlightTicket flight(12, "Hamna", 350, "2025-05-05", "Lahore", "Air Sial", "6709", "Economy");
    TrainTicket train(34, "Khalid", 178, "2025-04-13", "Islamabad", "Karakoram", "Sleeper", "10:00 AM");
    BusTicket bus(56, "Sara", 100, "2025-06-20", "Karachi", "Faisal Movers", "D03");
    ConcertTicket concert(78, "Dania", 250, "2025-09-01", "Pechs", "Pop Singer", "Marquee", "Normal");

    flight.displayTicketInfo();
    train.reserve();
    bus.cancel();
    concert.displayTicketInfo();
    
    return 0;
}