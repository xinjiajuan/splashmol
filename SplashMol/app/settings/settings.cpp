#include "settings.h"
#include "app/app.h"
#include "ui_settings.h"
settings::settings(QWidget *parent) :
                                      QDialog(parent),
                                      ui(new Ui::settings)
{
    ui->setupUi(this);
    ui->digitsSpinBox->setMaximum(9);
    QString filename = QDir::currentPath() + "/.SplashMol.ini";
    setting = new QSettings(filename, QSettings::IniFormat);
    qDebug() << setting->fileName();
    setting->setIniCodec("UTF-8");
    setting->beginGroup("Settings");
    if (setting->value("decimal_digits").isNull()) {
        digits = 2;
        ui->digitsSpinBox->setValue(2);
    } else
        ui->digitsSpinBox->setValue(setting->value("decimal_digits").toInt());
}

settings::~settings()
{
    delete ui;
}

void settings::on_backButton_clicked() {
    digits = ui->digitsSpinBox->value();
    setting->setValue("decimal_digits", digits);
    settings::close();
}

void settings::on_aboutButton_clicked() {
    QMessageBox::about(this, tr("About SplashMol"),
                       tr("SplashMol v1.4 \r\nMade with <3 by "
                          "CRH6F-A-0464\r\n\r\nBuilt with Qt 5.14.1"));
}
