#include "sliderdoublespinbox.h"


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

    slider = new QSlider(Qt::Horizontal);
    slider->setRange(min, max);

    spinBox = new QSpinBox;
    spinBox->setMinimum(min);
    spinBox->setMaximum(max);

    connect(slider, SIGNAL(valueChanged(int)), this, SLOT(setValue(int)));
    connect(spinBox, SIGNAL(valueChanged(int)), this, SLOT(setValue(int)));

    layout->addWidget(slider);
    layout->addWidget(spinBox);

    setLayout(layout);
}

void SliderDoubleSpinBox::setValue(int value)
{
    spinBox->setValue(value);
    slider->setValue(value);

    emit valueChanged(value);
}

int SliderDoubleSpinBox::getValue()
{
    return spinBox->value();
}
