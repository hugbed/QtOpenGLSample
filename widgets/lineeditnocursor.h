#ifndef LINEEDITNOCURSOR_H
#define LINEEDITNOCURSOR_H

#include <QLineEdit>

class LineEditNoCursor : public QLineEdit
{
    Q_OBJECT
public:
    LineEditNoCursor(QWidget *parent = nullptr);

    void keyPressEvent(QKeyEvent* e) override;
};

#endif // LINEEDITNOCURSOR_H
