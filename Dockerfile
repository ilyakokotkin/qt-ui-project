FROM ubuntu:20.04

ENV DEBIAN_FRONTEND=noninteractive

RUN apt-get update && apt-get install -y \
    build-essential \
    qt5-default \
    qt5-qmake \
    qtbase5-dev \
    libqt5multimedia5 \
    libqt5multimedia5-plugins \
    libqt5multimediawidgets5 \
    && rm -rf /var/lib/apt/lists/*


COPY . /app

WORKDIR /app

RUN qtchooser -run-tool=qmake -qt=5 && make

CMD ["./videoplayer"]
