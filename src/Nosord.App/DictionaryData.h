#pragma once

namespace Nosord {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Collections::Generic;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;

	[Serializable]
	ref class DictionaryData
	{
	public:
		String ^Name;
		String ^Description;
		Generic::SortedList<String^, String^>^ Items;

		DictionaryData()
		{
			Items = gcnew Generic::SortedList<String^, String^>();
		}
	};
}