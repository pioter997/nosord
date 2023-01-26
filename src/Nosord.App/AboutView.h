#pragma once

namespace Nosord {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;
    using namespace System::IO;

    /// <summary>
    /// A view responsible for displaying information about the application.
    /// </summary>
    public ref class AboutView : public System::Windows::Forms::Form
    {
    public:
        /// <summary>
        /// Initializes a new instance of the AboutView class.
        /// </summary>
        AboutView()
        {
            InitializeComponent();
            // https://patorjk.com/software/taag/#p=display&f=Georgi16&t=SLOWNIK
            String^ aboutText =
                L"   ____  ____       ____   ____              ___ ___      _________    __   \r\n" +
                L"  6MMMMb `MM'      6MMMMb  `Mb(      db      )d' `MM\     `M'`MM`MM    d'   \r\n" +
                L" 6M'    ` MM      8P    Y8  YM.     ,PM.     ,P   MMM\     M  MM MM   d'    \r\n" +
                L" MM       MM     6M      Mb `Mb     d'Mb     d'   M\MM\    M  MM MM  d'     \r\n" +
                L" YM.      MM     MM      MM  YM.   ,P YM.   ,P    M \MM\   M  MM MM d'      \r\n" +
                L"  YMMMMb  MM     MM      MM  `Mb   d' `Mb   d'    M  \MM\  M  MM MMd'       \r\n" +
                L"      `Mb MM     MM      MM   YM. ,P   YM. ,P     M   \MM\ M  MM MMYM.      \r\n" +
                L"       MM MM     MM      MM   `Mb d'   `Mb d'     M    \MM\M  MM MM YM.     \r\n" +
                L"       MM MM     YM      M9    YM,P     YM,P      M     \MMM  MM MM  YM.    \r\n" +
                L" L    ,M9 MM      8b    d8     `MM'     `MM'      M      \MM  MM MM   YM.   \r\n" +
                L" MYMMMM9 _MMMMMMM  YMMMM9       YP       YP      _M_      \M _MM_MM_   YM._ \r\n" +
                L"\r\n" +
                L"PROJEKT: S£OWNIK\r\n" +
                L"ZAJÊCIA: PROGRAMOWANIE OBIEKTOWE\r\n" +
                L"AUTOR:   PIOTR NOSOROWSKI\r\n" +
                L"DATA:    2023.01.10";

            rtbAbout->Text = aboutText;
        }

    protected:
        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        ~AboutView()
        {
            if (components)
            {
                delete components;
            }
        }

    private:
    private: System::Windows::Forms::Panel^ pButtons;
    private: System::Windows::Forms::Button^ btnClose;
    private: System::Windows::Forms::RichTextBox^ rtbAbout;


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
            this->btnClose = (gcnew System::Windows::Forms::Button());
            this->rtbAbout = (gcnew System::Windows::Forms::RichTextBox());
            this->pButtons->SuspendLayout();
            this->SuspendLayout();
            // 
            // pButtons
            // 
            this->pButtons->BackColor = System::Drawing::SystemColors::ActiveCaption;
            this->pButtons->Controls->Add(this->btnClose);
            this->pButtons->Dock = System::Windows::Forms::DockStyle::Bottom;
            this->pButtons->Location = System::Drawing::Point(0, 266);
            this->pButtons->Margin = System::Windows::Forms::Padding(5);
            this->pButtons->Name = L"pButtons";
            this->pButtons->Size = System::Drawing::Size(579, 55);
            this->pButtons->TabIndex = 0;
            // 
            // btnClose
            // 
            this->btnClose->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
            this->btnClose->DialogResult = System::Windows::Forms::DialogResult::OK;
            this->btnClose->Location = System::Drawing::Point(491, 14);
            this->btnClose->Margin = System::Windows::Forms::Padding(5);
            this->btnClose->Name = L"btnClose";
            this->btnClose->Size = System::Drawing::Size(75, 27);
            this->btnClose->TabIndex = 2;
            this->btnClose->Text = L"Zamknij";
            this->btnClose->UseVisualStyleBackColor = true;
            this->btnClose->Click += gcnew System::EventHandler(this, &AboutView::btnSave_Click);
            // 
            // rtbAbout
            // 
            this->rtbAbout->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->rtbAbout->Font = (gcnew System::Drawing::Font(L"Courier New", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(238)));
            this->rtbAbout->Location = System::Drawing::Point(13, 13);
            this->rtbAbout->Margin = System::Windows::Forms::Padding(4);
            this->rtbAbout->Name = L"rtbAbout";
            this->rtbAbout->Size = System::Drawing::Size(553, 244);
            this->rtbAbout->TabIndex = 1;
            this->rtbAbout->Text = L"";
            // 
            // AboutView
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(579, 321);
            this->Controls->Add(this->rtbAbout);
            this->Controls->Add(this->pButtons);
            this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
            this->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
            this->Name = L"AboutView";
            this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
            this->Text = L"O aplikacji";
            this->pButtons->ResumeLayout(false);
            this->ResumeLayout(false);

        }
#pragma endregion

        /// <summary>
        /// Zapis pliku konfiguracyjnego s³ownika
        /// </summary>
        private: System::Void btnSave_Click(System::Object^ sender, System::EventArgs^ e) {
            
        }
};
}
