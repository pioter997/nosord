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
	/// Summary for WordView
	/// </summary>
	public ref class WordView : public System::Windows::Forms::Form
	{
	public:
		WordView()
		{
			InitializeComponent();
		}
		WordView(String^ word, String^ translation) : WordView()
		{
			this->txtWord->Text = word;
			this->rtbTranslation->Text = translation;
			this->rtbTranslation->Select();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~WordView()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
	private: System::Windows::Forms::Panel^ pButtons;
	private: System::Windows::Forms::Button^ btnCancel;
	private: System::Windows::Forms::Button^ btnSave;
	private: System::Windows::Forms::TextBox^ txtWord;
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
			this->pButtons = (gcnew System::Windows::Forms::Panel());
			this->btnCancel = (gcnew System::Windows::Forms::Button());
			this->btnSave = (gcnew System::Windows::Forms::Button());
			this->txtWord = (gcnew System::Windows::Forms::TextBox());
			this->rtbTranslation = (gcnew System::Windows::Forms::RichTextBox());
			this->pButtons->SuspendLayout();
			this->SuspendLayout();
			// 
			// pButtons
			// 
			this->pButtons->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->pButtons->Controls->Add(this->btnCancel);
			this->pButtons->Controls->Add(this->btnSave);
			this->pButtons->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->pButtons->Location = System::Drawing::Point(0, 206);
			this->pButtons->Margin = System::Windows::Forms::Padding(4);
			this->pButtons->Name = L"pButtons";
			this->pButtons->Size = System::Drawing::Size(434, 55);
			this->pButtons->TabIndex = 0;
			// 
			// btnCancel
			// 
			this->btnCancel->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->btnCancel->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			this->btnCancel->Location = System::Drawing::Point(210, 14);
			this->btnCancel->Margin = System::Windows::Forms::Padding(4);
			this->btnCancel->Name = L"btnCancel";
			this->btnCancel->Size = System::Drawing::Size(100, 28);
			this->btnCancel->TabIndex = 3;
			this->btnCancel->Text = L"Anuluj";
			this->btnCancel->UseVisualStyleBackColor = true;
			// 
			// btnSave
			// 
			this->btnSave->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->btnSave->DialogResult = System::Windows::Forms::DialogResult::OK;
			this->btnSave->Location = System::Drawing::Point(318, 14);
			this->btnSave->Margin = System::Windows::Forms::Padding(4);
			this->btnSave->Name = L"btnSave";
			this->btnSave->Size = System::Drawing::Size(100, 28);
			this->btnSave->TabIndex = 2;
			this->btnSave->Text = L"Zapisz";
			this->btnSave->UseVisualStyleBackColor = true;
			this->btnSave->Click += gcnew System::EventHandler(this, &WordView::btnSave_Click);
			// 
			// txtWord
			// 
			this->txtWord->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->txtWord->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->txtWord->Location = System::Drawing::Point(12, 12);
			this->txtWord->Name = L"txtWord";
			this->txtWord->Size = System::Drawing::Size(406, 23);
			this->txtWord->TabIndex = 4;
			this->txtWord->TabStop = false;
			// 
			// rtbTranslation
			// 
			this->rtbTranslation->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->rtbTranslation->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->rtbTranslation->Location = System::Drawing::Point(12, 40);
			this->rtbTranslation->Name = L"rtbTranslation";
			this->rtbTranslation->Size = System::Drawing::Size(406, 159);
			this->rtbTranslation->TabIndex = 1;
			this->rtbTranslation->Text = L"";
			// 
			// WordView
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(434, 261);
			this->Controls->Add(this->rtbTranslation);
			this->Controls->Add(this->txtWord);
			this->Controls->Add(this->pButtons);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
			this->Margin = System::Windows::Forms::Padding(2);
			this->Name = L"WordView";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"S³owo";
			this->pButtons->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		/// <summary>
		/// Zapis pliku konfiguracyjnego s³ownika
		/// </summary>
		private: System::Void btnSave_Click(System::Object^ sender, System::EventArgs^ e) {
			
		}
};
}
