FROM ubuntu:14.04.5

ENV DEBIAN_FRONTEND noninteractive

RUN apt-get update
RUN apt-get install -y \
    binutils \
    ca-certificates \
    clang \
    git \
    make \
    --no-install-recommends \
    && rm -rf /var/lib/apt/lists/*

ENV HOME /home/builder
RUN useradd --create-home --shell /bin/bash --base-dir /home builder
USER builder

RUN mkdir -p /home/builder/work
WORKDIR /home/builder/work
RUN git clone https://github.com/tetsuok/docker-exercise.git -b master --single-branch

# Build gtest
RUN mkdir -p /home/builder/work/docker-exercise/gtest-sample/third_party
WORKDIR /home/builder/work/docker-exercise/gtest-sample/third_party
RUN git clone https://github.com/google/googletest.git -b master --single-branch
WORKDIR /home/builder/work/docker-exercise/gtest-sample/third_party/googletest
RUN git pull
ENV GTEST_DIR /home/builder/work/docker-exercise/gtest-sample/third_party/googletest/googletest
RUN /home/builder/work/docker-exercise/gtest-sample/scripts/build_gtest.sh
WORKDIR /home/builder/work/docker-exercise/gtest-sample

ENTRYPOINT bash
