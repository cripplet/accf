#ifndef _ACCF_EXCEPTIONS_H
#define _ACCF_EXCEPTIONS_H

namespace accf {
  class NotImplemented : public std::logic_error {
    public:
      NotImplemented() : std::logic_error("Function not yet implemented") {};
  };

  class ParseError : public std::runtime_error {
    public:
      ParseError() : std::runtime_error("Error raised while parsing binary file") {};
  };
}

#endif  // _ACCF_EXCEPTIONS_H
