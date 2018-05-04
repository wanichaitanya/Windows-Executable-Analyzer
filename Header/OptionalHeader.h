#ifndef OPT_HEADER_H
#define OPT_HEADER_H

#include "Header.h"

__declspec(dllexport) class opt_header
{
  private:
    IMAGE_OPTIONAL_HEADER optHeader; //Represents the optional header format.
    int file_descriptor;

  public:
    opt_header(int f);
    void show_header();
};

#endif /*OPT_HEADER_H*/
