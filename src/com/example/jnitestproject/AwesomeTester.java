package com.example.jnitestproject;

public class AwesomeTester implements NativePeer
{
	public AwesomeTester()
	{
		LibraryLoader.INSTANCE.loadOnce("jnitestproject");
		createNativePeer();		
	}

	@Override
	public void createNativePeer()
	{
		if (hasNativePeer())
			throw new IllegalStateException("Native peer already initialized");

		mNativeInstance = nativeCreate();
	}

	@Override
	public boolean hasNativePeer()
	{
		return mNativeInstance != 0;
	}

	@Override
	public void releaseNativePeer()
	{
		verifyPeerObject();
		nativeFree(mNativeInstance);
		mNativeInstance = 0;
	}

	public String getName()
	{
		verifyPeerObject();
		return getName(mNativeInstance);
	}

	public void setName(String name)
	{
		verifyPeerObject();
		setName(mNativeInstance, name);
	}

	public int getAge()
	{
		verifyPeerObject();
		return getAge(mNativeInstance);
	}

	public void setAge(int age)
	{
		verifyPeerObject();
		setAge(mNativeInstance, age);
	}

	public boolean isAwesome()
	{
		verifyPeerObject();
		return isAwesome(mNativeInstance);
	}

	private void verifyPeerObject()
	{
		if (!hasNativePeer())
			throw new IllegalStateException("peer object not initialized");
	}

	private static native long nativeCreate();
	private static native void nativeFree(long nativeInstance);

	private native String getName(long nativeInstance);
	private native void setName(long nativeInstance, String name);

	private native int getAge(long nativeInstance);
	private native void setAge(long nativeInstance, int age);

	private native boolean isAwesome(long nativeInstance);
	
	private long mNativeInstance;
}
