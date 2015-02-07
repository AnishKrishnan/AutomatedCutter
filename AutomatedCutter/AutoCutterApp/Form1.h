#pragma once
#include "stdafx.h"
#include "CropImage.h"
#include "ScaleCalculator.h"
#include "Packet.h"

namespace AutoCutterApp {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//

			imageProcessor = new OpenCVImageProcessing();
			configManager = ConfigurationManager::instance();
			log = Logger::instance();
			if(!configManager)
			{
				throw AutoCutterException("Could not find configuration manager");
			}
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::OpenFileDialog^  openFileDialog;
	private: System::ComponentModel::IContainer^  components;







	protected: 

	protected: 

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>

	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::FlowLayoutPanel^  flowLayoutPanel1;
	private: System::Windows::Forms::Button^  button2;
	private: System::ComponentModel::BackgroundWorker^  imageProcessorWorker;
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::TrackBar^  trackBar1;
	private: System::Windows::Forms::TextBox^  FrameWidth;
	private: System::Windows::Forms::Label^  FrameWidthLabel;
	private: System::Windows::Forms::Button^  ExecuteButton;
	private: System::Windows::Forms::TextBox^  FrameHeight;
	private: System::Windows::Forms::Label^  FrameHeightLabel;




			 IImageInterface* imageProcessor;
			 ConfigurationManager* configManager;
	private: System::IO::Ports::SerialPort^  serialComms;

			 Logger* log;
		

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->openFileDialog = (gcnew System::Windows::Forms::OpenFileDialog());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->flowLayoutPanel1 = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->ExecuteButton = (gcnew System::Windows::Forms::Button());
			this->FrameWidthLabel = (gcnew System::Windows::Forms::Label());
			this->FrameWidth = (gcnew System::Windows::Forms::TextBox());
			this->FrameHeightLabel = (gcnew System::Windows::Forms::Label());
			this->FrameHeight = (gcnew System::Windows::Forms::TextBox());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->trackBar1 = (gcnew System::Windows::Forms::TrackBar());
			this->imageProcessorWorker = (gcnew System::ComponentModel::BackgroundWorker());
			this->serialComms = (gcnew System::IO::Ports::SerialPort(this->components));
			this->flowLayoutPanel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->trackBar1))->BeginInit();
			this->SuspendLayout();
			// 
			// openFileDialog
			// 
			this->openFileDialog->FileName = L"imageFile";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(3, 3);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(101, 44);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Open File";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// flowLayoutPanel1
			// 
			this->flowLayoutPanel1->Controls->Add(this->button1);
			this->flowLayoutPanel1->Controls->Add(this->button2);
			this->flowLayoutPanel1->Controls->Add(this->ExecuteButton);
			this->flowLayoutPanel1->Controls->Add(this->FrameWidthLabel);
			this->flowLayoutPanel1->Controls->Add(this->FrameWidth);
			this->flowLayoutPanel1->Controls->Add(this->FrameHeightLabel);
			this->flowLayoutPanel1->Controls->Add(this->FrameHeight);
			this->flowLayoutPanel1->Controls->Add(this->pictureBox1);
			this->flowLayoutPanel1->Controls->Add(this->trackBar1);
			this->flowLayoutPanel1->Location = System::Drawing::Point(1, 3);
			this->flowLayoutPanel1->Name = L"flowLayoutPanel1";
			this->flowLayoutPanel1->Size = System::Drawing::Size(863, 450);
			this->flowLayoutPanel1->TabIndex = 3;
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(110, 3);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(101, 44);
			this->button2->TabIndex = 2;
			this->button2->Text = L"Get Outlines";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
			// 
			// ExecuteButton
			// 
			this->ExecuteButton->Location = System::Drawing::Point(217, 3);
			this->ExecuteButton->Name = L"ExecuteButton";
			this->ExecuteButton->Size = System::Drawing::Size(101, 44);
			this->ExecuteButton->TabIndex = 7;
			this->ExecuteButton->Text = L"Execute";
			this->ExecuteButton->UseVisualStyleBackColor = true;
			this->ExecuteButton->Click += gcnew System::EventHandler(this, &Form1::ExecuteButton_Click);
			// 
			// FrameWidthLabel
			// 
			this->FrameWidthLabel->AutoSize = true;
			this->FrameWidthLabel->Location = System::Drawing::Point(324, 0);
			this->FrameWidthLabel->Name = L"FrameWidthLabel";
			this->FrameWidthLabel->Size = System::Drawing::Size(88, 17);
			this->FrameWidthLabel->TabIndex = 6;
			this->FrameWidthLabel->Text = L"Frame Width";
			// 
			// FrameWidth
			// 
			this->FrameWidth->Location = System::Drawing::Point(418, 3);
			this->FrameWidth->Name = L"FrameWidth";
			this->FrameWidth->Size = System::Drawing::Size(99, 22);
			this->FrameWidth->TabIndex = 5;
			// 
			// FrameHeightLabel
			// 
			this->FrameHeightLabel->AutoSize = true;
			this->FrameHeightLabel->Location = System::Drawing::Point(523, 0);
			this->FrameHeightLabel->Name = L"FrameHeightLabel";
			this->FrameHeightLabel->Size = System::Drawing::Size(93, 17);
			this->FrameHeightLabel->TabIndex = 9;
			this->FrameHeightLabel->Text = L"Frame Height";
			// 
			// FrameHeight
			// 
			this->FrameHeight->Location = System::Drawing::Point(622, 3);
			this->FrameHeight->Name = L"FrameHeight";
			this->FrameHeight->Size = System::Drawing::Size(99, 22);
			this->FrameHeight->TabIndex = 8;
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(3, 53);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(653, 397);
			this->pictureBox1->TabIndex = 3;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->DoubleClick += gcnew System::EventHandler(this, &Form1::pictureBox1_DoubleClick);
			// 
			// trackBar1
			// 
			this->trackBar1->Location = System::Drawing::Point(662, 53);
			this->trackBar1->Maximum = 255;
			this->trackBar1->Name = L"trackBar1";
			this->trackBar1->Orientation = System::Windows::Forms::Orientation::Vertical;
			this->trackBar1->Size = System::Drawing::Size(56, 191);
			this->trackBar1->TabIndex = 4;
			this->trackBar1->Value = 100;
			this->trackBar1->Scroll += gcnew System::EventHandler(this, &Form1::trackBar1_Scroll);
			// 
			// imageProcessorWorker
			// 
			this->imageProcessorWorker->DoWork += gcnew System::ComponentModel::DoWorkEventHandler(this, &Form1::imageProcessorWorker_DoWork);
			this->imageProcessorWorker->RunWorkerCompleted += gcnew System::ComponentModel::RunWorkerCompletedEventHandler(this, &Form1::imageProcessorWorker_WorkerCompleted);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(866, 454);
			this->Controls->Add(this->flowLayoutPanel1);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->flowLayoutPanel1->ResumeLayout(false);
			this->flowLayoutPanel1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->trackBar1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion

	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
				 if(openFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK)
				 {
					 
					 msclr::interop::marshal_context context;
					 std::string fileName = context.marshal_as<std::string>(openFileDialog->FileName);
					 imageProcessor->OpenFile(fileName);
					 
					 FormHelper::ShowImage(pictureBox1, *imageProcessor);

				 }
			 }

	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {

				 if(imageProcessor)
				 {
					 imageProcessorWorker->RunWorkerAsync();
				 }
			 }
	private: System::Void imageProcessorWorker_DoWork(System::Object^  sender, System::ComponentModel::DoWorkEventArgs^  e) {

				 imageProcessor->FindOutlines();
				 imageProcessor->DrawOutlines();
			 
			 }

	private: System::Void imageProcessorWorker_WorkerCompleted(System::Object^ sender, System::ComponentModel::RunWorkerCompletedEventArgs^  e){

				 FormHelper::ShowImage(pictureBox1, *imageProcessor);

			 }

private: System::Void trackBar1_Scroll(System::Object^  sender, System::EventArgs^  e) {

		 }

private: System::Void pictureBox1_DoubleClick(System::Object^  sender, System::EventArgs^  e) {
			 CropImage^ cropImage = gcnew CropImage(*imageProcessor);
			 cropImage->Show();
		 }
private: System::Void ExecuteButton_Click(System::Object^  sender, System::EventArgs^  e) {

			 double boundingWidth = 0.0, boundingHeight = 0.0;

			 if(!Double::TryParse(FrameWidth->Text, boundingWidth))
			 {
				 MessageBox::Show("Frame width not a valid number", "",MessageBoxButtons::OK, MessageBoxIcon::Error);
				 return;
			 }

			 double maxWidth = atof(configManager->getValue("MaxImageWidth").c_str());
			 if(boundingWidth <= 0.0 || boundingWidth > maxWidth)
			 {
				 MessageBox::Show("Frame width is not within valid bounds", "",MessageBoxButtons::OK, MessageBoxIcon::Error);
				 return;
			 }
			
			 if(!Double::TryParse(FrameHeight->Text, boundingHeight))
			 {
				 MessageBox::Show("Frame height not a valid number", "",MessageBoxButtons::OK, MessageBoxIcon::Error);
				 return;
			 }

			 double maxHeight = atof(configManager->getValue("MaxImageHeight").c_str());
			 if(boundingHeight <= 0.0 || boundingHeight > maxHeight)
			 {
				 MessageBox::Show("Frame height is not within valid bounds", "",MessageBoxButtons::OK, MessageBoxIcon::Error);
				 return;
			 }

			 vector<vector<CustomPoint3d<int>>> temp = imageProcessor->GetLines();
			 ScaleCalculator<int,float> scaleCalculator(imageProcessor->GetBoundingBox().GetWidth(), boundingWidth);
			 
			 vector<vector<CustomPoint3d<float>>> scaledTemp;
			 for(int i = 0; i < temp.size(); i++)
			 {
				 scaledTemp.push_back(scaleCalculator.ScalePointsList(temp[i]));
			 }

			 Packet p;
			 p.SetPacketType(PACKETTYPE_ACK);
			 char* testString = "Stuff";
			 vector<char> testStringVector(testString, testString + sizeof(testString) / sizeof(char));

			 char* rawPacket = p.ConstructPacket(testStringVector);
			 int x = sizeof(rawPacket);
			 vector<char> inputPacketTest(rawPacket, rawPacket + 18/sizeof(char));
			 Packet p2;
			 p2.TryParseDataToPacket(inputPacketTest);

		 }
};


}

