FROM ubuntu:14.04.5

ENV DEBIAN_FRONTEND noninteractive

RUN apt-get update
RUN apt install -y clang git make binutils
RUN apt install -y --no-install-recommends ca-certificates

ENV HOME /home/builder
RUN useradd --create-home --shell /bin/bash --base-dir /home builder
USER builder

RUN mkdir -p /home/builder/work
WORKDIR /home/builder/work
RUN git clone https://github.com/tetsuok/docker-exercise.git -b master --single-branch
WORKDIR /home/builder/work/docker-exercise/gtest-sample/src

# # Build gtest
RUN mkdir -p /home/builder/work/docker-exercise/gtest-sample/third_party
WORKDIR /home/builder/work/docker-exercise/gtest-sample/third_party
RUN git clone https://github.com/google/googletest.git -b master --single-branch
ENV GTEST_DIR /home/builder/work/docker-exercise/gtest-sample/third_party/googletest/googletest
RUN /home/builder/work/docker-exercise/gtest-sample/scripts/build_gtest.sh

WORKDIR /home/builder/work/docker-exercise/gtest-sample/src

ENTRYPOINT bash
