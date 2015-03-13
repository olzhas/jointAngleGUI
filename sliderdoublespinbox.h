#ifndef SLIDERDOUBLESPINBOX_H
#define SLIDERDOUBLESPINBOX_H

#include <QWidget>

class SliderDoubleSpinBox : public QWidget
{
    Q_OBJECT
public:
    explicit SliderDoubleSpinBox(QWidget *parent = 0);
    SliderDoubleSpinBox(int min, int max, QWidget *parent = 0);
protected:

    void createWidget(int min=0, int max=360);
private:

signals:

public slots:

};

#endif // SLIDERDOUBLESPINBOX_H
