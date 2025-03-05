#ifndef FUNC_H
#define FUNC_H

struct Price {
    int hryvnia;
    short kopiykas;

    Price();
    Price(int h, short k);

    void normalize();
    Price operator+(const Price& other) const;
    Price operator*(double multiplier) const;
    Price roundToNationalBank() const;
};

#endif //FUNC_H
