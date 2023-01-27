#pragma once
#include "FractalGenCpp.h"
#include "ImageOutput.h"
#include "DataController.h"

namespace CppCLRWinformsProjekt {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Zusammenfassung für Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: Konstruktorcode hier hinzufügen.
			//

			DataController dataController;
		}

	protected:
		/// <summary>
		/// Verwendete Ressourcen bereinigen.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ generateButton;
	private: System::Windows::Forms::PictureBox^ pictureBox;
	private: System::Windows::Forms::TextBox^ heightBox;

	protected:



	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ heightLabel;
	private: System::Windows::Forms::Label^ widthLabel;



	private: System::Windows::Forms::TextBox^ widthBox;
	private: System::Windows::Forms::Label^ iterLabel;


	private: System::Windows::Forms::TextBox^ iterBox;

	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ threadsLabel;


	private: System::Windows::Forms::TextBox^ textBox4;
	private: System::Windows::Forms::TextBox^ textBox5;
	private: System::Windows::Forms::TextBox^ threadsBox;

	private: System::Windows::Forms::RadioButton^ cppButton;
	private: System::Windows::Forms::RadioButton^ asmButton;
	private: System::Windows::Forms::Label^ libLabel;

	private: System::Windows::Forms::Button^ saveButton;





	protected:

	private:
		/// <summary>
		/// Erforderliche Designervariable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Erforderliche Methode für die Designerunterstützung.
		/// Der Inhalt der Methode darf nicht mit dem Code-Editor geändert werden.
		/// </summary>
		void InitializeComponent(void)
		{
			this->generateButton = (gcnew System::Windows::Forms::Button());
			this->pictureBox = (gcnew System::Windows::Forms::PictureBox());
			this->heightBox = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->heightLabel = (gcnew System::Windows::Forms::Label());
			this->widthLabel = (gcnew System::Windows::Forms::Label());
			this->widthBox = (gcnew System::Windows::Forms::TextBox());
			this->iterLabel = (gcnew System::Windows::Forms::Label());
			this->iterBox = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->threadsLabel = (gcnew System::Windows::Forms::Label());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->threadsBox = (gcnew System::Windows::Forms::TextBox());
			this->cppButton = (gcnew System::Windows::Forms::RadioButton());
			this->asmButton = (gcnew System::Windows::Forms::RadioButton());
			this->libLabel = (gcnew System::Windows::Forms::Label());
			this->saveButton = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox))->BeginInit();
			this->SuspendLayout();
			// 
			// generateButton
			// 
			this->generateButton->Location = System::Drawing::Point(12, 357);
			this->generateButton->Name = L"generateButton";
			this->generateButton->Size = System::Drawing::Size(349, 23);
			this->generateButton->TabIndex = 0;
			this->generateButton->Text = L"Wygeneruj fraktal";
			this->generateButton->UseVisualStyleBackColor = true;
			this->generateButton->Click += gcnew System::EventHandler(this, &Form1::generateButton_Click);
			// 
			// pictureBox
			// 
			this->pictureBox->Location = System::Drawing::Point(12, 12);
			this->pictureBox->Name = L"pictureBox";
			this->pictureBox->Size = System::Drawing::Size(349, 339);
			this->pictureBox->TabIndex = 1;
			this->pictureBox->TabStop = false;
			// 
			// heightBox
			// 
			this->heightBox->Location = System::Drawing::Point(510, 37);
			this->heightBox->Name = L"heightBox";
			this->heightBox->Size = System::Drawing::Size(156, 20);
			this->heightBox->TabIndex = 2;
			this->heightBox->TextChanged += gcnew System::EventHandler(this, &Form1::textBox1_TextChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(441, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(166, 13);
			this->label1->TabIndex = 3;
			this->label1->Text = L"Parametry generowanego obrazu ";
			this->label1->Click += gcnew System::EventHandler(this, &Form1::label1_Click);
			// 
			// heightLabel
			// 
			this->heightLabel->AutoSize = true;
			this->heightLabel->Location = System::Drawing::Point(371, 40);
			this->heightLabel->Name = L"heightLabel";
			this->heightLabel->Size = System::Drawing::Size(113, 13);
			this->heightLabel->TabIndex = 4;
			this->heightLabel->Text = L"Wysokoœæ w pixelach:";
			this->heightLabel->Click += gcnew System::EventHandler(this, &Form1::label2_Click);
			// 
			// widthLabel
			// 
			this->widthLabel->AutoSize = true;
			this->widthLabel->Location = System::Drawing::Point(371, 66);
			this->widthLabel->Name = L"widthLabel";
			this->widthLabel->Size = System::Drawing::Size(113, 13);
			this->widthLabel->TabIndex = 6;
			this->widthLabel->Text = L"Szerokoœæ w pixelach:";
			this->widthLabel->Click += gcnew System::EventHandler(this, &Form1::label3_Click);
			// 
			// widthBox
			// 
			this->widthBox->Location = System::Drawing::Point(510, 63);
			this->widthBox->Name = L"widthBox";
			this->widthBox->Size = System::Drawing::Size(156, 20);
			this->widthBox->TabIndex = 5;
			// 
			// iterLabel
			// 
			this->iterLabel->AutoSize = true;
			this->iterLabel->Location = System::Drawing::Point(371, 92);
			this->iterLabel->Name = L"iterLabel";
			this->iterLabel->Size = System::Drawing::Size(124, 13);
			this->iterLabel->TabIndex = 7;
			this->iterLabel->Text = L"Maksymalna ioœæ iteracji:";
			this->iterLabel->Click += gcnew System::EventHandler(this, &Form1::label4_Click);
			// 
			// iterBox
			// 
			this->iterBox->Location = System::Drawing::Point(510, 89);
			this->iterBox->Name = L"iterBox";
			this->iterBox->Size = System::Drawing::Size(156, 20);
			this->iterBox->TabIndex = 8;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(813, 9);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(90, 13);
			this->label5->TabIndex = 9;
			this->label5->Text = L"Dane z generacji:";
			this->label5->Click += gcnew System::EventHandler(this, &Form1::label5_Click);
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(707, 40);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(119, 13);
			this->label6->TabIndex = 10;
			this->label6->Text = L"Czas generowania C++:";
			this->label6->Click += gcnew System::EventHandler(this, &Form1::label6_Click);
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(707, 64);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(123, 13);
			this->label7->TabIndex = 11;
			this->label7->Text = L"Czas generowania ASM:";
			this->label7->Click += gcnew System::EventHandler(this, &Form1::label7_Click);
			// 
			// threadsLabel
			// 
			this->threadsLabel->AutoSize = true;
			this->threadsLabel->Location = System::Drawing::Point(371, 118);
			this->threadsLabel->Name = L"threadsLabel";
			this->threadsLabel->Size = System::Drawing::Size(72, 13);
			this->threadsLabel->TabIndex = 12;
			this->threadsLabel->Text = L"Iloœæ w¹tków:";
			this->threadsLabel->Click += gcnew System::EventHandler(this, &Form1::label8_Click);
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(846, 37);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(156, 20);
			this->textBox4->TabIndex = 14;
			// 
			// textBox5
			// 
			this->textBox5->Location = System::Drawing::Point(846, 61);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(156, 20);
			this->textBox5->TabIndex = 15;
			// 
			// threadsBox
			// 
			this->threadsBox->Location = System::Drawing::Point(510, 115);
			this->threadsBox->Name = L"threadsBox";
			this->threadsBox->Size = System::Drawing::Size(156, 20);
			this->threadsBox->TabIndex = 16;
			// 
			// cppButton
			// 
			this->cppButton->AutoSize = true;
			this->cppButton->Location = System::Drawing::Point(509, 172);
			this->cppButton->Name = L"cppButton";
			this->cppButton->Size = System::Drawing::Size(44, 17);
			this->cppButton->TabIndex = 17;
			this->cppButton->TabStop = true;
			this->cppButton->Text = L"C++";
			this->cppButton->UseVisualStyleBackColor = true;
			// 
			// asmButton
			// 
			this->asmButton->AutoSize = true;
			this->asmButton->Location = System::Drawing::Point(559, 172);
			this->asmButton->Name = L"asmButton";
			this->asmButton->Size = System::Drawing::Size(48, 17);
			this->asmButton->TabIndex = 18;
			this->asmButton->TabStop = true;
			this->asmButton->Text = L"ASM";
			this->asmButton->UseVisualStyleBackColor = true;
			// 
			// libLabel
			// 
			this->libLabel->AutoSize = true;
			this->libLabel->Location = System::Drawing::Point(371, 174);
			this->libLabel->Name = L"libLabel";
			this->libLabel->Size = System::Drawing::Size(102, 13);
			this->libLabel->TabIndex = 19;
			this->libLabel->Text = L"Biblioteka generacji:";
			this->libLabel->Click += gcnew System::EventHandler(this, &Form1::label9_Click);
			// 
			// saveButton
			// 
			this->saveButton->Location = System::Drawing::Point(478, 141);
			this->saveButton->Name = L"saveButton";
			this->saveButton->Size = System::Drawing::Size(75, 23);
			this->saveButton->TabIndex = 21;
			this->saveButton->Text = L"Zapisz";
			this->saveButton->UseVisualStyleBackColor = true;
			this->saveButton->Click += gcnew System::EventHandler(this, &Form1::saveButton_Click);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1014, 391);
			this->Controls->Add(this->saveButton);
			this->Controls->Add(this->libLabel);
			this->Controls->Add(this->asmButton);
			this->Controls->Add(this->cppButton);
			this->Controls->Add(this->threadsBox);
			this->Controls->Add(this->textBox5);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->threadsLabel);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->iterBox);
			this->Controls->Add(this->iterLabel);
			this->Controls->Add(this->widthLabel);
			this->Controls->Add(this->widthBox);
			this->Controls->Add(this->heightLabel);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->heightBox);
			this->Controls->Add(this->pictureBox);
			this->Controls->Add(this->generateButton);
			this->Name = L"Form1";
			this->Text = L"Generator fraktali ze zbioru Mandelbrota";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void generateButton_Click(System::Object^ sender, System::EventArgs^ e) {
		int width = 1000;
		int height = 1000;
		int maxIter = 500;
		int numThreads = 8;
		FractalGenCpp generator(width, height, maxIter, numThreads);
		generator.threadManagement();
	}
	private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label3_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label4_Click(System::Object^ sender, System::EventArgs^ e) {


	}
	private: System::Void label5_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label6_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label7_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label8_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void checkBox1_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label9_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void saveButton_Click(System::Object^ sender, System::EventArgs^ e) {


	}
};
}
