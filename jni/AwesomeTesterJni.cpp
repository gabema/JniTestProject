
#include "AwesomeTester.h"

#include "JniUtility.h"
#include "com_example_jnitestproject_AwesomeTester.h"

using namespace JniTestProject;

/*
 * Class:     com_example_jnitestproject_AwesomeTester
 * Method:    nativeInit
 * Signature: ()J
 */
JNIEXPORT jlong JNICALL Java_com_example_jnitestproject_AwesomeTester_nativeCreate
  (JNIEnv * javaEnvironment, jclass javaClass)
{
	jlong nativeInstance = 0L;
	AwesomeTester * tester = new AwesomeTester();
	nativeInstance = reinterpret_cast<jlong>(tester);
	return nativeInstance;
}

/*
 * Class:     com_example_jnitestproject_AwesomeTester
 * Method:    nativeFree
 * Signature: (J)J
 */
JNIEXPORT void JNICALL Java_com_example_jnitestproject_AwesomeTester_nativeFree
  (JNIEnv * javaEnvironment, jclass javaClass, jlong nativeInstance)
{
	if (nativeInstance != 0L)
	{
		AwesomeTester * tester = reinterpret_cast<AwesomeTester *>(nativeInstance);
		delete tester;
	}
}

/*
 * Class:     com_example_jnitestproject_AwesomeTester
 * Method:    getName
 * Signature: (J)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_example_jnitestproject_AwesomeTester_getName
  (JNIEnv * javaEnvironment, jobject javaInstance, jlong nativeInstance)
{
	if (nativeInstance != 0L)
	{
		AwesomeTester * tester = reinterpret_cast<AwesomeTester *>(nativeInstance);
		return JniUtility::StringToJString(javaEnvironment, tester->GetName());
	}

	return NULL;
}

/*
 * Class:     com_example_jnitestproject_AwesomeTester
 * Method:    setName
 * Signature: (JLjava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_com_example_jnitestproject_AwesomeTester_setName
  (JNIEnv * javaEnvironment, jobject javaInstance, jlong nativeInstance, jstring javaName)
{
	if (nativeInstance != 0L)
	{
		AwesomeTester * tester = reinterpret_cast<AwesomeTester *>(nativeInstance);
		tester->SetName(JniUtility::JStringToString(javaEnvironment, javaName));
	}
}

/*
 * Class:     com_example_jnitestproject_AwesomeTester
 * Method:    getAge
 * Signature: (J)I
 */
JNIEXPORT jint JNICALL Java_com_example_jnitestproject_AwesomeTester_getAge
  (JNIEnv * javaEnvironment, jobject javaInstance, jlong nativeInstance)
{
	if (nativeInstance != 0L)
	{
		AwesomeTester * tester = reinterpret_cast<AwesomeTester *>(nativeInstance);
		return tester->GetAge();
	}

	return 0;
}

/*
 * Class:     com_example_jnitestproject_AwesomeTester
 * Method:    setAge
 * Signature: (JI)V
 */
JNIEXPORT void JNICALL Java_com_example_jnitestproject_AwesomeTester_setAge
  (JNIEnv * javaEnvironment, jobject javaInstance, jlong nativeInstance, jint age)
{
	if (nativeInstance != 0L)
	{
		AwesomeTester * tester = reinterpret_cast<AwesomeTester *>(nativeInstance);
		tester->SetAge(age);
	}
}

/*
 * Class:     com_example_jnitestproject_AwesomeTester
 * Method:    isAwesome
 * Signature: (J)Z
 */
JNIEXPORT jboolean JNICALL Java_com_example_jnitestproject_AwesomeTester_isAwesome
  (JNIEnv * javaEnvironment, jobject javaInstance, jlong nativeInstance)
{
	if (nativeInstance != 0L)
	{
		AwesomeTester * tester = reinterpret_cast<AwesomeTester *>(nativeInstance);
		return tester->IsAwesome() ? JNI_TRUE : JNI_FALSE;
	}

	return JNI_FALSE;
}
