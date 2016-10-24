FROM ubuntu:16.04

RUN apt-get update
RUN apt-get install -y \
    binutils \
    ca-certificates \
    clang \
    git \
    make \
    openjdk-8-jdk \
    openssh-server \
    --no-install-recommends \
    && rm -rf /var/lib/apt/lists/*

RUN mkdir -p mkdir /var/run/sshd

ENV HOME /home/jenkins
RUN useradd --create-home --shell /bin/bash --base-dir /home jenkins

USER jenkins
RUN mkdir -p /home/jenkins/.ssh
COPY sshkeys/id_rsa.pub /home/jenkins/.ssh/authorized_keys
USER root
RUN chown -Rf jenkins:jenkins /home/jenkins/.ssh
USER jenkins
RUN chmod 0700 -R /home/jenkins/.ssh

USER root
EXPOSE 22
CMD ["/usr/sbin/sshd", "-D"]
