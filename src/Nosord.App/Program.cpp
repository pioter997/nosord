#include "pch.h"
#include "MainView.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThread]
int main()
{
	// Enable current visual styles for the app 
	Application::EnableVisualStyles();

	// Disable the default text rendering for the app
	Application::SetCompatibleTextRenderingDefault(false);

	// Run the main app window
	Application::Run(gcnew Nosord::MainView()); 

	// Program completion
	return 0;                                                
}