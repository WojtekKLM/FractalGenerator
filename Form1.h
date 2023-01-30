#pragma once
#include "FractalGenCpp.h"
#include "FractalGenAsm.h"
#include "ImageOutput.h"
#include "DataController.h"

namespace CppCLRWinformsProjekt {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Threading;
	using namespace std;
	using namespace std::chrono;

	/// <summary>
	/// Zusammenfassung für Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:

		DataController^ dataController;

		Form1(void)
		{
			InitializeComponent();
			dataController = gcnew DataController();
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

	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ threadsLabel;
	private: System::Windows::Forms::TextBox^ textBox4;
	private: System::Windows::Forms::TextBox^ textBox5;
	private: System::Windows::Forms::TextBox^ threadsBox;
	private: System::Windows::Forms::RadioButton^ cppButton;
	private: System::Windows::Forms::RadioButton^ asmButton;
	private: System::Windows::Forms::Label^ libLabel;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::TextBox^ medTimeCppBox;

	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::TextBox^ medTimeAsmBox;

	private: System::Windows::Forms::Label^ label10;

	protected:

	private:

		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code

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
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->threadsLabel = (gcnew System::Windows::Forms::Label());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->threadsBox = (gcnew System::Windows::Forms::TextBox());
			this->cppButton = (gcnew System::Windows::Forms::RadioButton());
			this->asmButton = (gcnew System::Windows::Forms::RadioButton());
			this->libLabel = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->medTimeCppBox = (gcnew System::Windows::Forms::TextBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->medTimeAsmBox = (gcnew System::Windows::Forms::TextBox());
			this->label10 = (gcnew System::Windows::Forms::Label());
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
			this->pictureBox->Click += gcnew System::EventHandler(this, &Form1::pictureBox_Click);
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
			this->label1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label1->Location = System::Drawing::Point(367, 12);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(217, 17);
			this->label1->TabIndex = 3;
			this->label1->Text = L"Parametry generowanego obrazu:";
			this->label1->Click += gcnew System::EventHandler(this, &Form1::label1_Click);
			// 
			// heightLabel
			// 
			this->heightLabel->AutoSize = true;
			this->heightLabel->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->heightLabel->Location = System::Drawing::Point(371, 40);
			this->heightLabel->Name = L"heightLabel";
			this->heightLabel->Size = System::Drawing::Size(118, 13);
			this->heightLabel->TabIndex = 4;
			this->heightLabel->Text = L"Wysokoœæ w pixelach:";
			this->heightLabel->Click += gcnew System::EventHandler(this, &Form1::label2_Click);
			// 
			// widthLabel
			// 
			this->widthLabel->AutoSize = true;
			this->widthLabel->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->widthLabel->Location = System::Drawing::Point(371, 66);
			this->widthLabel->Name = L"widthLabel";
			this->widthLabel->Size = System::Drawing::Size(118, 13);
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
			this->iterLabel->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->iterLabel->Location = System::Drawing::Point(371, 92);
			this->iterLabel->Name = L"iterLabel";
			this->iterLabel->Size = System::Drawing::Size(133, 13);
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
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label6->Location = System::Drawing::Point(371, 221);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(130, 13);
			this->label6->TabIndex = 10;
			this->label6->Text = L"Czas generowania C++:";
			this->label6->Click += gcnew System::EventHandler(this, &Form1::label6_Click);
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label7->Location = System::Drawing::Point(371, 245);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(130, 13);
			this->label7->TabIndex = 11;
			this->label7->Text = L"Czas generowania ASM:";
			this->label7->Click += gcnew System::EventHandler(this, &Form1::label7_Click);
			// 
			// threadsLabel
			// 
			this->threadsLabel->AutoSize = true;
			this->threadsLabel->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->threadsLabel->Location = System::Drawing::Point(371, 118);
			this->threadsLabel->Name = L"threadsLabel";
			this->threadsLabel->Size = System::Drawing::Size(77, 13);
			this->threadsLabel->TabIndex = 12;
			this->threadsLabel->Text = L"Iloœæ w¹tków:";
			this->threadsLabel->Click += gcnew System::EventHandler(this, &Form1::label8_Click);
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(510, 218);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(125, 20);
			this->textBox4->TabIndex = 14;
			this->textBox4->TextChanged += gcnew System::EventHandler(this, &Form1::textBox4_TextChanged);
			// 
			// textBox5
			// 
			this->textBox5->Location = System::Drawing::Point(510, 242);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(125, 20);
			this->textBox5->TabIndex = 15;
			this->textBox5->TextChanged += gcnew System::EventHandler(this, &Form1::textBox5_TextChanged);
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
			this->cppButton->Location = System::Drawing::Point(510, 145);
			this->cppButton->Name = L"cppButton";
			this->cppButton->Size = System::Drawing::Size(44, 17);
			this->cppButton->TabIndex = 17;
			this->cppButton->TabStop = true;
			this->cppButton->Text = L"C++";
			this->cppButton->UseVisualStyleBackColor = true;
			this->cppButton->CheckedChanged += gcnew System::EventHandler(this, &Form1::cppButton_CheckedChanged);
			// 
			// asmButton
			// 
			this->asmButton->AutoSize = true;
			this->asmButton->Location = System::Drawing::Point(560, 145);
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
			this->libLabel->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->libLabel->Location = System::Drawing::Point(372, 147);
			this->libLabel->Name = L"libLabel";
			this->libLabel->Size = System::Drawing::Size(111, 13);
			this->libLabel->TabIndex = 19;
			this->libLabel->Text = L"Biblioteka generacji:";
			this->libLabel->Click += gcnew System::EventHandler(this, &Form1::label9_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label2->Location = System::Drawing::Point(372, 197);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(114, 17);
			this->label2->TabIndex = 20;
			this->label2->Text = L"Dane z generacji:";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label3->Location = System::Drawing::Point(641, 218);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(24, 17);
			this->label3->TabIndex = 21;
			this->label3->Text = L"[s]";
			this->label3->Click += gcnew System::EventHandler(this, &Form1::label3_Click_1);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label4->Location = System::Drawing::Point(641, 242);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(24, 17);
			this->label4->TabIndex = 22;
			this->label4->Text = L"[s]";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label5->Location = System::Drawing::Point(372, 316);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(119, 13);
			this->label5->TabIndex = 23;
			this->label5->Text = L"Œredni czas gen. ASM:";
			// 
			// medTimeCppBox
			// 
			this->medTimeCppBox->Location = System::Drawing::Point(510, 287);
			this->medTimeCppBox->Name = L"medTimeCppBox";
			this->medTimeCppBox->Size = System::Drawing::Size(125, 20);
			this->medTimeCppBox->TabIndex = 24;
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label8->Location = System::Drawing::Point(641, 287);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(24, 17);
			this->label8->TabIndex = 25;
			this->label8->Text = L"[s]";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label9->Location = System::Drawing::Point(641, 313);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(24, 17);
			this->label9->TabIndex = 28;
			this->label9->Text = L"[s]";
			// 
			// medTimeAsmBox
			// 
			this->medTimeAsmBox->Location = System::Drawing::Point(510, 313);
			this->medTimeAsmBox->Name = L"medTimeAsmBox";
			this->medTimeAsmBox->Size = System::Drawing::Size(125, 20);
			this->medTimeAsmBox->TabIndex = 27;
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label10->Location = System::Drawing::Point(372, 290);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(119, 13);
			this->label10->TabIndex = 26;
			this->label10->Text = L"Œredni czas gen. C++:";
			this->label10->Click += gcnew System::EventHandler(this, &Form1::label10_Click);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(685, 391);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->medTimeAsmBox);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->medTimeCppBox);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->libLabel);
			this->Controls->Add(this->asmButton);
			this->Controls->Add(this->cppButton);
			this->Controls->Add(this->threadsBox);
			this->Controls->Add(this->textBox5);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->threadsLabel);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
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
		int widthPre, heightPre, maxIterPre, numThreadsPre;
		int width, height, maxIter, numThreads;
		bool dataOK = 0;
		bool dataFull = 0;
		float medCppTime = 0;
		bool dataFullAsm = 0;
		float medAsmTime = 0;

		try {
			widthPre = System::Convert::ToInt32(widthBox->Text);
			heightPre = System::Convert::ToInt32(heightBox->Text);
			maxIterPre = System::Convert::ToInt32(iterBox->Text);
			numThreadsPre = System::Convert::ToInt32(threadsBox->Text);

			if (widthPre >= 1 && widthPre <= 10000 && heightPre >= 1 && heightPre <= 10000 && maxIterPre >= 1 && maxIterPre <= 1000 && numThreadsPre >= 1 && numThreadsPre <= 100) {
				width = widthPre;
				height = heightPre;
				maxIter = maxIterPre; 
				numThreads = numThreadsPre; 
				dataOK = 1; 
			}
			else {
				System::Windows::Forms::MessageBox::Show("Nieprawid³owe dane.");
			}
		}
		catch (System::FormatException^) {
			// Wyœwietl komunikat o b³êdzie, jeœli tekst nie jest liczb¹
			System::Windows::Forms::MessageBox::Show("Nieprawid³owo uzupe³nione pole z danymi.");
		}

		if (!cppButton->Checked && !asmButton->Checked) {
			System::Windows::Forms::MessageBox::Show("Nie wybrano biblioteki.");
		}
		if (dataOK == 1 && cppButton->Checked) {
			FractalGenCpp generator(width, height, maxIter, numThreads);
			generator.threadManagement();
			float runtime = generator.returnRunTime();
			textBox4->Text = runtime.ToString();
			dataController->addData(runtime);

			dataFull = dataController->isDataFull();
			medCppTime = dataController->getAverage();
			if (dataFull) {
				medTimeCppBox->Text = medCppTime.ToString();
			}
		}
		if (dataOK == 1 && asmButton->Checked) {
			FractalGenAsm generator(width, height, maxIter, numThreads);
			generator.threadManagement();
			float runtime = generator.returnRunTime();
			textBox5->Text = runtime.ToString();

			dataFullAsm = dataController->isDataFullAsm();
			medAsmTime = dataController->getAverageAsm();
			if (dataFullAsm) {
				medTimeAsmBox->Text = medAsmTime.ToString();
			}
		}
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
private: System::Void textBox4_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void cppButton_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label3_Click_1(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label10_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void pictureBox_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void textBox5_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
};
}
