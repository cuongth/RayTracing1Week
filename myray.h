#ifndef MYRAY_H
#define MYRAY_H

#include <QVector3D>

class MyRay
{
private:
    const QVector3D orig, dir;
public:
    MyRay();
    MyRay(const QVector3D& origin, const QVector3D& direction);
    const QVector3D& origin() const;
    const QVector3D& direction() const;
    QVector3D at(float t) const;
};

#endif // MYRAY_H
