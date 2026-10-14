#include "mainwindow.h"
#include "ui_mainwindow.h"

QImage img(500,500,QImage::Format_RGB888);
QRgb bgcolour(qRgb(0,0,0));

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::dda(int x1,int y1,int x2,int y2)
{   QRgb value=qRgb(0,230,230);


    float xinc,yinc,x,y;
    float dx,dy,step;

    dx=x2-x1;
    dy=y2-y1;

    if(abs(dx)>abs(dy))
    {
        step=dx;
    }
    else
    {
        step=dy;
    }

    xinc=dx/step;
    yinc=dy/step;


    int i=0;
    x=x1;
    y=y1;

    while(i<step)
    {
        img.setPixel(x,y,value);
        x=x+xinc;
        y=y+yinc;
        i++;
    }

}

void MainWindow::bresenham_Circle(int xc,int yc,int r)
{
    QRgb value=qRgb(255,255,0);
    int x,y,D;
    x=0;
    y=r;

    D=3-(2*r);
    while(x<=y)
    {
        img.setPixel(x+xc,y+yc,value);
        img.setPixel(-x+xc,y+yc,value);
        img.setPixel(x+xc,-y+yc,value);
        img.setPixel(-x+xc,-y+yc,value);
        img.setPixel(y+xc,x+yc,value);
        img.setPixel(-y+xc,x+yc,value);
        img.setPixel(y+xc,-x+yc,value);
        img.setPixel(-y+xc,-x+yc,value);

        if(D<0)
        {
         D=D+4*(x)+6;
        }
        else
        {
         D=D+4*(x-y)+10;
         y=y-1;
        }
        x=x+1;
    }

}


void MainWindow::on_DDA_Line_Clicked_clicked()
{   int x1,y1,x2,y2;

    x1=ui->plainTextEdit->toPlainText().toInt();
    y1=ui->plainTextEdit_2->toPlainText().toInt();
    x2=ui->plainTextEdit_3->toPlainText().toInt();
    y2=ui->plainTextEdit_4->toPlainText().toInt();

    dda(x1,y1,x2,y2);
    ui->Display->setPixmap(QPixmap::fromImage(img));
    ui->Display->show();
}


void MainWindow::on_Bresenha_Circle_clicked_clicked()
{
    int xc,yc,R;

    xc=ui->plainTextEdit_5->toPlainText().toInt();
    yc=ui->plainTextEdit_6->toPlainText().toInt();
    R=ui->plainTextEdit_7->toPlainText().toInt();

    bresenham_Circle(xc,yc,R);
    ui->Display->setPixmap(QPixmap::fromImage(img));
    ui->Display->show();
}
