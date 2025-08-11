#include "renderwidget.h"
#include <QPainter>

RenderWidget::RenderWidget(QWidget* parent) : QWidget(parent)
{
    setMinimumSize(256, 256);
    render();
}

RenderWidget::~RenderWidget() {}

void RenderWidget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this);
    if (!m_img.isNull())
        painter.drawImage(0, 0, m_img);
}

void RenderWidget::render()
{
    m_img = QImage(256, 256, QImage::Format_RGB32);

    for (int j = 0; j < m_img.height(); ++j)
        for (int i = 0; i < m_img.width(); ++i)
        {
            float r = (float) i / (float) m_img.width();
            float g = (float) j / (float) m_img.height();
            float b = 0.2;

            int ir = static_cast<int>(255.99 * r);
            int ig = static_cast<int>(255.99 * g);
            int ib = static_cast<int>(255.99 * b);

            m_img.setPixel(i, j, qRgb(ir, ig, ib));
        }

    update();
}
