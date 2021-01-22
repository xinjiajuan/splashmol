#include "app.h"
#include "calc.h"
#include "ui_app.h"
App::App(QWidget *parent): QWidget(parent), ui(new Ui::App){
    ui->setupUi(this);
    this->setFixedSize(this->width(), this->height());
    ui->calcButton->setShortcut(Qt::Key_Enter);
    ui->calcButton->setShortcut(Qt::Key_Return);
    init_table();
}
App::~App(){
    delete ui;
}
void App::on_calcButton_clicked() {
    input = ui->lineEdit->text();
    input.toUtf8().constData();
    ans = calc_mass(input.toUtf8().constData());
    ui->resultLabel->setText(tr("<center><p style=\"font-size:28px\">") +
                             QString::number(ans) + tr("</center></p>"));
}
void App::on_aboutButton_clicked() {
    QMessageBox::about(this, tr("About SplashMol"),
                       tr("SplashMol v1.2 \r\nMade with <3 by CRH6F-A-0464"));
}
