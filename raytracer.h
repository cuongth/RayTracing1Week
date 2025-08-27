#ifndef RAYTRACER_H
#define RAYTRACER_H

#include <QObject>
#include <QImage>
#include <QVector3D>
#include "myray.h"

class RayTracer : public QObject
{
    Q_OBJECT
public:
    explicit RayTracer(QObject* parent = nullptr);
    ~RayTracer();
public slots:
    void render();
signals:
    void frameReady(const QImage* img);
private:
    QImage *img;
    QVector3D ray_color(const MyRay& r);
    void draw_color(const int i, const int j, const QVector3D& pixel_color);
};

#endif // RAYTRACER_H
