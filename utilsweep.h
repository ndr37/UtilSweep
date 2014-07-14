#ifndef UTILSWEEP_H
#define UTILSWEEP_H

#include <QMainWindow>

namespace Ui {
class UtilSweep;
}

class UtilSweep : public QMainWindow
{
    Q_OBJECT

public:
    explicit UtilSweep(QWidget *parent = 0);
    ~UtilSweep();

private:
    Ui::UtilSweep *ui;
};

#endif // UTILSWEEP_H
