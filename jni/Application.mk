
NDK_TOOLCHAIN_VERSION := clang

APP_PLATFORM    := android-14

# GCC / GNU STL
#APP_STL		:= gnustl_static
APP_STL         := c++_static

#GCC / GNU STL
#APP_CPPFLAGS += -std=gnu++11
APP_CPPFLAGS    := -fexceptions -frtti

APP_ABI         := x86 armeabi-v7a