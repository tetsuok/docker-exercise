copy-sshkeys:
	cp -fr ../sshkeys .

docker: Dockerfile copy-sshkeys
	docker build -t jenkins-agent .

run:
	docker run --name "jenkins-agent" -p 10022:22 -v $(PWD)/ws:/jenkins/ws -d jenkins-agent

logs:
	docker logs jenkins-agent

stop:
	docker stop jenkins-agent

clean:
	docker rm $(shell docker ps -a -q)
