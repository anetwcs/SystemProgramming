/* Copyright 2022 An Nguyen anetw@uw.edu*/


#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <iostream>
#include "SocketUtil.h"

static constexpr int buf_size = 1024;
void Usage(char* progname);
// Create a listening socket, accept a connection from a client,
// and write all the data the client sends to stdout.
int main(int argc, char** argv) {
  if (argc != 2) {
    Usage(argv[0]);
  }

  int sock_family, lfd;
  lfd = Listen(argv[1], &sock_family);
  if (lfd == -1) {
    std::cerr << "Failed to create socket: "
              << argv[1] << std::endl;
    Usage(argv[0]);
  }

  // Wait for a client
  int cfd;
  while (1) {
    struct sockaddr_storage caddr;
    socklen_t cadd_len = sizeof(caddr);
    cfd = accept(lfd,
                reinterpret_cast<struct sockaddr *> (&caddr),
                &cadd_len);
     if (cfd < 0) {
      if ((errno == EAGAIN) || (errno == EINTR)) {
        continue;
      }
      std::cerr << "Failed to accept: " << strerror(errno)
      << std::endl;
      Usage(argv[0]);
     }
     break;
  }

  // Read
  while (1) {
    unsigned char buf[buf_size];
    int r_result = WrappedRead(cfd, buf, buf_size);
    if (r_result <=0) {
      break;
    }
    int w_result = fwrite(buf, 1, r_result, stdout);
    if (w_result != r_result) {
      break;
    }
  }

  close(cfd);
  close(lfd);
  return EXIT_SUCCESS;
}

void Usage(char* progname) {
  std::cerr << "usage: " << progname <<
  " port" << std::endl;
  exit(EXIT_FAILURE);
}
