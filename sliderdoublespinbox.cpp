#include "sliderdoublespinbox.h"

#include <QtGui>
#include <math.h>

SliderDoubleSpinBox::SliderDoubleSpinBox(QWidget *parent) :
    QWidget(parent)
{
    createWidget();
}

SliderDoubleSpinBox::SliderDoubleSpinBox(int min, int max, QWidget *parent) :
    QWidget(parent)
{
    createWidget(min, max);
}



void SliderDoubleSpinBox::createWidget(int min, int max)
{
    QHBoxLayout *layout = new QHBoxLayout;

    QSlider *slider = new QSlider(Qt::Horizontal);
    slider->setRange(min, max);

    QSpinBox *spinBox = new QSpinBox;
    spinBox->setMinimum(min);
    spinBox->setMaximum(max);

    connect(slider, SIGNAL(valueChanged(int)), spinBox, SLOT(setValue(int)));
    connect(spinBox, SIGNAL(valueChanged(int)), slider, SLOT(setValue(int)));

    layout->addWidget(slider);
    layout->addWidget(spinBox);

    setLayout(layout);
}
