#pragma once

namespace Nosord {

    using namespace System;

    [Serializable]
    ref class AppConfiguration
    {
    public:
        String^ DatabaseFilePath;

        AppConfiguration()
        {
            
        }
    };
}