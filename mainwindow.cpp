#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionNew_triggered()
{

}

void MainWindow::on_actionOpen_triggered()
{
    fileName=QFileDialog::getOpenFileName(this);
    workingFile = new QFile(fileName,this);
    workingFile->open(QFile::ReadWrite);
    data = workingFile->readAll();
    workingFile->close();
    stringData=QString(data);
   ui->plainTextEdit->document()->setPlainText(stringData);

}

void MainWindow::on_actionSave_triggered()
{
    stringData = ui->plainTextEdit->document()->toPlainText();
    fileName = QFileDialog::getSaveFileName(this);
    QFile *saveFile = new QFile(fileName,this);
    saveFile->open(QFile::WriteOnly);
    saveFile->write(stringData.toAscii());
    saveFile->flush();
    saveFile->close();



}
