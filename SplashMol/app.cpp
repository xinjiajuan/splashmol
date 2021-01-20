#include "app.h"
#include "calc.h"
#include "ui_app.h"
App::App(QWidget *parent): QWidget(parent), ui(new Ui::App){
    ui->setupUi(this);
    // ui->resultBox->setFont(QFont("Google Sans"));
    ui->resultBox->setFontPointSize(48);
    ui->resultBox->setAlignment(Qt::AlignLeft);
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
    ui->resultBox->setText(QString::number(ans));
}
void App::on_aboutButton_clicked() {
    QMessageBox::about(this, tr("About SplashMol"),
                       tr("SplashMol v1.0 \r\nMade with <3 by CRH6F-A-0464"));
}
