#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include<QApplication>
#include<QWidget>

#include<QMainWindow>
#include<QPushButton>
#include<QLabel>
#include<QSpinBox>
#include<QRadioButton>
#include<QPlainTextEdit>
#include<QFormLayout>
#include<QGridLayout>
#include<QBoxLayout>
#include<QSlider>

class MainWindow : public QMainWindow
{
    Q_OBJECT

private slots:

    // red
    void enter_to_red_spin_box(int red_value);

    void move_red_slider(int red_value);

    // green
    void enter_to_green_spin_box(int green_value);

    void move_green_slider(int green_value);

    // blue
    void enter_to_blue_spin_box(int blue_value);

    void move_blue_slider(int blue_value);

    // set color in palette
    void set_color_to_palette();

    // finctional of actions_buttons
    void up_to_maximum_red_green_blue_values();

    void down_to_minimum_red_green_blue_values();

    // work_modes
    void syngly_mode(bool mode);

    void together_mode(bool mode);

    void lock_mode(bool mode);

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    // color changers
    QSpinBox red_spin_box, green_spin_box, blue_spin_box; // color_cpin_boxes
    QSlider red_slider, green_slider, blue_slider; // color_sliders

    // actions_buttons
    QRadioButton singly_radio_button, together_radio_button, lock_radio_button; // actions_radio_buttons
    QPushButton top_button, default_button, exit_button; // actions_push_buttons

    // color informaters
    QLabel red_label, green_label, blue_label; // color_labels
    QPlainTextEdit color_palette; // result_color_palette
};
#endif // MAINWINDOW_H
