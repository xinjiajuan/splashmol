#ifndef APP_H
#define APP_H

#include "settings/settings.h"
#include <QApplication>
#include <QButtonGroup>
#include <QDebug>
#include <QIcon>
#include <QMessageBox>
#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class App; }
QT_END_NAMESPACE

class App : public QWidget{
    Q_OBJECT

  public:
    App(QWidget *parent = nullptr);
    ~App();

  private slots:
    void on_calcButton_clicked();
    void on_settingsButton_clicked();
    void clear_text_area();

  private:
    Ui::App *ui;
    QButtonGroup *mode;
    QString input;
    double ans;
    QFont adaptive_font_size(QFont f, QString str);
    void change_font_size(int size);
    settings *Settings;
};
#endif // APP_H
