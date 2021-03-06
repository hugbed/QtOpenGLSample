#include "convergenceindicatorwidget.h"

#include <QPixmap>

ConvergenceIndicatorWidget::ConvergenceIndicatorWidget(QWidget *parent)
    : QLabel(parent)
{
    initPixmaps();

    setAlignment(Qt::AlignCenter);
    setSizePolicy(QSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed));

    auto &&pixmap = m_pixmaps[static_cast<int>(State::Neutral)];
    setMinimumSize(pixmap->width() + 5, pixmap->height() + 4);
}

void ConvergenceIndicatorWidget::setState(ConvergenceIndicatorWidget::State state)
{
    setPixmap(*m_pixmaps[static_cast<int>(state)]);
    update();
}

void ConvergenceIndicatorWidget::initPixmaps()
{
    initPixmap(State::ShouldNarrowVeryMuch, ":icons/in_arrows_red.png");
    initPixmap(State::ShouldNarrowMuch, ":icons/in_arrows_orange.png");
    initPixmap(State::ShouldNarrow, ":icons/in_arrows_green.png");
    initPixmap(State::ShouldWidenVeryMuch, ":icons/out_arrows_red.png");
    initPixmap(State::ShouldWidenMuch, ":icons/out_arrows_orange.png");
    initPixmap(State::ShouldWiden, ":icons/out_arrows_green.png");
    initPixmap(State::Neutral, ":icons/neutral_arrows.png");

    setPixmap(*m_pixmaps[static_cast<int>(State::Neutral)]);
}

void ConvergenceIndicatorWidget::initPixmap(State state, const QString &filepath)
{
    auto pixmap = std::make_unique<QPixmap>(filepath);
    m_pixmaps[static_cast<int>(state)] = std::move(pixmap);
}
