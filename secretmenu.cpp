#include "secretmenu.h"
#include "ui_secretmenu.h"

SecretMenu::SecretMenu(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::SecretMenu)
{
    ui->setupUi(this);
}

SecretMenu::~SecretMenu()
{
    delete ui;
}

void SecretMenu::on_pushButton_clicked()
{
    this->close();
}

