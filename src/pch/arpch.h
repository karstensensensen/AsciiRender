#pragma once

#include "Asciir/Platform/PlatformMacros.h"

#include <Eigen/Eigen>

#include <functional>
#include <memory>
#include <algorithm>
#include <math.h>
#include <thread>
#include <chrono>
#include <filesystem>
#include <type_traits>
#include <limits.h>

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <future>
#include <vector>
#include <array>
#include <tuple>
#include <variant>
#include <assert.h>
#include <signal.h>

#ifdef AR_WIN
#include <Windows.h>
#undef min
#undef max
#else
#include <sys/ioctl>
#include <unistd>
#include <ncurses.h>
#endif
