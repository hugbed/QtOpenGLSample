#ifndef ALIGNMENTPARAMETERSWIDGET_H
#define ALIGNMENTPARAMETERSWIDGET_H

#include <QHBoxLayout>
#include <QWidget>
#include <QString>

#include "parameterwidget.h"

#include <memory>

class ParametersListView : public QWidget
{
    Q_OBJECT
public:
    using LabelSymbolPair = std::pair<QString, QString>;

    explicit ParametersListView(QWidget *parent = nullptr);
    ~ParametersListView();
    void updateUI();

signals:

public slots:
    void generateParameterWidgets(std::vector<LabelSymbolPair> labels);
    void setParameter(const QString& label, float value);
    void clearParameters();

private:
    std::map<QString, ParameterWidget*> m_parameters;
    QHBoxLayout *m_layout;
};

#endif // ALIGNMENTPARAMETERSWIDGET_H
