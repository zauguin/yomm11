// -*- compile-command: "make asteroids && ./asteroids" -*-

// asteroids.cpp
// Copyright (c) 2013 Jean-Louis Leroy
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#include "multimethods.hpp"

#include <iostream>

using namespace std;
using multimethods::virtual_;

struct object : multimethods::selector {
  MM_CLASS(object);
  object() {
    MM_INIT();
  }
};

struct ship : object {
  MM_CLASS(ship, object);
  ship() {
    MM_INIT();
  }
};

struct asteroid : object {
  MM_CLASS(asteroid, object);
  asteroid() {
    MM_INIT();
  }
};

struct saucer : object {
  MM_CLASS(saucer, object);
  saucer() {
    MM_INIT();
  }
};

struct bullet : object {
  MM_CLASS(bullet, object);
  bullet() {
    MM_INIT();
  }
};

MULTIMETHOD(collide, string(virtual_<object>&, virtual_<object>&, bool swapped));

BEGIN_METHOD(collide, string, object& a, object& b, bool swapped) {
  if (swapped) {
    return "kaboom!";
  } else {
    return collide(b, a, true);
  }
} END_METHOD;

BEGIN_METHOD(collide, string, asteroid& a, asteroid& b, bool swapped) {
  return "traverse";
} END_METHOD;

int main() {
  multimethods::initialize(); // IMPORTANT!
  
  ship player;
  asteroid as;
  saucer small;
  bullet b;

  cout << collide(player, as, false) << endl; // kaboom!
  cout << collide(as, as, false) << endl; // traverse

  return 0;
}
