#include "commthread.h"

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

    forever {
        if(abort)
            return;

        QThread::msleep(15);

        // Generate a pose

        gazebo::math::Pose pose(controlWidget[0]->getValue(),
                controlWidget[1]->getValue(),
                controlWidget[2]->getValue(),
                controlWidget[3]->getValue(),
                controlWidget[4]->getValue(),
                controlWidget[5]->getValue());

        // Convert to a pose message
        gazebo::msgs::Pose msg;
        gazebo::msgs::Set(&msg, pose);

        pub->Publish(msg);
//        std::cout << controlWidget[0]->getValue() << " " <<
//            controlWidget[1]->getValue() << " " <<
//            controlWidget[2]->getValue() << " " <<
//            controlWidget[3]->getValue() << " " <<
//            controlWidget[4]->getValue() << " " <<
//            controlWidget[5]->getValue() << std::endl;

    }
}

void CommThread::setPublisher(gazebo::transport::PublisherPtr newPub)
{
    pub = newPub;
}
