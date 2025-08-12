#include "raytracer.h"

RayTracer::RayTracer(QObject* parent) : QObject{parent}
{}

void RayTracer::render()
{
    QImage img(256, 256, QImage::Format_RGB32);

    for (int j = 0; j < img.height(); ++j)
        for (int i = 0; i < img.width(); ++i)
        {
            float r = (float) i / (float) img.width();
            float g = (float) j / (float) img.height();
            float b = 0.2;

            int ir = static_cast<int>(255.99 * r);
            int ig = static_cast<int>(255.99 * g);
            int ib = static_cast<int>(255.99 * b);

            img.setPixel(i, j, qRgb(ir, ig, ib));
        }

    emit frameReady(img);
}


