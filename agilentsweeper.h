#ifndef AGILENTSWEEPER_H
#define AGILENTSWEEPER_H

#include <QDockWidget>

namespace Ui {
class AgilentSweeper;
}

class AgilentSweeper : public QDockWidget
{
    Q_OBJECT

public:
    explicit AgilentSweeper(QWidget *parent = 0);
    ~AgilentSweeper();

private:
    Ui::AgilentSweeper *ui;
};

#endif // AGILENTSWEEPER_H
