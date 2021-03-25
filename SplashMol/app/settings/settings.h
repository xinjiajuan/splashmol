#ifndef SETTINGS_H
#define SETTINGS_H

#include <QDialog>
#include <QDir>
#include <QSettings>
#include <QString>

namespace Ui {
class settings;
}

class settings : public QDialog
{
    Q_OBJECT

  public:
    explicit settings(QWidget *parent = nullptr);
    ~settings();

  private slots:
    void on_backButton_clicked();

    void on_aboutButton_clicked();

  private:
    Ui::settings *ui;
    int digits;
    QSettings *setting;
};

#endif // SETTINGS_H