#include <openssl/evp.h>
#include <openssl/hmac.h>

#include <cassert>
#include <cstring>
#include <iostream>

#include "openssl_ptr.h"

int main() {
  // Crypto::UniquePtr<HMAC_CTX> hmac_ctx;
  constexpr char key[] = "password";
  unsigned char* data = (unsigned char*) "data";
  unsigned char result[32];
  unsigned int length = 0;
  unsigned char* ptr = HMAC(EVP_sha256(), key, 8, data, 4, result, &length);
  if (ptr == nullptr) {
    std::cerr << "HMAC failed" << std::endl;
    exit(1);
  }
  assert(ptr == result);
  std::cout << "result length: " << length << std::endl;
  return 0;
}
