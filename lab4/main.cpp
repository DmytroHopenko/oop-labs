#include "Device.h"

int main() {
    Laptop laptop("Dell", "XPS 13", 16);
    Smartphone phone("Samsung", "Galaxy S24", true);
    Tablet tablet("Apple", "iPad Pro", true);
    GamingLaptop gaming("Asus", "ROG Zephyrus", 32, "NVIDIA RTX 4080");

    Device* devices[] = { &laptop, &phone, &tablet, &gaming };

    for (Device* device : devices) {
        device->displayInfo();
        device->turnOn();
        cout << "--------------------------" << endl;
    }

    laptop.upgradeRAM(8);
    laptop.displayInfo();

    return 0;
}