Learning Go..Sample Programs
Create a docker container where you can run your go programs.
docker run -it ubantu:latest bash 
apt-get update
apt-get install golang-go
go version

Write a program and use following command to run it. 
go run file.go 
go build file.go  << This generates binary file which can be run  
