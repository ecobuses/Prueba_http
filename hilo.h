#ifndef HILO_H
#define HILO_H
#include <QThread>
class hilo:public QThread
{
public:
    hilo();
    void setId(int id){this->id=id;}
    int getId(){return this->id;}
private:
    int id;
protected:
    void run();
};

#endif // HILO_H
