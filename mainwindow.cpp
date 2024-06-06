#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QDebug>
#include <QString>
#include <QtMath>
#include <QTimer>
#include "secretmenu.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    timer.setSingleShot(true);
    timer.setInterval(4000);
    second_timer.setSingleShot(true);
    second_timer.setInterval(5000);
    connect(ui->resultButton, &QPushButton::pressed, this, &MainWindow::onResultButtonPressed);
    connect(ui->resultButton, &QPushButton::released, this, &MainWindow::onResultButtonReleased);
    connect(&timer, &QTimer::timeout, this, &MainWindow::onTimerTimeout);
    connect(&second_timer, &QTimer::timeout, this, &MainWindow::onSecondTimerTimeout);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onResultButtonPressed() {
    timer.start();
}

void MainWindow::onResultButtonReleased() {
    timer.stop();
}

void MainWindow::onTimerTimeout() {
    qDebug() << "timer accepted";
    result_long_pressed = true;
    second_timer.start();
}
void MainWindow::onSecondTimerTimeout(){
    qDebug() << "timer declined";
    result_long_pressed = false;
}
void MainWindow::CheckSecret(){
    if (result_long_pressed && secret_combination == "123"){
        SecretMenu *secretMenu = new SecretMenu();
        secretMenu->show();
    }
}

double MainWindow::GetModifiedValue(double arg, int increment) {
    if (is_point_pressed) {
        arg += increment * point_mul;
        point_mul *= 0.1;
    }
    else {
        if (!arg) {
            arg += increment;
        }
        else {
            arg = (arg * 10) + increment;
        }
    }
    return arg;
}

void MainWindow::SetComputationLabel(){
    if(right_argument && current_command){
        ui->computationLabel->setText(QString::number(left_argument) + current_command + QString::number(right_argument));
    }
    else{
        ui->computationLabel->setText(QString::number(left_argument));
    }
}

void MainWindow::on_oneButton_clicked()
{
    if(is_right_arg){
        right_argument = GetModifiedValue(right_argument, digits[1]);
    }
    else{
        left_argument = GetModifiedValue(left_argument, digits[1]);
    }
    SetComputationLabel();
    secret_combination += "1";
}


void MainWindow::on_twoButton_clicked()
{
    if(is_right_arg){
        right_argument = GetModifiedValue(right_argument, digits[2]);
    }
    else{
        left_argument = GetModifiedValue(left_argument, digits[2]);
    }
    SetComputationLabel();
    secret_combination += "2";
}


void MainWindow::on_threeButton_clicked()
{
    if(is_right_arg){
        right_argument = GetModifiedValue(right_argument, digits[3]);
    }
    else{
        left_argument = GetModifiedValue(left_argument, digits[3]);
    }
    SetComputationLabel();
    secret_combination += "3";
    CheckSecret();
}


void MainWindow::on_fourButton_clicked()
{
    if(is_right_arg){
        right_argument = GetModifiedValue(right_argument, digits[4]);
    }
    else{
        left_argument = GetModifiedValue(left_argument, digits[4]);
    }
    SetComputationLabel();
}


void MainWindow::on_fiveButton_clicked()
{
    if(is_right_arg){
        right_argument = GetModifiedValue(right_argument, digits[5]);
    }
    else{
        left_argument = GetModifiedValue(left_argument, digits[5]);
    }
    SetComputationLabel();
}


void MainWindow::on_sixButton_clicked()
{
    if(is_right_arg){
        right_argument = GetModifiedValue(right_argument, digits[6]);
    }
    else{
        left_argument = GetModifiedValue(left_argument, digits[6]);
    }
    SetComputationLabel();
}


void MainWindow::on_sevenButton_clicked()
{
    if(is_right_arg){
        right_argument = GetModifiedValue(right_argument, digits[7]);
    }
    else{
        left_argument = GetModifiedValue(left_argument, digits[7]);
    }
    SetComputationLabel();
}


void MainWindow::on_eightButton_clicked()
{
    if(is_right_arg){
        right_argument = GetModifiedValue(right_argument, digits[8]);
    }
    else{
        left_argument = GetModifiedValue(left_argument, digits[8]);
    }
    SetComputationLabel();
}


void MainWindow::on_nineButton_clicked()
{
    if(is_right_arg){
        right_argument = GetModifiedValue(right_argument, digits[9]);
    }
    else{
        left_argument = GetModifiedValue(left_argument, digits[9]);
    }
    SetComputationLabel();
}

void MainWindow::on_zeroButton_clicked()
{
    if(is_right_arg){
        right_argument = GetModifiedValue(right_argument, digits[0]);
    }
    else{
        left_argument = GetModifiedValue(left_argument, digits[0]);
    }
    SetComputationLabel();
}

void MainWindow::on_cancelButton_clicked()
{
    ui->computationLabel->clear();
    ui->resultLabel->clear();
    right_argument = 0;
    left_argument = 0;
    is_right_arg = false;
    is_plus_pressed = false;
    is_minus_pressed = false;
    is_mul_pressed = false;
    is_delim_pressed = false;
    is_first_bracket = false;
    is_point_pressed = false;
    secret_combination.clear();
}

void MainWindow::SendCommand(char command){
    switch (command){
    case '+':
        if(is_plus_pressed){
            ui->resultLabel->setText(QString::number(left_argument + right_argument));
        }
        else{
            ui->computationLabel->setText(QString::number(left_argument) + '+');
            right_argument = 0;
        }
        is_plus_pressed = true;
        break;
    case '-':
        if(is_minus_pressed){
            ui->resultLabel->setText(QString::number(left_argument - right_argument));
        }
        else{
            ui->computationLabel->setText(QString::number(left_argument) + '-');
            right_argument = 0;
        }
        is_minus_pressed = true;
        break;
    case '*':
        if(is_mul_pressed){
            ui->resultLabel->setText(QString::number(left_argument * right_argument));
        }
        else{
            ui->computationLabel->setText(QString::number(left_argument) + '*');
            right_argument = 0;
        }
        is_mul_pressed = true;
        break;
    case '/':
        if(is_delim_pressed){
            ui->resultLabel->setText(QString::number(left_argument / right_argument));
        }
        else{
            ui->computationLabel->setText(QString::number(left_argument) + '/');
            right_argument = 0;
        }
        is_delim_pressed = true;
        break;
    }
}

void MainWindow::on_resultButton_clicked()
{
    if(is_plus_pressed){
        ui->resultLabel->setText(QString::number(left_argument + right_argument));
        is_plus_pressed = false;
    }
    else if(is_minus_pressed){
        ui->resultLabel->setText(QString::number(left_argument - right_argument));
        is_minus_pressed = false;
    }
    else if(is_mul_pressed){
        ui->resultLabel->setText(QString::number(left_argument * right_argument));
        is_mul_pressed = false;
    }
    else if(is_delim_pressed){
        ui->resultLabel->setText(QString::number(left_argument / right_argument));
        is_delim_pressed = false;
    }
    else{
        ui->resultLabel->setText(QString::number(left_argument));
    }
}

void MainWindow::on_plusButton_clicked()
{
    is_point_pressed = false;
    current_command = '+';
    is_right_arg = true;
    SendCommand(current_command);
}

void MainWindow::on_minusButton_clicked()
{
    is_point_pressed = false;
    current_command = '-';
    is_right_arg = true;
    SendCommand(current_command);
}


void MainWindow::on_mulButton_clicked()
{
    is_point_pressed = false;
    current_command = '*';
    is_right_arg = true;
    SendCommand(current_command);
}


void MainWindow::on_delimButton_clicked()
{
    is_point_pressed = false;
    current_command = '/';
    is_right_arg = true;
    SendCommand(current_command);
}


void MainWindow::on_percentButton_clicked()
{
    if (left_argument != 0 && right_argument != 0) {
        right_argument = (left_argument * right_argument) / 100.0;
        ui->resultLabel->setText(QString::number(right_argument));
    }
}


void MainWindow::on_plusMinusButton_clicked()
{
    is_point_pressed = false;
    if(!is_right_arg){
        left_argument *= -1;
    }
    else{
        right_argument *= -1;
    }
}


void MainWindow::on_bracketsButton_clicked()
{
    if(!is_first_bracket){
        ui->computationLabel->setText(ui->computationLabel->text() + "(");
        is_first_bracket = true;
    }
    else{
        ui->computationLabel->setText(ui->computationLabel->text() + ")");
        is_first_bracket = false;
    }
}


void MainWindow::on_pointButton_clicked()
{
    if(!is_point_pressed){
        ui->computationLabel->setText(ui->computationLabel->text() + '.');
        point_mul = 0.1;
    }
    is_point_pressed = true;
}

