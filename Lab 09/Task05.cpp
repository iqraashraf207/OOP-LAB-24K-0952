//Name: Iqra Ashraf
//Roll number: 24K-0952

#include <iostream>
using namespace std;

class Shipment {
protected:
    string trackingNumber;
    double weight;

public:
    Shipment(string tn, double w) : trackingNumber(tn), weight(w) {}

    virtual void estimateDeliveryTime() = 0;
    virtual void showDetails() = 0;
    virtual ~Shipment() {}
};

class AirFreight : public Shipment {
public:
    AirFreight(string tNum, double w) : Shipment(tNum, w) {}

    void estimateDeliveryTime() override {
        cout << "Estimated Delivery Time for Air Freight: 1-3 days" << endl;
    }

    void showDetails() override {
        cout << "Air Freight -> Tracking Number: " << trackingNumber << ", Weight: " << weight << endl;
    }
};

class GroundShipment : public Shipment {
public:
    GroundShipment(string tNum, double w) : Shipment(tNum, w) {}

    void estimateDeliveryTime() override {
        cout << "Estimated Delivery Time for Ground Shipment: 4-5 days" << endl;
    }

    void showDetails() override {
        cout << "Ground Shipment -> Tracking Number: " << trackingNumber << ", Weight: " << weight << endl;
    }
};

int main() {
    AirFreight air("AF123", 13.0);
    GroundShipment ground("GS456", 25.2);

    Shipment* shipments[2];
    shipments[0] = &air;
    shipments[1] = &ground;

    for (int i = 0; i < 2; i++)
    {
        shipments[i]->showDetails();
        shipments[i]->estimateDeliveryTime();
        cout << endl;
    }

    for (int i = 0; i < 2; i++)
    {
        delete shipments[i];
    }

    return 0;
}