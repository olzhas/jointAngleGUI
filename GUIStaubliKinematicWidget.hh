#ifndef GUISTAUBLIKINEMATICWIDGET_HH
#define GUISTAUBLIKINEMATICWIDGET_HH

#include <gazebo/common/Plugin.hh>
#include <gazebo/gui/GuiPlugin.hh>
#ifndef Q_MOC_RUN  // See: https://bugreports.qt-project.org/browse/QTBUG-22829
# include <gazebo/transport/transport.hh>
# include <gazebo/gui/gui.hh>
#endif

namespace gazebo
{
    class GAZEBO_VISIBLE GUIStaubliKinematicWidget : public GUIPlugin
    {
        Q_OBJECT

        /// \brief Constructor
        public: GUIStaubliKinematicWidget();

        /// \brief Destructor
        public: virtual ~GUIStaubliKinematicWidget();

        /// \brief Node used to establish communication with gzserver.
        private: transport::NodePtr node;

        /// \brief Publisher to world statistics messages.
        private: transport::PublisherPtr statePub;

        ///
        private: QGroupBox *formGroupBox;

        private: enum {numJoints = 6};

        ///
        private: void createFormGroupBox();
    };
}
#endif // GUISTAUBLIKINEMATICWIDGET_HH
