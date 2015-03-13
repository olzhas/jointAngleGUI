#include <QApplication>
#include <QPushButton>
#include <iostream>

#include <gazebo/gazebo.hh>
#include <gazebo/transport/transport.hh>
#include <gazebo/msgs/msgs.hh>
#include <gazebo/math/gzmath.hh>

#include "dialog.h"

int main(int argc, char* argv[]) 
{
  QApplication app(argc, argv);
  
  Dialog dialog;
  dialog.show();

  // Load gazebo
  gazebo::setupClient(argc, argv);

  // Create our node for communication
  gazebo::transport::NodePtr node(new gazebo::transport::Node());
  node->Init();

  // Publish to a gazebo plugin

  return app.exec();
}
