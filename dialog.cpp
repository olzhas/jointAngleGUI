#include <QtGui>
#include "dialog.h"
#include "sliderdoublespinbox.h"

Dialog::Dialog()
{
    QVBoxLayout *mainLayout = new QVBoxLayout;

    createFormGroupBox();

    mainLayout->addWidget(formGroupBox);
    setLayout(mainLayout);
    setWindowTitle(tr("SafeSpace project"));
}



void Dialog::createFormGroupBox()
{
    formGroupBox = new QGroupBox(tr("Joint angle control"));
    QFormLayout *layout = new QFormLayout;
    for (int i = 0; i < Dialog::numJoints; ++i) {
        sliders[i] = new QSlider;
        const QString label = QString("Joint ") + QString(i+1+'0');
        layout->addRow(new QLabel(label), new SliderDoubleSpinBox);
    }
    formGroupBox->setLayout(layout);
}


