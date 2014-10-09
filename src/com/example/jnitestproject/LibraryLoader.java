package com.example.jnitestproject;

import java.util.HashSet;
import java.util.Set;

public enum LibraryLoader {
	INSTANCE;

	public void loadOnce(String libraryName)
	{
		if (!mLibraries.contains(libraryName))
		{
			System.loadLibrary(libraryName);
			mLibraries.add(libraryName);
		}
	}

	private LibraryLoader()
	{
		mLibraries = new HashSet<String>();
	}

	private Set<String> mLibraries;
}
