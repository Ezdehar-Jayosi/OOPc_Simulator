#pragma once

#include <stdio.h>
#include <iostream>
#include <vector>
#include <cstdlib>
#include "MyForm1.h"
#include "SOC.h"
#include <time.h>
/*Heat Map Numbers to compare to routers load
Numbers here are temporary
*/
enum { blue=30,orange=50};
//--------------------------------------------------//
bool* choosen_units = NULL;
int num_of_clicks = 0;
int total_routers = 0;
int main_unit_id = -1;
namespace Project1 {

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
			//TODO: Add the constructor code here
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
	private: System::Windows::Forms::Label^ label1;
	protected:
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button4;

	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Button^ button19;
	private:System::Windows::Forms::FlowLayoutPanel^ flowLayoutPanel1;
	private: System::Windows::Forms::Button^ button5;
	private: System::Windows::Forms::Button^ button6;
	private: System::Windows::Forms::Button^ button7;
	private: System::Windows::Forms::Button^ button8;
	private: System::Windows::Forms::Button^ button9;
	private: System::Windows::Forms::Button^ blue_with_unit;
	private: System::Windows::Forms::Button^ orange_with_unit;

	private: System::Windows::Forms::Button^ red_with_unit;
	private: System::Windows::Forms::Button^ red_button;
	private: System::Windows::Forms::Button^ orange_button;


	private: System::Windows::Forms::Button^ blue_button;









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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->button19 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->flowLayoutPanel1 = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->button8 = (gcnew System::Windows::Forms::Button());
			this->button9 = (gcnew System::Windows::Forms::Button());
			this->blue_with_unit = (gcnew System::Windows::Forms::Button());
			this->orange_with_unit = (gcnew System::Windows::Forms::Button());
			this->red_with_unit = (gcnew System::Windows::Forms::Button());
			this->red_button = (gcnew System::Windows::Forms::Button());
			this->orange_button = (gcnew System::Windows::Forms::Button());
			this->blue_button = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Arial Unicode MS", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::SystemColors::GrayText;
			this->label1->Location = System::Drawing::Point(276, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(187, 33);
			this->label1->TabIndex = 0;
			this->label1->Text = L"OOPc Simulator";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->label1->Click += gcnew System::EventHandler(this, &MyForm::label1_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(12, 88);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(64, 19);
			this->label2->TabIndex = 1;
			this->label2->Text = L"#Units:";
			this->label2->Click += gcnew System::EventHandler(this, &MyForm::label2_Click);
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(16, 306);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(193, 40);
			this->button1->TabIndex = 2;
			this->button1->Text = L"Build System";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// textBox1
			// 
			this->textBox1->ForeColor = System::Drawing::SystemColors::WindowFrame;
			this->textBox1->Location = System::Drawing::Point(107, 90);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(64, 20);
			this->textBox1->TabIndex = 3;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox1_TextChanged_1);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(12, 134);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(87, 19);
			this->label3->TabIndex = 4;
			this->label3->Text = L"#Threads:";
			// 
			// textBox3
			// 
			this->textBox3->ForeColor = System::Drawing::SystemColors::WindowFrame;
			this->textBox3->Location = System::Drawing::Point(107, 134);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(64, 20);
			this->textBox3->TabIndex = 6;
			this->textBox3->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox3_TextChanged_3);
			// 
			// button2
			// 
			this->button2->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button2->Location = System::Drawing::Point(16, 398);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(193, 40);
			this->button2->TabIndex = 7;
			this->button2->Text = L"Show Heat Map";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// button3
			// 
			this->button3->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button3->Location = System::Drawing::Point(16, 352);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(193, 40);
			this->button3->TabIndex = 8;
			this->button3->Text = L"Start Simulation";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(12, 171);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(178, 19);
			this->label4->TabIndex = 10;
			this->label4->Text = L"Total Simulation Time:";
			this->label4->Click += gcnew System::EventHandler(this, &MyForm::label4_Click);
			// 
			// textBox2
			// 
			this->textBox2->ForeColor = System::Drawing::SystemColors::WindowFrame;
			this->textBox2->Location = System::Drawing::Point(18, 202);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(64, 20);
			this->textBox2->TabIndex = 11;
			this->textBox2->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox2_TextChanged_2);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Arial", 8, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->Location = System::Drawing::Point(88, 208);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(44, 14);
			this->label5->TabIndex = 12;
			this->label5->Text = L"Cycles";
			// 
			// button19
			// 
			this->button19->Location = System::Drawing::Point(0, 0);
			this->button19->Name = L"button19";
			this->button19->Size = System::Drawing::Size(75, 23);
			this->button19->TabIndex = 0;
			this->button19->UseVisualStyleBackColor = true;
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(0, 0);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(75, 23);
			this->button4->TabIndex = 0;
			// 
			// flowLayoutPanel1
			// 
			this->flowLayoutPanel1->AutoScroll = true;
			this->flowLayoutPanel1->Location = System::Drawing::Point(279, 67);
			this->flowLayoutPanel1->Name = L"flowLayoutPanel1";
			this->flowLayoutPanel1->Size = System::Drawing::Size(200, 100);
			this->flowLayoutPanel1->TabIndex = 13;
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(0, 0);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(75, 23);
			this->button5->TabIndex = 0;
			// 
			// button6
			// 
			this->button6->Location = System::Drawing::Point(498, 68);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(94, 99);
			this->button6->TabIndex = 14;
			this->button6->Text = L"button6";
			this->button6->UseVisualStyleBackColor = true;
			// 
			// button7
			// 
			this->button7->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button7->Location = System::Drawing::Point(16, 260);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(193, 40);
			this->button7->TabIndex = 14;
			this->button7->Text = L"Choose Units";
			this->button7->UseVisualStyleBackColor = true;
			this->button7->Click += gcnew System::EventHandler(this, &MyForm::button7_Click);
			// 
			// button8
			// 
			this->button8->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button8.BackgroundImage")));
			this->button8->Location = System::Drawing::Point(548, 107);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(69, 64);
			this->button8->TabIndex = 15;
			this->button8->Text = L"button8";
			this->button8->UseVisualStyleBackColor = true;
			// 
			// button9
			// 
			this->button9->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button9.BackgroundImage")));
			this->button9->Location = System::Drawing::Point(548, 182);
			this->button9->Name = L"button9";
			this->button9->Size = System::Drawing::Size(69, 64);
			this->button9->TabIndex = 16;
			this->button9->Text = L"button9";
			this->button9->UseVisualStyleBackColor = true;
			// 
			// blue_with_unit
			// 
			this->blue_with_unit->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"blue_with_unit.BackgroundImage")));
			this->blue_with_unit->Location = System::Drawing::Point(560, 65);
			this->blue_with_unit->Name = L"blue_with_unit";
			this->blue_with_unit->Size = System::Drawing::Size(86, 87);
			this->blue_with_unit->TabIndex = 15;

			this->blue_with_unit->UseVisualStyleBackColor = true;
		
			// 
			// orange_with_unit
			// 
			this->orange_with_unit->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"orange_with_unit.BackgroundImage")));
			this->orange_with_unit->Location = System::Drawing::Point(332, 211);
			this->orange_with_unit->Name = L"orange_with_unit";
			this->orange_with_unit->Size = System::Drawing::Size(86, 87);
			this->orange_with_unit->TabIndex = 16;
			
			this->orange_with_unit->UseVisualStyleBackColor = true;
			
			// 
			// red_with_unit
			// 
			this->red_with_unit->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"red_with_unit.BackgroundImage")));
			this->red_with_unit->Location = System::Drawing::Point(476, 208);
			this->red_with_unit->Name = L"red_with_unit";
			this->red_with_unit->Size = System::Drawing::Size(86, 87);
			this->red_with_unit->TabIndex = 17;

			this->red_with_unit->UseVisualStyleBackColor = true;
			// 
			// red_button
			// 
			this->red_button->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"red_button.BackgroundImage")));
			this->red_button->Location = System::Drawing::Point(522, 355);
			this->red_button->Name = L"red_button";
			this->red_button->Size = System::Drawing::Size(86, 87);
			this->red_button->TabIndex = 18;
			this->red_button->UseVisualStyleBackColor = true;
			// 
			// orange_button
			// 
			this->orange_button->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"orange_button.BackgroundImage")));
			this->orange_button->Location = System::Drawing::Point(393, 330);
			this->orange_button->Name = L"orange_button";
			this->orange_button->Size = System::Drawing::Size(86, 87);
			this->orange_button->TabIndex = 19;
			this->orange_button->UseVisualStyleBackColor = true;
			// 
			// blue_button
			// 
			this->blue_button->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"blue_button.BackgroundImage")));
			this->blue_button->Location = System::Drawing::Point(601, 238);
			this->blue_button->Name = L"blue_button";
			this->blue_button->Size = System::Drawing::Size(86, 87);
			this->blue_button->TabIndex = 20;
			this->blue_button->UseVisualStyleBackColor = true;
			
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoScroll = true;
			this->ClientSize = System::Drawing::Size(750, 508);
			/*this->Controls->Add(this->blue_button);
			this->Controls->Add(this->orange_button);
			this->Controls->Add(this->red_button);
			this->Controls->Add(this->red_with_unit);
			this->Controls->Add(this->orange_with_unit);
			this->Controls->Add(this->blue_with_unit);*/
			this->Controls->Add(this->button7);
			this->Controls->Add(this->flowLayoutPanel1);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Name = L"MyForm";
			this->Text = L"OOPc Simulator";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		int num_of_units, num_of_threads, simulation_duration, num_of_routers, routers_per_line;
		int counter = 0;
		bool show_heat_map = false, build_system = false, start_simulation = false;
		int** unit_rate_arr = NULL;
		SystemOnAChip* system;
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}

	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
		System::Windows::Forms::Control::ControlCollection^ controls = flowLayoutPanel1->Controls;
		controls->Clear();
		//std::cout << choosen_units[0] << choosen_units[1] << choosen_units[2] << choosen_units[3] << std::endl;
		Double num_of_buttons = ceil(sqrt(num_of_units));
		routers_per_line = num_of_buttons;
		//std::cout << num_of_buttons << std::endl;
		this->flowLayoutPanel1->Size = System::Drawing::Size((num_of_buttons + 1) * 100, (num_of_buttons + 1) * 97);
		this->flowLayoutPanel1->AutoScroll = true;
		int i = 0;
		int total = pow(num_of_buttons, 2);

		total_routers = total;
		num_of_routers = total;
		//this->flowLayoutPanel1->Size = System::Drawing::Size(100,1000);
		//this->ClientSize = System::Drawing::Size(2000, 508 + num_of_buttons * 97);
		while (i < total) {
			System::Windows::Forms::Button^ new_button = (gcnew System::Windows::Forms::Button());
			new_button->Name = System::Convert::ToString(i);
			new_button->Size = System::Drawing::Size(100, 97);
			//new_button->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button19.BackgroundImage")));
			//new_button->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button6.BackgroundImage")));
			//if (i < num_of_units) {
			if (choosen_units[i]) {
				new_button->Click += gcnew System::EventHandler(this, &MyForm::unit_button_Click);
				new_button->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button9.BackgroundImage")));
			}
			else {
				new_button->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button8.BackgroundImage")));
			}
			//
			flowLayoutPanel1->Controls->Add(new_button);

			i++;

		}
		this->Controls->Add(this->button3);
	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		vector<int>* heat_map = generateHeatMap();
	}
		   // DONE	
	private: System::Void textBox1_TextChanged_1(System::Object^ sender, System::EventArgs^ e) {
		//printf("hi we are here");
		//REMOVE CONTROlS
		System::Windows::Forms::Control::ControlCollection^ controls = flowLayoutPanel1->Controls;
		controls->Clear();
		TextBox^ unit_box = safe_cast<TextBox^>(sender);
		num_of_units = int::Parse(unit_box->Text);
		//std::cout << num_of_units << std::endl;
		unit_rate_arr = new int* [total_routers]; //ADDED ARRAY OF RATES
		//printf("here 2\n");
		Double num_of_buttons = ceil(sqrt(num_of_units));
		int total = pow(num_of_buttons, 2);
		total_routers = total;
		for (int i = 0; i < total_routers; ++i) {
			unit_rate_arr[i] = new int[total_routers];
			for (int j = 0; j < total_routers; j++) {
				unit_rate_arr[i][j] = -1;
				//std::cout << "unit rate arr in " << i << j << " " << unit_rate_arr[i][j] << "this is the rate in unit" << std::endl;
			}
			//choosen_units[i] = false;
		}
		//Double num_of_buttons = ceil(sqrt(num_of_units));
		//int total = pow(num_of_buttons, 2);
		choosen_units = new bool[total];
		for (int i = 0; i < total; i++) {
			choosen_units[i] = false;
		}
	}
		   // DONE
	private: System::Void textBox3_TextChanged_3(System::Object^ sender, System::EventArgs^ e) {// DONE

		TextBox^ thread_box = safe_cast<TextBox^>(sender);
		num_of_threads = int::Parse(thread_box->Text);
		//std::cout << num_of_threads << std::endl;
	}
		   // DONE
	private: System::Void textBox2_TextChanged_2(System::Object^ sender, System::EventArgs^ e) { //DONE

		TextBox^ cycles_box = safe_cast<TextBox^>(sender);
		simulation_duration = int::Parse(cycles_box->Text);
		//std::cout << simulation_duration << std::endl;
	}


	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
		std::vector<pair<int, int>> unit_cords = getUnitCords(system->getSystemTopology());
		/*std::cout << "here we have the system topology: " << std::endl;
		for (int i = 0; i < unit_cords.size(); i++) {
			std::cout << unit_cords[i].first << "    " << unit_cords[i].second << std::endl;
		}*/
		system->print();
		startSimulation(unit_cords);
		this->Controls->Add(this->button2);
		//delete unit_cords
	}

	private: System::Void label4_Click(System::Object^ sender, System::EventArgs^ e) {
	}
		   //DOING NOW
		   /*
		   * TODO LIST:
		   * ADD A ARR OF RATES --- DONE UP
		   * SHOW A POPUP WINDOW WHEN THE UNIT BUTTON IS CLICKED.
		   * USE FLOWLAYOUTPANEL TO MAKE A LIST OF THE OTHER UNITS TO WRITE THE RATE FROM THE CLICKED ON UNIT TO THEM.
		   * CHECK IF THAT WORKED
		   */
	private: System::Void unit_button_Click(System::Object^ sender, System::EventArgs^ e) {
		counter++;
		Button^ cycles_box = safe_cast<Button^>(sender);
		int unit_id = int::Parse(cycles_box->Name);
		//std::cout << "unit id is " << unit_id << std::endl;
		//std::cout << "   mmmm   unit rate index 0 is " << unit_rate_arr[unit_id][0] << std::endl;

		//int& main_unit_ptr = main_unit_id;
		Project1::MyForm1^ form = gcnew Project1::MyForm1(total_routers, unit_id, choosen_units, &(unit_rate_arr[unit_id]), &main_unit_id);
		//std::cout << "ok_clicked is " << OK_clicked << std::endl;
		form->ShowDialog();
		delete form;
		//form = nullptr;
		//std::cout << "ok_clicked is " << std::endl;
		for (int i = 0; i < total_routers; i++) {

			if (i != unit_id) {
				std::cout << "unit_rate_arr[" << unit_id << "][" << i << "] = " << unit_rate_arr[unit_id][i] << std::endl;
				///rate_arr[i] = -1;
			}


		}
		//std::cout << "hello" << std::endl;
		if (counter == num_of_units) {
			buildSystem();
		}
	}


	private: System::Void flowLayoutPanel1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	}
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {
	}

	private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void unit_button_Click2(System::Object^ sender, System::EventArgs^ e) {

		Button^ cycles_box = safe_cast<Button^>(sender);
		int unit_id = int::Parse(cycles_box->Name);
		choosen_units[unit_id] = true;
		//num_of_clicks++;
		//std::cout << "hello" << std::endl;
	}

	private: System::Void button7_Click(System::Object^ sender, System::EventArgs^ e) {  //CHOOSE UNITS BUTTON
		System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
		System::Windows::Forms::Control::ControlCollection^ controls = flowLayoutPanel1->Controls;
		controls->Clear();
		Double num_of_buttons = ceil(sqrt(num_of_units));
		//routers_per_line = num_of_buttons;
		//std::cout << num_of_buttons << std::endl;
		this->flowLayoutPanel1->Size = System::Drawing::Size((num_of_buttons + 1) * 35, (num_of_buttons + 1) * 35);
		this->flowLayoutPanel1->AutoScroll = true;
		int i = 0;

		//this->flowLayoutPanel1->Size = System::Drawing::Size(100,1000);
		//this->ClientSize = System::Drawing::Size(2000, 508 + num_of_buttons * 97);
		while (i < total_routers) {
			System::Windows::Forms::Button^ new_button = (gcnew System::Windows::Forms::Button());
			new_button->Name = System::Convert::ToString(i);
			new_button->Text = System::Convert::ToString(i);
			new_button->Size = System::Drawing::Size(35, 35);

			new_button->Click += gcnew System::EventHandler(this, &MyForm::unit_button_Click2);

			flowLayoutPanel1->Controls->Add(new_button);

			i++;
		}
		this->Controls->Add(this->button1);
	}
		   void buildSystem() {
			   std::vector<vector<Unit*>> system_topology;
			   int k = 0;
			   vector<pair<int, int>*>* active_units_cords = new vector<pair<int, int>*>();
			   for (int i = 0; i < routers_per_line; i++) {
				   std::vector<Unit*> vec;
				   for (int j = 0; j < routers_per_line; j++) {
					   Router router = Router(i, j, num_of_threads);
					   //std::cout << " the cords is: " << router->getCord_x() << router->getCord_y() << std::endl;
					   if (choosen_units[k]) {
						   pair<int, int>* curr_unit = new pair<int, int>();
						   curr_unit->first = i;
						   curr_unit->second = j;
						   active_units_cords->push_back(curr_unit);
						   //std::cout << "main_unit_id = " << main_unit_id << " && k+1 = " << k + 1 << std::endl;
						   if (main_unit_id == k) {
							   //std::cout << "main_unit_id: " << main_unit_id << " && routers_per_line: " << routers_per_line << std::endl;
							   Unit* new_unit = new Unit(i, j, router, true, num_of_threads);
							   //std::cout << "praavooooo" << std::endl;
							   vec.push_back(new_unit);
						   }
						   else {
							   Unit* new_unit = new Unit(i, j, router, false, num_of_threads); vec.push_back(new_unit);
							   //std::cout << " the cords is: " << (new_unit.getRouter())->getCord_x() << (new_unit.getRouter())->getCord_y() << std::endl;
						   }
					   }
					   else { Unit* new_unit = new Unit(-1, -1, router, false, num_of_threads); vec.push_back(new_unit); }
					   k++;
				   }
				   system_topology.push_back(vec);
			   }
			   //to initialize the routers
			   int border = routers_per_line - 1;
			   for (int i = 0; i < routers_per_line; i++) {
				   for (int j = 0; j < routers_per_line; j++) {
					   Unit* unit = system_topology[i][j];
					   if (i == 0) {
						   if (j == 0) {
							   (system_topology[i][j])->setRouterPorts((system_topology[i][j + 1])->getRouter(), nullptr, nullptr, (system_topology[i + 1][j])->getRouter(), unit);
						   }
						   else if (j == border) {
							   (system_topology[i][j])->setRouterPorts(nullptr, (system_topology[i][j - 1])->getRouter(), nullptr, (system_topology[i + 1][j])->getRouter(), unit);
						   }
						   else {
							   (system_topology[i][j])->setRouterPorts((system_topology[i][j + 1])->getRouter(), (system_topology[i][j - 1])->getRouter(), nullptr, (system_topology[i + 1][j])->getRouter(), unit);
						   }
					   }
					   else if (i == border) {
						   if (j == 0) {
							   (system_topology[i][j])->setRouterPorts((system_topology[i][j + 1])->getRouter(), nullptr, (system_topology[i - 1][j])->getRouter(), nullptr, unit);
						   }
						   else if (j == border) {
							   (system_topology[i][j])->setRouterPorts(nullptr, (system_topology[i][j - 1])->getRouter(), (system_topology[i - 1][j])->getRouter(), nullptr, unit);
						   }
						   else {
							   (system_topology[i][j])->setRouterPorts((system_topology[i][j + 1])->getRouter(), (system_topology[i][j - 1])->getRouter(), (system_topology[i - 1][j])->getRouter(), nullptr, unit);
						   }
					   }
					   else if (j == 0) {
						   if (i != border && i != 0) {
							   (system_topology[i][j])->setRouterPorts((system_topology[i][j + 1])->getRouter(), nullptr, (system_topology[i - 1][j])->getRouter(), (system_topology[i + 1][j])->getRouter(), unit);
						   }
					   }
					   else if (j == border) {
						   if (i != border && i != 0) {
							   (system_topology[i][j])->setRouterPorts(nullptr, (system_topology[i][j - 1])->getRouter(), (system_topology[i - 1][j])->getRouter(), (system_topology[i + 1][j])->getRouter(), unit);
						   }
					   }
					   else {
						   (system_topology[i][j])->setRouterPorts((system_topology[i][j + 1])->getRouter(), (system_topology[i][j - 1])->getRouter(), (system_topology[i - 1][j])->getRouter(), (system_topology[i + 1][j])->getRouter(), unit);
					   }
				   }
			   }
			   //unit_rate_arr
			   /*std::vector<vector<int>> rate(num_of_units);
			   int k = 0;
			   for (int i = 0; i < num_of_units; i++) {
				   rate[i] = vector<int>(num_of_units);
				   for (int j = 0; j < num_of_units; j++) {
					   rate[i][j] = (*unit_rate_arr)[k];
					   k++;
				   }
			   }*/
			   //  std::cout << " the main_unit is : " << main_unit_id << std::endl;
				 //print the system
				// system.print();
			   int** rates = unit_rate_arr;
			   for (int i = 0; i < total_routers; i++) {
				   for (int j = 0; j < total_routers; j++) {
					   //std::cout << " rate = " << rates[i][j] << "    ";
				   }
				   //std::cout << std::endl;
			   }
			   int unit_index = 0;
			   for (int i = 0; i < system_topology.size(); i++) {
				   for (int j = 0; j < system_topology[0].size(); j++) {
					   (system_topology[i][j])->set_units_rates(rates, system_topology.size(), unit_index);
					   (system_topology[i][j])->set_active_units(active_units_cords);
					   unit_index++;
				   }
			   }
			   system = new SystemOnAChip(system_topology, rates, num_of_units, num_of_routers);
			   system->set_num_cycles(simulation_duration);
		   }
		   string getRandPacket(std::vector<pair<int, int>>& units_cords) {
			   int index = rand() % (units_cords.size());
			   std::vector<int> result;
			   string packet;
			   packet.push_back(units_cords[index].first + '0');
			   packet.push_back(units_cords[index].second + '0');
			   //std::cout << "hhhhhh the packet is :  " << packet << std::endl;
			   return packet;
		   }
		   std::vector<pair<int, int>> getUnitCords(std::vector<vector<Unit*>> system_topology) {
			   std::vector<pair<int, int>>* result = new vector<pair<int, int>>();
			   for (int i = 0; i < system_topology.size(); i++) {
				   for (int j = 0; j < system_topology[0].size(); j++) {
					   if ((system_topology[i][j])->getCord_x() != -1) {
						   pair<int, int>* curr = new pair<int, int>();
						   curr->first = (system_topology[i][j])->getCord_x();
						   curr->second = (system_topology[i][j])->getCord_y();
						   std::cout << "first is : " << curr->first << " second is : " << curr->second << std::endl;
						   result->push_back(*curr);
					   }
				   }
			   }
			   return *result;
		   }

		   void startSimulation(std::vector<pair<int, int>>& unit_cords) {
			   vector<vector<Unit*>> topology = system->getSystemTopology();
			   Unit* leader_unit = system->getLeaderUnit();
			   Router* leader_unit_router = leader_unit->getRouter();
			   int num_of_clocks = 0;
			
			   for (int i = 0; i < topology.size(); i++) {
				   for (int j = 0; j < topology[0].size(); j++) {
					   if (topology[i][j]->getCord_x() != -1) topology[i][j]->start_thread(simulation_duration);
				   }
			   }
			   std::cout << " started simulation .... " << std::endl;
			  
			   while (simulation_duration) {
				   simulation_did_not_start = true;
				   string new_packet = getRandPacket(unit_cords);
				   leader_unit_router->receive_packet(new_packet);
				
				   simulation_duration--;

			   }
			   time_out_flag = true;
			   std::cout << "Simulation ended ... num of clocks is " << num_of_clocks << std::endl;
			 
		   }
		   vector<int>* generateHeatMap() {
			 
			   vector<vector<Unit*>> topology = system->getSystemTopology();
			   std::cout << "heat map: " << std::endl;
			 
			   vector<int>* heat_map = new vector<int>();
			   for (int i = 0; i < topology.size(); i++) {
				   for (int j = 0; j < topology[0].size(); j++) {
					 
					   if (topology[i][j]->getCord_x() != -1) {
						   std::cout << "Unit of cord: (" << topology[i][j]->getCord_y() << "," << topology[i][j]->getCord_y() << ") sent " << topology[i][j]->NumSentPackets() << " packets and recieved "
							   << topology[i][j]->NumRecievedPacket() << std::endl;
					   }

					   std::cout << "Router of cord: (" << topology[i][j]->getRouter()->getCord_x() << "," << topology[i][j]->getRouter()->getCord_y() << ") sent " << topology[i][j]->getRouter()->numOfSentPackets() << " packets and recieved "
						   << topology[i][j]->getRouter()->numOfReceivedPackets() << std::endl;
					   int load = topology[i][j]->getRouter()->numOfReceivedPackets() - topology[i][j]->getRouter()->numOfSentPackets();
					   heat_map->push_back(load);
					   std::cout << " " << load;


				   }
			   }
			   std::cout << std::endl;
			   return heat_map;
		   }

		   /* colored System based on the numbers in heatmap*/
		   void color_button(System::Windows::Forms::Button^ button, int router_load,bool withUnit) {
			   System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));

			   if (router_load <= blue) {
				   if (withUnit) {
					   button->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"blue_with_unit.BackgroundImage")));
				   }
				   else {
					   button->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"blue_button.BackgroundImage")));

				   }
			   }
			   else if (router_load > blue && router_load <= orange) {
				   if (withUnit) {
						button->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"orange_with_unit.BackgroundImage")));
				   }
				   else {
					   button->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"orange_button.BackgroundImage")));

				   }
			   }
			   else if (router_load > orange) {
				   if (withUnit) {
						button->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"red_with_unit.BackgroundImage")));
				   }
				   else {
					   button->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"red_button.BackgroundImage")));

				   }
			   }

		   }
			void createHeatMap(vector<int>* heat_map) {
				System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
				System::Windows::Forms::Control::ControlCollection^ controls = flowLayoutPanel1->Controls;
				controls->Clear();
				Double num_of_buttons = ceil(sqrt(num_of_units));
				routers_per_line = num_of_buttons;
				this->flowLayoutPanel1->Size = System::Drawing::Size((num_of_buttons + 1) * 100, (num_of_buttons + 1) * 97);
				this->flowLayoutPanel1->AutoScroll = true;
				int i = 0;
				int total = pow(num_of_buttons, 2);

				total_routers = total;
				num_of_routers = total;
				while (i < total) {
					System::Windows::Forms::Button^ new_button = (gcnew System::Windows::Forms::Button());
					new_button->Name = System::Convert::ToString(i);
					new_button->Size = System::Drawing::Size(100, 97);
					if (choosen_units[i]) {
						color_button(new_button, heat_map->at(i),true );
					}
					else {
						color_button(new_button, heat_map->at(i), false);
					}
					
					flowLayoutPanel1->Controls->Add(new_button);

					i++;

				}
				
			}
	


};
}
