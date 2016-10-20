docker: Dockerfile
	docker build -t jenkins .

# TODO: use HTTPS
run:
	docker run --name=jenkins-master -p 8080:8080 -p 50000:50000 -v $(PWD)/jenkins_home:/var/jenkins_home -d jenkins

logs:
	docker logs jenkins-master

stop:
	docker stop jenkins-master

clean: stop
	docker rm -v jenkins-master
