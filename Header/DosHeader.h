#ifndef DOS_HEADER_H
#define DOS_HEADER_H

#include "Header.h"
class dos_header
{
  private:
    IMAGE_DOS_HEADER dosheader;
    int file_descriptor;

  public:
    dos_header(int f);
    void show_header();
};

#endif DOS_HEADER_H /* DOS_HEADER_H */