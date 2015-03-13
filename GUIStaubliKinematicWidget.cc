#include "GUIStaubliKinematicWidget.hh"
#include "sliderdoublespinbox.h"

#include <gazebo/msgs/msgs.hh>

using namespace gazebo;

// Register this plugin with the simulator
GZ_REGISTER_GUI_PLUGIN(GUIStaubliKinematicWidget)

/////////////////////////////////////////////////

GUIStaubliKinematicWidget::GUIStaubliKinematicWidget()  : GUIPlugin()
{
    /*this->setStyleSheet(
                "QFrame { background-color : rgba(0, 0, 0, 0); color : white; }");
*/
    QVBoxLayout *mainLayout = new QVBoxLayout;

    this->createFormGroupBox();
    mainLayout->addWidget(this->formGroupBox);
    this->setLayout(mainLayout);

    // Create a node for transportation
    this->node = transport::NodePtr(new transport::Node());
    this->node->Init();
    this->statePub = node->Advertise<gazebo::msgs::Pose>("~/staubli_pose");

    // Wait for a subscriber to connect
    //this->statePub->WaitForConnection();


    // Generate a pose
    gazebo::math::Pose pose(1, 2, 3, 4, 5, 6);

    // Convert to a pose message
    gazebo::msgs::Pose msg;
    gazebo::msgs::Set(&msg, pose);

    statePub->Publish(msg);

}

////////////////////////////////////////////////////////////
/// \brief GUIStaubliKinematicWidget::~GUIStaubliKinematicWidget
///
GUIStaubliKinematicWidget::~GUIStaubliKinematicWidget()
{
}

////////////////////////////////////////////////////////////
/// \brief Dialog::createFormGroupBox
///

void GUIStaubliKinematicWidget::createFormGroupBox()
{
    this->formGroupBox = new QGroupBox(tr("Joint angle control"));
    QFormLayout *layout = new QFormLayout;
    for (int i = 0; i < GUIStaubliKinematicWidget::numJoints; ++i) {
        const QString label = QString("Joint ") + QString(i+1+'0');
        layout->addRow(new QLabel(label), new SliderDoubleSpinBox);
    }
    this->formGroupBox->setLayout(layout);
}

