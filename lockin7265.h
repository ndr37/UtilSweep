#ifndef LOCKIN7265_H
#define LOCKIN7265_H

class Lockin7265
{
public:
    int address;
    int handle;
    Lockin7265();
    void set_address(int ady);
    double get_x();

};

#endif // LOCKIN7265_H
