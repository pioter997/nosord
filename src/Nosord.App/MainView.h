#pragma once
#include "ConfigView.h"

namespace Nosord {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;

	/// <summary>
	/// Summary for MainView
	/// </summary>
	public ref class MainView : public System::Windows::Forms::Form
	{
	public:
		MainView(void)
		{
			LoadConfigutation();
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MainView()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		/// <summary>
		/// Loads the application configuration.
		/// </summary>
		void LoadConfigutation(void) 
		{
			// Gets the name of the executed application without extension.
			String^ applicationName = Path::GetFileNameWithoutExtension(Application::ExecutablePath);

			// Gets the directory name of the application.
			String^ applicationDirectoryName = Path::GetDirectoryName(Application::ExecutablePath);

			// The configuration file path.
			String^ configPath = Path::Combine(applicationDirectoryName, applicationName + ".config");

			// Checks whether the configuration file exists.
			if (!File::Exists(configPath)) 
			{
				// Creates a new instance of the ConfigView class.
				ConfigView^ configView = gcnew ConfigView();
				// Show application configuration view.
				System::Windows::Forms::DialogResult cfgDialogResult = configView->ShowDialog(this);

				if (cfgDialogResult == System::Windows::Forms::DialogResult::OK) {
					// TODO: Read and load application configuration.
					MessageBox::Show("Configuration loaded! Not implemented");
				}
				delete configView;
			}
			else 
			{
				// TODO: Read and load application configuration.
				MessageBox::Show("Configuration loaded! Not implemented");
			}
		}

		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->SuspendLayout();
			// 
			// MainView
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1178, 744);
			this->Name = L"MainView";
			this->Text = L"S³ownik";
			this->ResumeLayout(false);

		}
#pragma endregion
	};
}
