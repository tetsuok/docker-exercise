FROM ubuntu:14.04.5

ENV DEBIAN_FRONTEND noninteractive

RUN apt-get update
RUN apt-get install -y \
    ca-certificates \
    git \
    --no-install-recommends \
    && rm -rf /var/lib/apt/lists/*

ENV HOME /home/builder
RUN useradd --create-home --shell /bin/bash --base-dir /home builder
USER builder

RUN mkdir -p /home/builder/work
WORKDIR /home/builder/work
RUN git clone https://github.com/tetsuok/docker-exercise.git -b master

WORKDIR /home/builder/work/docker-exercise/hello/src

ENTRYPOINT bash
