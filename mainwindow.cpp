#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QEvent>
#include <QMouseEvent>
#include <QDoubleSpinBox>

#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->actionOpen_Left_Image, &QAction::triggered, [this]{
        requestImageFilename([this](const QString &filename) {
            ui->openGLWidget->setImageLeft(QImage(filename));
        });
    });

    connect(ui->actionOpen_Right_Image, &QAction::triggered, [this]{
        requestImageFilename([this](const QString &filename) {
            ui->openGLWidget->setImageRight(QImage(filename));
        });
    });

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
       ui->depthWidget->setShift(value);
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

template <class Functor>
void MainWindow::requestImageFilename(Functor f)
{
    QString filename = QFileDialog::getOpenFileName(this,
        tr("Open Image"), "/home/jon/Videos", tr("Image Files (*.png *.jpg *.bmp *.pbm)"));
    if (!filename.isEmpty()) {
        f(filename);
    }
}
