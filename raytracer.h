#ifndef RAYTRACER_H
#define RAYTRACER_H

#include <QObject>
#include <QImage>

class RayTracer : public QObject
{
    Q_OBJECT
public:
    explicit RayTracer(QObject* parent = nullptr);
public slots:
    void render();
signals:
    void frameReady(const QImage &img);
};

#endif // RAYTRACER_H
