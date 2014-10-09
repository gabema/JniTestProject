
#include "JniUtility.h"

namespace JniUtility
{
	jstring StringToJString(JNIEnv * environment, const std::string & nativeString)
	{
		// TODO: Handle Modified UTF8 scenarios
		return environment->NewStringUTF(nativeString.c_str());
	}

	std::string JStringToString(JNIEnv * environment, jstring javaString)
	{
		// TODO: Handle Modified UTF8 scenarios
		if (javaString == NULL)
			return std::string();
		else
			return std::string(environment->GetStringUTFChars(javaString, NULL));
	}
}
