#include "pch.h"
#include "GenerateImage.h"
#include "FractalGeneration.h"
#include "Form1.h"

using namespace System;


using namespace System::Windows::Forms;

[STAThread]
int main() {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew CppCLRWinformsProjekt::Form1()); 

	//GenerateImage mandelbrot;
	//mandelbrot.savePNG("fraktal.png");

	return 0;
}