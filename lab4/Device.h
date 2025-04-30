#ifndef VEHICLE_H
#define VEHICLE_H

#include <iostream>
#include <string>

using namespace std;

class Device {
protected:
    string brand;
    string model;

public:
    Device(string brand, string model);

    virtual void displayInfo();

    virtual void turnOn();
};

class Laptop : public Device {
protected:
    int ramGB;

public:
    Laptop(string brand, string model, int ramGB);

    void displayInfo() override;

    void turnOn() override;

    void upgradeRAM(int additionalGB);
};

class Smartphone : public Device {
    bool has5G;

public:
    Smartphone(string brand, string model, bool has5G);

    void displayInfo() override;

    void turnOn() override;
};

class Tablet : public Device {
    bool hasStylus;

public:
    Tablet(string brand, string model, bool hasStylus);

    void displayInfo() override;

    void turnOn() override;
};

class GamingLaptop : public Laptop {
    string gpu;

public:
    GamingLaptop(string brand, string model, int ramGB, string gpu);

    void displayInfo() override;

    void turnOn() override;
};

#endif //VEHICLE_H
