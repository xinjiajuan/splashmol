#include "settings.h"
#include "app/app.h"
#include "ui_settings.h"
settings::settings(QWidget *parent) : QDialog(parent), ui(new Ui::settings) {
    ui->setupUi(this);
    ui->digitsSpinBox->setMaximum(9);
    QString filename = QDir::currentPath() + "/.SplashMol.ini";
    setting = new QSettings(filename, QSettings::IniFormat);
    setting->setIniCodec("UTF-8");
    setting->beginGroup("Settings");
    ui->languageComboBox->addItem("English");
    ui->languageComboBox->addItem("中文");
    if (setting->value("language").isNull()) {
        language = "English";
        ui->languageComboBox->setCurrentText(language);
    } else
        ui->languageComboBox->setCurrentText(
            setting->value("language").toString());
    if (setting->value("decimal_digits").isNull()) {
        digits = 2;
        ui->digitsSpinBox->setValue(digits);
    } else
        ui->digitsSpinBox->setValue(setting->value("decimal_digits").toInt());
}
settings::~settings() { delete ui; }
void settings::on_backButton_clicked() {
    digits = ui->digitsSpinBox->value();
    setting->setValue("decimal_digits", digits);
    language = ui->languageComboBox->currentText();
    setting->setValue("language", language);
    settings::close();
}

void settings::on_aboutButton_clicked() {
    QMessageBox::about(this, tr("About SplashMol"),
                       tr("SplashMol v1.4 \r\nMade with <3 by "
                          "CRH6F-A-0464\r\n\r\nBuilt with Qt 5.14.1"));
}
