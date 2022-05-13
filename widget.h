#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTimer>
#include <QTime>
#include <QMouseEvent>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void slotMoveImage();

private:
    Ui::Widget *ui;
    QTimer timer;

    bool right;
    bool left;
    bool up;
    bool down;

    int count;
    int target;

protected:
    void mousePressEvent(QMouseEvent* event) override;

};
#endif // WIDGET_H
