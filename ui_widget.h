/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 6.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_openFile;
    QPushButton *pushButton_last;
    QPushButton *pushButton_switch;
    QPushButton *pushButton_next;
    QPushButton *pushButton_4;
    QListWidget *songListWidget;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_cTime;
    QSlider *playProcessSlider;
    QLabel *label_totalTime;
    QWidget *widget_3;
    QVBoxLayout *verticalLayout;
    QLabel *label_sound_1;
    QLabel *label_sound_2;
    QSlider *soundSlider;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName("Widget");
        Widget->setEnabled(true);
        Widget->resize(400, 500);
        Widget->setMinimumSize(QSize(400, 500));
        Widget->setMaximumSize(QSize(400, 500));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/Resources/replace.png"), QSize(), QIcon::Normal, QIcon::Off);
        Widget->setWindowIcon(icon);
        Widget->setStyleSheet(QString::fromUtf8("*{\n"
"	border:none;\n"
"}\n"
"\n"
"QPushButton:hover\n"
"{\n"
"	background-color: rgb(0, 85, 255);\n"
"}"));
        widget = new QWidget(Widget);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(0, 450, 401, 51));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName("horizontalLayout");
        pushButton_openFile = new QPushButton(widget);
        pushButton_openFile->setObjectName("pushButton_openFile");
        pushButton_openFile->setMaximumSize(QSize(32, 32));
        pushButton_openFile->setStyleSheet(QString::fromUtf8("background-image: url(:/Resources/replace.png);"));
        pushButton_openFile->setIconSize(QSize(16, 16));

        horizontalLayout->addWidget(pushButton_openFile);

        pushButton_last = new QPushButton(widget);
        pushButton_last->setObjectName("pushButton_last");
        pushButton_last->setMaximumSize(QSize(32, 32));
        pushButton_last->setStyleSheet(QString::fromUtf8("background-image: url(:/Resources/replace.png);"));
        pushButton_last->setIconSize(QSize(16, 16));

        horizontalLayout->addWidget(pushButton_last);

        pushButton_switch = new QPushButton(widget);
        pushButton_switch->setObjectName("pushButton_switch");
        pushButton_switch->setMaximumSize(QSize(32, 32));
        pushButton_switch->setStyleSheet(QString::fromUtf8("background-image: url(:/Resources/replace.png);"));
        pushButton_switch->setIconSize(QSize(16, 16));

        horizontalLayout->addWidget(pushButton_switch);

        pushButton_next = new QPushButton(widget);
        pushButton_next->setObjectName("pushButton_next");
        pushButton_next->setMaximumSize(QSize(32, 32));
        pushButton_next->setStyleSheet(QString::fromUtf8("background-image: url(:/Resources/replace.png);"));
        pushButton_next->setIconSize(QSize(16, 16));

        horizontalLayout->addWidget(pushButton_next);

        pushButton_4 = new QPushButton(widget);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setMaximumSize(QSize(32, 32));
        pushButton_4->setCursor(QCursor(Qt::ArrowCursor));
        pushButton_4->setStyleSheet(QString::fromUtf8("background-image: url(:/Resources/replace.png);"));
        pushButton_4->setIconSize(QSize(16, 16));

        horizontalLayout->addWidget(pushButton_4);

        songListWidget = new QListWidget(Widget);
        songListWidget->setObjectName("songListWidget");
        songListWidget->setGeometry(QRect(30, 20, 311, 361));
        songListWidget->setStyleSheet(QString::fromUtf8("font: 14pt \"\345\215\216\346\226\207\346\245\267\344\275\223\";"));
        widget_2 = new QWidget(Widget);
        widget_2->setObjectName("widget_2");
        widget_2->setGeometry(QRect(20, 410, 381, 40));
        horizontalLayout_2 = new QHBoxLayout(widget_2);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label_cTime = new QLabel(widget_2);
        label_cTime->setObjectName("label_cTime");

        horizontalLayout_2->addWidget(label_cTime);

        playProcessSlider = new QSlider(widget_2);
        playProcessSlider->setObjectName("playProcessSlider");
        playProcessSlider->setMinimumSize(QSize(250, 16));
        playProcessSlider->setMaximumSize(QSize(250, 16));
        playProcessSlider->setStyleSheet(QString::fromUtf8(""));
        playProcessSlider->setOrientation(Qt::Horizontal);

        horizontalLayout_2->addWidget(playProcessSlider);

        label_totalTime = new QLabel(widget_2);
        label_totalTime->setObjectName("label_totalTime");

        horizontalLayout_2->addWidget(label_totalTime);

        widget_3 = new QWidget(Widget);
        widget_3->setObjectName("widget_3");
        widget_3->setGeometry(QRect(350, 20, 42, 361));
        verticalLayout = new QVBoxLayout(widget_3);
        verticalLayout->setObjectName("verticalLayout");
        label_sound_1 = new QLabel(widget_3);
        label_sound_1->setObjectName("label_sound_1");
        label_sound_1->setStyleSheet(QString::fromUtf8("background-image: url(:/Resources/replace.png);"));

        verticalLayout->addWidget(label_sound_1);

        label_sound_2 = new QLabel(widget_3);
        label_sound_2->setObjectName("label_sound_2");

        verticalLayout->addWidget(label_sound_2);

        soundSlider = new QSlider(widget_3);
        soundSlider->setObjectName("soundSlider");
        soundSlider->setEnabled(true);
        soundSlider->setMinimumSize(QSize(20, 281));
        soundSlider->setMaximumSize(QSize(20, 281));
        soundSlider->setCursor(QCursor(Qt::ArrowCursor));
        soundSlider->setMouseTracking(false);
        soundSlider->setTabletTracking(false);
        soundSlider->setAutoFillBackground(false);
        soundSlider->setOrientation(Qt::Vertical);

        verticalLayout->addWidget(soundSlider);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Sound of Maple", nullptr));
        pushButton_openFile->setText(QCoreApplication::translate("Widget", "choose", nullptr));
        pushButton_last->setText(QCoreApplication::translate("Widget", "\344\270\212\344\270\200\351\246\226", nullptr));
        pushButton_switch->setText(QCoreApplication::translate("Widget", "\346\222\255\346\224\276", nullptr));
        pushButton_next->setText(QCoreApplication::translate("Widget", "\344\270\213\344\270\200\351\246\226", nullptr));
        pushButton_4->setText(QString());
        label_cTime->setText(QCoreApplication::translate("Widget", "00\357\274\23200", nullptr));
        label_totalTime->setText(QCoreApplication::translate("Widget", "00\357\274\23200", nullptr));
        label_sound_1->setText(QCoreApplication::translate("Widget", "\351\237\263\351\207\217", nullptr));
        label_sound_2->setText(QCoreApplication::translate("Widget", "50", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
