#pragma once

namespace Nosord {

    using namespace System;
    using namespace System::IO;
    using namespace System::Runtime::Serialization::Formatters::Binary;

    ref class DictionaryManager
    {
    public:
        DictionaryManager(String^ filePath)
        {
            dictionaryFilePath = filePath;
        }

        DictionaryManager(String^ name, String^ description, String^ filePath)
        {
            dictionaryName = name;
            dictionaryDescription = description;
            dictionaryFilePath = filePath;
        }

        DictionaryData^ GetDictionaryData()
        {
            DictionaryData^ dictionaryData;
            if (!File::Exists(dictionaryFilePath))
            {
                dictionaryData = GenerateDictionaryData();
            }
            else
            {
                auto binaryFormatter = gcnew BinaryFormatter();
                auto fileStream = File::OpenRead(dictionaryFilePath);
                fileStream->Position = 0;
                dictionaryData = (DictionaryData^)(binaryFormatter->Deserialize(fileStream));
                fileStream->Close();
            }

            return dictionaryData;
        }

        System::Void SaveDictionaryData(DictionaryData^ dictionaryData)
        {
            auto binaryFormatter = gcnew BinaryFormatter();
            auto fileStream = File::Create(dictionaryFilePath);
            binaryFormatter->Serialize(fileStream, dictionaryData);
            fileStream->Close();
        }
    private:
        String^ dictionaryName;
        String^ dictionaryDescription;
        String^ dictionaryFilePath;
        
        DictionaryData^ GenerateDictionaryData()
        {
            auto dictionaryData = gcnew DictionaryData();

            dictionaryData->Name = dictionaryName;
            dictionaryData->Description = dictionaryDescription;

            dictionaryData->Items->Add("dom", "home");
            dictionaryData->Items->Add("wyjœcie", "exit");
            dictionaryData->Items->Add("koniec", "end");
            dictionaryData->Items->Add("kot", "cat");
            dictionaryData->Items->Add("pies", "dog");

            for (int i = 0; i < 20; i++)
            {
                dictionaryData->Items->Add("wyraz_" + i, "tlumaczenie_" + i);
            }

            auto binaryFormatter = gcnew BinaryFormatter();
            auto fileStream = File::Create(dictionaryFilePath);
            binaryFormatter->Serialize(fileStream, dictionaryData);
            fileStream->Close();

            return dictionaryData;
        }
    };
}