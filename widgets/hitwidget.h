#ifndef HITWIDGET_H
#define HITWIDGET_H

#include <QDoubleSpinBox>

class HITWidget : public QDoubleSpinBox
{
    Q_OBJECT
public:
    explicit HITWidget(QWidget *parent = nullptr);
};

#endif // HITWIDGET_H
