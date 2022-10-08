#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QUrl>
#include <QMediaPlayer>
#include <QAudioOutput>


QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:

    void on_pushButton_openFile_clicked();

    void on_pushButton_switch_clicked();

    void on_pushButton_last_clicked();

    void on_pushButton_next_clicked();



    void on_songListWidget_doubleClicked(const QModelIndex &m_index);

private:
    Ui::Widget *ui;

    // 播放列表,媒体播放对象
    QList<QUrl> playList;
    QAudioOutput* audioOutput;
    QMediaPlayer* mediaPlayer;
    int index;

};
#endif // WIDGET_H
