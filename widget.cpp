#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include <QFileDialog>
#include <QDir>
#include <QMediaPlayer>
#include <QAudioOutput>
#include <QUrl>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //  创建并绑定媒体对象
    mediaPlayer = new QMediaPlayer(this);
    audioOutput = new QAudioOutput(this);
    mediaPlayer->setAudioOutput(audioOutput);

    // 音乐总时长
    connect(mediaPlayer, &QMediaPlayer::durationChanged, this, [=](qint64 duration)
    {
        ui->label_totalTime->setText(QString("%1:%2").arg(duration/1000/60, 2, 10, QChar('0'))
                                                     .arg(duration/1000%60, 2, 10, QChar('0')));
        ui->playProcessSlider->setRange(0,duration);
    });

    // 已播放时长
    connect(mediaPlayer, &QMediaPlayer::positionChanged, this, [=](qint64 pos)
    {
        ui->label_cTime->setText(QString("%1:%2").arg(pos/1000/60, 2, 10, QChar('0'))
                                                 .arg(pos/1000%60, 2, 10, QChar('0')));
        ui->playProcessSlider->setValue(pos);
    });

    // 进度条拖动
    connect(ui->playProcessSlider, &QSlider::sliderMoved, mediaPlayer, &QMediaPlayer::setPosition);

    // 音量条拖动
    audioOutput->setVolume(0.5);
    ui->soundSlider->setRange(0,100);
    ui->soundSlider->setValue(50);
    connect(ui->soundSlider, &QSlider::sliderMoved, audioOutput, [=](double sound)
    {
        audioOutput->setVolume(sound/100);
        ui->label_sound_2->setText(QString::number(sound));
    });
}


Widget::~Widget()
{
    delete ui;
}


// 按钮绑定函数：获取并显示歌单
void Widget::on_pushButton_openFile_clicked()
{
    // 打开文件选择框 并 选择音乐目录
    auto path = QFileDialog::getExistingDirectory(this, "选择音乐所在的目录","D:/文件/CloudMusic/music");
    QDir dir(path);
    auto musicList = dir.entryList(QStringList() << "*.mp3" << "*.flac" << "*.wav" << "*.ogg");


    // 传给songlistWidget显示
    if ( !musicList.empty() )
    {
        while(ui->songListWidget->count() > 0)
        {
            ui->songListWidget->takeItem(0);
        }
    }
    ui->songListWidget->addItems(musicList);
    ui->songListWidget->setCurrentRow(0);
    index = 0;

    // 传给playList(格式为全路径）
    if ( !musicList.empty() )
    {
        playList.clear();
    }
    for (auto file : musicList)
    {
        playList.append(QUrl::fromLocalFile(path + '/' + file));
    }

    qInfo() << playList;

}


// 按钮绑定函数：播放与暂停
void Widget::on_pushButton_switch_clicked()
{
    if (ui->songListWidget->count() == 0)
    {
        return;
    }

    switch (mediaPlayer->playbackState())
    {

    // 未播放
    case QMediaPlayer::PlaybackState::StoppedState:
    {
        index = ui->songListWidget->currentRow();
        mediaPlayer->setSource(playList[index]);
        mediaPlayer->play();
        break;
    }

    // 暂停
    case QMediaPlayer::PlaybackState::PausedState:
    {
        int indexTemp = ui->songListWidget->currentRow();
        if (index == indexTemp)
        {
            mediaPlayer->play();
        }
        else
        {
            index = indexTemp;
            mediaPlayer->setSource(playList[index]);
            mediaPlayer->play();
        }
        break;
    }

    // 正在播放
    case QMediaPlayer::PlaybackState::PlayingState:
    {
        int indexTemp = ui->songListWidget->currentRow();
        if (index == indexTemp)
        {
            mediaPlayer->pause();
        }
        else
        {
            index = indexTemp;
            mediaPlayer->setSource(playList[index]);
            mediaPlayer->play();
        }
        break;
    }


    }
}


// 上一首
void Widget::on_pushButton_last_clicked()
{
    if (ui->songListWidget->count() == 0)
    {
        return;
    }

    // 第一首 --> 最后一首
    if (index == 0)
    {
        index = ui->songListWidget->count() - 1;
        mediaPlayer->setSource(playList[index]);
        mediaPlayer->play();
        ui->songListWidget->setCurrentRow(index);
    }

    // 上一首
    else
    {
        index--;
        mediaPlayer->setSource(playList[index]);
        mediaPlayer->play();
        ui->songListWidget->setCurrentRow(index);
    }

}


// 下一首
void Widget::on_pushButton_next_clicked()
{
    if (ui->songListWidget->count() == 0)
    {
        return;
    }

    // 最后一首 --> 第一首
    if (index == ui->songListWidget->count() - 1)
    {
        index = 0;
        mediaPlayer->setSource(playList[index]);
        mediaPlayer->play();
        ui->songListWidget->setCurrentRow(index);
    }

    // 下一首
    else
    {
        index++;
        mediaPlayer->setSource(playList[index]);
        mediaPlayer->play();
        ui->songListWidget->setCurrentRow(index);
    }
}


// 双击播放
void Widget::on_songListWidget_doubleClicked(const QModelIndex &m_index)
{
    index = m_index.row();
    mediaPlayer->setSource(playList[index]);
    mediaPlayer->play();
}

