#pragma once

namespace Nosord {

    using namespace System;
    using namespace System::Collections;

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