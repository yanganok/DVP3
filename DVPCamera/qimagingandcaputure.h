#ifndef QIMAGINGANDCAPUTURE_H
#define QIMAGINGANDCAPUTURE_H
#include <QThread>
#include <functional>
#include <QDebug>
#include <QWaitCondition>
#include <QMutex>
#include "DVPCamera.h"

class QImagingAndCaputure : public QThread
{
    Q_OBJECT
public:
    QImagingAndCaputure(QObject *parent);
    ~QImagingAndCaputure();
    inline void setDvpCameraHandle(const dvpHandle &value){ _cameraHandle = value; }
private:
    QWaitCondition _waitCondition;
    QMutex _mtx;

    // QThread interface
protected:
    void run() override;
private:
    std::function<void()> _doWork;
    dvpHandle _cameraHandle;
    QWaitCondition _condition;
    void doWork();
};

#endif // QIMAGINGANDCAPUTURE_H
