docker: Dockerfile
	docker build -t jenkins-executor .

run:
	docker run -t -i --name "jenkins-executor" -p 10022:22 -v $(PWD)/ws:/jenkins/ws -d jenkins-executor

clean:
	docker rm $(shell docker ps -a -q)
