#include "Device.h"

Device::Device(string brand, string model) : brand(brand), model(model) {
    cout << "Device constructor\n";
}

Device::~Device() {
    cout << "Device destructor\n";
}

void Device::displayInfo() const {
    cout << "Brand: " << brand << ", Model: " << model << endl;
}

Computer::Computer(string brand, string model, string cpu)
    : Device(brand, model), cpu(cpu) {
    cout << "Computer constructor\n";
}

Computer::~Computer() {
    cout << "Computer destructor\n";
}

void Computer::displayInfo() const {
    Device::displayInfo();
    cout << "CPU: " << cpu << endl;
}

Portable::Portable(string brand, string model, double weight)
    : Device(brand, model), weight(weight) {
    cout << "Portable constructor\n";
}

Portable::~Portable() {
    cout << "Portable destructor\n";
}

void Portable::displayInfo() const {
    Device::displayInfo();
    cout << "Weight: " << weight << " kg" << endl;
}

// Laptop
Laptop::Laptop(string brand, string model, string cpu, double weight)
    : Device(brand, model), Computer(brand, model, cpu), Portable(brand, model, weight) {
    cout << "Laptop constructor\n";
}

Laptop::~Laptop() {
    cout << "Laptop destructor\n";
}

void Laptop::displayInfo() const {
    Computer::displayInfo();
    Portable::displayInfo();
}

// SuperDevice
SuperDevice::SuperDevice(string brand, string model, string cpu, double weight, bool hasTouchscreen)
    : Device(brand, model),
      Laptop(brand, model, cpu, weight),
      hasTouchscreen(hasTouchscreen) {
    cout << "SuperDevice constructor\n";
}

SuperDevice::~SuperDevice() {
    cout << "SuperDevice destructor\n";
}

void SuperDevice::displayInfo() const {
    Laptop::displayInfo();
    cout << "Touchscreen: " << (hasTouchscreen ? "Yes" : "No") << endl;
}

void Device::turnOn() {
    cout << brand << " device is now ON." << endl;
}

