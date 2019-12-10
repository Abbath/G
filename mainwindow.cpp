#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>
#include <QPainter>
#include <defs.hpp>

bool operator==(const Goods a, const Goods b) { return b.id == a.id; }
bool operator==(const Entity a, const Entity b) { return b.id == a.id; }

void MainWindow::paintEvent(QPaintEvent *e) {
  e->accept();
  QPainter painter(this);
  if (gameovah) {
    painter.setBrush(QBrush(Qt::red));
    painter.drawText(this->rect(), Qt::AlignCenter,
                     "GAME OVER\nSCORE: " + QString::number(score));
    return;
  }

  painter.setBrush(QBrush(Qt::white));
  painter.drawRect(QRect(0, 0, FIELD_WIDTH, FIELD_HEIGHT));
  painter.setBrush(QBrush(Qt::green));
  int to_remove = -1;
  for (auto &g : goods) {
//    g.setValue(g.getValue() + (dice_roll4() == 0 ? 1 : 0));
    auto d = g.getCoords().distance(player.getCoords());
    if (d < EATING_NUMBER + sqrt(player.getHp())) {
      to_remove = g.getId();
    }
    painter.drawEllipse({g.getCoords().X(), g.getCoords().Y()},
                        5 + sqrt(g.getValue()), 5 + sqrt(g.getValue()));
  }
  if (to_remove >= 0) {
    score += goods[to_remove].getValue();
    player.setHp(player.getHp() + goods[to_remove].getValue() / 20);
    goods.remove(to_remove);
    goods.insert(to_remove, Goods(to_remove, Coords(dice_roll2(), dice_roll2()),
                                  dice_roll3()));
  }
  QSet<int> to_remove_e;
  painter.setBrush(QBrush(Qt::red));
  for (auto &e : entities) {
    auto d = e.getCoords().distance(player.getCoords());
    if (d < HUNTING_NUMBER || e.getHunting()) {
      e.setHunting(true);
      auto dxs = sgn(player.getCoords().X() - e.getCoords().X());
      auto dys = sgn(player.getCoords().Y() - e.getCoords().Y());
      auto dx = std::abs(e.getCoords().X() - player.getCoords().X());
      auto dy = std::abs(e.getCoords().Y() - player.getCoords().Y());
      dx = dx / d * 2.0 * dxs;
      dy = dy / d * 2.0 * dys;
      e.step(dx, dy);
    } else {
      e.setHp(e.getHp() + (dice_roll4() == 0 ? (log10(player.getHp())-1) : 0));
      e.step(dice_roll1(), dice_roll1());
    }
    if (d > RELEASE_NUMBER) {
      e.setHunting(false);
    }
    if (d < DIE_NUMBER + sqrt(player.getHp())) {
      player.setHp(player.getHp() - e.getHp() / 10);
      e.setHp(e.getHp() - player.getHp() / 20);
      if (e.getHp() <= 0) {
        e.setHp(0);
        to_remove_e.insert(entities.key(e));
      }
      if (player.getHp() <= 0) {
        player.setHp(0);
        gameovah = true;
      }
    }

    painter.drawEllipse({e.getCoords().X(), e.getCoords().Y()},
                        5 + sqrt(e.getHp()), 5 + sqrt(e.getHp()));
  }

  for (int to_remove : to_remove_e) {
    score += 1000;
    player.setHp(player.getHp() + 50);
    entities.remove(to_remove);
    entities.insert(
        to_remove,
        Entity(to_remove, Coords(dice_roll2(), dice_roll2()), dice_roll3()));
  }
  painter.setBrush(QBrush(Qt::blue));
  painter.drawEllipse({player.getCoords().X(), player.getCoords().Y()},
                      5 + sqrt(player.getHp()), 5 + sqrt(player.getHp()));
  painter.setBrush(QBrush(Qt::black));
  painter.drawText(0, FIELD_HEIGHT,
                   QString::number(player.getHp()) + ", " +
                       QString::number(score));
}

void MainWindow::keyPressEvent(QKeyEvent *e) {
  switch (e->key()) {
  case Qt::Key_Left: {
    player.step(-3, 0);
    update();
    break;
  }
  case Qt::Key_Right: {
    player.step(3, 0);
    update();
    break;
  }
  case Qt::Key_Up: {
    player.step(0, -3);
    update();
    break;
  }
  case Qt::Key_Down: {
    player.step(0, 3);
    update();
    break;
  }
  }
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow),
      player(Coords{FIELD_WIDTH / 2, FIELD_HEIGHT / 2}, 100) {
  ui->setupUi(this);
  this->resize(FIELD_WIDTH, FIELD_HEIGHT);
  for (int i = 0; i < ENTITIES_NUMBER; ++i) {
    entities.insert(
        i, Entity(i, Coords(dice_roll2(), dice_roll2()), dice_roll3()));
  }
  for (int i = 0; i < GOODS_NUMBER; ++i) {
    goods.insert(i, Goods(i, Coords(dice_roll2(), dice_roll2()), dice_roll3()));
  }
}

MainWindow::~MainWindow() { delete ui; }
