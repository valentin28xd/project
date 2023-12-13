FROM gcc:10.3.0
WORKDIR /usr/src/myapp
COPY myapp.cpp .
RUN gcc -o myapp myapp.cpp -lstdc++
CMD ["./myapp"]