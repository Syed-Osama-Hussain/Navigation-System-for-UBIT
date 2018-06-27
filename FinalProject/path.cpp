#include "path.h"
#include "ui_path.h"

Path::Path(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Path)
{
    ui->setupUi(this);
}

Path::~Path()
{
    delete ui;
}

QString Path:: getPath()
{
return ui->Path_Display->text();
}

void Path:: setPath ( const QString & name )
{
ui->Path_Display->setText(name);
}

void Path::on_pushButton_clicked()
{
    QApplication::quit();
}
