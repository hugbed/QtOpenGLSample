#ifndef DEPTHWIDGET_H
#define DEPTHWIDGET_H

#include <QWidget>

#include <QLabel>

#include "depthvolumeindicator.h"

#include <memory>

class DepthWidget : public QWidget
{
    Q_OBJECT
public:
    explicit DepthWidget(QWidget *parent = nullptr);

signals:

public slots:
    void setLowValue(float lowValue);
    void setHighValue(float highValue);
    void setDisplayRange(float rangeMin, float rangeMax);
    void setExpectedRange(float rangeMin, float rangeMax);

private:
    std::unique_ptr<QLabel> m_minValue;
    std::unique_ptr<DepthVolumeIndicator> m_depthIndicator;
    std::unique_ptr<QLabel> m_maxValue;
};

#endif // DEPTHWIDGET_H
