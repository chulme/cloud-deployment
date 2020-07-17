FROM gcc:4.9
COPY . /src
WORKDIR /src
RUN make
CMD ["./output"]
RUN make clean