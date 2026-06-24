FROM ubuntu:22.04

RUN apt-get update && apt-get install -y \
    g++ cmake git \
    libjsoncpp-dev uuid-dev \
    zlib1g-dev libssl-dev

RUN git clone https://github.com/drogonframework/drogon /drogon && \
    cd /drogon && \
    git submodule update --init && \
    mkdir build && cd build && \
    cmake .. && make -j4 && make install

WORKDIR /app

COPY main.cc .
COPY controllers/ ./controllers/
COPY CMakeLists.txt .
COPY test/ ./test/

RUN mkdir build && cd build && cmake .. && make -j4

CMD ["./build/myapi"]
