/*
 * created by Malith Samarasinghe 2020
 * built language   C++
 *
 * For the full copyright and license information, please view
 * the file license.txt that was distributed with this source code.
 */

#include "enemy.h"
#include <QDebug>
#include <QObject>
#include <math.h>

Enemy::Enemy(QObject *parent)
    : QObject(parent)

{
    xdir = 0;
    ydir = 1;
    destroyed = false;
    image.load(":images/en1.png");
    rect = image.rect();
    timerd = startTimer(100);
  //  xt = QTime::currentTime();
    xt = QTime::currentTime().addSecs(1);
    irot = 1;
}
Enemy::~Enemy()
{
    killTimer(timerd);
    qDebug() << "Enemy deleted:" <<  "OK";
}

void Enemy::resetState(int x,int y)
{
	rect.moveTo(x,y);
}
void Enemy::autoMove()
{
	rect.translate(xdir, ydir);
}
void Enemy::Destroyed()
{
    image.load(":images/explo.png");
    destroyed=true;
    qDebug() << "Enemy destroyed!!" <<  "OK";
}
void Enemy::timerEvent(QTimerEvent *event)
{

    n = QTime::currentTime();
    if(xt > n){
       image.load(":images/en11.png");

    }
    if(xt < n){
        image.load(":images/en11.png");
		xt = QTime::currentTime().addSecs(1);
    }
}

QRect Enemy::getRect(){
  return rect;
}

QImage & Enemy::getImage(){
  return image;
}
void Enemy::moveTop(int top)
{
  rect.moveTop(top);
}
