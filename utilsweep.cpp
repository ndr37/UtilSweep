#include "utilsweep.h"
#include "ui_utilsweep.h"
#include "agilentsweeper.h"
#include <QDockWidget>
#include <QMainWindow>

UtilSweep::UtilSweep(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::UtilSweep)
{
    ui->setupUi(this);

}

UtilSweep::~UtilSweep()
{
    delete ui;
}

void UtilSweep::on_sweepMainMagButton_clicked()
{

}

void UtilSweep::initializeAgligentSweeper(bool state)
{
    if (state==1){
        sweeper = new AgilentSweeper(this);
        addDockWidget(Qt::RightDockWidgetArea,sweeper);
    } else {
        removeDockWidget(sweeper);
        delete sweeper; //Call the destructor
    }
}

void UtilSweep::initialize7270(bool state) {
    if (state==1) {
        dual_lockin = new Lockin7270();
        dual_lockin->start("192.168.1.1", 50000); //Currently hard coded in
    } else {
        delete dual_lockin;
    }

}

void UtilSweep::initialize7265(bool state) {
    if (state==1) {
        single_lockin = new Lockin7265();
        single_lockin->set_address(27); //Currently hard coded in
    } else {
        delete single_lockin;
    }

}

void UtilSweep::initializeKeithley2k(bool state)
{
    if (state==1) {
        keithley = new Keithley2k();
        keithley->set_address(26);
    } else {
        delete keithley;
    }
}
