#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <math.h>

static QImage img(500,500,QImage::Format_RGB888);
static QRgb bgcolor(qRgb(0,0,0));


MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->Display->setPixmap(QPixmap::fromImage(img));
};

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::DDA_algo(int x1,int y1,int x2,int y2)
{
    QRgb value;
    value = qRgb(0, 230, 230);
    int length = 0;
    if (abs(x2 - x1) >= abs(y2 - y1)){
        length = abs(x2 - x1);
    }
    else {
        length = abs(y2 - y1);
    }
    float dx = float(x2 - x1)/float(length);
    float dy = float(y2 - y1)/float(length);
    float x = x1;
    float y = y1;
    int i = 1;
    while (i <= length){
        img.setPixel(x, y, value);
        x = x + dx;
        y = y + dy;
        i++;
    }

}

void MainWindow::Bresenham_algo(int xc,int yc,int r)
{
    QRgb value;     //set colour of pixel
    value = qRgb(255,255,0);
    int x=0;    //start at point (0,r)
    int y=r;
    int D = 3 - (2*r);  //initial decision parameter
    while(x<=y){
        //set pixels in all 8 octants
        img.setPixel(y+xc, x+yc, value);
        img.setPixel(x+xc, y+yc, value);
        img.setPixel(-x+xc, y+yc, value);
        img.setPixel(-y+xc, x+yc, value);
        img.setPixel(-y+xc, -x+yc, value);
        img.setPixel(-x+xc, -y+yc, value);
        img.setPixel(x+xc, -y+yc, value);
        img.setPixel(y+xc, -x+yc, value);

        if (D<0){
            D = D + 4*x + 6;    //next decision parameter
        }
        else{
            D = D + 4*(x-y) + 10;   //next decision parameter
            y = y-1;
        }
        x = x+1;
    }
}




void MainWindow::on_DDA_clicked()
{
    int x1 = ui->plainTextEdit->toPlainText().toInt();
    int y1 = ui->plainTextEdit_2->toPlainText().toInt();
    int x2 = ui->plainTextEdit_3->toPlainText().toInt();
    int y2 = ui->plainTextEdit_4->toPlainText().toInt();

    DDA_algo(x1, y1, x2, y2);
    ui->Display->setPixmap(QPixmap::fromImage(img));
    ui->Display->show();
}


void MainWindow::on_Bresenham_clicked()
{
    int xc = ui->plainTextEdit_5->toPlainText().toInt();
    int yc = ui->plainTextEdit_6->toPlainText().toInt();
    int r  = ui->plainTextEdit_7->toPlainText().toInt();

    Bresenham_algo(xc, yc, r);
    ui->Display->setPixmap(QPixmap::fromImage(img));
    ui->Display->show();
}

