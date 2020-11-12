#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtGui>
#include <QtCore>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public slots:
    void showCurrentMousePosition(QPoint&);
    void mousePressed();
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_show_axes_stateChanged(int arg1);

    void on_grid_size_valueChanged(int arg1);

    void on_reset_clicked();

    void on_set_p1_clicked();

    void on_set_p2_clicked();

    void on_unset_p2_clicked();

    void on_unset_p1_clicked();

private:
    Ui::MainWindow *ui;
    int gridSize;
    QPoint p1, p2;

    //////////////////// BASIC UTILITY FUNCTION////////////////////
    void point(int x, int y, int r=200, int g=200, int b=200);
    void point(int x, int y, QRgb color);
    void clear_frame();
    int scale(int X);
    int transformX(int X);
    int transformY(int Y);
    void reset();


    ////////////////// FUNCTIONS FOR GRID AND AXES////////////////////
    void draw_axes();
    void remove_axes();
    void draw_grid();
};
#endif // MAINWINDOW_H
