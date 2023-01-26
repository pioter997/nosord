#pragma once

namespace Nosord {

    using namespace System;
    using namespace System::IO;
    using namespace System::Runtime::Serialization::Formatters::Binary;

    /// <summary>
    /// The base class for the DictionaryManager class.
    /// </summary>
    ref class DictionaryBase
    {
    protected:
        String^ dictionaryFilePath;
        String^ dictionaryName;
        String^ dictionaryDescription;
    };

    ref class DictionaryManager : DictionaryBase
    {
    public:
        /// <summary>
        /// Default contstructor
        /// </summary>
        DictionaryManager() { }

        /// <summary>
        /// Parametrized constructor.
        /// </summary>
        /// <param name="filePath"></param>
        DictionaryManager(String^ filePath) : DictionaryManager()
        {
            dictionaryFilePath = filePath;
        }

        /// <summary>
        /// Parametrized constructor.
        /// </summary>
        /// <param name="name">The name of the dictionary.</param>
        /// <param name="description">The discription of the dicitonary.</param>
        /// <param name="filePath">The file path to the dictionary file.</param>
        DictionaryManager(String^ name, String^ description, String^ filePath) : DictionaryManager(filePath)
        {
            dictionaryName = name;
            dictionaryDescription = description;
        }

        /// <summary>
        /// Gets the dicitonary data.
        /// </summary>
        /// <returns>Returns the DictionaryData object.</returns>
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

        /// <summary>
        /// Save dictionary data into file.
        /// </summary>
        /// <param name="dictionaryData"></param>
        /// <returns></returns>
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
        /// <summary>
        /// Generates empty dictionary data object.
        /// </summary>
        /// <returns>Returns </returns>
        DictionaryData^ GenerateDictionaryData()
        {
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

            auto binaryFormatter = gcnew BinaryFormatter();
            FileStream^ fileStream ;
            try
            {
                fileStream = File::Create(dictionaryFilePath);
                binaryFormatter->Serialize(fileStream, dictionaryData);
            }
            finally
            {
                fileStream->Close();
            }
            
            return dictionaryData;
        }
    };
}