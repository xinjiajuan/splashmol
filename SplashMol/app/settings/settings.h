#ifndef SETTINGS_H
#define SETTINGS_H

#include <QDialog>
#include <QDir>
#include <QSettings>
#include <QString>

static QSettings *setting;
int get_decimal_digits();
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
    int digits, language_index;
    QString language;
};

#endif // SETTINGS_H
