#pragma once

#include <fstream>
#include "msclr/marshal_cppstd.h"


namespace LOGINVENTANAS {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de cambioContrasena
	/// </summary>
	public ref class cambioContrasena : public System::Windows::Forms::Form
	{
	public:
		cambioContrasena(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~cambioContrasena()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	protected:
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Button^ bEnviar;


	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->bEnviar = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(436, 147);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(44, 16);
			this->label1->TabIndex = 0;
			this->label1->Text = L"label1";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(438, 200);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(171, 22);
			this->textBox1->TabIndex = 1;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(439, 345);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(170, 22);
			this->textBox2->TabIndex = 2;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(435, 279);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(151, 20);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Repetir contraseña";
			// 
			// bEnviar
			// 
			this->bEnviar->Location = System::Drawing::Point(439, 409);
			this->bEnviar->Name = L"bEnviar";
			this->bEnviar->Size = System::Drawing::Size(108, 43);
			this->bEnviar->TabIndex = 4;
			this->bEnviar->Text = L"Enviar";
			this->bEnviar->UseVisualStyleBackColor = true;
			this->bEnviar->Click += gcnew System::EventHandler(this, &cambioContrasena::bEnviar_Click);
			// 
			// cambioContrasena
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1019, 531);
			this->Controls->Add(this->bEnviar);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label1);
			this->Name = L"cambioContrasena";
			this->Text = L"cambioContrasena";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void bEnviar_Click(System::Object^ sender, System::EventArgs^ e) {
		//label1->Text = usuario;
		MessageBox::Show("Aquí saldrá elnombre del usuario \n y pediré que ingrese la nueva contraseña");
	};
};
}
