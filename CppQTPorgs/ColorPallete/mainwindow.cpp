#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent){}

MainWindow::~MainWindow(){}

// red settings
void MainWindow::enter_to_red_spin_box(int red_value)
{
    red_slider.setValue(red_value);
}

void MainWindow::move_red_slider(int red_value)
{
    red_spin_box.setValue(red_value);
}

// green settings
void MainWindow::enter_to_green_spin_box(int green_value)
{
    green_slider.setValue(green_value);
}

void MainWindow::move_green_slider(int green_value)
{
    green_spin_box.setValue(green_value);
}

// blue settings
void MainWindow::enter_to_blue_spin_box(int blue_value)
{
    blue_slider.setValue(blue_value);
}

void MainWindow::move_blue_slider(int blue_value)
{
    blue_spin_box.setValue(blue_value);
}

// set color in palette
void MainWindow::set_color_to_palette()
{
    int red_value = red_spin_box.value();
    int green_value = green_spin_box.value();
    int blue_value = blue_spin_box.value();
    QColor color_value = QColor(red_value, green_value, blue_value);
    QString color_style = "background: rgb(%1, %2, %3);";
    color_style = color_style.arg(color_value.red()).arg(color_value.green()).arg(color_value.blue());
    color_palette.setStyleSheet(color_style);
}

//finctional of actions_buttons
void MainWindow::up_to_maximum_red_green_blue_values()
{
    red_spin_box.setValue(red_spin_box.maximum());
    green_spin_box.setValue(green_spin_box.maximum());
    blue_spin_box.setValue(blue_spin_box.maximum());
}

void MainWindow::down_to_minimum_red_green_blue_values()
{
    red_spin_box.setValue(red_spin_box.minimum());
    green_spin_box.setValue(green_spin_box.minimum());
    blue_spin_box.setValue(blue_spin_box.minimum());
}

// work_modes
void MainWindow::syngly_mode(bool mode)
{
    if(mode) {} // do nothing, but show the slot
    else {}
}

void MainWindow::together_mode(bool mode)
{
    if(mode)
    {
        //connecting red with green and blue
        QObject::connect(&red_slider, SIGNAL(valueChanged(int)), this, SLOT(move_green_slider(int)));
        QObject::connect(&red_slider, SIGNAL(valueChanged(int)), this, SLOT(move_blue_slider(int)));

        //connecting green with red and blue
        QObject::connect(&green_slider, SIGNAL(valueChanged(int)), this, SLOT(move_red_slider(int)));
        QObject::connect(&green_slider, SIGNAL(valueChanged(int)), this, SLOT(move_blue_slider(int)));

        //connecting blue with red and green
        QObject::connect(&blue_slider, SIGNAL(valueChanged(int)), this, SLOT(move_red_slider(int)));
        QObject::connect(&blue_slider, SIGNAL(valueChanged(int)), this, SLOT(move_green_slider(int)));

    }
    else
    {
        //disconnecting red with green and blue
        QObject::disconnect(&red_slider, SIGNAL(valueChanged(int)), this, SLOT(move_green_slider(int)));
        QObject::disconnect(&red_slider, SIGNAL(valueChanged(int)), this, SLOT(move_blue_slider(int)));

        //disconnecting green with red and blue
        QObject::disconnect(&green_slider, SIGNAL(valueChanged(int)), this, SLOT(move_red_slider(int)));
        QObject::disconnect(&green_slider, SIGNAL(valueChanged(int)), this, SLOT(move_blue_slider(int)));

        //disconnecting blue with red and green
        QObject::disconnect(&blue_slider, SIGNAL(valueChanged(int)), this, SLOT(move_red_slider(int)));
        QObject::disconnect(&blue_slider, SIGNAL(valueChanged(int)), this, SLOT(move_green_slider(int)));
    }
}

void MainWindow::lock_mode(bool mode)
{
    if(mode)
    {
        red_spin_box.setDisabled(true);
        red_slider.setDisabled(true);

        green_spin_box.setDisabled(true);
        green_slider.setDisabled(true);

        blue_spin_box.setDisabled(true);
        blue_slider.setDisabled(true);

        QObject::disconnect(&top_button, SIGNAL(clicked()), this, SLOT(up_to_maximum_red_green_blue_values()));
        QObject::disconnect(&default_button, SIGNAL(clicked()), this, SLOT(down_to_minimum_red_green_blue_values()));
    }
    else
    {
        red_spin_box.setDisabled(false);
        red_slider.setDisabled(false);

        green_spin_box.setDisabled(false);
        green_slider.setDisabled(false);

        blue_spin_box.setDisabled(false);
        blue_slider.setDisabled(false);

        QObject::connect(&top_button, SIGNAL(clicked()), this, SLOT(up_to_maximum_red_green_blue_values()));
        QObject::connect(&default_button, SIGNAL(clicked()), this, SLOT(down_to_minimum_red_green_blue_values()));
    }
}

