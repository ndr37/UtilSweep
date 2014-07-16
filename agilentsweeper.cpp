#include "agilentsweeper.h"
#include "ui_agilentsweeper.h"
#include <QDockWidget>

AgilentSweeper::AgilentSweeper(QWidget *parent) :
    QDockWidget(parent),
    ui(new Ui::AgilentSweeper)
{
    ui->setupUi(this);
}

AgilentSweeper::~AgilentSweeper()
{
    delete ui;
}
