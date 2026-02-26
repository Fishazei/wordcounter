ARG PACKAGE_NAME="Wordcounter.deb"

# common set up
FROM ubuntu:latest
ARG PACKAGE_NAME
# make dir in docker
WORKDIR /tmp

# prepare
RUN apt-get update
RUN apt-get install -y dpkg-dev

# install
COPY ../$PACKAGE_NAME /tmp/
RUN dpkg -i $PACKAGE_NAME
RUN apt-get -f install -y

RUN chmod +x /usr/vin/wordcounter	# Its need because this stuff comes without execute perm

ENTRYPOINT ["wordcounter"]
