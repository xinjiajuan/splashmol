#include "app.h"
#include "calc.h"
#include "ui_app.h"
#include <QDebug>
App::App(QWidget *parent): QWidget(parent), ui(new Ui::App){
    ui->setupUi(this);
    this->setFixedSize(this->width(), this->height());
    mode = new QButtonGroup(this);
    mode->addButton(ui->radioButtonNormal, 0);
    mode->addButton(ui->radioButtonSchool, 1);
    ui->calcButton->setShortcut(Qt::Key_Enter);
    ui->calcButton->setShortcut(Qt::Key_Return);
    connect(ui->lineEdit, &QLineEdit::textEdited, this, &App::clear_text_area);
    ui->radioButtonSchool->setChecked(true);
    init_table_school();
}
App::~App(){
    delete ui;
}
void App::on_calcButton_clicked() {
    int mode_selection = mode->checkedId();
    if (!mode_selection)
        init_table_normal();
    else
        init_table_school();
    input = ui->lineEdit->text();
    ans = calc_mass(input.toUtf8().constData());
    QString str;
    if (!mode_selection)
        str = QString::number(ans, 'f', 2);
    else
        str = QString::number(ans, 'f', 1);
    if (str.endsWith(".0"))
        str.remove(".0");
    if (str != "0" && input != "") {
        ui->resultLabel->setFont(
            adaptive_font_size(ui->resultLabel->font(), str));
        ui->resultLabel->setText(str);
        ui->calcButton->setIcon(QIcon(":/assets/assets/finish.png"));
    } else
        clear_text_area();
}
void App::clear_text_area() {
    ui->resultLabel->clear();
    change_font_size(14);
    ui->resultLabel->setText("<b> See result here </b>");
    ui->calcButton->setIcon(QIcon(":/assets/assets/calc.png"));
}
void App::on_aboutButton_clicked() {
    QMessageBox::about(this, tr("About SplashMol"),
                       tr("SplashMol v1.3 \r\nMade with <3 by "
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
void App::change_font_size(int size) {
    QFont tmpfont = ui->resultLabel->font();
    tmpfont.setPointSize(size);
    ui->resultLabel->setFont(tmpfont);
}
