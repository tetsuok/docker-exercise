FROM ubuntu:16.04

RUN apt-get update
RUN apt-get install -y openjdk-8-jdk openssh-server git binutils clang make
RUN apt install -y --no-install-recommends ca-certificates

RUN mkdir -p mkdir /var/run/sshd

ENV HOME /home/jenkins
RUN useradd --create-home --shell /bin/bash --base-dir /home jenkins

# This might be temporary?
USER jenkins
RUN mkdir -p /home/jenkins/.ssh
COPY sshkeys/id_rsa /home/jenkins/.ssh/id_rsa
COPY sshkeys/id_rsa.pub /home/jenkins/.ssh/authorized_keys
USER root
RUN chown -Rf jenkins:jenkins /home/jenkins/.ssh
USER jenkins
RUN chmod 0700 -R /home/jenkins/.ssh
RUN /bin/bash -c "eval '$(ssh-agent -s)'; ssh-add /home/jenkins/.ssh/id_rsa"

USER root
EXPOSE 22
CMD ["/usr/sbin/sshd", "-D"]
