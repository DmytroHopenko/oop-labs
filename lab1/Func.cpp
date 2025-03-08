#include "Func.h"
#include <cmath>

void normalize(Price& price) {
    if (price.kopiykas >= 100) {
        price.hryvnia += price.kopiykas / 100;
        price.kopiykas %= 100;
    }
}

void addPrices(Price& result, const Price& a, const Price& b) {
    result.hryvnia = a.hryvnia + b.hryvnia;
    result.kopiykas = a.kopiykas + b.kopiykas;
}

void multiplyPrice(Price& result, const Price& price, int multiplier) {
    int totalKop = (price.hryvnia * 100 + price.kopiykas) * multiplier;
    result.hryvnia = totalKop / 100;
    result.kopiykas = totalKop % 100;
}

int roundToNationalBank(Price& price) {
    int remainder = price.kopiykas % 10;

    if (remainder < 5)
        price.kopiykas -= remainder;
    else
        price.kopiykas += (10 - remainder);

    normalize(price);

    return price.hryvnia * 100 + price.kopiykas;
}
