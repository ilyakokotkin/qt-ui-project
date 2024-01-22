# Video Player Application

This project is a simple video player application developed using the Qt framework. It features a home screen with "Play Video" and "About" buttons. Clicking the "Play Video" button plays a predetermined video, and the "About" button displays information about the application.

## Requirements

- Qt 6.6.1 or later
- Qt Multimedia module
- Docker (if containerization is needed)

### Configuring the Video File

The application containts video.mp4 within its source code via the use of video_resource.qrc file.

## Building the Application

### Using Docker 

#### Build the Docker Image:

Open a terminal and navigate to the directory containing your project and the Dockerfile. 
Run the following command to build the Docker image:
```
docker build -t videoplayer .
```
This command builds a new Docker image with the tag videoplayer based on the instructions in your Dockerfile.

#### Run the Container:

After building the image, run your application in a new container using:

```
docker run --rm -it videoplayer
```

The --rm option tells Docker to remove the container after it exits, and -it allows you to interact with the application.

#### Note:

Running a GUI application from a Docker container on host system can be complex because the application needs access to the host's display server. 

This is straightforward on a Linux system but can be quite involved on Windows or macOS.

For a Linux system, one can share the host's display with the container like this:

```
docker run --rm -e DISPLAY=$DISPLAY -v /tmp/.X11-unix:/tmp/.X11-unix videoplayer
```

### Using Qt Creator

1. Open Qt Creator.

2. Select File > Open File or Project....

3. Navigate to the directory containing the project files and select the CMakeLists.txt file.

4. Choose a build directory.

5. Click the Configure Project button.

6. Once the configuration is done, click the Build button on the bottom left or select Build > Build All.

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

## License
This project is licensed under the BSD-3-Clause License - see the LICENSE file for details.

## Acknowledgments
Developed By Ilya Kokotkin using Qt for Harbinger Motors