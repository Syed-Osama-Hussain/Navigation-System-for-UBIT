#ifndef FIRSTFLOOR_H
#define FIRSTFLOOR_H

#include <QDialog>

namespace Ui {
class Firstfloor;
}

class Firstfloor : public QDialog
{
    Q_OBJECT

public:
    explicit Firstfloor(QWidget *parent = 0);
    ~Firstfloor();

private:
    Ui::Firstfloor *ui;
};

#endif // FIRSTFLOOR_H
