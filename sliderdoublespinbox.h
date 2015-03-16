#ifndef SLIDERDOUBLESPINBOX_H
#define SLIDERDOUBLESPINBOX_H

#include <QWidget>
#include <QtGui>

class SliderDoubleSpinBox : public QWidget
{
    Q_OBJECT
public:
    explicit SliderDoubleSpinBox(QWidget *parent = 0);
    SliderDoubleSpinBox(int min, int max, QWidget *parent = 0);

    int getValue();
protected:

    void createWidget(int min=0, int max=360);
private:
    QSpinBox *spinBox;
    QSlider *slider;

signals:
    void valueChanged(int newValue);
public slots:
    void setValue(int value);

};

#endif // SLIDERDOUBLESPINBOX_H
