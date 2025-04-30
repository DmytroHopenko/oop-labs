#include "Device.h"

Device::Device(string brand, string model) : brand(brand), model(model) {}

void Device::displayInfo() {
    cout << "Brand: " << brand << ", Model: " << model << endl;
}

void Device::turnOn() {
    cout << brand << " device is now ON." << endl;
}

Laptop::Laptop(string brand, string model, int ramGB) : Device(brand, model), ramGB(ramGB) {}

void Laptop::displayInfo() {
    Device::displayInfo();
    cout << "RAM: " << ramGB << " GB" << endl;
}

void Laptop::turnOn() {
    cout << "Booting up laptop..." << endl;
}

void Laptop::upgradeRAM(int additionalGB) {
    ramGB += additionalGB;
    cout << "RAM upgraded. New RAM: " << ramGB << " GB" << endl;
}

Smartphone::Smartphone(string brand, string model, bool has5G)
    : Device(brand, model), has5G(has5G) {}

void Smartphone::displayInfo() {
    Device::displayInfo();
    cout << "5G Support: " << (has5G ? "Yes" : "No") << endl;
}

void Smartphone::turnOn() {
    cout << "Powering on smartphone..." << endl;
}

Tablet::Tablet(string brand, string model, bool hasStylus)
    : Device(brand, model), hasStylus(hasStylus) {}

void Tablet::displayInfo() {
    Device::displayInfo();
    cout << "Stylus Support: " << (hasStylus ? "Yes" : "No") << endl;
}

void Tablet::turnOn() {
    cout << "Turning on tablet..." << endl;
}

GamingLaptop::GamingLaptop(string brand, string model, int ramGB, string gpu)
    : Laptop(brand, model, ramGB), gpu(gpu) {}

void GamingLaptop::displayInfo() {
    Laptop::displayInfo();
    cout << "GPU: " << gpu << endl;
}

void GamingLaptop::turnOn() {
    cout << "Gaming laptop powering up with high performance mode..." << endl;
}
