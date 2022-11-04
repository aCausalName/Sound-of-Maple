#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QUrl>
#include <QMediaPlayer>
#include <QAudioOutput>
#include <QDir>


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

    void on_soundSlider_valueChanged(int value);

    void on_pushButton_modeSwitch_clicked();

    void on_pushButton_locate_clicked();

    void keyPressEvent(QKeyEvent* event);
private:
    Ui::Widget *ui;

    // 歌曲文件读取
    QString path;
    QDir dir;

    // 播放列表,媒体播放对象
    QList<QUrl> playList;
    QList<QString> musicList;
    QAudioOutput* audioOutput;
    QMediaPlayer* mediaPlayer;

    int index;                          // 当前播放编号
    int playMode = 0;                   // 播放模式 0-列表循环， 1-随机, 2-单曲循环

};
#endif // WIDGET_H
