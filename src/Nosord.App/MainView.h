#pragma once
#include "ConfigView.h"
#include "WordView.h"
#include "DictionaryData.h"
#include "DictionaryManager.h"
#include "AppConfiguration.h"

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
            InitializeComponent();
            LoadConfigutation();
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
        AppConfiguration^ appConfiguration;
        DictionaryManager^ dictionaryManager;
        DictionaryData^ dictionaryData;
    
        /// <summary>
        /// Loads the application configuration.
        /// </summary>
        void LoadConfigutation(void)
        {
            auto binaryFormatter = gcnew BinaryFormatter();

            // Gets the name of the executed application without extension
            String^ applicationName = Path::GetFileNameWithoutExtension(Application::ExecutablePath);

            // Gets the directory name of the application
            String^ applicationDirectoryName = Path::GetDirectoryName(Application::ExecutablePath);

            // The configuration file path
            String^ configPath = Path::Combine(applicationDirectoryName, applicationName + ".config");

            // Checks whether the configuration file exists.
            if (!File::Exists(configPath))
            {
                String^ defaultDictionaryName = "pl-en";
                String^ defaultDictionaryDescription = "S³ownik polsko-angielski";
                String^ defaultDictionaryFileName = "pl-en.dict";

                String^ dataDirectory = Path::Combine(Path::GetDirectoryName(Application::ExecutablePath), "data");
                if (!Directory::Exists(dataDirectory)) {
                    Directory::CreateDirectory(dataDirectory);
                }

                String^ defaultDictionaryFilePath = Path::Combine(dataDirectory, defaultDictionaryFileName);
                dictionaryManager = gcnew DictionaryManager(defaultDictionaryName, defaultDictionaryDescription, defaultDictionaryFilePath);
                this->dictionaryData = dictionaryManager->GetDictionaryData();

                auto configFileStream = File::Create(configPath);
                appConfiguration = gcnew AppConfiguration();
                appConfiguration->DatabaseFilePath = defaultDictionaryFilePath;
                binaryFormatter->Serialize(configFileStream, appConfiguration);
                configFileStream->Close();
            }
            else
            {
                auto configFileStream = File::OpenRead(configPath);
                configFileStream->Position = 0;
                appConfiguration = (AppConfiguration^)(binaryFormatter->Deserialize(configFileStream));
                configFileStream->Close();
                dictionaryManager = gcnew DictionaryManager(appConfiguration->DatabaseFilePath);
                this->dictionaryData = dictionaryManager->GetDictionaryData();
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
    private: System::Windows::Forms::TextBox^ txtSearch;
    private: System::Windows::Forms::Button^ btnDelete;
    private: System::Windows::Forms::Button^ btnEdit;
    private: System::Windows::Forms::Button^ btnAdd;
    private: System::Windows::Forms::RichTextBox^ rtbTranslation;

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
               this->rtbTranslation = (gcnew System::Windows::Forms::RichTextBox());
               this->btnDelete = (gcnew System::Windows::Forms::Button());
               this->btnEdit = (gcnew System::Windows::Forms::Button());
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
               this->mvPanel->Margin = System::Windows::Forms::Padding(2);
               this->mvPanel->Name = L"mvPanel";
               this->mvPanel->Size = System::Drawing::Size(736, 466);
               this->mvPanel->TabIndex = 0;
               // 
               // spMainView
               // 
               this->spMainView->Dock = System::Windows::Forms::DockStyle::Fill;
               this->spMainView->Location = System::Drawing::Point(0, 38);
               this->spMainView->Margin = System::Windows::Forms::Padding(2);
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
               this->spMainView->Panel2->Controls->Add(this->rtbTranslation);
               this->spMainView->Panel2->Controls->Add(this->btnDelete);
               this->spMainView->Panel2->Controls->Add(this->btnEdit);
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
               this->lbSearchResult->Margin = System::Windows::Forms::Padding(2);
               this->lbSearchResult->Name = L"lbSearchResult";
               this->lbSearchResult->Size = System::Drawing::Size(230, 412);
               this->lbSearchResult->TabIndex = 0;
               this->lbSearchResult->SelectedIndexChanged += gcnew System::EventHandler(this, &MainView::lbSearchResult_SelectedIndexChanged);
               // 
               // rtbTranslation
               // 
               this->rtbTranslation->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                   | System::Windows::Forms::AnchorStyles::Left)
                   | System::Windows::Forms::AnchorStyles::Right));
               this->rtbTranslation->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                   static_cast<System::Byte>(238)));
               this->rtbTranslation->Location = System::Drawing::Point(0, 5);
               this->rtbTranslation->Name = L"rtbTranslation";
               this->rtbTranslation->Size = System::Drawing::Size(486, 382);
               this->rtbTranslation->TabIndex = 3;
               this->rtbTranslation->Text = L"";
               // 
               // btnDelete
               // 
               this->btnDelete->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
               this->btnDelete->Enabled = false;
               this->btnDelete->Location = System::Drawing::Point(369, 392);
               this->btnDelete->Margin = System::Windows::Forms::Padding(2);
               this->btnDelete->Name = L"btnDelete";
               this->btnDelete->Size = System::Drawing::Size(56, 22);
               this->btnDelete->TabIndex = 2;
               this->btnDelete->Text = L"Usuñ";
               this->btnDelete->UseVisualStyleBackColor = true;
               this->btnDelete->Click += gcnew System::EventHandler(this, &MainView::btnDelete_Click);
               // 
               // btnEdit
               // 
               this->btnEdit->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
               this->btnEdit->Enabled = false;
               this->btnEdit->Location = System::Drawing::Point(430, 392);
               this->btnEdit->Margin = System::Windows::Forms::Padding(2);
               this->btnEdit->Name = L"btnEdit";
               this->btnEdit->Size = System::Drawing::Size(56, 22);
               this->btnEdit->TabIndex = 1;
               this->btnEdit->Text = L"Edytuj";
               this->btnEdit->UseVisualStyleBackColor = true;
               this->btnEdit->Click += gcnew System::EventHandler(this, &MainView::btnEdit_Click);
               // 
               // searchPanel
               // 
               this->searchPanel->BackColor = System::Drawing::SystemColors::Control;
               this->searchPanel->Controls->Add(this->btnAdd);
               this->searchPanel->Controls->Add(this->txtSearch);
               this->searchPanel->Dock = System::Windows::Forms::DockStyle::Top;
               this->searchPanel->Location = System::Drawing::Point(0, 0);
               this->searchPanel->Margin = System::Windows::Forms::Padding(2);
               this->searchPanel->Name = L"searchPanel";
               this->searchPanel->Size = System::Drawing::Size(736, 38);
               this->searchPanel->TabIndex = 0;
               // 
               // btnAdd
               // 
               this->btnAdd->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
               this->btnAdd->BackColor = System::Drawing::SystemColors::Control;
               this->btnAdd->Enabled = false;
               this->btnAdd->Location = System::Drawing::Point(671, 11);
               this->btnAdd->Margin = System::Windows::Forms::Padding(2);
               this->btnAdd->Name = L"btnAdd";
               this->btnAdd->Size = System::Drawing::Size(56, 22);
               this->btnAdd->TabIndex = 1;
               this->btnAdd->Text = L"Dodaj";
               this->btnAdd->UseVisualStyleBackColor = false;
               this->btnAdd->Click += gcnew System::EventHandler(this, &MainView::btnAdd_Click);
               // 
               // txtSearch
               // 
               this->txtSearch->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
                   | System::Windows::Forms::AnchorStyles::Right));
               this->txtSearch->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                   static_cast<System::Byte>(238)));
               this->txtSearch->Location = System::Drawing::Point(9, 10);
               this->txtSearch->Margin = System::Windows::Forms::Padding(2);
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
               this->miConfig->Click += gcnew System::EventHandler(this, &MainView::miConfig_Click);
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
               this->miHelp->Size = System::Drawing::Size(162, 26);
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
               this->Margin = System::Windows::Forms::Padding(2);
               this->Name = L"MainView";
               this->Text = L"S³ownik";
               this->mvPanel->ResumeLayout(false);
               this->spMainView->Panel1->ResumeLayout(false);
               this->spMainView->Panel2->ResumeLayout(false);
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

        /// <summary>
        /// Occurs when the miExit menu item is clicked.
        /// </summary>
        /// <remarks>
        /// https://learn.microsoft.com/en-us/dotnet/api/system.windows.forms.control.click?view=windowsdesktop-7.0#definition
        /// </remarks>
        private: System::Void miExit_Click(System::Object^ sender, System::EventArgs^ e) 
        {
            this->Close();
        }

        /// <summary>
        /// Occurs when the lbSearchResult->SelectedIndex property or the SelectedIndices collection has changed.
        /// </summary>
        /// <remarks>
        /// https://learn.microsoft.com/en-us/dotnet/api/system.windows.forms.listbox.selectedindexchanged?view=windowsdesktop-7.0#definition
        /// </remarks>
        private: System::Void lbSearchResult_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e)
        {
            // Disable delete and edit button
            this->btnDelete->Enabled = false;
            this->btnEdit->Enabled = false;

            // Checks if the index of lbSearchResult->SelectedIndex property is different from -1
            // which means that there is a selected element.
            if (this->lbSearchResult->SelectedIndex != -1)
            {
                auto selectedWord = this->lbSearchResult->SelectedItem->ToString();
                if (this->dictionaryData->Items->ContainsKey(selectedWord)) 
                {
                    auto value = this->dictionaryData->Items[selectedWord];
                    // https://www.c-sharpcorner.com/UploadFile/mahesh/richtextbox-in-C-Sharp/
                    // Cleans up the content of the translation
                    this->rtbTranslation->Clear();

                    // Display dictionary info
                    this->rtbTranslation->SelectionFont = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(238)));
                    this->rtbTranslation->SelectionColor = Color::DarkGreen;
                    this->rtbTranslation->SelectedText = "<--- " + this->dictionaryData->Description + " --->" + System::Environment::NewLine;

                    // Display selected word
                    this->rtbTranslation->SelectionFont = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(238)));
                    this->rtbTranslation->SelectionColor = Color::DarkBlue;
                    this->rtbTranslation->SelectedText = selectedWord + System::Environment::NewLine;

                    // Display translation
                    this->rtbTranslation->SelectionColor = Color::Black;
                    this->rtbTranslation->SelectionFont = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(238)));
                    this->rtbTranslation->SelectedText = "----------" + System::Environment::NewLine + value;

                    this->rtbTranslation->ReadOnly = true;
                    this->btnDelete->Enabled = true;
                    this->btnEdit->Enabled = true;
                }
            }
        }

        /// <summary>
        /// Occurs when the txtSearch->Text property value changes.
        /// </summary>
        /// <remarks>
        /// https://learn.microsoft.com/en-us/dotnet/api/system.windows.forms.control.textchanged?view=windowsdesktop-7.0#definition
        /// </remarks>
        private: System::Void txtSearch_TextChanged(System::Object^ sender, System::EventArgs^ e) 
        {
            // Gets the search value
            String^ value = this->txtSearch->Text;

            // Clears the contents of the box list
            this->lbSearchResult->Items->Clear();

            // Disable delete and edit button
            this->btnDelete->Enabled = false;
            this->btnEdit->Enabled = false;

            // Clears all text from the translation text box
            this->rtbTranslation->Clear();

            // Checks whether the search value is not null or empty
            if (!String::IsNullOrEmpty(value))
            {
                for (int i = 0; i < this->dictionaryData->Items->Count; i++)
                {
                    // Gets key value from the dictionary data items
                    String^ key = this->dictionaryData->Items->Keys[i];

                    // If the key value starts with the value you are looking for
                    if (key->StartsWith(value))
                    {
                        // Adds a key to the list of found words
                        this->lbSearchResult->Items->Add(key);
                    }
                }
                // Checks whether the specified word exists in the dictionary
                auto valueExists = this->dictionaryData->Items->ContainsKey(value);
                // If the word exists disable the addition of a new word
                this->btnAdd->Enabled = !valueExists;
            }
            else
            {
                // If the search box field is empty, block the addition of a new word
                this->btnAdd->Enabled = false;
            }
        }

        /// <summary>
        /// Occurs when the btnAdd button is clicked.
        /// </summary>
        private: System::Void btnAdd_Click(System::Object^ sender, System::EventArgs^ e)
        {
            // Gets the search value
            String^ searchValue = this->txtSearch->Text;
            auto view = gcnew WordView(searchValue, "");
            OpenWordDialog(view);
            delete view;
        }

        /// <summary>
        /// Occurs when the btnEdit button is clicked.
        /// </summary>
        private: System::Void btnEdit_Click(System::Object^ sender, System::EventArgs^ e) 
        {
            // Gets selected word
            if (this->lbSearchResult->SelectedIndex != -1)
            {
                auto selectedWord = this->lbSearchResult->SelectedItem->ToString();
                if (this->dictionaryData->Items->ContainsKey(selectedWord))
                {
                    auto value = this->dictionaryData->Items[selectedWord];

                    auto view = gcnew WordView(selectedWord, value);
                    OpenWordDialog(view);
                    delete view;
                }
            }
        }

        /// <summary>
        /// Opens dialog window to add or edit word translation.
        /// </summary>
        private: System::Void OpenWordDialog(WordView^ view)
        {
            auto dialogResult = view->ShowDialog(this);
            if (dialogResult == Windows::Forms::DialogResult::OK)
            {
                String^ translation = view->GetTranslation();
                String^ word = view->GetWord();
                if (this->dictionaryData->Items->ContainsKey(word))
                {
                    this->dictionaryData->Items[word] = translation;
                }
                else
                {
                    this->dictionaryData->Items->Add(word, translation);
                    this->lbSearchResult->Items->Add(word);
                }

                // to refresh rtbTranslation control it is required to run 
                // lbSearchResult_SelectedIndexChanged function
                if (this->lbSearchResult->Items->Count == 1)
                {
                    // if the list was empty and only one word was added then:
                    // change of the selected index to 0 is required
                    this->lbSearchResult->SelectedIndex = 0;
                }
                else
                {
                    // if the list was not empty and had more than one word then:
                    // change of the selected index to -1 and resetting the previous value is required
                    auto prevIndex = this->lbSearchResult->SelectedIndex;
                    this->lbSearchResult->SelectedIndex = -1;
                    this->lbSearchResult->SelectedIndex = prevIndex;
                }

                dictionaryManager->SaveDictionaryData(this->dictionaryData);
            }
        }

        /// <summary>
        /// Occurs when the btnDelete button is clicked.
        /// </summary>
        private: System::Void btnDelete_Click(System::Object^ sender, System::EventArgs^ e)
        {
            // Gets selected word
            if (this->lbSearchResult->SelectedIndex != -1)
            {
                auto selectedWord = this->lbSearchResult->SelectedItem->ToString();
                if (this->dictionaryData->Items->ContainsKey(selectedWord))
                {
                    this->rtbTranslation->Clear();
                    this->lbSearchResult->SelectedIndex = -1;
                    this->dictionaryData->Items->Remove(selectedWord);
                    this->lbSearchResult->Items->Remove(selectedWord);
                    dictionaryManager->SaveDictionaryData(this->dictionaryData);
                }
            }
        }

        /// <summary>
        /// Opens the application configuration dialog.
        /// </summary>
        private: System::Void miConfig_Click(System::Object^ sender, System::EventArgs^ e)
        {
            auto view = gcnew ConfigView(this->appConfiguration);
            auto dialogResult = view->ShowDialog(this);
            if (dialogResult == Windows::Forms::DialogResult::OK)
            {
                MessageBox::Show("Not implemented");
            }
            delete view;
        }
    };
}
