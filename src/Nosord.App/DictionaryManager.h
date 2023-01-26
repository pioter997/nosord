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
                FileStream^ fileStream;
                
                try
                {
                    fileStream = File::OpenRead(dictionaryFilePath);
                    fileStream->Position = 0;
                    dictionaryData = (DictionaryData^)(binaryFormatter->Deserialize(fileStream));
                }
                finally
                {
                    fileStream->Close();
                }
            }

            return dictionaryData;
        }

        System::Void SaveDictionaryData(DictionaryData^ dictionaryData)
        {
            auto binaryFormatter = gcnew BinaryFormatter();
            FileStream^ fileStream;
            try
            {
                fileStream = File::Create(dictionaryFilePath);
                binaryFormatter->Serialize(fileStream, dictionaryData);
            }
            finally
            {
                fileStream->Close();
            }
        }
    private:
        String^ dictionaryName;
        String^ dictionaryDescription;
        String^ dictionaryFilePath;
        
        DictionaryData^ GenerateDictionaryData()
        {
            // The auto keyword in C++ automatically detects and assigns a data type to the variable with which it is used // Used for reference types
            auto dictionaryData = gcnew DictionaryData();

            dictionaryData->Name = dictionaryName;
            dictionaryData->Description = dictionaryDescription;

            //dictionaryData->Items->Add("dom", "home");
            //dictionaryData->Items->Add("wyjscie", "exit");
            //dictionaryData->Items->Add("koniec", "end");
            //dictionaryData->Items->Add("kot", "cat");
            //dictionaryData->Items->Add("pies", "dog");

            //for (int i = 0; i < 20; i++)
            //{
            //    dictionaryData->Items->Add("word_" + i, "translation_" + i);
            //}
            
            // Binaryformatter is used to serialize dictionary data object // To serialize means to save as bytes
            auto binaryFormatter = gcnew BinaryFormatter();
            FileStream^ fileStream ;

            try
            {
                // Creates or overwrites a file in the specified path
                fileStream = File::Create(dictionaryFilePath);

                // Serializes an object, or graph of connected objects, to the given stream  
                binaryFormatter->Serialize(fileStream, dictionaryData);
            }
            finally
            {
                //Closes the current stream and releases any resources
                fileStream->Close();
            }
            
            return dictionaryData;
        }
    };
}