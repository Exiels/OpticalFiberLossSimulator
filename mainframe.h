#ifndef MAINFRAME_H
#define MAINFRAME_H

#include <QtWidgets>

class MainFrame : public QMainWindow
{
    Q_OBJECT

public:
    MainFrame();

private slots:
    void About();
    void New();
    void Calc();

protected:
    QString version;
    QLabel *GB_Main_Title_0;
    QLabel *GB_Main_Title_1;
    QLabel *GB_Main_Title_2;
    QLabel *GB_Main_Title_3;
    QLabel *GB_Main_Title_4;
    QLabel *GB_Main_Title_5;
    QLabel *GB_Main_Title_6;
    QLabel *GB_Main_Title_7;
    QLabel *GB_Main_Title_8;
    QLabel *GB_Main_Title_9;
    QLabel *GB_Main_Title_10;
    QDoubleSpinBox *GB_Main_n_Line;
    QDoubleSpinBox *GB_Main_C_Line;
    QDoubleSpinBox *GB_Main_c_Line;
    QDoubleSpinBox *GB_Main_J_Line;
    QDoubleSpinBox *GB_Main_M_Line;
    QDoubleSpinBox *GB_Main_a_Line;
    QDoubleSpinBox *GB_Main_L_Line;

    QPushButton *calc;
};

#endif // MAINFRAME_H
