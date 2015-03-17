#include "commthread.h"
#include "staubli_joint_states.pb.h"
#include <iostream>

CommThread::CommThread(QObject *parent) :
    QThread(parent)
{
}

CommThread::~CommThread()
{
    std::cout << "Shutting the communication thread" << std::endl;
    mutex.lock();
    abort = true;
    mutex.unlock();
    wait();
}

void CommThread::run()
{
    abort = false;

    forever {
        if(abort)
            return;

        QThread::msleep(15);

        // Generate a pose
        staubli_joint_states_msgs::msgs::StaubliJointStates jointStatesMsg;
        jointStatesMsg.set_joint1(controlWidget[0]->getValue());
        jointStatesMsg.set_joint2(controlWidget[1]->getValue());
        jointStatesMsg.set_joint3(controlWidget[2]->getValue());
        jointStatesMsg.set_joint4(controlWidget[3]->getValue());
        jointStatesMsg.set_joint5(controlWidget[4]->getValue());
        jointStatesMsg.set_joint6(controlWidget[5]->getValue());

        pub->Publish(jointStatesMsg);
    }
}

void CommThread::setPublisher(gazebo::transport::PublisherPtr newPub)
{
    pub = newPub;
}
