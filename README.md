# Video Player Application

This project is a simple video player application developed using the Qt framework. It features a home screen with "Play Video" and "About" buttons. Clicking the "Play Video" button plays a predetermined video, and the "About" button displays information about the application.

## Requirements

- Qt 6.6.1 or later
- Qt Multimedia module

### Configuring the Video File

The application expects a video file to be located in the videos directory within the project folder. To set up your video file, follow these steps:

1. Create a folder named videos in the root of the project directory.
2. Place your video file inside the videos folder and rename it to sample.mp4, or use the actual name of your video file and update the source path in the code accordingly.

Alternatively, you can modify the source code to point to the location of your video file: 
```
m_mediaPlayer->setSource(QUrl::fromLocalFile("your/path/to/video/file.mp4"));
```
Replace your/path/to/video/file.mp4 with the actual path to your video file on your system.

## Building the Application
### Using Qt Creator

Open Qt Creator.

Select File > Open File or Project....

Navigate to the directory containing the project files and select the CMakeLists.txt file.

Choose a build directory.

Click the Configure Project button.

Once the configuration is done, click the Build button on the bottom left or select Build > Build All.

### Using Command Line

Navigate to the root directory of the project in your terminal.
Create a new build directory and enter it:
```
mkdir build && cd build
```
Run CMake to configure the project and generate the makefile:
```
cmake ..
```
Build the project:
```
cmake --build .
```
To run the application, you can use:
```
./videoplayer
```
## Running the Application

After building the application, you can run the executable directly from Qt Creator by clicking the Run button, or from the command line as shown above. The application should open with the home screen displayed. Click "Play Video" to watch the video or "About" to see the application details.

## Project Structure

main.cpp: Initializes the application and sets up the main window.

videoplayer.h: Header file for the main widget of the application.

videoplayer.cpp: Implementation of the main widget, including media player setup and UI interactions.

videoplayer.ui: UI file describing the layout of the application's main widget.

## Contributing

Please read CONTRIBUTING.md for details on our code of conduct, and the process for submitting pull requests to us.

## License
This project is licensed under the BSD-3-Clause License - see the LICENSE file for details.

## Acknowledgments
Developed By Ilya Kokotkin using Qt for Harbinger Motors