#include "utilsweep.h"
#include "ui_utilsweep.h"

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
