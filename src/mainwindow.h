#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include "videowidget.h"
#include "capturethread.h"

class MainWindow : public QWidget {
    Q_OBJECT
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

    QVBoxLayout *vbox;
    videowidget *video;
    QPushButton *exitButton;
    QPushButton *startCapture;
    QPushButton *stopCapture;
    CaptureThread *t;

private slots:
    /*void on_videoWidget_destroyed();*/
    void on_exit_clicked();
    void onStartCapture();
    void onStopCapture();
};

#endif // MAINWINDOW_H
