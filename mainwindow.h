#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_oneButton_clicked();

    void on_twoButton_clicked();

    void on_threeButton_clicked();

    void on_fourButton_clicked();

    void on_fiveButton_clicked();

    void on_sixButton_clicked();

    void on_sevenButton_clicked();

    void on_eightButton_clicked();

    void on_nineButton_clicked();

    void on_cancelButton_clicked();

    void on_plusButton_clicked();

    void on_zeroButton_clicked();

    void on_resultButton_clicked();

    void on_minusButton_clicked();

    void on_mulButton_clicked();

    void on_delimButton_clicked();

    void on_percentButton_clicked();

    void on_plusMinusButton_clicked();

    void on_bracketsButton_clicked();

    void on_pointButton_clicked();

private:
    Ui::MainWindow *ui;

    QTimer timer, second_timer;
    bool result_long_pressed = false;
    QString secret_combination;
    void CheckSecret();
    void onSecondTimerTimeout();
    void onResultButtonPressed();
    void onResultButtonReleased();
    void onTimerTimeout();

    double GetModifiedValue(double arg, int increment);
    void SetComputationLabel();
    void SendCommand(char command);

    double left_argument = 0;
    double right_argument = 0;
    char current_command;
    bool is_right_arg = false;
    bool is_plus_pressed = false;
    bool is_minus_pressed = false;
    bool is_mul_pressed = false;
    bool is_delim_pressed = false;
    bool is_first_bracket = false;
    bool is_point_pressed = false;
    double point_mul = 0;

    std::array<int,10> digits = {0,1,2,3,4,5,6,7,8,9};
};
#endif // MAINWINDOW_H
