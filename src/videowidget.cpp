#include "videowidget.h"

videowidget::videowidget(QWidget *parent) :
    QWidget(parent)
{
    setAutoFillBackground(true);

}

void videowidget::paintEvent(QPaintEvent *event) {
    try{
    QPainter painter(this);
    painter.setPen(Qt::blue);
    painter.setFont(QFont("Arial", 40));
    painter.drawText(rect(), Qt::AlignBottom|Qt::AlignCenter, "Peisheng YE Testing");


        if(!img.isNull()){
            painter.drawImage(QPoint(0,0), img);
        }
    }catch(...){}
}
