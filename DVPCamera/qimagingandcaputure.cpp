#include "qimagingandcaputure.h"

QImagingAndCaputure::QImagingAndCaputure(QObject* parent):QThread(parent)
{

}

QImagingAndCaputure::~QImagingAndCaputure()
{

}

void QImagingAndCaputure::run()
{
    qDebug() << "ImagingThread thread:" << QThread::currentThreadId();
    doWork();
    //_doWork();
}

void QImagingAndCaputure::doWork()
{

}
