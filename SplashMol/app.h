#ifndef APP_H
#define APP_H

#include <QApplication>
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
    void on_aboutButton_clicked();

  private:
    Ui::App *ui;
    QString input;
    double ans;
    QFont adaptive_font_size(QFont f, QString str);
};
#endif // APP_H
