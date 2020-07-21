#=============BUILD STEPS====================
#Sets base image as a Debian image with GCC installed 
FROM gcc:4.9

#Copies src folder and puts it into a folder named src
COPY src /src

#Sets workspace to src (where following commands are executed)
WORKDIR /src

#Builds application
RUN make

#Removes all files except the executable 
RUN make clean && rm Makefile *.cpp *.h

#=============RUN STEPS====================
#This command is executed when the image is ran, which runs the C++ executable
CMD ["./output"]
