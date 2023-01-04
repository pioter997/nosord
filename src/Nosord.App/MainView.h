#pragma once
#include "ConfigView.h"
#include "DictionaryData.h"

namespace Nosord {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;
	using namespace System::Runtime::Serialization;
	using namespace System::Runtime::Serialization::Formatters::Binary;
	using namespace System::Collections::Generic;

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

			this->lbSearchResult->Items->Clear();

			for (int i = 0; i < this->dictionaryData->Items->Count; i++)
			{
				String^ key = this->dictionaryData->Items->Keys[i];
				this->lbSearchResult->Items->Add(key);
			}
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
			String^ dictionaryFileName = "pl-en.dict";
			auto binaryFormatter = gcnew BinaryFormatter();
			FileStream^ dictFileStream;

			if (true)
			{
				dictFileStream = File::Create(dictionaryFileName);
				this->dictionaryData = gcnew DictionaryData();
				dictionaryData->Name = "pl-en";
				dictionaryData->Description = "S³ownik polsko-angielski";

				dictionaryData->Items->Add("dom", "home");
				dictionaryData->Items->Add("wyjœcie", "exit");
				dictionaryData->Items->Add("koniec", "end");
				dictionaryData->Items->Add("kot", "cat");
				dictionaryData->Items->Add("pies", "dog");

				for (int i = 0; i < 100; i++)
				{
					dictionaryData->Items->Add("wyraz_" + i, "tlumaczenie_" + i);
				}

				binaryFormatter->Serialize(dictFileStream, dictionaryData);
				dictFileStream->Close();
			} 
			else
			{
				dictFileStream = File::OpenRead(dictionaryFileName);
				dictFileStream->Position = 0;
				this->dictionaryData = (DictionaryData^)(binaryFormatter->Deserialize(dictFileStream));
				dictFileStream->Close();
			}

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
	private: System::Windows::Forms::SplitContainer^ spMainView;
	private: System::Windows::Forms::Panel^ searchPanel;
	private: System::Windows::Forms::ListBox^ lbSearchResult;
	private: System::Windows::Forms::TextBox^ txtTranslation;
	private: System::Windows::Forms::TextBox^ txtSearch;



	private: DictionaryData^ dictionaryData;

		   /// <summary>
		   /// Required designer variable.
		   /// </summary>
		   System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		   /// <summary>
		   /// Required method for Designer support - do not modify
		   /// the contents of this method with the code editor.
		   /// </summary>
		   void InitializeComponent(void)
		   {
			   this->mvPanel = (gcnew System::Windows::Forms::Panel());
			   this->spMainView = (gcnew System::Windows::Forms::SplitContainer());
			   this->lbSearchResult = (gcnew System::Windows::Forms::ListBox());
			   this->txtTranslation = (gcnew System::Windows::Forms::TextBox());
			   this->searchPanel = (gcnew System::Windows::Forms::Panel());
			   this->txtSearch = (gcnew System::Windows::Forms::TextBox());
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
			   this->mvPanel->SuspendLayout();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->spMainView))->BeginInit();
			   this->spMainView->Panel1->SuspendLayout();
			   this->spMainView->Panel2->SuspendLayout();
			   this->spMainView->SuspendLayout();
			   this->searchPanel->SuspendLayout();
			   this->mMenu->SuspendLayout();
			   this->SuspendLayout();
			   // 
			   // mvPanel
			   // 
			   this->mvPanel->Controls->Add(this->spMainView);
			   this->mvPanel->Controls->Add(this->searchPanel);
			   this->mvPanel->Dock = System::Windows::Forms::DockStyle::Fill;
			   this->mvPanel->Location = System::Drawing::Point(0, 28);
			   this->mvPanel->Name = L"mvPanel";
			   this->mvPanel->Size = System::Drawing::Size(1178, 716);
			   this->mvPanel->TabIndex = 0;
			   // 
			   // spMainView
			   // 
			   this->spMainView->Dock = System::Windows::Forms::DockStyle::Fill;
			   this->spMainView->Location = System::Drawing::Point(0, 49);
			   this->spMainView->Name = L"spMainView";
			   // 
			   // spMainView.Panel1
			   // 
			   this->spMainView->Panel1->Controls->Add(this->lbSearchResult);
			   // 
			   // spMainView.Panel2
			   // 
			   this->spMainView->Panel2->Controls->Add(this->txtTranslation);
			   this->spMainView->Size = System::Drawing::Size(1178, 667);
			   this->spMainView->SplitterDistance = 391;
			   this->spMainView->TabIndex = 1;
			   // 
			   // lbSearchResult
			   // 
			   this->lbSearchResult->Dock = System::Windows::Forms::DockStyle::Fill;
			   this->lbSearchResult->FormattingEnabled = true;
			   this->lbSearchResult->ItemHeight = 16;
			   this->lbSearchResult->Location = System::Drawing::Point(0, 0);
			   this->lbSearchResult->Name = L"lbSearchResult";
			   this->lbSearchResult->Size = System::Drawing::Size(391, 667);
			   this->lbSearchResult->TabIndex = 0;
			   this->lbSearchResult->SelectedIndexChanged += gcnew System::EventHandler(this, &MainView::lbSearchResult_SelectedIndexChanged);
			   // 
			   // txtTranslation
			   // 
			   this->txtTranslation->Dock = System::Windows::Forms::DockStyle::Fill;
			   this->txtTranslation->Location = System::Drawing::Point(0, 0);
			   this->txtTranslation->Multiline = true;
			   this->txtTranslation->Name = L"txtTranslation";
			   this->txtTranslation->Size = System::Drawing::Size(783, 667);
			   this->txtTranslation->TabIndex = 0;
			   // 
			   // searchPanel
			   // 
			   this->searchPanel->BackColor = System::Drawing::Color::LightGray;
			   this->searchPanel->Controls->Add(this->txtSearch);
			   this->searchPanel->Dock = System::Windows::Forms::DockStyle::Top;
			   this->searchPanel->Location = System::Drawing::Point(0, 0);
			   this->searchPanel->Name = L"searchPanel";
			   this->searchPanel->Size = System::Drawing::Size(1178, 49);
			   this->searchPanel->TabIndex = 0;
			   // 
			   // txtSearch
			   // 
			   this->txtSearch->Location = System::Drawing::Point(12, 12);
			   this->txtSearch->Name = L"txtSearch";
			   this->txtSearch->Size = System::Drawing::Size(515, 22);
			   this->txtSearch->TabIndex = 0;
			   this->txtSearch->TextChanged += gcnew System::EventHandler(this, &MainView::txtSearch_TextChanged);
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
			   this->miAdd->Size = System::Drawing::Size(200, 26);
			   this->miAdd->Text = L"Dodaj";
			   // 
			   // miSep1
			   // 
			   this->miSep1->Name = L"miSep1";
			   this->miSep1->Size = System::Drawing::Size(197, 6);
			   // 
			   // miExit
			   // 
			   this->miExit->Name = L"miExit";
			   this->miExit->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Alt | System::Windows::Forms::Keys::F4));
			   this->miExit->Size = System::Drawing::Size(200, 26);
			   this->miExit->Text = L"Zakoñcz";
			   this->miExit->Click += gcnew System::EventHandler(this, &MainView::miExit_Click);
			   // 
			   // miTools
			   // 
			   this->miTools->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->miConfig });
			   this->miTools->Name = L"miTools";
			   this->miTools->Size = System::Drawing::Size(90, 24);
			   this->miTools->Text = L"Narzêdzia";
			   // 
			   // miConfig
			   // 
			   this->miConfig->Name = L"miConfig";
			   this->miConfig->Size = System::Drawing::Size(176, 26);
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
			   this->Text = L"S³ownik";
			   this->mvPanel->ResumeLayout(false);
			   this->spMainView->Panel1->ResumeLayout(false);
			   this->spMainView->Panel2->ResumeLayout(false);
			   this->spMainView->Panel2->PerformLayout();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->spMainView))->EndInit();
			   this->spMainView->ResumeLayout(false);
			   this->searchPanel->ResumeLayout(false);
			   this->searchPanel->PerformLayout();
			   this->mMenu->ResumeLayout(false);
			   this->mMenu->PerformLayout();
			   this->ResumeLayout(false);
			   this->PerformLayout();

		   }
#pragma endregion
	private: System::Void miExit_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
	private: System::Void lbSearchResult_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {

		this->txtTranslation->Text = this->lbSearchResult->SelectedIndex.ToString();

		/*String^ key = this->lbSearchResult->Items[this->lbSearchResult->SelectedIndex]
			this->dictionaryData->Items[key]*/
		/*this->txtTranslation->Text = "To jest t³umaczenie s³owa: " + this->lbSearchResult->Items[this->lbSearchResult->SelectedIndex]->ToString();
		String^ key = this->lbSearchResult->Items[this->lbSearchResult->SelectedIndex]->ToString();
		this->txtTranslation->Text = "To jest t³umaczenie s³owa:" + System::Environment::NewLine + this->dictionaryData->Items[key];*/
	}
	private: System::Void txtSearch_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		String^ value = this->txtSearch->Text;
		this->lbSearchResult->Items->Clear();
		for (int i = 0; i < this->dictionaryData->Items->Count; i++)
		{
			String^ key = this->dictionaryData->Items->Keys[i];
			if (key->Contains(value))
			{
				this->lbSearchResult->Items->Add(key);
			}
		}
	}
};
}
