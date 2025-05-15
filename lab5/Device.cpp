#include "Device.h"

Device::Device(string brand, string model, double weight)
    : brand(brand), model(model), weight(weight) {
    cout << "Device constructor\n";
}

Device::~Device() {
    cout << "Device destructor\n";
}

void Device::displayInfo() const {
    cout << "Brand: " << brand << ", Model: " << model << endl;
    cout << "Weight: " << weight << " kg" << endl;
}

void Device::turnOn() {
    cout << brand << " device is now ON." << endl;
}

// Portable
Portable::Portable(string brand, string model, double weight)
    : Device(brand, model, weight) {
    cout << "Portable constructor\n";
}

Portable::~Portable() {
    cout << "Portable destructor\n";
}

void Portable::displayInfo() const {
    Device::displayInfo();
}

// Phone
Phone::Phone(string brand, string model, double weight)
    : Device(brand, model, weight) {
    cout << "Phone constructor\n";
}

Phone::~Phone() {
    cout << "Phone destructor\n";
}

void Phone::displayInfo() const {
    Device::displayInfo();
}

// Computer
Computer::Computer(string brand, string model, string cpu)
    : Device(brand, model, 0), cpu(cpu) {
    cout << "Computer constructor\n";
}

Computer::~Computer() {
    cout << "Computer destructor\n";
}

void Computer::displayInfo() const {
    Device::displayInfo();
    cout << "CPU: " << cpu << endl;
}

// Laptop
Laptop::Laptop(string brand, string model, string cpu, double weight)
    : Device(brand, model, weight),
      Computer(brand, model, cpu),
      Portable(brand, model, weight) {
    cout << "Laptop constructor\n";
}

Laptop::~Laptop() {
    cout << "Laptop destructor\n";
}

void Laptop::displayInfo() const {
    Computer::displayInfo();
}

// SuperDevice
SuperDevice::SuperDevice(string brand, string model, string cpu, double weight, bool hasTouchscreen)
    : Device(brand, model, weight),
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

// SmartHybridDevice
SmartHybridDevice::SmartHybridDevice(string brand, string model, string cpu, double weight, bool hasTouchscreen)
    : Device(brand, model, weight),
      Portable(brand, model, weight),
      Phone(brand, model, weight),
      Computer(brand, model, cpu),
      hasTouchscreen(hasTouchscreen) {
    cout << "SmartHybridDevice constructor\n";
}

SmartHybridDevice::~SmartHybridDevice() {
    cout << "SmartHybridDevice destructor\n";
}

void SmartHybridDevice::displayInfo() const {
    Device::displayInfo();
    cout << "Touchscreen: " << (hasTouchscreen ? "Yes" : "No") << endl;
}
