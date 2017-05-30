#include "parameterslistview.h"

#include <QPushButton>

ParametersListView::ParametersListView(QWidget *parent) : QWidget(parent)
{
    generateParameterWidgets({{"Roll", "°"},
                              {"Vertical", "%"},
                              {"Keystone", "%"},
                              {"Tilt Keystone", "%"},
                              {"Y Offset", "%"},
                              {"Zoom", "%"}});
    setParameter("Roll", 0.1);
    setSizePolicy(QSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed));
}

ParametersListView::~ParametersListView()
{
    clearParameters();
}

void ParametersListView::updateUI()
{
    // update layout
    update();
}

void ParametersListView::generateParameterWidgets(std::vector<LabelSymbolPair> labels)
{
    m_layout = new QHBoxLayout;
    for (auto & label : labels) {
        ParameterWidget *paramWidget = new ParameterWidget(label.first, label.second);
        m_parameters.insert(std::pair<QString, ParameterWidget*>(label.first, paramWidget));
        m_layout->addWidget(paramWidget);
    }
    setLayout(m_layout);
}

void ParametersListView::setParameter(const QString &label, float value)
{
    // check if parameter is in map
    auto it = m_parameters.find(label);

    // if in map, set value
    if(it != m_parameters.end()) {
       it->second->setValue(value);
    }

    // updateUI
}

void ParametersListView::clearParameters()
{
    QLayoutItem *child;
    while ((child = m_layout->takeAt(0)) != nullptr)  {
        m_layout->removeItem(child);
        delete child->widget();
        delete child;
    }

    m_parameters.clear();
}
