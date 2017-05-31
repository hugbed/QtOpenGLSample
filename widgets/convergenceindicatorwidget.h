#ifndef CONVERGENCEINDICATORWIDGET_H
#define CONVERGENCEINDICATORWIDGET_H

#include <QLabel>

#include <memory>

class ConvergenceIndicatorWidget : public QLabel
{
    Q_OBJECT
public:
    enum class State {
        ShouldNarrowVeryMuch,
        ShouldWidenVeryMuch,
        ShouldNarrowMuch,
        ShouldWidenMuch,
        ShouldNarrow,
        ShouldWiden,
        Neutral,
        NB_STATES
    };

    ConvergenceIndicatorWidget(QWidget *parent = nullptr);

    void setState(State state);

private:
    void initPixmaps();
    void initPixmap(State state, const QString &filepath);

    std::unique_ptr<QPixmap> m_pixmaps[static_cast<int>(State::NB_STATES)];
};

#endif // CONVERGENCEINDICATORWIDGET_H
