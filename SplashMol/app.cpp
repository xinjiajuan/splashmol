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
    QString str = QString::number(ans, 'f', 1);
    if (str.endsWith(".0"))
        str.remove(".0");
    ui->resultLabel->setFont(adaptive_font_size(ui->resultLabel->font(), str));
    ui->resultLabel->setText(str);
}
void App::on_aboutButton_clicked() {
    QMessageBox::about(this, tr("About SplashMol"),
                       tr("SplashMol v1.2 \r\nMade with <3 by "
                          "CRH6F-A-0464\r\n\r\nBuilt with Qt 5.14.1"));
}
QFont App::adaptive_font_size(QFont f, QString str) {
    /* Credits @ https://gist.github.com/earthday/7cb3cb9b00f033e05834 */
    bool fit = false;
    f.setPointSize(48);
    while (!fit) {
        QFontMetrics fm(f);
        QRect bound = fm.boundingRect(0, 0, ui->resultLabel->width(),
                                      ui->resultLabel->height(),
                                      Qt::TextWordWrap | Qt::AlignLeft, str);
        if (bound.width() <= ui->resultLabel->width() &&
            bound.height() <= ui->resultLabel->height())
            fit = true;
        else
            f.setPointSize(f.pointSize() - 8);
    }
    return f;
}
