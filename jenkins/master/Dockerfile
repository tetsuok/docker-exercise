FROM jenkins
COPY executors.groovy /usr/share/jenkins/ref/init.groovy.d/executors.groovy

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

# for web and attached slave agents
EXPOSE 8080
EXPOSE 50000
