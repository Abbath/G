#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPaintEvent>
#include <QKeyEvent>
#include <player.hpp>
#include <entity.hpp>
#include <goods.hpp>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    QMap<int, Goods> goods;
    QMap<int, Entity> entities;
    Player player;
    bool gameovah = false;
    int score = 0;
public:
    void paintEvent(QPaintEvent *e);
    void keyPressEvent(QKeyEvent *e);
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
