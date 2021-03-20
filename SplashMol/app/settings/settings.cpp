#include "settings.h"
#include "app/app.h"
#include "ui_settings.h"
settings::settings(QWidget *parent) :
                                      QDialog(parent),
                                      ui(new Ui::settings)
{
    ui->setupUi(this);
    ui->digitsSpinBox->setMaximum(9);
    ui->digitsSpinBox->setValue(2);
    QString filename = QDir::homePath() + ".SplashMol.ini";
    QSettings setting(filename, QSettings::IniFormat);
    setting.setIniCodec("UTF-8");
}

settings::~settings()
{
    delete ui;
}

void settings::on_backButton_clicked() { settings::close(); }
