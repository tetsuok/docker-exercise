IMAGE = clang-tidy

docker: Dockerfile
	docker image build -t $(IMAGE) .

run:
	docker container run -it --name "$(IMAGE)" $(IMAGE)

stop:
	docker container stop $(IMAGE)

start:
	docker start -i $(IMAGE)

clean:
	docker container rm $(shell docker ps -a -q)
	docker image prune
