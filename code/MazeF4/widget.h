#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPainter>
#include "f4mazemap.h"
namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

protected:
    void paintEvent(QPaintEvent*);
    bool isupdate;

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

   // void on_pushButton_4_clicked();

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
