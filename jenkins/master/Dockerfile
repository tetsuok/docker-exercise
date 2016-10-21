FROM jenkins

ENV JENKINS_HOME /var/jenkins_home
ENV JENKINS_SLAVE_AGENT_PORT 50000

USER root
RUN mkdir -p /home/jenkins
RUN chown -Rf jenkins:jenkins /home/jenkins

USER jenkins
RUN mkdir -p /home/jenkins/.ssh

COPY sshkeys/id_rsa /home/jenkins/.ssh/id_rsa
COPY sshkeys/id_rsa.pub /home/jenkins/.ssh/id_rsa.pub
USER root
RUN chown -Rf jenkins:jenkins /home/jenkins/.ssh
USER jenkins
RUN chmod 0700 -R /home/jenkins/.ssh

USER root
COPY certs/cert.pem /usr/local/etc/jenkins/certs/cert.pem
COPY certs/key.pem /usr/local/etc/jenkins/certs/key.pem
RUN chmod +r /usr/local/etc/jenkins/certs/cert.pem
RUN chown -R jenkins:jenkins /usr/local/etc/jenkins

USER jenkins
ENV JENKINS_OPTS --httpPort=-1 --httpsPort=8443 --httpsCertificate=/usr/local/etc/jenkins/certs/cert.pem --httpsPrivateKey=/usr/local/etc/jenkins/certs/key.pem

# for web and attached slave agents
EXPOSE 8443
EXPOSE 50000
