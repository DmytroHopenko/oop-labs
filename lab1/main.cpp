#include <iostream>
#include "Func.h"

using namespace std;

int main() {
    Price total{0, 0};

    FILE* file = fopen("/Users/dmytro/Desktop/Development/oop-labs/lab1/input.txt", "r");

    if (!file) {
        cerr << "Error: Unable to open input.txt" << endl;
        return 1;
    }

    int h, k, quantity;
    while (fscanf(file, "%d %d %d", &h, &k, &quantity) == 3){
        if (h < 0 || k < 0 || quantity < 0) continue;

        Price itemPrice{h, static_cast<short>(k)};
        Price cost{0, 0};
        multiplyPrice(cost, itemPrice, quantity);
        addPrices(total, total, cost);
    }

    roundToNationalBank(total);

    cout << "\nTotal bill amount: "
         << total.hryvnia << " hrn " << total.kopiykas << " kop" << endl;
    cout << "Amount due (rounded): "
         << total.hryvnia << " hrn " << total.kopiykas << " kop" << endl;

    fclose(file);

    return 0;
}
