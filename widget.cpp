#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    timer.start(4);

    right = true;
    left = false;
    up = true;
    down = false;

    count = -2;
    target = false;

    connect(&timer, SIGNAL(timeout()), this, SLOT(slotMoveImage()));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::slotMoveImage()
{
    if(ui->frame->geometry().x()==this->geometry().width() - ui->frame->geometry().width())
    {
        right = false;
        left = true;
        count++;
        qDebug() << count;
    }
    if(ui->frame->geometry().x()==0)
    {
        right = true;
        left = false;
        count++;
        qDebug() << count;
    }
    if(ui->frame->geometry().y()==0)
    {
        up = false;
        down = true;
        count++;
        qDebug() << count;
    }
    if(ui->frame->geometry().y()==this->geometry().height() - ui->frame->geometry().height())
    {
        down = false;
        up = true;
        count++;
        qDebug() << count;
    }

    ui->frame->move(ui->frame->geometry().x()+(1*right)-(1*left), ui->frame->geometry().y()-(1*up)+(1*down));

    if (((ui->frame->geometry().x()==(this->geometry().width() - ui->frame->geometry().width())) &&
        (ui->frame->geometry().y()==(this->geometry().height() - ui->frame->geometry().height()))) ||
        ((ui->frame->geometry().x()==(this->geometry().width() - ui->frame->geometry().width())) &&
        (ui->frame->geometry().y()==0)) || ((ui->frame->geometry().x()==0)&&(ui->frame->geometry().y()==0)) ||
        ((ui->frame->geometry().x()==0)&&(ui->frame->geometry().y()==(this->geometry().height() - ui->frame->geometry().height()))))
    {
        target++;
        qDebug() << "TARGET" <<  target;
        qDebug() << "COUNT" << count;
        qDebug() << "X:" << ui->frame->geometry().x();
        qDebug() << "Y:" << ui->frame->geometry().y();

        switch(target)
        {
        case 1:
        {
            ui->frame->setStyleSheet("background-color: rgb(255,170,255);");
            break;
        }
        case 2:
        {
            ui->frame->setStyleSheet("background-color: rgb(85,170,255);");
            break;
        }
        case 3:
        {
            ui->frame->setStyleSheet("background-color: rgb(255,255,127);");
            break;
        }
        case 4:
        {
            ui->frame->setStyleSheet("background-color: rgb(85,255,0);");
            break;
        }
        case 5:
        {
            ui->frame->setStyleSheet("background-color: rgb(170,170,255);");
            break;
        }
        case 6:
        {
            ui->frame->setStyleSheet("background-color: rgb(0,255,255);");
            break;
        }
        }
        if (target == 6)
            target = 0;


    }
    timer.start(4);
}

void Widget::mousePressEvent(QMouseEvent *event)
{
    if (event->button()==Qt::LeftButton)
        this->close();
}

