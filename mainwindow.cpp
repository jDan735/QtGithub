#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "github.h"

#include <QPushButton>
#include <QVBoxLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    GitHub github;

    QString fake_response = github.download("https://lurkmore.to/api.php?action=query&format=json&list=search&srsearch=%D0%9F%D1%83%D1%82%D0%B8%D0%BD&srprop=size&srlimit=1");
    //ui->label->setText(fake_response);

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
        btn->setText("\nban\n");
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

