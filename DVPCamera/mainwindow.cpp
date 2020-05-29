#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),_imgCapture(nullptr)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    enumDVPCamera();
    initConnect();
    _imgCapture = new QImagingAndCaputure(this);
    qDebug() << "Main thread:" << QThread::currentThreadId();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initConnect()
{
    connect(ui->cbCamera, QOverload<int>::of(&QComboBox::currentIndexChanged), this, [=](int index){
        memcpy(&_userId, &(_dvpCameraInfos[index]->UserID), sizeof(dvpString128));
        qDebug()<< "_userId:"<< _userId << endl;
    });
    connect(ui->btnOpen, &QPushButton::clicked, this, [=](){
        openCamera();
    });
    connect(ui->btnStart, &QPushButton::clicked, this, [=](){
        StartCapture();
    });
}

void MainWindow::enumDVPCamera()
{
    dvpUint32 cameraCount = 0;
    dvpRefresh(&cameraCount);
    _dvpCameraInfos.reserve(cameraCount);
    for(dvpUint32 i = 0; i < cameraCount; ++i)
    {
        dvpCameraInfo cameraInfo;
        memset(&cameraInfo, 0, sizeof(dvpCameraInfo));
        _dvpCameraInfos.push_back(std::move(&cameraInfo));
        dvpStatus status = dvpEnum(i, &cameraInfo);
        if(status == DVP_STATUS_OK)
        {
            ui->cbCamera->addItem(QString(cameraInfo.FriendlyName), QVariant::fromValue(QString(cameraInfo.UserID)));
            //qDebug() <<  ui->cbCamera->itemText(i) << ui->cbCamera->itemData(i).value<QString>() << _dvpCameraInfos[i]->UserID <<endl;
        }
    }
    if(ui->cbCamera->count() > 0)
    {
        memcpy(&_userId, &(_dvpCameraInfos[0]->UserID), sizeof(dvpString128));
    }
    qDebug() << "_userId:"<< _userId  << endl;
}

void MainWindow::openCamera()
{
    if(!isValidHandle(_cameraHandle))
    {
        if(_userId != "")
        {
            dvpStatus status = dvpOpenByUserId(_userId, OPEN_NORMAL, &_cameraHandle);
            if(status == DVP_STATUS_OK)
            {
                QMessageBox::information(this, QStringLiteral("infomation"), QStringLiteral("Open camera success"), QMessageBox::StandardButton::Ok);
                qDebug() << "openCamera sucess" << endl;
            }
            else
            {
                QMessageBox::critical(this, QStringLiteral("error"), QStringLiteral("Open camera failure"),QMessageBox::StandardButton::Ok);
                qDebug() << "openCamera failure" << endl;
            }
        }
        _imgCapture->setDvpCameraHandle(_cameraHandle);
    }
    else
    {
    }
}

bool MainWindow::isValidHandle(dvpHandle &handle)
{
    bool bValidHandle;
    dvpStatus status = dvpIsValid(handle, &bValidHandle);
    if (status == DVP_STATUS_OK)
    {
        return bValidHandle;
    }
    return false;
}

bool MainWindow::StartCapture()
{
    _imgCapture->start();
    return true;
}

