// Copyright (C) 2017 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR BSD-3-Clause

#include "videoplayer.h"

#include <QApplication>
#include <QCommandLineOption>
#include <QCommandLineParser>
#include <QDir>
#include <QScreen>
#include <QUrl>

// The main function: the entry point of the application

int main(int argc, char *argv[])
{
    // Initialize the QApplication object with command-line arguments

    QApplication app(argc, argv);

    // Set application metadata used by the system and for identification
    QCoreApplication::setApplicationName("Video Widget Example");
    QCoreApplication::setOrganizationName("QtProject");
    QGuiApplication::setApplicationDisplayName(QCoreApplication::applicationName());
    QCoreApplication::setApplicationVersion(QT_VERSION_STR);

    // Initialize a command line parser
    QCommandLineParser parser;
    parser.setApplicationDescription("Qt Video Widget Example");
    parser.addHelpOption();
    parser.addVersionOption();

    // Define a positional argument 'url' that can be used to specify a video file to open
    parser.addPositionalArgument("url", "The URL to open.");

    // Process the actual command line arguments given by the user
    parser.process(app);

    // Instantiate the VideoPlayer object
    VideoPlayer player;
     // Check if the user has provided a positional argument for the video file
    if (!parser.positionalArguments().isEmpty()) {
        // Get the first positional argument as a URL
        const QUrl url = QUrl::fromUserInput(parser.positionalArguments().constFirst(),
                                             QDir::currentPath(), QUrl::AssumeLocalFile);
        // Set the URL in the video player
        player.setUrl(url);
    }

    // Get the size of the screen where the player is displayed
    const QSize availableGeometry = player.screen()->availableSize();

    // Resize the player window to be a fraction of the screen size
    player.resize(availableGeometry.width() / 6, availableGeometry.height() / 4);

    // Show the player window
    player.show();

    // Enter the main event loop and wait until exit() is called
    // Returns the value that was set to exit() (which is 0 if exit() is called via quit())
    return app.exec();
}
