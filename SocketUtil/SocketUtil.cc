/* Copyright 2022 An Nguyen anetw@uw.edu*/

#include "SocketUtil.h"
#include <stdio.h>
#include <unistd.h>
#include <string.h>

#include <iostream>

using std::cerr;
using std::endl;


int Listen(char* portnum, int* sock_family) {
  // Fill in the addrinfo structure for getaddrinfo()
  struct addrinfo hints;
  memset(&hints, 0, sizeof(struct addrinfo));
  hints.ai_family = AF_INET6;
  hints.ai_socktype = SOCK_STREAM;  // stream
  hints.ai_flags = AI_PASSIVE;
  hints.ai_protocol = IPPROTO_TCP;  // TCP protocol
  hints.ai_canonname = nullptr;
  hints.ai_next = nullptr;

  // Pass in the string representation of the port
  // number to get addrinfo() and returns a list of address
  // structure to 'result';

  struct addrinfo *result;
  int res = getaddrinfo(nullptr, portnum, &hints, &result);

  if (res != 0) {
    std::cerr << "getaddrinfo() failed: ";
    std::cerr << gai_strerror(res) << std::endl;
    return -1;
  }

  // Create a socket and bind to one.
  int lfd = -1;
  for (struct addrinfo *rs = result; rs != nullptr; rs = rs->ai_next) {
    lfd = socket(rs->ai_family,
                  rs->ai_socktype, rs->ai_protocol);
    if (lfd == -1) {
      // Failed to create socket
      std::cerr << "socket() failed "
      << strerror(errno) << std::endl;
      lfd = -1;
      continue;
    }

  // Set SO_RESUADDR make the port that the code bind
  // to be available as soon as the code exits.

    int opt = 1;
    setsockopt(lfd, SOL_SOCKET,
    SO_REUSEADDR, &opt, sizeof(opt));

    // Bind the socket to the returned address and port number
    if (bind(lfd, rs->ai_addr, rs->ai_addrlen) == 0) {
      *sock_family = rs->ai_family;
      break;
    }
  close(lfd);
  lfd = -1;
  }

  // Free the returned structure and return
  // the listening file descriptor
  freeaddrinfo(result);
  if (lfd <= 0) {
    // Failed to bind
    return lfd;
  }

  if (listen(lfd, SOMAXCONN) != 0) {
    std::cerr << "Failed to mark socket: ";
    std::cerr << strerror(errno) << std::endl;
    close(lfd);
    return -1;
  }

  return lfd;
}

int WrappedRead(int fd, unsigned char* buf, int readlen) {
  int res;
  while (1) {
    res = read(fd, buf, readlen);
    if (res == -1) {
      if ((errno == EAGAIN) || (errno == EINTR)) {
        continue;
      }
      break;
    }
  }
  return res;
}

int WrappedWrite(int fd, unsigned char* buf, int writelen) {
  int res, written = 0;
  while (written < writelen) {
    res = write(fd, buf + written, writelen - written);
    if (res == -1) {
      if ((errno == EAGAIN) || (errno == EINTR)) {
        continue;
      }
      break;
    }
    if (res == 0) {
      break;
    }
    written += res;
  }
  return written;
}
