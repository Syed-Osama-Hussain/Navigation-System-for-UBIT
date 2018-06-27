#ifndef PATH_H
#define PATH_H

#include <QMainWindow>

namespace Ui {
class Path;
}

class Path : public QMainWindow
{
    Q_OBJECT

public:
    explicit Path(QWidget *parent = 0);
    ~Path();
    QString getPath ();
    void setPath ( const QString & name );

private slots:
    void on_pushButton_clicked();

private:
    Ui::Path *ui;
};

#endif // PATH_H
