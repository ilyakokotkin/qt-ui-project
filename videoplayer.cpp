// Copyright (C) 2017 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR BSD-3-Clause
#include "videoplayer.h"

#include <QBoxLayout>
#include <QFileDialog>
#include <QHBoxLayout>
#include <QLabel>
#include <QMediaPlayer>
#include <QPushButton>
#include <QSizePolicy>
#include <QSlider>
#include <QStackedWidget>
#include <QStandardPaths>
#include <QString>
#include <QStyle>
#include <QVideoWidget>
#include <QMessageBox>


VideoPlayer::VideoPlayer(QWidget *parent) : QWidget(parent)
{
    // Create the media player and video widget first
    m_mediaPlayer = new QMediaPlayer(this);
    QVideoWidget *videoWidget = new QVideoWidget;

    // Bake in the video file into the code using .qrc resource file
    m_mediaPlayer->setVideoOutput(videoWidget);
    m_mediaPlayer->setSource(QUrl("qrc:/new/prefix1/video.mp4"));

    // Create the home screen widget
    QWidget *homeScreen = new QWidget;
    QVBoxLayout *homeLayout = new QVBoxLayout(homeScreen);
    QPushButton *playVideoButton = new QPushButton(tr("Play Video"));
    homeLayout->addWidget(playVideoButton);
    QPushButton *aboutButton = new QPushButton(tr("About"));
    homeLayout->addWidget(aboutButton);

    // Create the stacked widget and add the home screen and video widget to it
    QStackedWidget *stackedWidget = new QStackedWidget(this);
    stackedWidget->addWidget(homeScreen);
    stackedWidget->addWidget(videoWidget);

    // Set the stacked widget as the main layout
    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(stackedWidget);
    setLayout(mainLayout);

    // Set up the media player and video output
    m_mediaPlayer->setVideoOutput(videoWidget);

    // Connect the play video button to show the video widget and start playback
    connect(playVideoButton, &QPushButton::clicked, this, [this, stackedWidget, videoWidget]() {
        stackedWidget->setCurrentWidget(videoWidget);
        m_mediaPlayer->play();});
    connect(aboutButton, &QPushButton::clicked, this, [this]() {
            QMessageBox::about(this, tr("About"), tr("Developed By Ilya Kokotkin using Qt for Harbinger Motors"));
    });
}

VideoPlayer::~VideoPlayer() { }

void VideoPlayer::openFile()
{
    QFileDialog fileDialog(this);
    fileDialog.setAcceptMode(QFileDialog::AcceptOpen);
    fileDialog.setWindowTitle(tr("Open Movie"));
    fileDialog.setDirectory(QStandardPaths::standardLocations(QStandardPaths::MoviesLocation)
                                    .value(0, QDir::homePath()));
    if (fileDialog.exec() == QDialog::Accepted)
        setUrl(fileDialog.selectedUrls().constFirst());
}

void VideoPlayer::setUrl(const QUrl &url)
{
    m_errorLabel->setText(QString());
    setWindowFilePath(url.isLocalFile() ? url.toLocalFile() : QString());
    m_mediaPlayer->setSource(url);
    m_playButton->setEnabled(true);
}

void VideoPlayer::play()
{
    switch (m_mediaPlayer->playbackState()) {
    case QMediaPlayer::PlayingState:
        m_mediaPlayer->pause();
        break;
    default:
        m_mediaPlayer->play();
        break;
    }
}

void VideoPlayer::mediaStateChanged(QMediaPlayer::PlaybackState state)
{
    switch (state) {
    case QMediaPlayer::PlayingState:
        m_playButton->setIcon(style()->standardIcon(QStyle::SP_MediaPause));
        break;
    default:
        m_playButton->setIcon(style()->standardIcon(QStyle::SP_MediaPlay));
        break;
    }
}

void VideoPlayer::positionChanged(qint64 position)
{
    m_positionSlider->setValue(position);
}

void VideoPlayer::durationChanged(qint64 duration)
{
    m_positionSlider->setRange(0, duration);
}

void VideoPlayer::setPosition(int position)
{
    m_mediaPlayer->setPosition(position);
}

void VideoPlayer::handleError()
{
    if (m_mediaPlayer->error() == QMediaPlayer::NoError)
        return;

    m_playButton->setEnabled(false);
    const QString errorString = m_mediaPlayer->errorString();
    QString message = "Error: ";
    if (errorString.isEmpty())
        message += " #" + QString::number(int(m_mediaPlayer->error()));
    else
        message += errorString;
    m_errorLabel->setText(message);
}

#include "moc_videoplayer.cpp"
