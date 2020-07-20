FROM gcc:4.9
COPY src /src
WORKDIR /src
RUN make
RUN make clean
RUN rm Makefile *.cpp *.h

CMD ["./output"]
