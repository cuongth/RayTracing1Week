#include "raytracer.h"

RayTracer::RayTracer(QObject* parent) : QObject{parent}
{
    img = new QImage(256, 256, QImage::Format_RGB32);
}

RayTracer::~RayTracer()
{
    delete img;
}

void RayTracer::render()
{
    float aspect_ratio = 16.0 / 9.0;
    int image_width = 400;
    // Calculate the image height, and ensure that it's at least 1.
    int image_height = int(image_width / aspect_ratio);
    image_height = (image_height < 1) ? 1 : image_height;
    // Camera
    float focal_length = 1.0;
    float viewport_height = 2.0;
    float viewport_width = viewport_height * (float(image_width)/image_height);
    QVector3D camera_center(0, 0, 0);
    // Calculate the vectors across the horizontal and down the vertical viewport edges.
    QVector3D viewport_u(viewport_width, 0, 0);
    QVector3D viewport_v(0, -viewport_height, 0);
    // Calculate the horizontal and vertical delta vectors from pixel to pixel.
    QVector3D pixel_delta_u = viewport_u / (float)image_width;
    QVector3D pixel_delta_v = viewport_v / (float)image_height;
    QVector3D viewport_upper_left = camera_center - QVector3D(0, 0, focal_length) - viewport_u/2 - viewport_v/2;
    QVector3D pixel00_loc = viewport_upper_left + 0.5 * (pixel_delta_u + pixel_delta_v);
    // Render
    for (int j = 0; j < img->height(); ++j)
        for (int i = 0; i < img->width(); ++i)
        {
            const QVector3D pixel_center = pixel00_loc + (i * pixel_delta_u) + (j * pixel_delta_v);
            const QVector3D ray_direction = pixel_center - camera_center;
            MyRay r(camera_center, ray_direction);
            draw_color(i, j, ray_color(r));
          }


    emit frameReady(img);
}

QVector3D RayTracer::ray_color(const MyRay& r)
{
    QVector3D unit_direction(r.direction().normalized());
    float a = 0.5*(unit_direction.y() + 1.0);
    return QVector3D(1.0, 1.0, 1.0)*(1.0-a) + QVector3D(0.5, 0.7, 1.0)*a;
}

void RayTracer::draw_color(const int i, const int j,
        const QVector3D &pixel_color)
{
    float r = pixel_color.x();
    float g = pixel_color.y();
    float b = pixel_color.z();

    int ir = static_cast<int>(255.99 * r);
    int ig = static_cast<int>(255.99 * g);
    int ib = static_cast<int>(255.99 * b);

    img->setPixel(i, j, qRgb(ir, ig, ib));
}
