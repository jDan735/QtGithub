#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>
#include <QVBoxLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Profile image
    QPixmap pic1(":/avatar/img/avatar/ava.png");
    QSize PicSize(71, 71);

    pic1 = pic1.scaled(PicSize, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    ui->label_2->setPixmap(pic1);
    ui->label_2->repaint();

    // Buttons
    QVBoxLayout *layout = new QVBoxLayout;

    for (int i = 0; i < 30; ++i){
        QPushButton *btn = new QPushButton();
        btn->setText("ban");
        layout->addWidget(btn);
    }

    QWidget* widget = new QWidget;
    widget->setLayout(layout);
    ui->scrollArea->setWidget(widget);
}

MainWindow::~MainWindow()
{
    delete ui;
}

