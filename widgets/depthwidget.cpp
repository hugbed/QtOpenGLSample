#include "depthwidget.h"

#include <QHBoxLayout>

DepthWidget::DepthWidget(QWidget *parent) : QWidget(parent)
{
    m_minValue = std::make_unique<QLabel>();
    m_depthIndicator = std::make_unique<DepthVolumeIndicator>();
    m_maxValue = std::make_unique<QLabel>();

    setDisplayRange(-3.0f, 3.0f);
    setExpectedRange(-0.7f, 1.0f);
    setLowValue(-0.7);
    setHighValue(1.0);

    auto layout = std::make_unique<QHBoxLayout>();
    layout->addWidget(m_minValue.get(), 0, Qt::AlignLeft);
    layout->addWidget(m_depthIndicator.get(), 0, Qt::AlignCenter);
    layout->addWidget(m_maxValue.get(), 0, Qt::AlignRight);
    setLayout(layout.release());
}

void DepthWidget::setLowValue(float lowValue)
{
    m_minValue->setText(QString::number(lowValue, 'f', 1));
    m_depthIndicator->setLowValue(lowValue);
}

void DepthWidget::setHighValue(float highValue)
{
    m_maxValue->setText(QString::number(highValue, 'f', 1));
    m_depthIndicator->setHighValue(highValue);
}

void DepthWidget::setDisplayRange(float rangeMin, float rangeMax)
{
    m_depthIndicator->setDisplayRange(rangeMin, rangeMax);
}

void DepthWidget::setExpectedRange(float rangeMin, float rangeMax)
{
    m_depthIndicator->setExpectedRange(rangeMin, rangeMax);
}
