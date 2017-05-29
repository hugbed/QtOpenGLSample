#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->actionAnaglyph, &QAction::triggered, [this]{
       ui->openGLWidget->displayModeChanged(OpenGLWidget::DisplayMode::Anaglyph);
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
}

MainWindow::~MainWindow()
{
    delete ui;
}
