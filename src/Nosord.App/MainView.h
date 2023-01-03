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
	private: System::Windows::Forms::Panel^ mvPanel;
	private: System::Windows::Forms::MenuStrip^ mMenu;

	private: System::Windows::Forms::ToolStripMenuItem^ miFile;
	private: System::Windows::Forms::ToolStripMenuItem^ miAdd;
	private: System::Windows::Forms::ToolStripMenuItem^ miTools;
	private: System::Windows::Forms::ToolStripMenuItem^ mHelp;

	private: System::Windows::Forms::ToolStripSeparator^ miSep1;
	private: System::Windows::Forms::ToolStripMenuItem^ miExit;
	private: System::Windows::Forms::ToolStripMenuItem^ miConfig;
	private: System::Windows::Forms::ToolStripMenuItem^ miAbout;
	private: System::Windows::Forms::ToolStripMenuItem^ miHelp;



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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MainView::typeid));
			this->mvPanel = (gcnew System::Windows::Forms::Panel());
			this->mMenu = (gcnew System::Windows::Forms::MenuStrip());
			this->miFile = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->miAdd = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->miSep1 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->miExit = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->miTools = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->miConfig = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->mHelp = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->miAbout = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->miHelp = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->mMenu->SuspendLayout();
			this->SuspendLayout();
			// 
			// mvPanel
			// 
			this->mvPanel->Dock = System::Windows::Forms::DockStyle::Fill;
			this->mvPanel->Location = System::Drawing::Point(0, 28);
			this->mvPanel->Name = L"mvPanel";
			this->mvPanel->Size = System::Drawing::Size(1178, 716);
			this->mvPanel->TabIndex = 0;
			// 
			// mMenu
			// 
			this->mMenu->ImageScalingSize = System::Drawing::Size(20, 20);
			this->mMenu->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->miFile, this->miTools,
					this->mHelp
			});
			this->mMenu->Location = System::Drawing::Point(0, 0);
			this->mMenu->Name = L"mMenu";
			this->mMenu->Size = System::Drawing::Size(1178, 28);
			this->mMenu->TabIndex = 1;
			this->mMenu->Text = L"Menu";
			// 
			// miFile
			// 
			this->miFile->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->miAdd, this->miSep1,
					this->miExit
			});
			this->miFile->Name = L"miFile";
			this->miFile->Size = System::Drawing::Size(46, 24);
			this->miFile->Text = L"Plik";
			// 
			// miAdd
			// 
			this->miAdd->Name = L"miAdd";
			this->miAdd->Size = System::Drawing::Size(224, 26);
			this->miAdd->Text = L"Dodaj";
			// 
			// miSep1
			// 
			this->miSep1->Name = L"miSep1";
			this->miSep1->Size = System::Drawing::Size(221, 6);
			// 
			// miExit
			// 
			this->miExit->Name = L"miExit";
			this->miExit->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Alt | System::Windows::Forms::Keys::F4));
			this->miExit->Size = System::Drawing::Size(224, 26);
			this->miExit->Text = L"Zako�cz";
			this->miExit->Click += gcnew System::EventHandler(this, &MainView::miExit_Click);
			// 
			// miTools
			// 
			this->miTools->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->miConfig });
			this->miTools->Name = L"miTools";
			this->miTools->Size = System::Drawing::Size(90, 24);
			this->miTools->Text = L"Narz�dzia";
			// 
			// miConfig
			// 
			this->miConfig->Name = L"miConfig";
			this->miConfig->Size = System::Drawing::Size(224, 26);
			this->miConfig->Text = L"Konfiguracja";
			// 
			// mHelp
			// 
			this->mHelp->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) { this->miAbout, this->miHelp });
			this->mHelp->Name = L"mHelp";
			this->mHelp->Size = System::Drawing::Size(68, 24);
			this->mHelp->Text = L"Pomoc";
			// 
			// miAbout
			// 
			this->miAbout->Name = L"miAbout";
			this->miAbout->Size = System::Drawing::Size(162, 26);
			this->miAbout->Text = L"O aplikacji";
			// 
			// miHelp
			// 
			this->miHelp->Name = L"miHelp";
			this->miHelp->Size = System::Drawing::Size(162, 26);
			this->miHelp->Text = L"Pomoc";
			// 
			// MainView
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1178, 744);
			this->Controls->Add(this->mvPanel);
			this->Controls->Add(this->mMenu);
			this->MainMenuStrip = this->mMenu;
			this->Name = L"MainView";
			this->Text = L"S�ownik";
			this->mMenu->ResumeLayout(false);
			this->mMenu->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void miExit_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
};
}
