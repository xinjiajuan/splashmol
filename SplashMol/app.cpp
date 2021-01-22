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
    std::string str = input.toUtf8().constData();
    ans = calc_mass(str);
    ui->resultLabel->setText(tr("<center><p style=\"font-size:48px\">") +
                             QString::number(ans) + tr("</p></center>"));
}
void App::on_aboutButton_clicked() {
    QMessageBox::about(this, tr("About SplashMol"),
                       tr("SplashMol v1.1 \r\nMade with <3 by CRH6F-A-0464"));
}
