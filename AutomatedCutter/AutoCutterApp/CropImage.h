#pragma once
#include "stdafx.h"
namespace AutoCutterApp {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for CropImage
	/// </summary>
	public ref class CropImage : public System::Windows::Forms::Form
	{
	public:
		CropImage(IImageInterface& pImageInterface) : _imageProcessor(pImageInterface)
		{
			InitializeComponent();
			IImageContainer& imageContainer = _imageProcessor.GetImage();
			Image->Width = imageContainer.GetWidth();
			Image->Height = imageContainer.GetHeight();
			this->Width = imageContainer.GetWidth() + 50;
			this->Height = imageContainer.GetHeight() + 50;
			//FormHelper::ShowImage(Image, _imageProcessor);	
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~CropImage()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  OKButton;
	private: System::Windows::Forms::Button^  ClearButton;
	private: System::Windows::Forms::Button^  CancelButton;
	private: System::Windows::Forms::FlowLayoutPanel^  flowLayoutPanel1;
	private: System::Windows::Forms::PictureBox^  Image;

	protected: 

	protected: 

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;
		
		IImageInterface& _imageProcessor;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->OKButton = (gcnew System::Windows::Forms::Button());
			this->ClearButton = (gcnew System::Windows::Forms::Button());
			this->CancelButton = (gcnew System::Windows::Forms::Button());
			this->flowLayoutPanel1 = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->Image = (gcnew System::Windows::Forms::PictureBox());
			this->flowLayoutPanel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->Image))->BeginInit();
			this->SuspendLayout();
			// 
			// OKButton
			// 
			this->OKButton->Location = System::Drawing::Point(3, 3);
			this->OKButton->Name = L"OKButton";
			this->OKButton->Size = System::Drawing::Size(75, 23);
			this->OKButton->TabIndex = 0;
			this->OKButton->Text = L"OK";
			this->OKButton->UseVisualStyleBackColor = true;
			this->OKButton->Click += gcnew System::EventHandler(this, &CropImage::OKButton_Click);
			// 
			// ClearButton
			// 
			this->ClearButton->Location = System::Drawing::Point(84, 3);
			this->ClearButton->Name = L"ClearButton";
			this->ClearButton->Size = System::Drawing::Size(75, 23);
			this->ClearButton->TabIndex = 1;
			this->ClearButton->Text = L"Clear";
			this->ClearButton->UseVisualStyleBackColor = true;
			// 
			// CancelButton
			// 
			this->CancelButton->Location = System::Drawing::Point(165, 3);
			this->CancelButton->Name = L"CancelButton";
			this->CancelButton->Size = System::Drawing::Size(75, 23);
			this->CancelButton->TabIndex = 2;
			this->CancelButton->Text = L"Cancel";
			this->CancelButton->UseVisualStyleBackColor = true;
			// 
			// flowLayoutPanel1
			// 
			this->flowLayoutPanel1->Controls->Add(this->OKButton);
			this->flowLayoutPanel1->Controls->Add(this->ClearButton);
			this->flowLayoutPanel1->Controls->Add(this->CancelButton);
			this->flowLayoutPanel1->Location = System::Drawing::Point(12, 212);
			this->flowLayoutPanel1->Name = L"flowLayoutPanel1";
			this->flowLayoutPanel1->Size = System::Drawing::Size(246, 39);
			this->flowLayoutPanel1->TabIndex = 3;
			// 
			// Image
			// 
			this->Image->Location = System::Drawing::Point(12, 12);
			this->Image->Name = L"Image";
			this->Image->Size = System::Drawing::Size(246, 194);
			this->Image->TabIndex = 4;
			this->Image->TabStop = false;
			
			
			// 
			// CropImage
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(282, 253);
			this->Controls->Add(this->Image);
			this->Controls->Add(this->flowLayoutPanel1);
			this->Name = L"CropImage";
			this->Text = L"CropImage";
			this->flowLayoutPanel1->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->Image))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion

private: System::Void OKButton_Click(System::Object^  sender, System::EventArgs^  e) {

			 
		 }
};
}
