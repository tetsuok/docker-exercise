FROM ubuntu:16.04

RUN apt-get update
RUN apt-get install -y openjdk-8-jdk openssh-server git binutils clang make inetutils-ping
RUN apt install -y --no-install-recommends ca-certificates

ENV HOME /home/executor
RUN useradd --create-home --shell /bin/bash --base-dir /home executor
RUN mkdir -p mkdir /var/run/sshd
CMD ["/usr/sbin/sshd", "-D"]
