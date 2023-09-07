#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

struct Vector2D;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void AddWidget(QWidget* widgetToAdd, const Vector2D& size ,const Vector2D& position);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
