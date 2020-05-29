#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "DVPCamera.h"
#include <QList>
#include <utility>
#include <qDebug>
#include <QMessageBox>
#include "qimagingandcaputure.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    void initConnect();
    void enumDVPCamera();
    void openCamera();
    bool isValidHandle(dvpHandle &handle);
    bool StartCapture();
private:
    Ui::MainWindow *ui;
    QList<dvpCameraInfo*> _dvpCameraInfos;
    dvpString128 _userId;
    dvpHandle _cameraHandle;
    QImagingAndCaputure *_imgCapture;
};
#endif // MAINWINDOW_H
