#ifndef COMMTHREAD_H
#define COMMTHREAD_H

#include <QThread>

class commThread : public QThread
{
    Q_OBJECT
public:
    explicit commThread(QObject *parent = 0);

signals:

public slots:

};

#endif // COMMTHREAD_H
