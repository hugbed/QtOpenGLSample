#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QEvent>
#include <QMouseEvent>
#include <QDoubleSpinBox>

#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->actionAnaglyph, &QAction::triggered, [this]{
       ui->openGLWidget->displayModeChanged(OpenGLWidget::DisplayMode::Anaglyph);
    });
    connect(ui->actionOpacity, &QAction::triggered, [this]{
       ui->openGLWidget->displayModeChanged(OpenGLWidget::DisplayMode::Opacity);
    });
    connect(ui->actionInterlaced, &QAction::triggered, [this]{
       ui->openGLWidget->displayModeChanged(OpenGLWidget::DisplayMode::Interlaced);
    });
    connect(ui->actionSide_by_side, &QAction::triggered, [this]{
       ui->openGLWidget->displayModeChanged(OpenGLWidget::DisplayMode::SideBySide);
    });
    connect(ui->actionLeft, &QAction::triggered, [this]{
       ui->openGLWidget->displayModeChanged(OpenGLWidget::DisplayMode::Left);
    });
    connect(ui->actionRight, &QAction::triggered, [this]{
       ui->openGLWidget->displayModeChanged(OpenGLWidget::DisplayMode::Right);
    });

    connect(ui->hitWidget, QOverload<double>::of(&QDoubleSpinBox::valueChanged), [this](double value) {
       ui->openGLWidget->setHorizontalShift(value/100.0);
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}
