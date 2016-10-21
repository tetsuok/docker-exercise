copy-sshkeys:
	cp -fr ../sshkeys .

docker: Dockerfile copy-sshkeys
	docker build -t jenkins .

run:
	docker run --name=jenkins-master -p 8443:8443 -p 50000:50000 -v $(PWD)/jenkins_home:/var/jenkins_home -d jenkins

logs:
	docker logs jenkins-master

stop:
	docker stop jenkins-master

clean: stop
	docker rm -v jenkins-master
