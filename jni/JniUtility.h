#pragma once

#include <jni.h>
#include <string>

namespace JniUtility
{
	jstring StringToJString(JNIEnv * environment, const std::string & nativeString);
	std::string JStringToString(JNIEnv * environment, jstring javaString);
}
