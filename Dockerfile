FROM gcc:4.9
COPY src /src
WORKDIR /src
RUN make
CMD ["./output"]
RUN make clean