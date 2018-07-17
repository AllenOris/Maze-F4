#ifndef TEST_H
#define TEST_H

#include <QDialog>
#include "f4mazemap.h"
namespace Ui {
class Test;
}

class Test : public QDialog
{
    Q_OBJECT

public:
    explicit Test(QWidget *parent = 0);
    ~Test();
protected:
    void paintEvent(QPaintEvent*);
private:
    Ui::Test *ui;
};

#endif // TEST_H
