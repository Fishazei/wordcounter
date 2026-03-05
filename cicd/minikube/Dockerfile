ARG PACKAGE_NAME="Wordcounter.deb"

FROM ubuntu:latest
ARG PACKAGE_NAME
WORKDIR /tmp
RUN apt-get install update
RUN apt-get install -y dpkg-dev

COPY $PACKAGE_NAME /tmp/
COPY cicd/minikube/wordcounter-service.sh /tmp/

RUN dpkg -i /tmp/$PACKAGE_NAME
RUN apt-get -f install -y
RUN chmod +x /usr/bin/wordcounter

CMD ["/tmp/wordcounter-service.sh"]
