FROM ubuntu:16.04
ENV DEBIAN_FRONTEND noninteractive

RUN apt-get update \
    && apt-get -y --quiet --no-install-recommends install \
    wget

# http://apt.llvm.org/
RUN wget --quiet http://apt.llvm.org/llvm-snapshot.gpg.key -O - | apt-key add -
RUN sh -c 'echo "deb http://apt.llvm.org/xenial/ llvm-toolchain-xenial-4.0 main" >> /etc/apt/sources.list'
RUN sh -c 'echo "deb-src http://apt.llvm.org/xenial/ llvm-toolchain-xenial-4.0 main" >> /etc/apt/sources.list'

RUN apt-get update
RUN apt-get install -y \
    binutils \
    clang-4.0 \
    clang-tidy-4.0 \
    llvm-4.0 \
    make \
    vim \
    python \
    --no-install-recommends \
    && rm -rf /var/lib/apt/lists/*

RUN update-alternatives --install /usr/bin/clang clang /usr/bin/clang-4.0 1 \
    && update-alternatives --install /usr/bin/clang++ clang++ /usr/bin/clang++-4.0 1 \
    && update-alternatives --install /usr/bin/clang-tidy clang-tidy /usr/bin/clang-tidy-4.0 1

ENV HOME /home/local
RUN useradd --create-home --shell /bin/bash --base-dir /home local
#USER local
WORKDIR /home/local
ENTRYPOINT bash
