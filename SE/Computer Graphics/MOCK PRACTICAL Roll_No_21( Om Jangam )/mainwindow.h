#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:


    void on_DDA_Line_Clicked_clicked();

    void on_Bresenha_Circle_clicked_clicked();

    void on_Inner_Circle_clicked();

private:
    Ui::MainWindow *ui;
    void bresenham_Circle(int xc, int yc, int r);
    void dda(int x1, int y1, int x2, int y2);

};
#endif // MAINWINDOW_H
