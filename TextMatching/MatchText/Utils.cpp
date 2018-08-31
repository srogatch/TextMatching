#include "stdafx.h"
#include "Utils.h"

std::string ReadAllText(const std::string& filePath) {
  FILE *fpin = fopen(filePath.c_str(), "rt");
  if (fpin == nullptr) {
    fprintf(stderr, "Cannot open file: %s\n", filePath.c_str());
    return "";
  }
  setvbuf(fpin, nullptr, _IOFBF, 1 << 24);
  char buf[1 << 16];
  std::string ans;
  while (fgets(buf, sizeof(buf), fpin) != nullptr) {
    ans += buf;
  }
  fclose(fpin);
  return ans;
}
