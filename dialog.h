#ifndef DIALOG_H
#define DIALOG_G

#include <QDialog>

class QLabel;
class QSlider;
class QGroupBox;

class Dialog : public QDialog 
{
  Q_OBJECT
  public:
    Dialog();

  private:

    void createFormGroupBox();

    enum {numJoints = 6};



    QSlider *sliders[numJoints];
    QGroupBox *formGroupBox;


};
#endif
