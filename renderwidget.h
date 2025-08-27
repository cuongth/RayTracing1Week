#ifndef RENDERWIDGET_H
#define RENDERWIDGET_H

#include <QWidget>
#include <QPixmap>
#include <QImage>

class RenderWidget : public QWidget
{
    Q_OBJECT

public:
    RenderWidget(QWidget* parent = nullptr);
    ~RenderWidget();
public slots:
    void updateRender(const QImage* renderedImg);
protected:
    void paintEvent(QPaintEvent* event) override;
private:
    void startRendering();
    QPixmap frontBuffer, backBuffer;
};
#endif // RENDERWIDGET_H
