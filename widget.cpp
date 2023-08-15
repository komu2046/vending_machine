#include "widget.h"
#include "./ui_widget.h"
#include <QMessageBox>

int money = 0;
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->pbCoffee->setEnabled(false);
    ui->pbTea->setEnabled(false);
    ui->pbMilk->setEnabled(false);

}

Widget::~Widget()
{
    delete ui;
}

void Widget::changeMoney(int diff){
    money += diff;
    ui->lcdNumber->display(money);
    if (money >= 100)
    {
        ui->pbCoffee->setEnabled(true);
    }
    else
        ui->pbCoffee->setEnabled(false);
    if (money >= 150)
    {
        ui->pbTea->setEnabled(true);
    }
    else
        ui->pbTea->setEnabled(false);
    if (money >= 200)
    {
        ui->pbMilk->setEnabled(true);
    }
    else
        ui->pbMilk->setEnabled(false);
}

void Widget::on_pb10_clicked()
{
    changeMoney(10);
}


void Widget::on_pbCoffee_clicked()
{
    changeMoney(-100);
}


void Widget::on_pbTea_clicked()
{
    changeMoney(-150);
}


void Widget::on_pbMilk_clicked()
{
    changeMoney(-200);
}


void Widget::on_pb50_clicked()
{
    changeMoney(50);
}


void Widget::on_pb100_clicked()
{
    changeMoney(100);
}


void Widget::on_pb500_clicked()
{
    changeMoney(500);
}


void Widget::on_pbReset_clicked()
{
    int result_10;
    int result_50;
    int result_100;
    int result_500;
    result_500 = money / 500;
    money = money % 500;
    result_100 = money / 100;
    money = money % 100;
    result_50 = money / 50;
    money = money % 50;
    result_10 = money / 10;

    QMessageBox msgBox;
    msgBox.setText(QString("500원 동전 : %1개\n100원 동전 : %2개\n50원 동전 : %3개\n10원 동전 : %4개").arg(result_500).arg(result_100).arg(result_50).arg(result_10));
    msgBox.exec();
    money = 0;
    changeMoney(0);

}
