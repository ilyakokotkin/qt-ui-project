# Use the official Ubuntu 20.04 LTS base image
FROM ubuntu:20.04

# Set environment variables to non-interactive (this prevents some prompts)
ENV DEBIAN_FRONTEND=noninteractive

# Install Qt5 and other build dependencies
RUN apt-get update && apt-get install -y \
    build-essential \
    qt5-default \
    qt5-qmake \
    qtbase5-dev \
    libqt5multimedia5-plugins \
    libqt5widgets5 \
    && rm -rf /var/lib/apt/lists/*

# Copy your application's source code into the container
COPY . /app

# Set the working directory to the app directory
WORKDIR /app

# Build the application
RUN qmake && make

# Set the command to run your application
CMD ["./videoplayer"]
