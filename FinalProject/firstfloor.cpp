#include "firstfloor.h"
#include "ui_firstfloor.h"

Firstfloor::Firstfloor(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Firstfloor)
{
    ui->setupUi(this);
}

Firstfloor::~Firstfloor()
{
    delete ui;
}
