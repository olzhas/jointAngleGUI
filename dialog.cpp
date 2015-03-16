#include <QtGui>
#include "dialog.h"


Dialog::Dialog()
{
    QVBoxLayout *mainLayout = new QVBoxLayout;

    commThread = new CommThread;

    createFormGroupBox();
    commThread->start();

    mainLayout->addWidget(formGroupBox);
    setLayout(mainLayout);
    setWindowTitle(tr("SafeSpace project"));
}

Dialog::~Dialog()
{
    delete commThread;
}

void Dialog::createFormGroupBox()
{
    formGroupBox = new QGroupBox(tr("Joint angle control"));
    QFormLayout *layout = new QFormLayout;
    for (int i = 0; i < CommThread::numJoints; ++i) {
        const QString label = QString("Joint ") + QString(i+1+'0');
        commThread->controlWidget[i] = new SliderDoubleSpinBox;
        layout->addRow(new QLabel(label), commThread->controlWidget[i]);
    }

    formGroupBox->setLayout(layout);
}

void Dialog::setPublisher(gazebo::transport::PublisherPtr pub)
{
    commThread->setPublisher(pub);
}
