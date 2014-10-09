package com.example.jnitestproject;

import android.app.Fragment;
import android.os.Bundle;
import android.util.Log;
import android.view.KeyEvent;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.EditText;
import android.widget.TextView;
import android.widget.TextView.OnEditorActionListener;

public class JniPeerInstanceFragment extends Fragment {
	public static JniPeerInstanceFragment newInstance() {
		return new JniPeerInstanceFragment();
	}

	public JniPeerInstanceFragment() {
	}

	@Override
	public void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);

		mAwesomeTester = new AwesomeTester();
	}
	
	@Override
	public View onCreateView(LayoutInflater inflater, ViewGroup container,
			Bundle savedInstanceState) {
		return inflater.inflate(R.layout.fragment_jni_peer, container, false);
	}

	@Override
	public void onViewCreated(View view, Bundle savedInstanceState) {
		mName = (EditText) view.findViewById(R.id.name);
		mName.setOnEditorActionListener(mEditorActionListener);
		mAge = (EditText) view.findViewById(R.id.age);
		mAge.setOnEditorActionListener(mEditorActionListener);
		mIsAwesome = (TextView) view.findViewById(R.id.isAwesome);		
	}

	@Override
	public void onDestroy() {
		super.onDestroy();

		mAwesomeTester.releaseNativePeer();
	}

	protected static final String TAG = "JniPeerInstanceFragment";

	private final OnEditorActionListener mEditorActionListener = new OnEditorActionListener() {
		@Override
		public boolean onEditorAction(TextView v, int actionId, KeyEvent event) {
			if (v == mName) {
				mAwesomeTester.setName(v.getText().toString());
			} else if (v == mAge) {
				try {
				int age = Integer.parseInt(v.getText().toString());
				mAwesomeTester.setAge(age);
				} catch (NumberFormatException nfe) {
					Log.w(TAG, nfe);
				}
			}

			mIsAwesome.setText(mAwesomeTester.isAwesome() ? "Is Awesome" : "Is NOT Awesome");

			return false;
		}
	};

	private EditText mName;
	private EditText mAge;
	private AwesomeTester mAwesomeTester;
	private TextView mIsAwesome;
}