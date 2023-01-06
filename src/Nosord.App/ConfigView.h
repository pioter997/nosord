#pragma once
#include "AppConfiguration.h"

namespace Nosord {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;
    using namespace System::IO;

    /// <summary>
    /// A view responsible for editing application configuration.
    /// </summary>
    public ref class ConfigView : public System::Windows::Forms::Form
    {
    public:
        ConfigView(AppConfiguration^ appConfiguration)
        {
            InitializeComponent();
            this->appConfiguration = appConfiguration;
            LoadConfiguration();
        }

    protected:
        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        ~ConfigView()
        {
            if (components)
            {
                delete components;
            }
        }

    private: AppConfiguration^ appConfiguration;
    private: System::Windows::Forms::Panel^ pButtons;
    private: System::Windows::Forms::Button^ btnCancel;
    private: System::Windows::Forms::Button^ btnSave;
    private: System::Windows::Forms::TabControl^ tabControl;
    private: System::Windows::Forms::TabPage^ tabPageDefault;
    private: System::Windows::Forms::TabPage^ tabPageOther;
    private: System::Windows::Forms::GroupBox^ gbDatabase;
    private: System::Windows::Forms::Button^ btnBrowse;
    private: System::Windows::Forms::TextBox^ txtDatabase;
    private: System::Windows::Forms::OpenFileDialog^ openFileDialog;
    private: System::Windows::Forms::Label^ lblDatabaseFile;

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
            this->pButtons = (gcnew System::Windows::Forms::Panel());
            this->btnCancel = (gcnew System::Windows::Forms::Button());
            this->btnSave = (gcnew System::Windows::Forms::Button());
            this->tabControl = (gcnew System::Windows::Forms::TabControl());
            this->tabPageDefault = (gcnew System::Windows::Forms::TabPage());
            this->gbDatabase = (gcnew System::Windows::Forms::GroupBox());
            this->btnBrowse = (gcnew System::Windows::Forms::Button());
            this->lblDatabaseFile = (gcnew System::Windows::Forms::Label());
            this->txtDatabase = (gcnew System::Windows::Forms::TextBox());
            this->tabPageOther = (gcnew System::Windows::Forms::TabPage());
            this->openFileDialog = (gcnew System::Windows::Forms::OpenFileDialog());
            this->pButtons->SuspendLayout();
            this->tabControl->SuspendLayout();
            this->tabPageDefault->SuspendLayout();
            this->gbDatabase->SuspendLayout();
            this->SuspendLayout();
            // 
            // pButtons
            // 
            this->pButtons->BackColor = System::Drawing::SystemColors::ActiveCaption;
            this->pButtons->Controls->Add(this->btnCancel);
            this->pButtons->Controls->Add(this->btnSave);
            this->pButtons->Dock = System::Windows::Forms::DockStyle::Bottom;
            this->pButtons->Location = System::Drawing::Point(0, 389);
            this->pButtons->Margin = System::Windows::Forms::Padding(5);
            this->pButtons->Name = L"pButtons";
            this->pButtons->Size = System::Drawing::Size(779, 55);
            this->pButtons->TabIndex = 0;
            // 
            // btnCancel
            // 
            this->btnCancel->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
            this->btnCancel->DialogResult = System::Windows::Forms::DialogResult::Cancel;
            this->btnCancel->Location = System::Drawing::Point(605, 14);
            this->btnCancel->Margin = System::Windows::Forms::Padding(5);
            this->btnCancel->Name = L"btnCancel";
            this->btnCancel->Size = System::Drawing::Size(75, 27);
            this->btnCancel->TabIndex = 1;
            this->btnCancel->Text = L"Anuluj";
            this->btnCancel->UseVisualStyleBackColor = true;
            // 
            // btnSave
            // 
            this->btnSave->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
            this->btnSave->Location = System::Drawing::Point(690, 14);
            this->btnSave->Margin = System::Windows::Forms::Padding(5);
            this->btnSave->Name = L"btnSave";
            this->btnSave->Size = System::Drawing::Size(75, 27);
            this->btnSave->TabIndex = 0;
            this->btnSave->Text = L"Zapisz";
            this->btnSave->UseVisualStyleBackColor = true;
            this->btnSave->Click += gcnew System::EventHandler(this, &ConfigView::btnSave_Click);
            // 
            // tabControl
            // 
            this->tabControl->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->tabControl->Controls->Add(this->tabPageDefault);
            this->tabControl->Controls->Add(this->tabPageOther);
            this->tabControl->Location = System::Drawing::Point(13, 15);
            this->tabControl->Margin = System::Windows::Forms::Padding(4);
            this->tabControl->Name = L"tabControl";
            this->tabControl->SelectedIndex = 0;
            this->tabControl->Size = System::Drawing::Size(752, 365);
            this->tabControl->TabIndex = 1;
            // 
            // tabPageDefault
            // 
            this->tabPageDefault->Controls->Add(this->gbDatabase);
            this->tabPageDefault->Location = System::Drawing::Point(4, 25);
            this->tabPageDefault->Margin = System::Windows::Forms::Padding(4);
            this->tabPageDefault->Name = L"tabPageDefault";
            this->tabPageDefault->Padding = System::Windows::Forms::Padding(4);
            this->tabPageDefault->Size = System::Drawing::Size(744, 336);
            this->tabPageDefault->TabIndex = 0;
            this->tabPageDefault->Text = L"Domyœlne";
            this->tabPageDefault->UseVisualStyleBackColor = true;
            // 
            // gbDatabase
            // 
            this->gbDatabase->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->gbDatabase->Controls->Add(this->btnBrowse);
            this->gbDatabase->Controls->Add(this->lblDatabaseFile);
            this->gbDatabase->Controls->Add(this->txtDatabase);
            this->gbDatabase->Location = System::Drawing::Point(8, 7);
            this->gbDatabase->Margin = System::Windows::Forms::Padding(4);
            this->gbDatabase->Name = L"gbDatabase";
            this->gbDatabase->Padding = System::Windows::Forms::Padding(4);
            this->gbDatabase->Size = System::Drawing::Size(720, 90);
            this->gbDatabase->TabIndex = 0;
            this->gbDatabase->TabStop = false;
            this->gbDatabase->Text = L"Baza danych";
            // 
            // btnBrowse
            // 
            this->btnBrowse->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
            this->btnBrowse->Location = System::Drawing::Point(612, 37);
            this->btnBrowse->Margin = System::Windows::Forms::Padding(4);
            this->btnBrowse->Name = L"btnBrowse";
            this->btnBrowse->Size = System::Drawing::Size(100, 28);
            this->btnBrowse->TabIndex = 2;
            this->btnBrowse->Text = L"Wybierz";
            this->btnBrowse->UseVisualStyleBackColor = true;
            this->btnBrowse->Click += gcnew System::EventHandler(this, &ConfigView::btnBrowse_Click);
            // 
            // lblDatabaseFile
            // 
            this->lblDatabaseFile->AutoSize = true;
            this->lblDatabaseFile->Location = System::Drawing::Point(8, 20);
            this->lblDatabaseFile->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
            this->lblDatabaseFile->Name = L"lblDatabaseFile";
            this->lblDatabaseFile->Size = System::Drawing::Size(108, 16);
            this->lblDatabaseFile->TabIndex = 1;
            this->lblDatabaseFile->Text = L"Plik bazy danych";
            // 
            // txtDatabase
            // 
            this->txtDatabase->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->txtDatabase->Location = System::Drawing::Point(8, 39);
            this->txtDatabase->Margin = System::Windows::Forms::Padding(4);
            this->txtDatabase->Name = L"txtDatabase";
            this->txtDatabase->Size = System::Drawing::Size(595, 22);
            this->txtDatabase->TabIndex = 0;
            // 
            // tabPageOther
            // 
            this->tabPageOther->Location = System::Drawing::Point(4, 25);
            this->tabPageOther->Margin = System::Windows::Forms::Padding(4);
            this->tabPageOther->Name = L"tabPageOther";
            this->tabPageOther->Padding = System::Windows::Forms::Padding(4);
            this->tabPageOther->Size = System::Drawing::Size(744, 336);
            this->tabPageOther->TabIndex = 1;
            this->tabPageOther->Text = L"Inne";
            this->tabPageOther->UseVisualStyleBackColor = true;
            // 
            // openFileDialog
            // 
            this->openFileDialog->CheckFileExists = false;
            this->openFileDialog->FileName = L"pl_en.dict";
            this->openFileDialog->Filter = L"Pliki bazy danych|*.dict|All files|*.*";
            // 
            // ConfigView
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(779, 444);
            this->Controls->Add(this->tabControl);
            this->Controls->Add(this->pButtons);
            this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
            this->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
            this->Name = L"ConfigView";
            this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
            this->Text = L"Konfiguracja";
            this->pButtons->ResumeLayout(false);
            this->tabControl->ResumeLayout(false);
            this->tabPageDefault->ResumeLayout(false);
            this->gbDatabase->ResumeLayout(false);
            this->gbDatabase->PerformLayout();
            this->ResumeLayout(false);

        }
#pragma endregion

        private: System::Void LoadConfiguration()
        {
            txtDatabase->Text = this->appConfiguration->DatabaseFilePath;
        }

        /// <summary>
        /// Zapis pliku konfiguracyjnego s³ownika
        /// </summary>
        private: System::Void btnSave_Click(System::Object^ sender, System::EventArgs^ e) {

            this->DialogResult = Windows::Forms::DialogResult::OK;

            appConfiguration->DatabaseFilePath = txtDatabase->Text;

            this->Close();
        }

        /// <summary>
        /// Domyœlny plik bazy danych s³ownika
        /// </summary>
        private: System::Void btnBrowse_Click(System::Object^ sender, System::EventArgs^ e) {
            String^ dataDirectory = Path::Combine(Path::GetDirectoryName(Application::ExecutablePath), "data");
            if (!Directory::Exists(dataDirectory)) {
                Directory::CreateDirectory(dataDirectory);
            }
            this->openFileDialog->InitialDirectory = dataDirectory;
            System::Windows::Forms::DialogResult result = this->openFileDialog->ShowDialog(this);
            if (result == System::Windows::Forms::DialogResult::OK) {
                this->txtDatabase->Text = this->openFileDialog->FileName;
            }
        }
};
}
