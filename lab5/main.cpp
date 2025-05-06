#include "Device.h"

int main() {
    cout << "Creating SuperDevice:\n";
    SuperDevice sd("Apple", "MacBook Pro", "M2", 1.4, true);

    cout << "\nDevice Info:\n";
    sd.displayInfo();

    cout << "\nExiting program...\n";
    return 0;
}
