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

    ui->mainMagnetComboBox->addItem("Tabletop");//Index 0
    ui->mainMagnetComboBox->addItem("CCMR projected field");//Index 1
    ui->mainMagnetComboBox->addItem("Ralph projected field");//Index 2
    ui->mainMagnetComboBox->addItem("Alex's Lakeshore"); // Index 3
    ui->mainMagnetComboBox->setCurrentIndex(3); // Set the default mag here

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
        sweeper = NULL;
    }
}

void UtilSweep::initialize7270(bool state) {
    if (state==1) {
        dual_lockin = new Lockin7270();
        dual_lockin->start("192.168.1.1", 50000); //Currently hard coded in
    } else {
        delete dual_lockin;
        dual_lockin = NULL;
    }

}

void UtilSweep::initialize7265(bool state) {
    if (state==1) {
        single_lockin = new Lockin7265();
        single_lockin->set_address(27); //Currently hard coded in
    } else {
        delete single_lockin;
        single_lockin = NULL;
    }

}

void UtilSweep::initializeKeithley2k(bool state)
{
    if (state==1) {
        keithley = new Keithley2k();
        keithley->set_address(26);
    } else {
        delete keithley;
        keithley = NULL;
    }
}

void UtilSweep::on_mainMagnetComboBox_currentIndexChanged(int index)
{
    switch (index) {
    case 0: break; //Tabletop
    case 1: break; //CCMR Projected field
    case 2: break; //Ralph Projected field
    case 3: { //Alex Projected field
        if (!lakeshore) {
            lakeshore = new DaqLakeshoreMag();

        }
    } break;
    }
}
