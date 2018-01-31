#pragma once
#ifndef ConcurrentModificationException_H
#define ConcurrentModificationException_H
#include <exception>

class ConcurrentModificationException final : std::exception {
};
#endif
