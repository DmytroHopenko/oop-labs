#ifndef FUNC_H
#define FUNC_H

#include <iostream>
#include <string>

using namespace std;

class Device {
protected:
    string brand;
    string model;

public:
    Device(string brand, string model);

    virtual ~Device();

    virtual void displayInfo() const;

    virtual void turnOn();
};

class Portable : virtual public Device {
protected:
    double weight;

public:
    Portable(string brand, string model, double weight);

    virtual ~Portable();

    void displayInfo() const override;
};

class Computer : virtual public Device {
protected:
    string cpu;

public:
    Computer(string brand, string model, string cpu);

    virtual ~Computer();

    void displayInfo() const override;
};

class Laptop : public Portable, public Computer {
public:
    Laptop(string brand, string model, string cpu, double weight);

    virtual ~Laptop();

    void displayInfo() const override;
};

class SuperDevice : public Laptop {
    bool hasTouchscreen;

public:
    SuperDevice(string brand, string model, string cpu, double weight, bool hasTouchscreen);

    virtual ~SuperDevice();

    void displayInfo() const override;
};

#endif // FUNC_H
