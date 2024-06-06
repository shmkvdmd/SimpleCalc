#ifndef SECRETMENU_H
#define SECRETMENU_H

#include <QWidget>

namespace Ui {
class SecretMenu;
}

class SecretMenu : public QWidget
{
    Q_OBJECT

public:
    explicit SecretMenu(QWidget *parent = nullptr);
    ~SecretMenu();

private slots:
    void on_pushButton_clicked();

private:
    Ui::SecretMenu *ui;
};

#endif // SECRETMENU_H
