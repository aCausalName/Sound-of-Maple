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
    QWidget *widget_bottons;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_openFile;
    QPushButton *pushButton_last;
    QPushButton *pushButton_switch;
    QPushButton *pushButton_next;
    QPushButton *pushButton_modeSwitch;
    QPushButton *pushButton_coment;
    QWidget *widget_playProcess;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_cTime;
    QSlider *playProcessSlider;
    QLabel *label_totalTime;
    QLabel *label_attention;
    QLabel *label_nowPlay;
    QLabel *label_nowPlay2;
    QWidget *widget_sound;
    QVBoxLayout *verticalLayout;
    QLabel *label_sound_1;
    QLabel *label_sound_2;
    QSlider *soundSlider;
    QListWidget *songListWidget;
    QPushButton *pushButton_locate;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName("Widget");
        Widget->setEnabled(true);
        Widget->resize(800, 493);
        Widget->setMinimumSize(QSize(0, 0));
        Widget->setMaximumSize(QSize(99999, 99999));
        QIcon icon;
        icon.addFile(QString::fromUtf8("Resources/MapleLeaf.png"), QSize(), QIcon::Normal, QIcon::Off);
        Widget->setWindowIcon(icon);
        Widget->setStyleSheet(QString::fromUtf8("*{\n"
"	border:none;\n"
"}\n"
"\n"
"QPushButton:hover\n"
"{\n"
"	background-color: rgb(0, 85, 255);\n"
"}\n"
""));
        widget_bottons = new QWidget(Widget);
        widget_bottons->setObjectName("widget_bottons");
        widget_bottons->setGeometry(QRect(0, 435, 471, 51));
        widget_bottons->setMouseTracking(true);
        widget_bottons->setFocusPolicy(Qt::NoFocus);
        widget_bottons->setAutoFillBackground(false);
        horizontalLayout = new QHBoxLayout(widget_bottons);
        horizontalLayout->setObjectName("horizontalLayout");
        pushButton_openFile = new QPushButton(widget_bottons);
        pushButton_openFile->setObjectName("pushButton_openFile");
        pushButton_openFile->setMaximumSize(QSize(32, 32));
        pushButton_openFile->setMouseTracking(true);
        pushButton_openFile->setFocusPolicy(Qt::NoFocus);
        pushButton_openFile->setAutoFillBackground(false);
        pushButton_openFile->setStyleSheet(QString::fromUtf8("border-image: url(:/Resources/folder.png);"));
        pushButton_openFile->setIconSize(QSize(16, 16));

        horizontalLayout->addWidget(pushButton_openFile);

        pushButton_last = new QPushButton(widget_bottons);
        pushButton_last->setObjectName("pushButton_last");
        pushButton_last->setMaximumSize(QSize(32, 32));
        pushButton_last->setMouseTracking(true);
        pushButton_last->setFocusPolicy(Qt::NoFocus);
        pushButton_last->setAutoFillBackground(false);
        pushButton_last->setStyleSheet(QString::fromUtf8("border-image: url(:/Resources/last.png);"));
        pushButton_last->setIconSize(QSize(16, 16));

        horizontalLayout->addWidget(pushButton_last);

        pushButton_switch = new QPushButton(widget_bottons);
        pushButton_switch->setObjectName("pushButton_switch");
        pushButton_switch->setMaximumSize(QSize(32, 32));
        pushButton_switch->setMouseTracking(true);
        pushButton_switch->setFocusPolicy(Qt::NoFocus);
        pushButton_switch->setAutoFillBackground(false);
        pushButton_switch->setStyleSheet(QString::fromUtf8("border-image: url(:/Resources/pause.png);"));
        pushButton_switch->setIconSize(QSize(16, 16));

        horizontalLayout->addWidget(pushButton_switch);

        pushButton_next = new QPushButton(widget_bottons);
        pushButton_next->setObjectName("pushButton_next");
        pushButton_next->setMaximumSize(QSize(32, 32));
        pushButton_next->setMouseTracking(true);
        pushButton_next->setFocusPolicy(Qt::NoFocus);
        pushButton_next->setAutoFillBackground(false);
        pushButton_next->setStyleSheet(QString::fromUtf8("border-image: url(:/Resources/next.png);"));
        pushButton_next->setIconSize(QSize(16, 16));

        horizontalLayout->addWidget(pushButton_next);

        pushButton_modeSwitch = new QPushButton(widget_bottons);
        pushButton_modeSwitch->setObjectName("pushButton_modeSwitch");
        pushButton_modeSwitch->setMinimumSize(QSize(32, 32));
        pushButton_modeSwitch->setMaximumSize(QSize(32, 32));
        pushButton_modeSwitch->setMouseTracking(true);
        pushButton_modeSwitch->setFocusPolicy(Qt::NoFocus);
        pushButton_modeSwitch->setAutoFillBackground(false);
        pushButton_modeSwitch->setStyleSheet(QString::fromUtf8("border-image: url(:/Resources/listCirculate.png);"));

        horizontalLayout->addWidget(pushButton_modeSwitch);

        pushButton_coment = new QPushButton(widget_bottons);
        pushButton_coment->setObjectName("pushButton_coment");
        pushButton_coment->setMaximumSize(QSize(32, 32));
        pushButton_coment->setCursor(QCursor(Qt::ArrowCursor));
        pushButton_coment->setMouseTracking(true);
        pushButton_coment->setFocusPolicy(Qt::NoFocus);
        pushButton_coment->setAutoFillBackground(false);
        pushButton_coment->setStyleSheet(QString::fromUtf8("border-image: url(:/Resources/comment.png);"));
        pushButton_coment->setIconSize(QSize(16, 16));

        horizontalLayout->addWidget(pushButton_coment);

        widget_playProcess = new QWidget(Widget);
        widget_playProcess->setObjectName("widget_playProcess");
        widget_playProcess->setGeometry(QRect(30, 400, 701, 41));
        widget_playProcess->setMouseTracking(true);
        widget_playProcess->setFocusPolicy(Qt::NoFocus);
        widget_playProcess->setAutoFillBackground(false);
        horizontalLayout_2 = new QHBoxLayout(widget_playProcess);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label_cTime = new QLabel(widget_playProcess);
        label_cTime->setObjectName("label_cTime");
        label_cTime->setMinimumSize(QSize(60, 30));
        label_cTime->setMaximumSize(QSize(60, 30));
        QFont font;
        font.setPointSize(12);
        label_cTime->setFont(font);
        label_cTime->setMouseTracking(true);
        label_cTime->setFocusPolicy(Qt::NoFocus);
        label_cTime->setAutoFillBackground(false);

        horizontalLayout_2->addWidget(label_cTime);

        playProcessSlider = new QSlider(widget_playProcess);
        playProcessSlider->setObjectName("playProcessSlider");
        playProcessSlider->setMinimumSize(QSize(0, 16));
        playProcessSlider->setMaximumSize(QSize(9999, 3577543));
        playProcessSlider->setMouseTracking(true);
        playProcessSlider->setFocusPolicy(Qt::NoFocus);
        playProcessSlider->setAutoFillBackground(false);
        playProcessSlider->setStyleSheet(QString::fromUtf8("QSlider::handle:horizontal\n"
"{\n"
"	image: url(:/Resources/MapleLeaf.png);\n"
"}\n"
"\n"
"QSlider::sub-page:horizontal\n"
"{\n"
"	margin-top: 8px;\n"
"	margin-bottom:8px;\n"
"	background:rgb(0,255,0);\n"
"	background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(0, 255, 0, 255), stop:1 rgba(255, 255, 255, 255));\n"
"}"));
        playProcessSlider->setOrientation(Qt::Horizontal);

        horizontalLayout_2->addWidget(playProcessSlider);

        label_totalTime = new QLabel(widget_playProcess);
        label_totalTime->setObjectName("label_totalTime");
        label_totalTime->setMinimumSize(QSize(60, 30));
        label_totalTime->setMaximumSize(QSize(60, 30));
        label_totalTime->setFont(font);
        label_totalTime->setMouseTracking(true);
        label_totalTime->setFocusPolicy(Qt::NoFocus);
        label_totalTime->setAutoFillBackground(false);

        horizontalLayout_2->addWidget(label_totalTime);

        label_attention = new QLabel(Widget);
        label_attention->setObjectName("label_attention");
        label_attention->setGeometry(QRect(395, 465, 401, 20));
        label_attention->setFont(font);
        label_attention->setMouseTracking(true);
        label_attention->setFocusPolicy(Qt::NoFocus);
        label_attention->setAutoFillBackground(false);
        label_attention->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_nowPlay = new QLabel(Widget);
        label_nowPlay->setObjectName("label_nowPlay");
        label_nowPlay->setGeometry(QRect(100, 342, 360, 65));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_nowPlay->sizePolicy().hasHeightForWidth());
        label_nowPlay->setSizePolicy(sizePolicy);
        label_nowPlay->setMinimumSize(QSize(0, 12));
        label_nowPlay->setMaximumSize(QSize(16777215, 73));
        label_nowPlay->setFont(font);
        label_nowPlay->setMouseTracking(true);
        label_nowPlay->setFocusPolicy(Qt::NoFocus);
        label_nowPlay->setAutoFillBackground(false);
        label_nowPlay->setTextFormat(Qt::AutoText);
        label_nowPlay->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_nowPlay->setWordWrap(true);
        label_nowPlay2 = new QLabel(Widget);
        label_nowPlay2->setObjectName("label_nowPlay2");
        label_nowPlay2->setGeometry(QRect(12, 363, 80, 23));
        label_nowPlay2->setMinimumSize(QSize(60, 0));
        label_nowPlay2->setMaximumSize(QSize(80, 50));
        label_nowPlay2->setFont(font);
        label_nowPlay2->setMouseTracking(true);
        label_nowPlay2->setFocusPolicy(Qt::NoFocus);
        label_nowPlay2->setAutoFillBackground(false);
        widget_sound = new QWidget(Widget);
        widget_sound->setObjectName("widget_sound");
        widget_sound->setGeometry(QRect(730, 20, 61, 431));
        widget_sound->setMouseTracking(true);
        widget_sound->setFocusPolicy(Qt::NoFocus);
        widget_sound->setAutoFillBackground(false);
        verticalLayout = new QVBoxLayout(widget_sound);
        verticalLayout->setObjectName("verticalLayout");
        label_sound_1 = new QLabel(widget_sound);
        label_sound_1->setObjectName("label_sound_1");
        label_sound_1->setMinimumSize(QSize(37, 37));
        label_sound_1->setMaximumSize(QSize(37, 37));
        label_sound_1->setMouseTracking(true);
        label_sound_1->setFocusPolicy(Qt::NoFocus);
        label_sound_1->setAutoFillBackground(false);
        label_sound_1->setStyleSheet(QString::fromUtf8("border-image: url(:/Resources/sound-2.png);"));

        verticalLayout->addWidget(label_sound_1);

        label_sound_2 = new QLabel(widget_sound);
        label_sound_2->setObjectName("label_sound_2");
        label_sound_2->setMinimumSize(QSize(0, 40));
        label_sound_2->setMaximumSize(QSize(40, 60));
        QFont font1;
        font1.setPointSize(12);
        font1.setBold(false);
        label_sound_2->setFont(font1);
        label_sound_2->setMouseTracking(true);
        label_sound_2->setFocusPolicy(Qt::NoFocus);
        label_sound_2->setAutoFillBackground(false);
        label_sound_2->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_sound_2);

        soundSlider = new QSlider(widget_sound);
        soundSlider->setObjectName("soundSlider");
        soundSlider->setEnabled(true);
        soundSlider->setMinimumSize(QSize(20, 0));
        soundSlider->setMaximumSize(QSize(40, 99999));
        soundSlider->setCursor(QCursor(Qt::ArrowCursor));
        soundSlider->setMouseTracking(true);
        soundSlider->setTabletTracking(false);
        soundSlider->setFocusPolicy(Qt::NoFocus);
        soundSlider->setAutoFillBackground(false);
        soundSlider->setStyleSheet(QString::fromUtf8("QSlider::handle:vertical\n"
"{\n"
"	image: url(:/Resources/MapleLeaf.png);\n"
"}"));
        soundSlider->setOrientation(Qt::Vertical);

        verticalLayout->addWidget(soundSlider);

        songListWidget = new QListWidget(Widget);
        songListWidget->setObjectName("songListWidget");
        songListWidget->setGeometry(QRect(30, 30, 461, 301));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("\346\226\271\346\255\243\350\210\222\344\275\223")});
        font2.setPointSize(14);
        songListWidget->setFont(font2);
        songListWidget->setMouseTracking(true);
        songListWidget->setFocusPolicy(Qt::NoFocus);
        songListWidget->setAutoFillBackground(false);
        pushButton_locate = new QPushButton(Widget);
        pushButton_locate->setObjectName("pushButton_locate");
        pushButton_locate->setGeometry(QRect(470, 360, 31, 31));
        pushButton_locate->setMouseTracking(true);
        pushButton_locate->setFocusPolicy(Qt::NoFocus);
        pushButton_locate->setAutoFillBackground(false);
        pushButton_locate->setStyleSheet(QString::fromUtf8("border-image: url(:/Resources/locate.png);"));

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "\351\243\216\345\217\266\351\237\263\344\271\220", nullptr));
        pushButton_openFile->setText(QString());
        pushButton_last->setText(QString());
        pushButton_switch->setText(QString());
        pushButton_next->setText(QString());
        pushButton_modeSwitch->setText(QString());
        pushButton_coment->setText(QString());
        label_cTime->setText(QCoreApplication::translate("Widget", "00\357\274\23200", nullptr));
        label_totalTime->setText(QCoreApplication::translate("Widget", "00\357\274\23200", nullptr));
        label_attention->setText(QCoreApplication::translate("Widget", "\346\234\254\347\250\213\345\272\217\344\273\205\346\224\257\346\214\201mp3\357\274\214wav, flac, m4a\347\232\204\346\222\255\346\224\276\357\274\201", nullptr));
        label_nowPlay->setText(QCoreApplication::translate("Widget", "\346\227\240", nullptr));
        label_nowPlay2->setText(QCoreApplication::translate("Widget", "\345\275\223\345\211\215\346\222\255\346\224\276\357\274\232", nullptr));
        label_sound_1->setText(QString());
        label_sound_2->setText(QCoreApplication::translate("Widget", "50", nullptr));
        pushButton_locate->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
