#include "daqlakeshoremag.h"

#include <math.h>
#include <windows.h>
#include "NIDAQmx.h"
#include <QString>

template <typename T> int sgn(T val) {
    return (T(0) < val) - (val < T(0));
}

DaqLakeshoreMag::DaqLakeshoreMag()
{
      set = 0.0;
      now = 0.0;
      //internal_delta = 0.001;
      //internal_delay_us = 10;
}

void DaqLakeshoreMag::set_chan(QString this_chan)
{
    QByteArray bA = this_chan.toUtf8();
    chan_char = bA.constData();
}

void DaqLakeshoreMag::ramp(double this_set, double delta, int delay)
{
    double thisvolts;
    set = this_set;
    while (fabs(set-now)>delta)
    {
        now+=delta*sgn(set-now);
        thisvolts=0.026142-35.013*now+1.9131*pow(now,2)+4.6271*pow(now,3)-18.01*pow(now,4);
        set_volts(thisvolts);
        Sleep(delay);
    }
    Sleep(delay);
    now=set;
    thisvolts=0.026142-35.013*now+1.9131*pow(now,2)+4.6271*pow(now,3)-18.01*pow(now,4);
    set_volts(thisvolts);
}

void DaqLakeshoreMag::set_volts(double this_volts)
{
    DAQmxCreateTask("",&taskHandle);
    DAQmxCreateAOVoltageChan (taskHandle, chan_char, "", -10.0, 10.0, DAQmx_Val_Volts , NULL);
    DAQmxStartTask(taskHandle);
    double volts=this_volts;
    DAQmxWriteAnalogF64(taskHandle,1,1,10.0,DAQmx_Val_GroupByChannel,&volts,NULL,NULL);
    if( taskHandle!=0 )
    {
        DAQmxStopTask(taskHandle);
        DAQmxClearTask(taskHandle);
    }
}
