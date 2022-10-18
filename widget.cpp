#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include <QFileDialog>
#include <QDir>
#include <QMediaPlayer>
#include <QAudioOutput>
#include <QUrl>
#include <ctime>
#include <QKeyEvent>

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

    // 音量条初始化
    audioOutput->setVolume(0.5);
    ui->soundSlider->setRange(0,100);
    ui->soundSlider->setValue(50);

    // 自动联播相关
    connect(mediaPlayer, &QMediaPlayer::playbackStateChanged, this, [this]()
    {
        int total = playList.count();

        // 切换下一首
        if (mediaPlayer->mediaStatus() == QMediaPlayer::EndOfMedia)
        {
            // 计算下一首的序号
            srand((unsigned int)time(NULL));
            if ( playMode == 0 ) {index++;}              //列表循环
            else if(playMode==1) {index=rand()%total;}   //随机
            else if(playMode==2)
            {
                mediaPlayer->setPosition(0);
                mediaPlayer->play();
                return;
            }                                            //单曲循环

            //播放
            mediaPlayer->setSource(playList[index % total]);
            mediaPlayer->play();
            ui->pushButton_switch->setStyleSheet("border-image: url(:/Resources/play.png);");

        }

        // "当前播放"更新
        ui->label_nowPlay->setText(musicList[index % total]);

        // play按钮状态改变
        if ( mediaPlayer->playbackState() == QMediaPlayer::PlaybackState::PlayingState )
        { ui->pushButton_switch->setStyleSheet("border-image: url(:/Resources/play.png);"); }
        else if ( mediaPlayer->playbackState() == QMediaPlayer::PlaybackState::StoppedState ||
                  mediaPlayer->playbackState() == QMediaPlayer::PlaybackState::PausedState)
        { ui->pushButton_switch->setStyleSheet("border-image: url(:/Resources/pause.png);"); }

    } );



}

Widget::~Widget()
{
    delete ui;
}


// 获取并显示歌单
void Widget::on_pushButton_openFile_clicked()
{
    // 打开文件选择框 并 选择音乐目录 (QList<Qurl>)musicList
    path = QFileDialog::getExistingDirectory(this, "选择音乐所在的目录","D:/文件/CloudMusic/music");
    QDir dir(path);
    musicList = dir.entryList(QStringList() << "*.mp3" << "*.flac" << "*.wav" << "*.m4a" << "*.mp4");

    // 清空(QListWidget)songListWidget, (QList<String>)playList
    if ( !musicList.empty() )
    {
        playList.clear();
        while(ui->songListWidget->count() > 0)
        {
            ui->songListWidget->takeItem(0);
        }
    }

    // 传给songlistWidget显示
    ui->songListWidget->addItems(musicList);
    ui->songListWidget->setCurrentRow(0);
    index = 0;

    // 传给playList(格式为全路径）
    for (auto file : musicList)
    {
        playList.append(QUrl::fromLocalFile(path + '/' + file));
    }

    this->releaseKeyboard();


}

// 播放与暂停
void Widget::on_pushButton_switch_clicked()
{
    if (playList.empty()){return;}

    switch (mediaPlayer->playbackState())
    {

    // 未播放
    case QMediaPlayer::PlaybackState::StoppedState:
    {
        index = ui->songListWidget->currentRow();
        mediaPlayer->setSource(playList[index]);
        mediaPlayer->play();
        ui->pushButton_switch->setStyleSheet("border-image: url(:/Resources/play.png);");
        break;
    }

    // 暂停
    case QMediaPlayer::PlaybackState::PausedState:
    {
        mediaPlayer->play();
        ui->pushButton_switch->setStyleSheet("border-image: url(:/Resources/play.png);");
        break;
    }

    // 正在播放
    case QMediaPlayer::PlaybackState::PlayingState:
    {
        mediaPlayer->pause();
        ui->pushButton_switch->setStyleSheet("border-image: url(:/Resources/pause.png);");
        break;
    }


    }
}

// 上一首
void Widget::on_pushButton_last_clicked()
{
    if (playList.empty()){return;}

    // 计算 接下来播放（上一首） 的序号
    int total = playList.count();
    srand((unsigned int)time(NULL));
    if (playMode==0||playMode==2) {index--;}              //列表循环
    else if(playMode==1) {index=rand()%total;}            //随机

    if ( index < 0 ){index += total;}                     //index不能为负

    mediaPlayer->setSource(playList[index%total]);
    mediaPlayer->play();
    ui->songListWidget->setCurrentRow(index%total);
    ui->pushButton_switch->setStyleSheet("border-image: url(:/Resources/play.png);");


}

// 下一首
void Widget::on_pushButton_next_clicked()
{
    if (playList.empty()){return;}

    // 计算下一首的序号
    int total = playList.count();
    srand((unsigned int)time(NULL));
    rand() % total;                                         //跳过第一个数
    if (playMode==0||playMode==2) {index++;}              //列表循环
    else if( playMode == 1 ) {index=rand()%total;}        //随机

    mediaPlayer->setSource(playList[index%total]);
    mediaPlayer->play();
    ui->songListWidget->setCurrentRow(index%total);
    ui->pushButton_switch->setStyleSheet("border-image: url(:/Resources/play.png);");

}

// 双击播放
void Widget::on_songListWidget_doubleClicked(const QModelIndex &m_index)
{
    index = m_index.row();
    mediaPlayer->setSource(playList[index]);
    mediaPlayer->play();
    ui->pushButton_switch->setStyleSheet("border-image: url(:/Resources/play.png);");

}

// 音量条拖动 与 图标变换
void Widget::on_soundSlider_valueChanged(int value)
{
    audioOutput->setVolume((float)value/100);
    ui->label_sound_2->setText(QString::number(value));


    if     ( value == 0 )                { ui->label_sound_1->setStyleSheet("border-image: url(:/Resources/sound-0.png);"); }
    else if(  0 < value && value < 34 )  { ui->label_sound_1->setStyleSheet("border-image: url(:/Resources/sound-1.jpg);"); }
    else if( 33 < value && value < 67 )  { ui->label_sound_1->setStyleSheet("border-image: url(:/Resources/sound-2.png);"); }
    else if( 66 < value && value < 101 ) { ui->label_sound_1->setStyleSheet("border-image: url(:/Resources/sound-3.png);"); }

}

// 播放模式切换  0-列表循环， 1-随机, 2-单曲循环
void Widget::on_pushButton_modeSwitch_clicked()
{
    if ( playMode == 0 )
    {
        playMode = 1;
        ui->pushButton_modeSwitch->setStyleSheet("border-image: url(:/Resources/random.png);");
    }
    else if ( playMode == 1 )
    {
        playMode = 2;
        ui->pushButton_modeSwitch->setStyleSheet("border-image: url(:/Resources/single.png);");
    }
    else if ( playMode == 2 )
    {
        playMode = 0;
        ui->pushButton_modeSwitch->setStyleSheet("border-image: url(:/Resources/listCirculate.png);");
    }
}

// 定位
void Widget::on_pushButton_locate_clicked()
{
    if (playList.empty()){return;}
    ui->songListWidget->setCurrentRow(index % playList.count());
}

//
void Widget::keyPressEvent(QKeyEvent* event)
{
    if ( event->key() == Qt::Key_Right ){ this->on_pushButton_next_clicked(); }
    if ( event->key() == Qt::Key_Left  ){ this->on_pushButton_last_clicked(); }
    if ( event->key() == Qt::Key_Space ){ this->on_pushButton_switch_clicked(); }
//    if ( event->key() == Qt::Key_Up ){ this->on_pushButton_next_clicked(); }
//    if ( event->key() == Qt::Key_Down ){ this->on_pushButton_next_clicked(); }
}
