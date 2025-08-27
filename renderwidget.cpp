#include "renderwidget.h"
#include "raytracer.h"
#include <QPainter>
#include <QThread>

RenderWidget::RenderWidget(QWidget* parent) : QWidget(parent)
{
    setMinimumSize(256, 256);
    startRendering();
}

RenderWidget::~RenderWidget() {}

// double buffers
void RenderWidget::updateRender(const QImage* renderedImg)
{
    // convert to QPixmap for display
    backBuffer = QPixmap::fromImage(*renderedImg);
    // actually we compute the pixels (using QImage) only 1 time,
    // then display QPixmap.
    std::swap(frontBuffer, backBuffer);
    update();
}

// better rendering performance with QPixmap
void RenderWidget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this);
    if (!frontBuffer.isNull())
        painter.drawPixmap(0, 0, frontBuffer);
}

void RenderWidget::startRendering()
{
    QThread* renderTh = new QThread;
    RayTracer* rayTracer = new RayTracer();
    rayTracer->moveToThread(renderTh);
    connect(renderTh, &QThread::started,
            rayTracer, &RayTracer::render);
    connect(rayTracer, &RayTracer::frameReady,
            this, &RenderWidget::updateRender);
    connect(renderTh, &QThread::finished,
            rayTracer, &QObject::deleteLater);
    renderTh->start();
}
