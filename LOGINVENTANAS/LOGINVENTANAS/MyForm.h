#pragma once

#include <fstream>
#include "msclr/marshal_cppstd.h"
#include "ACCESO.h"
#include "NUEVOUSUARIO.h"
#include "NUEVACONTRA.h"
#include <mysql.h>
#include <Windows.h>


namespace LOGINVENTANAS {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
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
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::LinkLabel^ eOlvido;
	protected:

	private: System::Windows::Forms::Button^ bEntrada;
	private: System::Windows::Forms::TextBox^ nombreUsuario;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ contrasena;
	private: System::Windows::Forms::LinkLabel^ eCrear;



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
			this->eOlvido = (gcnew System::Windows::Forms::LinkLabel());
			this->bEntrada = (gcnew System::Windows::Forms::Button());
			this->nombreUsuario = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->contrasena = (gcnew System::Windows::Forms::TextBox());
			this->eCrear = (gcnew System::Windows::Forms::LinkLabel());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(547, 159);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(124, 20);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Nombre Usuario";
			// 
			// eOlvido
			// 
			this->eOlvido->AutoSize = true;
			this->eOlvido->Location = System::Drawing::Point(547, 442);
			this->eOlvido->Name = L"eOlvido";
			this->eOlvido->Size = System::Drawing::Size(220, 20);
			this->eOlvido->TabIndex = 1;
			this->eOlvido->TabStop = true;
			this->eOlvido->Text = L"¿Has olvidado tu contraseña\?";
			this->eOlvido->LinkClicked += gcnew System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, &MyForm::eOlvido_LinkClicked);
			// 
			// bEntrada
			// 
			this->bEntrada->Location = System::Drawing::Point(550, 536);
			this->bEntrada->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->bEntrada->Name = L"bEntrada";
			this->bEntrada->Size = System::Drawing::Size(125, 88);
			this->bEntrada->TabIndex = 2;
			this->bEntrada->Text = L"Enviar";
			this->bEntrada->UseVisualStyleBackColor = true;
			this->bEntrada->Click += gcnew System::EventHandler(this, &MyForm::bEntrada_Click);
			// 
			// nombreUsuario
			// 
			this->nombreUsuario->Location = System::Drawing::Point(550, 198);
			this->nombreUsuario->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->nombreUsuario->Name = L"nombreUsuario";
			this->nombreUsuario->Size = System::Drawing::Size(355, 26);
			this->nombreUsuario->TabIndex = 3;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(547, 309);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(92, 20);
			this->label2->TabIndex = 4;
			this->label2->Text = L"Contraseña";
			// 
			// contrasena
			// 
			this->contrasena->Location = System::Drawing::Point(550, 349);
			this->contrasena->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->contrasena->Name = L"contrasena";
			this->contrasena->Size = System::Drawing::Size(112, 26);
			this->contrasena->TabIndex = 5;
			// 
			// eCrear
			// 
			this->eCrear->AutoSize = true;
			this->eCrear->Location = System::Drawing::Point(853, 442);
			this->eCrear->Name = L"eCrear";
			this->eCrear->Size = System::Drawing::Size(101, 20);
			this->eCrear->TabIndex = 6;
			this->eCrear->TabStop = true;
			this->eCrear->Text = L"Crear cuenta";
			this->eCrear->LinkClicked += gcnew System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, &MyForm::eCrear_LinkClicked);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1933, 1021);
			this->Controls->Add(this->eCrear);
			this->Controls->Add(this->contrasena);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->nombreUsuario);
			this->Controls->Add(this->bEntrada);
			this->Controls->Add(this->eOlvido);
			this->Controls->Add(this->label1);
			this->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->Name = L"MyForm";
			this->Text = L"Curso C++";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void bEntrada_Click(System::Object^ sender, System::EventArgs^ e) {


		MYSQL* conectar;
		MYSQL_RES* resultado;
		MYSQL_ROW fila;

		//variable string c++ para buscar si estiste el fichero con el nombre del usuario
		std::string leoArchivo = msclr::interop::marshal_as < std::string>(nombreUsuario->Text);

		//a la variable fichero le asigno el nombre del fichero del ususario
		std::ifstream fichero(leoArchivo + ".txt");

		//compruebo que exista el fichero del usuario
		if (fichero.is_open()) {
			//creo la variable leoContrasena y le asigno la contraseña que hay en el archivo .txt
			std::string leoContrasena;
			fichero >> leoContrasena;

			//transformola variable para poderla comparar con el textbos
			String^ comparoContrasena = msclr::interop::marshal_as<System::String^>(leoContrasena);
			
			//si la contraseña es correcta paso al siguiente formulario
			if (contrasena->Text == comparoContrasena) {
				ACCESO^ main = gcnew ACCESO();
				main->ShowDialog();
			}
			//no es correcta la contraseña, muestro mensaje de error
			else {
				MessageBox::Show("Contraseña incorrecta");
			}
		}
		//no existe el usuario, mensaje de error
		else {
			MessageBox::Show("Error, no existe el usuario");
		}

	}

		   //********************FORMULARIO PARA CREAR NUEVOS USUSARIOS *****************************

private: System::Void eCrear_LinkClicked(System::Object^ sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^ e) {
	//llamada al formulario para crear nuevos ususarios
	NUEVOUSUARIO^ main = gcnew NUEVOUSUARIO();
	main->ShowDialog();
}

private: System::Void eOlvido_LinkClicked(System::Object^ sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^ e) {
	NUEVACONTRA^ main = gcnew NUEVACONTRA();
	main->ShowDialog();
}
};
}
