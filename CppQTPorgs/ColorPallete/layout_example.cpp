#include <mainwindow.h>

int main (int argc, char **argv)
{
    QApplication app(argc, argv);
    QWidget widget(0);

    MainWindow mw;

    // create layouts
    QGridLayout grid_layout;
    widget.setLayout(&grid_layout);
    QFormLayout form_layout;
    QFormLayout v_box_layout;
    QHBoxLayout hor_box_layout;
    grid_layout.addLayout(&form_layout, 0, 0);
    grid_layout.addLayout(&v_box_layout, 0, 1);
    grid_layout.addLayout(&hor_box_layout, 2, 0, 1, 2);

    // settings for color_cpin_boxes
    mw.red_spin_box.setMinimum(0);
    mw.red_spin_box.setMaximum(255);
    mw.green_spin_box.setMinimum(0);
    mw.green_spin_box.setMaximum(255);
    mw.blue_spin_box.setMinimum(0);
    mw.blue_spin_box.setMaximum(255);

    // settings for color_labels
    mw.red_label.setText("Red");
    mw.green_label.setText("Green");
    mw.blue_label.setText("Blue");

    // set color_spin_boxes and color_labels in layout
    form_layout.addRow(&mw.red_label, &mw.red_spin_box);
    form_layout.addRow(&mw.green_label, &mw.green_spin_box);
    form_layout.addRow(&mw.blue_label, &mw.blue_spin_box);
    form_layout.setFieldGrowthPolicy(QFormLayout::FieldsStayAtSizeHint);

    // settings for color_sliders
    mw.red_slider.setOrientation(Qt::Horizontal);
    mw.red_slider.setMinimum(0);
    mw.red_slider.setMaximum(255);
    mw.green_slider.setOrientation(Qt::Horizontal);
    mw.green_slider.setMinimum(0);
    mw.green_slider.setMaximum(255);
    mw.blue_slider.setOrientation(Qt::Horizontal);
    mw.blue_slider.setMinimum(0);
    mw.blue_slider.setMaximum(255);

    // connecting color_sliders with color_spin_boxes
    QObject::connect(&mw.red_slider, SIGNAL(valueChanged(int)), &mw, SLOT(move_red_slider(int)));
    QObject::connect(&mw.green_slider, SIGNAL(valueChanged(int)), &mw, SLOT(move_green_slider(int)));
    QObject::connect(&mw.blue_slider, SIGNAL(valueChanged(int)), &mw, SLOT(move_blue_slider(int)));

    // connecting color_spin_boxes with color_sliders
    QObject::connect(&mw.red_spin_box, SIGNAL(valueChanged(int)), &mw, SLOT(enter_to_red_spin_box(int)));
    QObject::connect(&mw.green_spin_box, SIGNAL(valueChanged(int)), &mw, SLOT(enter_to_green_spin_box(int)));
    QObject::connect(&mw.blue_spin_box, SIGNAL(valueChanged(int)), &mw, SLOT(enter_to_blue_spin_box(int)));

    // settings for actions_radio_buttons
    mw.singly_radio_button.toggle();
    mw.singly_radio_button.setText("Singly");
    mw.together_radio_button.setText("Together");
    mw.lock_radio_button.setText("Lock");

    // connecting actions_radio_buttons with color_changers
    QObject::connect(&mw.singly_radio_button, SIGNAL(toggled(bool)), &mw, SLOT(syngly_mode(bool)));
    QObject::connect(&mw.together_radio_button, SIGNAL(toggled(bool)), &mw, SLOT(together_mode(bool)));
    QObject::connect(&mw.lock_radio_button, SIGNAL(toggled(bool)), &mw, SLOT(lock_mode(bool)));

    // set color_sliders and action_radio_buttons in layout
    v_box_layout.addRow(&mw.red_slider, &mw.singly_radio_button);
    v_box_layout.addRow(&mw.green_slider, &mw.together_radio_button);
    v_box_layout.addRow(&mw.blue_slider, &mw.lock_radio_button);

    // settings result_color_palette and set it in layout
    mw.color_palette.setEnabled(false);
    mw.color_palette.setBackgroundVisible(true);
    mw.color_palette.setStyleSheet("background: black");
    grid_layout.addWidget(&mw.color_palette, 1, 0, 1, 2); // the edit stretches for two coloumns

    // connecting color_changers with result_color_palette
    QObject::connect(&mw.red_spin_box, SIGNAL(valueChanged(int)), &mw, SLOT(set_color_to_palette()));
    QObject::connect(&mw.green_spin_box, SIGNAL(valueChanged(int)), &mw, SLOT(set_color_to_palette()));
    QObject::connect(&mw.blue_spin_box, SIGNAL(valueChanged(int)), &mw, SLOT(set_color_to_palette()));

    // settings actions_push_buttons
    mw.top_button.setText("Maximun");
    mw.default_button.setText("Minimun");
    mw.exit_button.setText("Exit");

    // connecting actions_buttons with color_changres
    QObject::connect(&mw.top_button, SIGNAL(clicked()), &mw, SLOT(up_to_maximum_red_green_blue_values()));
    QObject::connect(&mw.default_button, SIGNAL(clicked()), &mw, SLOT(down_to_minimum_red_green_blue_values()));
    QObject::connect(&mw.exit_button, SIGNAL(clicked()), &app, SLOT(quit()));

    // set actions_push_buttons in layout
    hor_box_layout.addStretch(20);
    hor_box_layout.addWidget(&mw.top_button);
    hor_box_layout.addWidget(&mw.default_button);
    hor_box_layout.addWidget(&mw.exit_button);

    // settings main window
    widget.setWindowTitle("Color palette");
    widget.resize(500, 400);
    widget.show();
    return app.exec();
}
