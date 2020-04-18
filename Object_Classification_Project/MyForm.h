#pragma once

#include<windows.h>
#include <atlstr.h>								// LPCTSTR 
#include<iostream>

#include<msclr\marshal_cppstd.h>
#include <fstream>
#include<vector>

#include "image_BMP.h"
#include "image_Processing.h"					// My Functions

namespace Object_Classification_Project {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the confilePathStructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	protected:
	private: System::Windows::Forms::ToolStripMenuItem^ fileToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ openToolStripMenuItem;
	private: System::Windows::Forms::OpenFileDialog^ openFileDialog1;
	private: System::Windows::Forms::PictureBox^ pictureBox1;

	private: System::Windows::Forms::DataVisualization::Charting::Chart^ chart1;
	private: System::Windows::Forms::PictureBox^ pictureBox2;
	private: System::Windows::Forms::PictureBox^ pictureBox5;
	private: System::Windows::Forms::PictureBox^ pictureBox6;
	private: System::Windows::Forms::PictureBox^ pictureBox7;

	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label12;
	private: System::Windows::Forms::Label^ label11;
	private: System::Windows::Forms::RichTextBox^ richTextBoxObjects;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::RadioButton^ trainingRadioButton;
	private: System::Windows::Forms::RadioButton^ testRadioButton;
	private: System::Windows::Forms::TextBox^ objectNameTextB;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::RichTextBox^ richTextBox1;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::CheckBox^ checkBMahalonobis;
	private: System::Windows::Forms::CheckBox^ checkBEuclidean;
	private: System::Windows::Forms::Label^ label13;
	private: System::Windows::Forms::Label^ totalDetectedNum;



	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea1 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^ legend1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^ series1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->openToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->chart1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox5 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox6 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox7 = (gcnew System::Windows::Forms::PictureBox());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->richTextBoxObjects = (gcnew System::Windows::Forms::RichTextBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->trainingRadioButton = (gcnew System::Windows::Forms::RadioButton());
			this->testRadioButton = (gcnew System::Windows::Forms::RadioButton());
			this->objectNameTextB = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->checkBMahalonobis = (gcnew System::Windows::Forms::CheckBox());
			this->checkBEuclidean = (gcnew System::Windows::Forms::CheckBox());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->totalDetectedNum = (gcnew System::Windows::Forms::Label());
			this->menuStrip1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox5))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox6))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox7))->BeginInit();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->fileToolStripMenuItem });
			this->menuStrip1->LayoutStyle = System::Windows::Forms::ToolStripLayoutStyle::HorizontalStackWithOverflow;
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Padding = System::Windows::Forms::Padding(7, 2, 0, 2);
			this->menuStrip1->Size = System::Drawing::Size(1292, 28);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// fileToolStripMenuItem
			// 
			this->fileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->openToolStripMenuItem });
			this->fileToolStripMenuItem->Name = L"fileToolStripMenuItem";
			this->fileToolStripMenuItem->Size = System::Drawing::Size(46, 24);
			this->fileToolStripMenuItem->Text = L"File";
			// 
			// openToolStripMenuItem
			// 
			this->openToolStripMenuItem->Name = L"openToolStripMenuItem";
			this->openToolStripMenuItem->Size = System::Drawing::Size(128, 26);
			this->openToolStripMenuItem->Text = L"Open";
			this->openToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::openToolStripMenuItem_Click);
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox1->Location = System::Drawing::Point(3, 47);
			this->pictureBox1->Margin = System::Windows::Forms::Padding(2);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(380, 380);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox1->TabIndex = 1;
			this->pictureBox1->TabStop = false;
			// 
			// chart1
			// 
			chartArea1->Name = L"ChartArea1";
			this->chart1->ChartAreas->Add(chartArea1);
			legend1->Name = L"Legend1";
			this->chart1->Legends->Add(legend1);
			this->chart1->Location = System::Drawing::Point(807, 46);
			this->chart1->Margin = System::Windows::Forms::Padding(2);
			this->chart1->Name = L"chart1";
			series1->ChartArea = L"ChartArea1";
			series1->Legend = L"Legend1";
			series1->Name = L"Hist";
			this->chart1->Series->Add(series1);
			this->chart1->Size = System::Drawing::Size(481, 196);
			this->chart1->TabIndex = 3;
			this->chart1->Text = L"chart1";
			this->chart1->Click += gcnew System::EventHandler(this, &MyForm::chart1_Click_1);
			// 
			// pictureBox2
			// 
			this->pictureBox2->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox2->Location = System::Drawing::Point(406, 46);
			this->pictureBox2->Margin = System::Windows::Forms::Padding(2);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(380, 380);
			this->pictureBox2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox2->TabIndex = 6;
			this->pictureBox2->TabStop = false;
			// 
			// pictureBox5
			// 
			this->pictureBox5->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox5->Location = System::Drawing::Point(3, 453);
			this->pictureBox5->Margin = System::Windows::Forms::Padding(2);
			this->pictureBox5->Name = L"pictureBox5";
			this->pictureBox5->Size = System::Drawing::Size(380, 380);
			this->pictureBox5->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox5->TabIndex = 14;
			this->pictureBox5->TabStop = false;
			// 
			// pictureBox6
			// 
			this->pictureBox6->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox6->Location = System::Drawing::Point(406, 453);
			this->pictureBox6->Margin = System::Windows::Forms::Padding(2);
			this->pictureBox6->Name = L"pictureBox6";
			this->pictureBox6->Size = System::Drawing::Size(380, 380);
			this->pictureBox6->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox6->TabIndex = 20;
			this->pictureBox6->TabStop = false;
			// 
			// pictureBox7
			// 
			this->pictureBox7->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox7->Location = System::Drawing::Point(810, 453);
			this->pictureBox7->Margin = System::Windows::Forms::Padding(2);
			this->pictureBox7->Name = L"pictureBox7";
			this->pictureBox7->Size = System::Drawing::Size(380, 380);
			this->pictureBox7->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox7->TabIndex = 23;
			this->pictureBox7->TabStop = false;
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label10->Location = System::Drawing::Point(0, 435);
			this->label10->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(62, 17);
			this->label10->TabIndex = 30;
			this->label10->Text = L"Opening";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label9->Location = System::Drawing::Point(404, 435);
			this->label9->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(35, 17);
			this->label9->TabIndex = 29;
			this->label9->Text = L"CCA";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label7->Location = System::Drawing::Point(404, 29);
			this->label7->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(64, 17);
			this->label7->TabIndex = 28;
			this->label7->Text = L"K-Means";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label6->Location = System::Drawing::Point(0, 29);
			this->label6->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(46, 17);
			this->label6->TabIndex = 27;
			this->label6->Text = L"Image";
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label12->Location = System::Drawing::Point(807, 435);
			this->label12->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(117, 17);
			this->label12->TabIndex = 49;
			this->label12->Text = L"Detected Objects";
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label11->Location = System::Drawing::Point(1111, 244);
			this->label11->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(179, 17);
			this->label11->TabIndex = 61;
			this->label11->Text = L"Names of Detected object :";
			// 
			// richTextBoxObjects
			// 
			this->richTextBoxObjects->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->richTextBoxObjects->Location = System::Drawing::Point(1114, 263);
			this->richTextBoxObjects->Margin = System::Windows::Forms::Padding(2);
			this->richTextBoxObjects->Name = L"richTextBoxObjects";
			this->richTextBoxObjects->Size = System::Drawing::Size(155, 129);
			this->richTextBoxObjects->TabIndex = 60;
			this->richTextBoxObjects->Text = L"";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label8->Location = System::Drawing::Point(807, 374);
			this->label8->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(98, 17);
			this->label8->TabIndex = 59;
			this->label8->Text = L"Object Name :";
			// 
			// trainingRadioButton
			// 
			this->trainingRadioButton->AutoSize = true;
			this->trainingRadioButton->Location = System::Drawing::Point(807, 344);
			this->trainingRadioButton->Margin = System::Windows::Forms::Padding(2);
			this->trainingRadioButton->Name = L"trainingRadioButton";
			this->trainingRadioButton->Size = System::Drawing::Size(84, 19);
			this->trainingRadioButton->TabIndex = 58;
			this->trainingRadioButton->Text = L"TRAINING";
			this->trainingRadioButton->UseVisualStyleBackColor = true;
			// 
			// testRadioButton
			// 
			this->testRadioButton->AutoSize = true;
			this->testRadioButton->Checked = true;
			this->testRadioButton->Location = System::Drawing::Point(807, 321);
			this->testRadioButton->Margin = System::Windows::Forms::Padding(2);
			this->testRadioButton->Name = L"testRadioButton";
			this->testRadioButton->Size = System::Drawing::Size(58, 19);
			this->testRadioButton->TabIndex = 57;
			this->testRadioButton->TabStop = true;
			this->testRadioButton->Text = L"TEST";
			this->testRadioButton->UseVisualStyleBackColor = true;
			// 
			// objectNameTextB
			// 
			this->objectNameTextB->Location = System::Drawing::Point(807, 392);
			this->objectNameTextB->Margin = System::Windows::Forms::Padding(2);
			this->objectNameTextB->Name = L"objectNameTextB";
			this->objectNameTextB->Size = System::Drawing::Size(155, 21);
			this->objectNameTextB->TabIndex = 56;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->Location = System::Drawing::Point(978, 244);
			this->label5->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(110, 17);
			this->label5->TabIndex = 55;
			this->label5->Text = L"K-Means steps :";
			// 
			// richTextBox1
			// 
			this->richTextBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->richTextBox1->Location = System::Drawing::Point(981, 263);
			this->richTextBox1->Margin = System::Windows::Forms::Padding(2);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->Size = System::Drawing::Size(129, 128);
			this->richTextBox1->TabIndex = 54;
			this->richTextBox1->Text = L"";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(1062, 397);
			this->label4->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(33, 17);
			this->label4->TabIndex = 53;
			this->label4->Text = L"T2 :";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(978, 396);
			this->label3->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(33, 17);
			this->label3->TabIndex = 52;
			this->label3->Text = L"T1 :";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(1099, 396);
			this->label2->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(46, 17);
			this->label2->TabIndex = 51;
			this->label2->Text = L"label2";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(1012, 396);
			this->label1->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(46, 17);
			this->label1->TabIndex = 50;
			this->label1->Text = L"label1";
			// 
			// checkBMahalonobis
			// 
			this->checkBMahalonobis->AutoSize = true;
			this->checkBMahalonobis->Location = System::Drawing::Point(807, 282);
			this->checkBMahalonobis->Name = L"checkBMahalonobis";
			this->checkBMahalonobis->Size = System::Drawing::Size(152, 19);
			this->checkBMahalonobis->TabIndex = 62;
			this->checkBMahalonobis->Text = L"Mahalonobis Distance";
			this->checkBMahalonobis->UseVisualStyleBackColor = true;
			// 
			// checkBEuclidean
			// 
			this->checkBEuclidean->AutoSize = true;
			this->checkBEuclidean->Checked = true;
			this->checkBEuclidean->CheckState = System::Windows::Forms::CheckState::Checked;
			this->checkBEuclidean->Location = System::Drawing::Point(807, 257);
			this->checkBEuclidean->Name = L"checkBEuclidean";
			this->checkBEuclidean->Size = System::Drawing::Size(135, 19);
			this->checkBEuclidean->TabIndex = 64;
			this->checkBEuclidean->Text = L"Euclidean Distance";
			this->checkBEuclidean->UseVisualStyleBackColor = true;
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label13->Location = System::Drawing::Point(1188, 397);
			this->label13->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(48, 17);
			this->label13->TabIndex = 65;
			this->label13->Text = L"Total :";
			// 
			// totalDetectedNum
			// 
			this->totalDetectedNum->AutoSize = true;
			this->totalDetectedNum->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->totalDetectedNum->Location = System::Drawing::Point(1240, 397);
			this->totalDetectedNum->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->totalDetectedNum->Name = L"totalDetectedNum";
			this->totalDetectedNum->Size = System::Drawing::Size(16, 17);
			this->totalDetectedNum->TabIndex = 66;
			this->totalDetectedNum->Text = L"0";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(7, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSize = true;
			this->BackColor = System::Drawing::SystemColors::ControlDark;
			this->ClientSize = System::Drawing::Size(1292, 853);
			this->Controls->Add(this->totalDetectedNum);
			this->Controls->Add(this->label13);
			this->Controls->Add(this->checkBEuclidean);
			this->Controls->Add(this->checkBMahalonobis);
			this->Controls->Add(this->label11);
			this->Controls->Add(this->richTextBoxObjects);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->trainingRadioButton);
			this->Controls->Add(this->testRadioButton);
			this->Controls->Add(this->objectNameTextB);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->richTextBox1);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->label12);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->pictureBox7);
			this->Controls->Add(this->pictureBox6);
			this->Controls->Add(this->pictureBox5);
			this->Controls->Add(this->pictureBox2);
			this->Controls->Add(this->chart1);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->menuStrip1);
			this->DoubleBuffered = true;
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"MyForm";
			this->Text = L"Form";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox5))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox6))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox7))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {


	}
	private: System::Void openToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {

		if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			pictureBox1->ImageLocation = openFileDialog1->FileName;

			LPCTSTR input;
			int Width, Height;
			long Size;

			CString filePathStr;

																						// dosya secmek icin openfiledialog olusturuldu ve secilen dosyanin adresi aliniyor
			filePathStr = openFileDialog1->FileName;

																						// LoadBMP fonksiyonu LPCTSTR destekler
			input = (LPCTSTR)filePathStr;

																						// LoadBMP nin parametre duzenlemesi yapildi
			BYTE* buffer = LoadBMP((int%)Width, (int%)Height, (long%)Size, input);
			BYTE* raw_intensity = ConvertBMPToIntensity(buffer, Width, Height);

																						// meanStructureElement ile meanFilter uygula => meanFilterI(ntensity)
			int* meanStructureElement = new int[9]{ 1,1,1,1,1,1,1,1,1 };
			BYTE* meanFilterI = meanFilter(raw_intensity, Width, Height, meanStructureElement, 3);

																						// meanFilter uygulanmis goruntuden histogram matrisini olustur 
			int* hist = createHistMatris(meanFilterI, Width, Height);

																						// histogram matrisini ekranda gostermek icin chart kullan
			chart1->Series["Hist"]->Points->Clear();
			for (int i = 0; i < 256; i++) {
				chart1->Series["Hist"]->Points->AddXY(i, hist[i]);
			}


																						//  kMeans adim degerlerini tutucak, threashold degerlerini izleyebilecegiz	
			std::vector <int> kMeansSteps;					
																						// kMeans hesapla ve dengeli threashold degerlerini TPoints return et
			int* TPoints;															    //  TPoints[0] -> T1, TPoints[1] -> T2		
			
			if(checkBEuclidean->Checked == true )			
				TPoints = kMeansEuclidean(hist, &kMeansSteps);					
			
			else if(checkBMahalonobis->Checked == true )	
				TPoints = kMeansMahalonobis(hist, &kMeansSteps);				


																						// richtexBox a kMeans threashold adimlarini aktar
			richTextBox1->Clear();
			for (int i = 0; i < kMeansSteps.size(); i += 2)
			{
				richTextBox1->AppendText(kMeansSteps[i].ToString() + " " + kMeansSteps[i + 1].ToString() + "\n");
				richTextBox1->SelectionColor = Color::Green;
			}
			kMeansSteps.clear();


																						// display k-Means	

			Bitmap^ kMeansSurface = gcnew Bitmap(Width, Height);
			pictureBox2->Image = kMeansSurface;											
			displayBitmap(meanFilterI, Width, Height, TPoints, kMeansSurface);			// Stabil Threashold degerlerini Euclidean dist ile hesapla ve S-B olarak ekrana yansit

																						// display Threshold values
			label1->Text = Convert::ToString(TPoints[0]);
			label2->Text = Convert::ToString(TPoints[1]);

																						// meanFilterI convert to binary image (1/0)
			int* bImage = intensity2Binary(meanFilterI, Width, Height, TPoints);
																						// arkaplani beyaz (0), nesneleri ise siyah olarak (1) yeniden duzenlesin
			backgroundControl(bImage, Width, Height);


			int* mask = new int[9]{ 1,1,1,1,1,1,1,1,1 };								// Structure Element [3*3]
			int* cnvErosion = erosionBinary(bImage, Width, Height, mask, 3);			// structure element kullanarak, Binary Image uzerinde erosion uygula

			int* cnvOpening = dilationBinary(cnvErosion, Width, Height, mask, 3);		// erosion goruntusu uzerinde dilation yap => Opening uygulamis olduk

																						// display Opening binary image	
			Bitmap^ surfaceOpening = gcnew Bitmap(Width, Height);
			pictureBox5->Image = surfaceOpening;
			displayBitmap(cnvOpening, Width, Height, surfaceOpening);

																						// Opening uygulanmis goruntuye ZeroPading ekle
			int* zeroPading = addZeroPading(cnvOpening, Width, Height, 3);

																						// ZeroPading uygulanmis goruntuyu baska bir adreste yedekle
			int* zeroPadingBinary = new int[Width * Height];
			deepCopyArray(zeroPading, Width, Height, zeroPadingBinary);					

																						// ZeroPading goruntusunde 8 komsuluklu CCA uygula; etiketleri tagVector de depola
			std::vector <int> tagVector;
			CConnectivityAnalysis8N(zeroPading, Width, Height, tagVector);				

																						
																						// display CCA
			Bitmap^ zeroPadingSurface = gcnew Bitmap(Width, Height);
			pictureBox6->Image = zeroPadingSurface;
			displayCConnectivityAnalysis(zeroPading, Width, Height, zeroPadingSurface, tagVector);		


			std::vector <int> tagCoordVector;											// nesnelerin kordinat bilgileri tutulur 0-> minCol, 1 -> minRow, 2-> maxCol, 3-> maxRow
			drawRectangle(zeroPading, Width, Height, tagVector, tagCoordVector);		// belirlenen nesnelerin etrafina kutu ciz

																						// tum islemleri iceren sonucunu goruntule
			Bitmap^ detectionSurface = gcnew Bitmap(Width, Height);
			pictureBox7->Image = detectionSurface;
			displayRectangle(zeroPading, Width, Height, detectionSurface, tagVector);

			///////////////  TRAINING
			if (trainingRadioButton->Checked == true)
			{
				richTextBoxObjects->Clear();

				int* cutBinaryImage;
				msclr::interop::marshal_context context;
				std::ofstream outFile;
				outFile.open("db.txt", std::ios::app);
				std::vector <double> Qvalues;
																			// her etiketlenen cismin icin tekrarla
				for (int i = 0; i < tagCoordVector.size(); i += 4)
				{
																			// tespit icin kirpilacak goruntu boyutu degiskenleri
					int cutWidth = 0;													
					int cutHeight = 0;
																			// tespit edilen cismin etiket koordinatlarini kullanarak, CCA uygulanmamis goruntu uzerinde kirp
					cutBinaryImage = binaryImageCut(zeroPadingBinary, Width, tagCoordVector[i], tagCoordVector[i + 1], tagCoordVector[i + 2], tagCoordVector[i + 3], cutWidth, cutHeight);

																			// Moment hesapla
					calculateQ(cutBinaryImage, cutWidth, cutHeight, Qvalues);
																			// 7 Q degerini dosyaya yaz
					for (int i = 0; i < 7; i++)
					{
						outFile << Qvalues[i] << " ";
					}
																			// egitim yapilacak object adini textBox dan al ve dosyaya aktar
					std::string objectName = context.marshal_as<std::string>(objectNameTextB->Text);
					outFile << objectName << std::endl;
					Qvalues.clear();
				}
				outFile.close();
			}

			//////////////	TEST
			else if (testRadioButton->Checked == true)
			{

				std::vector <int> tagColorVector;
				calculateTagColors(tagVector, tagColorVector);

				richTextBoxObjects->Clear();
				totalDetectedNum->Text = "";

				int* cutBinaryImage;
				msclr::interop::marshal_context context;
				std::string QValue;
				std::string objectName;

				std::vector <double> objectQValues;
				std::vector <std::string> objectTagNames;

				std::ifstream inFile;
				inFile.open("db.txt");
																				// dosyadaki tum training sonuclarini oku
				while (true)
				{
					for (int i = 0; i < 7; i++)
					{
						inFile >> QValue;
						if (inFile.eof())break;
						objectQValues.push_back(std::stod(QValue));				// objectQValues -> her nesne icin 7 adet Q degeri depolar
					}

					inFile >> objectName;
					if (inFile.eof())break;
					objectTagNames.push_back(objectName);						// objectTagNames -> her nesnenin ismini depolar
				}

				std::vector <double> diffVec;
				std::vector <double> QVector;
				
				int colorValue = 0;												// her etiketlenen cisim icin tekrarla
				for (int i = 0; i < tagCoordVector.size(); i += 4)
				{
					int cutWidth = 0;
					int cutHeight = 0;
																				// tespit edilen cismin etiket koordinatlarini kullanarak, CCA uygulanmamis goruntu uzerinde kirp
					cutBinaryImage = binaryImageCut(zeroPadingBinary, Width, tagCoordVector[i], tagCoordVector[i + 1], tagCoordVector[i + 2], tagCoordVector[i + 3], cutWidth, cutHeight);
																				// Moment hesapla
					calculateQ(cutBinaryImage, cutWidth, cutHeight, QVector);

					double diffSum = 0.0;
					for (int i = 0; i < objectQValues.size(); i += 7)
					{
						diffSum += System::Math::Abs(objectQValues[i] - QVector[0]);
						diffSum += System::Math::Abs(objectQValues[i + 1] - QVector[1]);
						diffSum += System::Math::Abs(objectQValues[i + 2] - QVector[2]);
						diffSum += System::Math::Abs(objectQValues[i + 3] - QVector[3]);
						diffSum += System::Math::Abs(objectQValues[i + 4] - QVector[4]);
						diffSum += System::Math::Abs(objectQValues[i + 5] - QVector[5]);
						diffSum += System::Math::Abs(objectQValues[i + 6] - QVector[6]);

																				// Hesaplanan Q degerleri ile db daki her nesne icin farklarini depola
						diffVec.push_back(diffSum);								
						diffSum = 0.0;
					}

					double minValue = vecMinValueDouble(diffVec);				// Cismin Q degerleri ile db daki farki min olani bul
																				// min farka sahip olan nesne ismini richTBox a aktar
					colorValue = tagColorVector[i / 4];							// detect edilen nesneler ile ayni renkte text color belirle
					richTextBoxObjects->SelectionColor = System::Drawing::Color::FromArgb(colorValue, (colorValue * colorValue) % 255, (colorValue * colorValue * colorValue) % 255);
					String^ detectionName = context.marshal_as<String^>(objectTagNames[vecValueIndexDouble(diffVec, minValue)]);
					richTextBoxObjects->AppendText(detectionName + "\n");
					
																				// toplam tespit edilen nesne miktari
					totalDetectedNum->Text = (System::String^)(tagCoordVector.size()/4).ToString();		
					
					QVector.clear();
					diffVec.clear();
				}
				inFile.close();

			}
		}
	}
	private: System::Void chart1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void chart1_Click_1(System::Object^ sender, System::EventArgs^ e) {
	}
	};
}