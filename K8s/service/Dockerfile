FROM golang:1.14.4-stretch AS builder

RUN apt-get update
RUN apt-get -y install vim net-tools

RUN cd $GOPATH/src && mkdir -p client
RUN cd $GOPATH/src && mkdir -p server
COPY ./src/client.go $GOPATH/src/client
COPY ./src/server.go $GOPATH/src/server
RUN cd $GOPATH/src/client && go build client.go
RUN cd $GOPATH/src/server && go build server.go
