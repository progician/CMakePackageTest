#include <Foo/Foo.h>

int FooFunc() {
#ifdef NDEBUG
  return 1;
#else
  return 0;
#endif
}
