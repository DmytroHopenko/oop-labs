#include <iostream>
#include "Func.h"

using namespace std;

int main() {
    Price total;

    cout << "Enter data in the format: hrn kop quantity (e.g.: 19 89 3)." << endl;
    cout << "To finish app, use a string format." << endl;

    int h, k, quantity;
    while (cin >> h >> k >> quantity) {
        Price itemPrice(h, k);
        if(h < 0 || k < 0 || quantity < 0) continue;
        Price cost = itemPrice * quantity;
        total = total + cost;
    }

    Price roundedTotal = total.roundToNationalBank();

    cout << "\nTotal bill amount: "
         << total.hryvnia << " hrn " << total.kopiykas << " kop" << endl;
    cout << "Amount due (rounded): "
         << roundedTotal.hryvnia << " hrn " << roundedTotal.kopiykas << " kop" << endl;

    return 0;
}

// TIP See CLion help at <a
// href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>.
//  Also, you can try interactive lessons for CLion by selecting
//  'Help | Learn IDE Features' from the main menu.