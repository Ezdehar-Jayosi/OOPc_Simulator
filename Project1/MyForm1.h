#pragma once

#include <iostream>

int mainUnitId = -1;
//extern bool OK_clicked = false;
int** rate_arr;
namespace Project1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm1
	/// </summary>
	public ref class MyForm1 : public System::Windows::Forms::Form
	{
	public:
		int num_of_units; //ADDED NUMBER OF UNITS

		int curr_unit_id;
		bool* units = NULL;
		int* main_unit_id;
		/*MyForm1(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}*/
		MyForm1(int inUnits, int currID, bool* choosen_units, int** unit_rate, int* main_unit)
		{
			this->num_of_units = inUnits;
			rate_arr = unit_rate;
			//	std::cout << "unit rate index 0 is " << unitclick_rate[0] << std::endl;
				//units = new bool[this->num_of_units];
			units = choosen_units;
			/*for (int i = 0; i <= num_of_units; i++) {
				//rate_arr[i] = -1;
				units[i] = choosen_units[i];
			}*/
			main_unit_id = main_unit;


			curr_unit_id = currID;
			InitializeComponent();

		}

		//int returnMainUnit() { return mainUnitId; }  //ADDED
	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm1()
		{

			if (components)
			{

				delete components;
			}

		}

	protected:

	private: System::Windows::Forms::Label^ label1;

	private: System::Windows::Forms::FlowLayoutPanel^ flowLayoutPanel1;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::CheckBox^ checkBox1;
	private: System::Windows::Forms::Button^ button1;


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
			std::cout << this->num_of_units << std::endl;
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->flowLayoutPanel1 = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			//this->flowLayoutPanel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(8, 23);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(262, 23);
			this->label1->TabIndex = 1;
			this->label1->Text = "Please enter the rate from unit " + System::Convert::ToString(curr_unit_id + 1) + " to other units\n such that the sum of them is 10";


			//
			//flowlayout
			//
			this->flowLayoutPanel1->AutoScroll = true;
			this->flowLayoutPanel1->Location = System::Drawing::Point(12, 63);
			this->flowLayoutPanel1->Name = L"flowLayoutPanel1";
			this->flowLayoutPanel1->TabIndex = 14;
			//this->flowLayoutPanel1->WrapContents = true;
			this->flowLayoutPanel1->FlowDirection = System::Windows::Forms::FlowDirection::LeftToRight;
			//this->flowLayoutPanel1->AutoSize = true;

			// 
			// MyForm1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(465, 370);
			//this->Controls->Add(this->checkBox1);
			//this->Controls->Add(this->label8);
			this->Controls->Add(this->flowLayoutPanel1);
			this->Controls->Add(this->label1);
			this->Name = L"MyForm1";
			this->Text = L"MyForm1";

			this->ResumeLayout(false);
			this->PerformLayout();


			System::Windows::Forms::Control::ControlCollection^ controls = flowLayoutPanel1->Controls;
			controls->Clear();
			this->flowLayoutPanel1->Size = System::Drawing::Size(320, 50 * (num_of_units / 2));
			//this->ClientSize = System::Drawing::Size(320, 100 * (num_of_units / 2) );
			int i = 0;
			while (i < num_of_units) {
				if ((i != curr_unit_id) && units[i] == true) {
					// 
					// label
					// 

					System::Windows::Forms::Label^ label = (gcnew System::Windows::Forms::Label());
					label->AutoSize = true;
					label->Font = (gcnew System::Drawing::Font(L"Arial", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
						static_cast<System::Byte>(177)));
					label->Name = "unit " + System::Convert::ToString(i + 1);
					label->Size = System::Drawing::Size(42, 16);
					label->TabIndex = 13;
					label->Text = System::Convert::ToString(curr_unit_id + 1) + "->" + System::Convert::ToString(i + 1);

					// 
					// textBox
					// 

					System::Windows::Forms::TextBox^ textBox = (gcnew System::Windows::Forms::TextBox());
					textBox->Name = System::Convert::ToString(i + 1);
					textBox->Size = System::Drawing::Size(53, 20);
					textBox->TabIndex = 12;
					textBox->TextChanged += gcnew System::EventHandler(this, &MyForm1::textBoxedChanged);
					flowLayoutPanel1->Controls->Add(label);
					flowLayoutPanel1->Controls->Add(textBox);

				}
				i++;
			}
			//
			// label8
			//
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Calibri", 8.5F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			//this->label8->Location = System::Drawing::Point(8, 36 * (num_of_units / 2));
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(85, 23);
			this->label8->TabIndex = 15;
			this->label8->Text = "Check the box if unit " + System::Convert::ToString(curr_unit_id) + " is the main Unit";
			//
			// checkBox1
			//
			this->checkBox1->AutoSize = true;
			//this->checkBox1->Location = System::Drawing::Point(101, 36 * (num_of_units / 2) + 3);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(15, 14);
			this->checkBox1->TabIndex = 16;
			this->checkBox1->UseVisualStyleBackColor = true;
			this->checkBox1->CheckedChanged += gcnew System::EventHandler(this, &MyForm1::checkBox1_CheckedChanged);
			this->AutoScroll = true;
			if (*main_unit_id == -1) {
				flowLayoutPanel1->Controls->Add(this->label8);
				flowLayoutPanel1->Controls->Add(this->checkBox1);
			}
			// 
			// button1
			// 
			/*this->button1->Location = System::Drawing::Point(197, 226);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 0;
			this->button1->Text = L"OK";
			this->button1->UseVisualStyleBackColor = true;
			*/
			//this->Controls->Add(this->button1);
			//this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		//DONE
	private: System::Void checkBox1_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		// mainUnitId = curr_unit_id;
		*(this->main_unit_id) = curr_unit_id;
		//std::cout << " the curr unit is: " << curr_unit_id << std::endl;
	}

	private: System::Void textBoxedChanged(System::Object^ sender, System::EventArgs^ e) {
		TextBox^ thread_box = safe_cast<TextBox^>(sender);
		int unit_id = int::Parse(thread_box->Name);
		int rate_value = int::Parse(thread_box->Text);
		//std::cout << unit_id << " value is " << rate_value << std::endl;
		//std::cout << "unit id is " << unit_id << "rate is " << rate_value << std::endl;
		(*rate_arr)[unit_id - 1] = rate_value;

	}
	};
}
