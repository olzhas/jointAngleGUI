#ifndef DIALOG_H
#define DIALOG_G



#include <QDialog>
#include "commthread.h"

class QLabel;
class QSlider;
class QGroupBox;

class Dialog : public QDialog 
{
    Q_OBJECT
public:
    Dialog();
    virtual ~Dialog();
    void setPublisher(gazebo::transport::PublisherPtr pub);

private:

    void createFormGroupBox();

    QGroupBox *formGroupBox;
    CommThread *commThread;

signals:


};
#endif
