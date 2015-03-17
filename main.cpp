#include <QApplication>
#include <iostream>

#include "dialog.h"

int main(int argc, char* argv[]) 
{
    QApplication app(argc, argv);


    // Publish to a gazebo plugin

    // Load gazebo
    gazebo::setupClient(argc, argv);

    // Create our node for communication
    gazebo::transport::NodePtr node(new gazebo::transport::Node());
    node->Init();

    // Publish to a Gazebo topic
    gazebo::transport::PublisherPtr pub =
            node->Advertise<gazebo::msgs::Pose>("~/staubli_joint_states");

    // Wait for a subscriber to connect
    pub->WaitForConnection();

    Dialog dialog;
    dialog.setPublisher(pub);
    dialog.show();

    int ret = app.exec();
    gazebo::shutdown();
    return ret;
}
