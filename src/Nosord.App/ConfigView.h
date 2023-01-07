#pragma once
#include "AppConfiguration.h"
#include "DictionaryData.h"
#include "DictionaryManager.h"

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

        DictionaryData^ GetDictionaryData()
        {
            return this->dictionaryData;
        }

        AppConfiguration^ GetAppConfiguration()
        {
            return this->appConfiguration;
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
    private: DictionaryData^ dictionaryData;
    private: AppConfiguration^ appConfiguration;

    private: System::Windows::Forms::Panel^ pButtons;
    private: System::Windows::Forms::Button^ btnCancel;
    private: System::Windows::Forms::Button^ btnSave;
    private: System::Windows::Forms::TabControl^ tabControl;
    private: System::Windows::Forms::TabPage^ tabPageDefault;
    private: System::Windows::Forms::TabPage^ tabPageOther;
    private: System::Windows::Forms::GroupBox^ gbDictionary;

    private: System::Windows::Forms::Button^ btnBrowse;
    private: System::Windows::Forms::TextBox^ txtDictionaryFile;

    private: System::Windows::Forms::OpenFileDialog^ openFileDialog;
    private: System::Windows::Forms::Label^ lblDictionaryFile;
    private: System::Windows::Forms::Label^ lblName;
    private: System::Windows::Forms::TextBox^ txtName;

    private: System::Windows::Forms::Label^ lblDescription;
    private: System::Windows::Forms::TextBox^ txtDescription;

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
            this->gbDictionary = (gcnew System::Windows::Forms::GroupBox());
            this->lblName = (gcnew System::Windows::Forms::Label());
            this->lblDescription = (gcnew System::Windows::Forms::Label());
            this->txtName = (gcnew System::Windows::Forms::TextBox());
            this->txtDescription = (gcnew System::Windows::Forms::TextBox());
            this->btnBrowse = (gcnew System::Windows::Forms::Button());
            this->lblDictionaryFile = (gcnew System::Windows::Forms::Label());
            this->txtDictionaryFile = (gcnew System::Windows::Forms::TextBox());
            this->tabPageOther = (gcnew System::Windows::Forms::TabPage());
            this->openFileDialog = (gcnew System::Windows::Forms::OpenFileDialog());
            this->pButtons->SuspendLayout();
            this->tabControl->SuspendLayout();
            this->tabPageDefault->SuspendLayout();
            this->gbDictionary->SuspendLayout();
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
            this->btnSave->DialogResult = System::Windows::Forms::DialogResult::OK;
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
            this->tabPageDefault->Controls->Add(this->gbDictionary);
            this->tabPageDefault->Location = System::Drawing::Point(4, 25);
            this->tabPageDefault->Margin = System::Windows::Forms::Padding(4);
            this->tabPageDefault->Name = L"tabPageDefault";
            this->tabPageDefault->Padding = System::Windows::Forms::Padding(4);
            this->tabPageDefault->Size = System::Drawing::Size(744, 336);
            this->tabPageDefault->TabIndex = 0;
            this->tabPageDefault->Text = L"Domyœlne";
            this->tabPageDefault->UseVisualStyleBackColor = true;
            // 
            // gbDictionary
            // 
            this->gbDictionary->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->gbDictionary->Controls->Add(this->lblName);
            this->gbDictionary->Controls->Add(this->lblDescription);
            this->gbDictionary->Controls->Add(this->txtName);
            this->gbDictionary->Controls->Add(this->txtDescription);
            this->gbDictionary->Controls->Add(this->btnBrowse);
            this->gbDictionary->Controls->Add(this->lblDictionaryFile);
            this->gbDictionary->Controls->Add(this->txtDictionaryFile);
            this->gbDictionary->Location = System::Drawing::Point(8, 7);
            this->gbDictionary->Margin = System::Windows::Forms::Padding(4);
            this->gbDictionary->Name = L"gbDictionary";
            this->gbDictionary->Padding = System::Windows::Forms::Padding(4);
            this->gbDictionary->Size = System::Drawing::Size(720, 208);
            this->gbDictionary->TabIndex = 0;
            this->gbDictionary->TabStop = false;
            this->gbDictionary->Text = L"S³ownik";
            // 
            // lblName
            // 
            this->lblName->AutoSize = true;
            this->lblName->Location = System::Drawing::Point(8, 23);
            this->lblName->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
            this->lblName->Name = L"lblName";
            this->lblName->Size = System::Drawing::Size(48, 16);
            this->lblName->TabIndex = 6;
            this->lblName->Text = L"Nazwa";
            // 
            // lblDescription
            // 
            this->lblDescription->AutoSize = true;
            this->lblDescription->Location = System::Drawing::Point(8, 79);
            this->lblDescription->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
            this->lblDescription->Name = L"lblDescription";
            this->lblDescription->Size = System::Drawing::Size(35, 16);
            this->lblDescription->TabIndex = 4;
            this->lblDescription->Text = L"Opis";
            // 
            // txtName
            // 
            this->txtName->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->txtName->Location = System::Drawing::Point(11, 43);
            this->txtName->Margin = System::Windows::Forms::Padding(4);
            this->txtName->Name = L"txtName";
            this->txtName->Size = System::Drawing::Size(701, 22);
            this->txtName->TabIndex = 5;
            // 
            // txtDescription
            // 
            this->txtDescription->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->txtDescription->Location = System::Drawing::Point(11, 99);
            this->txtDescription->Margin = System::Windows::Forms::Padding(4);
            this->txtDescription->Name = L"txtDescription";
            this->txtDescription->Size = System::Drawing::Size(701, 22);
            this->txtDescription->TabIndex = 3;
            // 
            // btnBrowse
            // 
            this->btnBrowse->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
            this->btnBrowse->Location = System::Drawing::Point(637, 153);
            this->btnBrowse->Margin = System::Windows::Forms::Padding(4);
            this->btnBrowse->Name = L"btnBrowse";
            this->btnBrowse->Size = System::Drawing::Size(75, 27);
            this->btnBrowse->TabIndex = 2;
            this->btnBrowse->Text = L"Wybierz";
            this->btnBrowse->UseVisualStyleBackColor = true;
            this->btnBrowse->Click += gcnew System::EventHandler(this, &ConfigView::btnBrowse_Click);
            // 
            // lblDictionaryFile
            // 
            this->lblDictionaryFile->AutoSize = true;
            this->lblDictionaryFile->Location = System::Drawing::Point(8, 135);
            this->lblDictionaryFile->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
            this->lblDictionaryFile->Name = L"lblDictionaryFile";
            this->lblDictionaryFile->Size = System::Drawing::Size(133, 16);
            this->lblDictionaryFile->TabIndex = 1;
            this->lblDictionaryFile->Text = L"Lokalizacja s³ownika";
            // 
            // txtDictionaryFile
            // 
            this->txtDictionaryFile->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->txtDictionaryFile->Location = System::Drawing::Point(11, 155);
            this->txtDictionaryFile->Margin = System::Windows::Forms::Padding(4);
            this->txtDictionaryFile->Name = L"txtDictionaryFile";
            this->txtDictionaryFile->Size = System::Drawing::Size(618, 22);
            this->txtDictionaryFile->TabIndex = 0;
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
            this->gbDictionary->ResumeLayout(false);
            this->gbDictionary->PerformLayout();
            this->ResumeLayout(false);

        }
#pragma endregion

        private: System::Void LoadConfiguration()
        {
            this->txtDictionaryFile->Text = this->appConfiguration->DatabaseFilePath;

            // Gets current dictionary data to retrieve the name and description of the dictionary
            auto dictionaryManager = gcnew DictionaryManager(this->appConfiguration->DatabaseFilePath);
            auto dictionaryData = dictionaryManager->GetDictionaryData();

            this->txtName->Text = dictionaryData->Name;
            this->txtDescription->Text = dictionaryData->Description;
        }

        /// <summary>
        /// Save application configuration.
        /// </summary>
        private: System::Void btnSave_Click(System::Object^ sender, System::EventArgs^ e)
        {
            if (String::IsNullOrEmpty(this->txtDictionaryFile->Text))
            {
                MessageBox::Show(L"Pole [Lokalizacja s³ownika] nie mo¿e byæ pusty", "B³¹d", System::Windows::Forms::MessageBoxButtons::OK, System::Windows::Forms::MessageBoxIcon::Warning);
                return;
            }

            if (String::IsNullOrEmpty(this->txtName->Text))
            {
                MessageBox::Show(L"Pole [Nazwa] nie mo¿e byæ puste", "B³¹d", System::Windows::Forms::MessageBoxButtons::OK, System::Windows::Forms::MessageBoxIcon::Warning);
                return;
            }

            if (String::IsNullOrEmpty(this->txtDescription->Text))
            {
                MessageBox::Show(L"Pole [Opis] nie mo¿e byæ puste", "B³¹d", System::Windows::Forms::MessageBoxButtons::OK, System::Windows::Forms::MessageBoxIcon::Warning);
                return;
            }

            auto dictionaryManager = gcnew DictionaryManager(txtDictionaryFile->Text);

            // If the path to the dictionary file has not changed
            if (this->appConfiguration->DatabaseFilePath == txtDictionaryFile->Text)
            {
                // Get the current dictionary data object
                this->dictionaryData = dictionaryManager->GetDictionaryData();
                
                // Update name and description
                this->dictionaryData->Name = this->txtName->Text;
                this->dictionaryData->Description = this->txtDescription->Text;
                
                // Save dictinary data object
                dictionaryManager->SaveDictionaryData(dictionaryData);
            }
            else
            {
                if (File::Exists(txtDictionaryFile->Text))
                {
                    try
                    {
                        this->dictionaryData = dictionaryManager->GetDictionaryData();
                        this->dictionaryData->Name = this->txtName->Text;
                        this->dictionaryData->Description = this->txtDescription->Text;
                        dictionaryManager->SaveDictionaryData(dictionaryData);
                    }
                    catch (Exception^ e)
                    {
                        // 
                        auto dialogResult = MessageBox::Show(
                            L"Wyst¹pi³ b³¹d podczas próby odczytu s³ownika z lokalizacji:\r\n" +
                            this->txtDictionaryFile->Text + "\r\n" +
                            "B³¹d: " + e->Message + "\r\n" +
                            "Czy chcesz nadpisaæ istnijêcy plik s³ownika?", "B³¹d s³ownika",
                            System::Windows::Forms::MessageBoxButtons::YesNo,
                            System::Windows::Forms::MessageBoxIcon::Warning);

                        if (dialogResult == System::Windows::Forms::DialogResult::Yes)
                        {
                            // To fix the file, save the dictionary with an empty DictionaryData object
                            this->dictionaryData = gcnew DictionaryData();
                            this->dictionaryData->Name = this->txtName->Text;
                            this->dictionaryData->Description = this->txtDescription->Text;
                            dictionaryManager->SaveDictionaryData(dictionaryData);
                        }
                        else
                        {
                            return;
                        }
                    }
                }
                else
                {
                    // If the dictionary file does not exist
                    this->dictionaryData = gcnew DictionaryData();
                    this->dictionaryData->Name = this->txtName->Text;
                    this->dictionaryData->Description = this->txtDescription->Text;
                    dictionaryManager->SaveDictionaryData(dictionaryData);
                }

                this->appConfiguration->DatabaseFilePath = txtDictionaryFile->Text;
            }

            this->Close();
        }

        /// <summary>
        /// Select default database file.
        /// </summary>
        private: System::Void btnBrowse_Click(System::Object^ sender, System::EventArgs^ e) {
            String^ dataDirectory = Path::Combine(Path::GetDirectoryName(Application::ExecutablePath), "data");
            if (!Directory::Exists(dataDirectory)) {
                Directory::CreateDirectory(dataDirectory);
            }

            this->openFileDialog->InitialDirectory = dataDirectory;
            auto openFileDialogResult = this->openFileDialog->ShowDialog(this);

            if (openFileDialogResult == System::Windows::Forms::DialogResult::OK)
            {
                auto dictionaryManager = gcnew DictionaryManager(this->openFileDialog->FileName);
                try
                {
                    this->dictionaryData = dictionaryManager->GetDictionaryData();
                    this->txtName->Text = dictionaryData->Name;
                    this->txtDescription->Text = dictionaryData->Description;
                    this->txtDictionaryFile->Text = this->openFileDialog->FileName;
                }
                catch (Exception^ e)
                {
                    auto dialogResult = MessageBox::Show(
                        L"Wyst¹pi³ b³¹d podczas próby odczytu s³ownika z lokalizacji:\r\n" +
                        this->openFileDialog->FileName + "\r\n" +
                        "B³¹d: " + e->Message + "\r\n" +
                        "Czy chcesz nadpisaæ istnijêcy plik s³ownika?", "B³¹d s³ownika",
                        System::Windows::Forms::MessageBoxButtons::YesNo,
                        System::Windows::Forms::MessageBoxIcon::Warning);

                    if (dialogResult == System::Windows::Forms::DialogResult::Yes)
                    {
                        // To fix the file, save the dictionary with an empty DictionaryData object
                        this->dictionaryData = gcnew DictionaryData();
                        this->dictionaryData->Name = this->txtName->Text;
                        this->dictionaryData->Description = this->txtDescription->Text;
                        dictionaryManager->SaveDictionaryData(dictionaryData);
                        this->txtDictionaryFile->Text = this->openFileDialog->FileName;
                    }
                    else
                    {
                        return;
                    }
                }
            }
        }
};
}
