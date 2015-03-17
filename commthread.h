#ifndef COMMTHREAD_H
#define COMMTHREAD_H

#include <QThread>
#include <QMutex>

#include <gazebo/gazebo.hh>
#include <gazebo/transport/transport.hh>
#include <gazebo/msgs/msgs.hh>
#include <gazebo/math/gzmath.hh>

#include "sliderdoublespinbox.h"
#include "staubli_joint_states.pb.h"

class CommThread : public QThread
{
    Q_OBJECT

    typedef const boost::shared_ptr<const staubli_joint_states_msgs::msgs::StaubliJointStates> StaubliJointStatesPtr;

public:
    explicit CommThread(QObject *parent = 0);
    ~CommThread();

signals:

public slots:

private:
    void run();

    gazebo::transport::PublisherPtr pub;
    bool abort;
    QMutex mutex;

public:
    enum {numJoints = 6};
    SliderDoubleSpinBox *controlWidget[numJoints];
    void setPublisher(gazebo::transport::PublisherPtr newPub);
};

#endif // COMMTHREAD_H
