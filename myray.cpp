#include "myray.h"

MyRay::MyRay() {}

MyRay::MyRay(const QVector3D &origin, const QVector3D &direction)
    : orig(origin), dir(direction)
{}

const QVector3D& MyRay::origin() const
{
    return orig;
}

const QVector3D& MyRay::direction() const
{
    return dir;
}

QVector3D MyRay::at(float t) const
{
    return (orig + dir*t);
}
