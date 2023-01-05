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

			if (false)
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
			if (!File::Exists(configPath) && false)
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
				// MessageBox::Show("Configuration loaded! Not implemented");
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
	private: System::Windows::Forms::Button^ btnDelete;
	private: System::Windows::Forms::Button^ btnSave;
	private: System::Windows::Forms::Button^ btnAdd;

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
			   this->btnDelete = (gcnew System::Windows::Forms::Button());
			   this->btnSave = (gcnew System::Windows::Forms::Button());
			   this->txtTranslation = (gcnew System::Windows::Forms::TextBox());
			   this->searchPanel = (gcnew System::Windows::Forms::Panel());
			   this->btnAdd = (gcnew System::Windows::Forms::Button());
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
			   this->mvPanel->Location = System::Drawing::Point(0, 24);
			   this->mvPanel->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			   this->mvPanel->Name = L"mvPanel";
			   this->mvPanel->Size = System::Drawing::Size(736, 466);
			   this->mvPanel->TabIndex = 0;
			   // 
			   // spMainView
			   // 
			   this->spMainView->Dock = System::Windows::Forms::DockStyle::Fill;
			   this->spMainView->Location = System::Drawing::Point(0, 38);
			   this->spMainView->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			   this->spMainView->Name = L"spMainView";
			   // 
			   // spMainView.Panel1
			   // 
			   this->spMainView->Panel1->BackColor = System::Drawing::SystemColors::Control;
			   this->spMainView->Panel1->Controls->Add(this->lbSearchResult);
			   // 
			   // spMainView.Panel2
			   // 
			   this->spMainView->Panel2->BackColor = System::Drawing::SystemColors::Control;
			   this->spMainView->Panel2->Controls->Add(this->btnDelete);
			   this->spMainView->Panel2->Controls->Add(this->btnSave);
			   this->spMainView->Panel2->Controls->Add(this->txtTranslation);
			   this->spMainView->Size = System::Drawing::Size(736, 428);
			   this->spMainView->SplitterDistance = 241;
			   this->spMainView->SplitterWidth = 3;
			   this->spMainView->TabIndex = 1;
			   // 
			   // lbSearchResult
			   // 
			   this->lbSearchResult->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				   | System::Windows::Forms::AnchorStyles::Left)
				   | System::Windows::Forms::AnchorStyles::Right));
			   this->lbSearchResult->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(238)));
			   this->lbSearchResult->FormattingEnabled = true;
			   this->lbSearchResult->ItemHeight = 17;
			   this->lbSearchResult->Location = System::Drawing::Point(9, 5);
			   this->lbSearchResult->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			   this->lbSearchResult->Name = L"lbSearchResult";
			   this->lbSearchResult->Size = System::Drawing::Size(230, 412);
			   this->lbSearchResult->TabIndex = 0;
			   this->lbSearchResult->SelectedIndexChanged += gcnew System::EventHandler(this, &MainView::lbSearchResult_SelectedIndexChanged);
			   // 
			   // btnDelete
			   // 
			   this->btnDelete->Anchor = System::Windows::Forms::AnchorStyles::Right;
			   this->btnDelete->Location = System::Drawing::Point(366, 392);
			   this->btnDelete->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			   this->btnDelete->Name = L"btnDelete";
			   this->btnDelete->Size = System::Drawing::Size(56, 22);
			   this->btnDelete->TabIndex = 2;
			   this->btnDelete->Text = L"Usuñ";
			   this->btnDelete->UseVisualStyleBackColor = true;
			   // 
			   // btnSave
			   // 
			   this->btnSave->Anchor = System::Windows::Forms::AnchorStyles::Right;
			   this->btnSave->Location = System::Drawing::Point(427, 392);
			   this->btnSave->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			   this->btnSave->Name = L"btnSave";
			   this->btnSave->Size = System::Drawing::Size(56, 22);
			   this->btnSave->TabIndex = 1;
			   this->btnSave->Text = L"Zapisz";
			   this->btnSave->UseVisualStyleBackColor = true;
			   // 
			   // txtTranslation
			   // 
			   this->txtTranslation->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				   | System::Windows::Forms::AnchorStyles::Left)
				   | System::Windows::Forms::AnchorStyles::Right));
			   this->txtTranslation->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(238)));
			   this->txtTranslation->Location = System::Drawing::Point(2, 5);
			   this->txtTranslation->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			   this->txtTranslation->Multiline = true;
			   this->txtTranslation->Name = L"txtTranslation";
			   this->txtTranslation->Size = System::Drawing::Size(482, 383);
			   this->txtTranslation->TabIndex = 0;
			   // 
			   // searchPanel
			   // 
			   this->searchPanel->BackColor = System::Drawing::SystemColors::Control;
			   this->searchPanel->Controls->Add(this->btnAdd);
			   this->searchPanel->Controls->Add(this->txtSearch);
			   this->searchPanel->Dock = System::Windows::Forms::DockStyle::Top;
			   this->searchPanel->Location = System::Drawing::Point(0, 0);
			   this->searchPanel->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			   this->searchPanel->Name = L"searchPanel";
			   this->searchPanel->Size = System::Drawing::Size(736, 38);
			   this->searchPanel->TabIndex = 0;
			   // 
			   // btnAdd
			   // 
			   this->btnAdd->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			   this->btnAdd->BackColor = System::Drawing::SystemColors::Control;
			   this->btnAdd->Location = System::Drawing::Point(671, 11);
			   this->btnAdd->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			   this->btnAdd->Name = L"btnAdd";
			   this->btnAdd->Size = System::Drawing::Size(56, 22);
			   this->btnAdd->TabIndex = 1;
			   this->btnAdd->Text = L"Dodaj";
			   this->btnAdd->UseVisualStyleBackColor = false;
			   // 
			   // txtSearch
			   // 
			   this->txtSearch->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				   | System::Windows::Forms::AnchorStyles::Right));
			   this->txtSearch->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(238)));
			   this->txtSearch->Location = System::Drawing::Point(9, 10);
			   this->txtSearch->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			   this->txtSearch->Name = L"txtSearch";
			   this->txtSearch->Size = System::Drawing::Size(659, 23);
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
			   this->mMenu->Padding = System::Windows::Forms::Padding(4, 2, 0, 2);
			   this->mMenu->Size = System::Drawing::Size(736, 24);
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
			   this->miFile->Size = System::Drawing::Size(38, 20);
			   this->miFile->Text = L"Plik";
			   // 
			   // miAdd
			   // 
			   this->miAdd->Name = L"miAdd";
			   this->miAdd->Size = System::Drawing::Size(160, 22);
			   this->miAdd->Text = L"Dodaj";
			   // 
			   // miSep1
			   // 
			   this->miSep1->Name = L"miSep1";
			   this->miSep1->Size = System::Drawing::Size(157, 6);
			   // 
			   // miExit
			   // 
			   this->miExit->Name = L"miExit";
			   this->miExit->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Alt | System::Windows::Forms::Keys::F4));
			   this->miExit->Size = System::Drawing::Size(160, 22);
			   this->miExit->Text = L"Zakoñcz";
			   this->miExit->Click += gcnew System::EventHandler(this, &MainView::miExit_Click);
			   // 
			   // miTools
			   // 
			   this->miTools->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->miConfig });
			   this->miTools->Name = L"miTools";
			   this->miTools->Size = System::Drawing::Size(70, 20);
			   this->miTools->Text = L"Narzêdzia";
			   // 
			   // miConfig
			   // 
			   this->miConfig->Name = L"miConfig";
			   this->miConfig->Size = System::Drawing::Size(141, 22);
			   this->miConfig->Text = L"Konfiguracja";
			   // 
			   // mHelp
			   // 
			   this->mHelp->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) { this->miAbout, this->miHelp });
			   this->mHelp->Name = L"mHelp";
			   this->mHelp->Size = System::Drawing::Size(57, 20);
			   this->mHelp->Text = L"Pomoc";
			   // 
			   // miAbout
			   // 
			   this->miAbout->Name = L"miAbout";
			   this->miAbout->Size = System::Drawing::Size(129, 22);
			   this->miAbout->Text = L"O aplikacji";
			   // 
			   // miHelp
			   // 
			   this->miHelp->Name = L"miHelp";
			   this->miHelp->Size = System::Drawing::Size(129, 22);
			   this->miHelp->Text = L"Pomoc";
			   // 
			   // MainView
			   // 
			   this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			   this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			   this->ClientSize = System::Drawing::Size(736, 490);
			   this->Controls->Add(this->mvPanel);
			   this->Controls->Add(this->mMenu);
			   this->MainMenuStrip = this->mMenu;
			   this->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
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
