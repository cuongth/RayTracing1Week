#ifndef RENDERWIDGET_H
#define RENDERWIDGET_H

#include <QWidget>
#include <QImage>

class RenderWidget : public QWidget
{
    Q_OBJECT

public:
    RenderWidget(QWidget* parent = nullptr);
    ~RenderWidget();
protected:
    void paintEvent(QPaintEvent* event) override;
private:
    void render();
    QImage m_img;
};
#endif // RENDERWIDGET_H
