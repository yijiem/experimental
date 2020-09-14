#include <openssl/hmac.h>

#include <memory>

namespace Crypto {

// trait
template<class T> struct DeleterOf;
// specialization
template<> struct DeleterOf<HMAC_CTX> { void operator()(HMAC_CTX* p) const { HMAC_CTX_free(p); } };

template<class OpenSSLType>
using UniquePtr = std::unique_ptr<OpenSSLType, Crypto::DeleterOf<OpenSSLType> >;

}  // namespace Crypto
