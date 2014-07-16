#ifndef DAQLAKESHOREMAG_H
#define DAQLAKESHOREMAG_H

#include <windows.h>
#include "NIDAQmx.h"
#include <QString>

class DaqLakeshoreMag
{
public:
    double set;
    double now;
    //double internal_delta;
    //int internal_delay_us;
    TaskHandle taskHandle;
    QString chan;
    const char * chan_char;

    DaqLakeshoreMag();

    void set_chan(QString this_chan);
    void ramp(double this_set, double delta, int delay);

private:
    void set_volts(double this_volts);


};

#endif // DAQLAKESHOREMAG_H
