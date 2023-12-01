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
	/// Resumen de NUEVOUSUARIO
	/// </summary>
	public ref class NUEVOUSUARIO : public System::Windows::Forms::Form
	{
	public:
		NUEVOUSUARIO(void)
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
		~NUEVOUSUARIO()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	protected:
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ nUsuario;
	private: System::Windows::Forms::TextBox^ contrasena;
	private: System::Windows::Forms::TextBox^ ccontrasena;


	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Button^ bEnvio;

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
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->nUsuario = (gcnew System::Windows::Forms::TextBox());
			this->contrasena = (gcnew System::Windows::Forms::TextBox());
			this->ccontrasena = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->bEnvio = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(304, 104);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(146, 20);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Introduzca nombre";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(304, 193);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(95, 20);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Contraseña";
			// 
			// nUsuario
			// 
			this->nUsuario->Location = System::Drawing::Point(307, 150);
			this->nUsuario->Name = L"nUsuario";
			this->nUsuario->Size = System::Drawing::Size(186, 22);
			this->nUsuario->TabIndex = 2;
			// 
			// contrasena
			// 
			this->contrasena->Location = System::Drawing::Point(307, 231);
			this->contrasena->Name = L"contrasena";
			this->contrasena->Size = System::Drawing::Size(186, 22);
			this->contrasena->TabIndex = 3;
			// 
			// ccontrasena
			// 
			this->ccontrasena->Location = System::Drawing::Point(307, 333);
			this->ccontrasena->Name = L"ccontrasena";
			this->ccontrasena->Size = System::Drawing::Size(186, 22);
			this->ccontrasena->TabIndex = 4;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(304, 282);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(176, 20);
			this->label3->TabIndex = 5;
			this->label3->Text = L"Comprobar contaseña";
			// 
			// bEnvio
			// 
			this->bEnvio->Location = System::Drawing::Point(353, 393);
			this->bEnvio->Name = L"bEnvio";
			this->bEnvio->Size = System::Drawing::Size(97, 55);
			this->bEnvio->TabIndex = 6;
			this->bEnvio->Text = L"Enviar";
			this->bEnvio->UseVisualStyleBackColor = true;
			this->bEnvio->Click += gcnew System::EventHandler(this, &NUEVOUSUARIO::bEnvio_Click);
			// 
			// NUEVOUSUARIO
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(916, 482);
			this->Controls->Add(this->bEnvio);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->ccontrasena);
			this->Controls->Add(this->contrasena);
			this->Controls->Add(this->nUsuario);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Name = L"NUEVOUSUARIO";
			this->Text = L"NUEVOUSUARIO";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private: System::Void bEnvio_Click(System::Object^ sender, System::EventArgs^ e) {

	//compara las 2 contraseñas para que si coinciden poder continuar
	if (ccontrasena->Text == contrasena->Text) {

		//creo variable para poder crear el fichero con los datos del usuario
		std::string nueArchivo = msclr::interop::marshal_as < std::string>(nUsuario->Text);
		std::ifstream fichero(nueArchivo + ".txt");

		//comprobar que no exista ya el usuario
		if (fichero.is_open()) {
			//ya existe el usuario, error
			MessageBox::Show("Error, el usuario ya esixte");
		}
		//no existe el usuario, lo creamos y añadimos la contraseña
		else {

			//creo variable c++ para asignarle el valor de contrasena.text
			std::string acontrasena = msclr::interop::marshal_as<std::string>(contrasena->Text);

			//creo el nuevo archivo añadiendo la contraseña
			std::ofstream creafichero(nueArchivo + ".txt");
			creafichero << acontrasena;
			creafichero.close();
		}

	}
	else {
		//no coincide la contraseña con la comprabación de la contraseña
		MessageBox::Show("Error, las contraseñas no coinciden");
	}
}
};
}
