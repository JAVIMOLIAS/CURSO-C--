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
	/// Resumen de NUEVACONTRA
	/// </summary>
	public ref class NUEVACONTRA : public System::Windows::Forms::Form
	{
	public:
	public: String^ usuario;
		NUEVACONTRA()
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
		~NUEVACONTRA()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ contrasena;
	private: System::Windows::Forms::TextBox^ cContrasena;




	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Button^ bEnvia;
	private: System::Windows::Forms::Label^ text;
	private: System::Windows::Forms::TextBox^ nombreUsuario;



	private: System::ComponentModel::IContainer^ components;


	protected:

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->contrasena = (gcnew System::Windows::Forms::TextBox());
			this->cContrasena = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->bEnvia = (gcnew System::Windows::Forms::Button());
			this->text = (gcnew System::Windows::Forms::Label());
			this->nombreUsuario = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(347, 237);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(138, 20);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Nueva contraseña";
			// 
			// contrasena
			// 
			this->contrasena->Location = System::Drawing::Point(351, 296);
			this->contrasena->Name = L"contrasena";
			this->contrasena->Size = System::Drawing::Size(205, 26);
			this->contrasena->TabIndex = 1;
			// 
			// cContrasena
			// 
			this->cContrasena->Location = System::Drawing::Point(351, 394);
			this->cContrasena->Name = L"cContrasena";
			this->cContrasena->Size = System::Drawing::Size(205, 26);
			this->cContrasena->TabIndex = 2;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(347, 335);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(140, 20);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Repite contraseña";
			// 
			// bEnvia
			// 
			this->bEnvia->Location = System::Drawing::Point(384, 495);
			this->bEnvia->Name = L"bEnvia";
			this->bEnvia->Size = System::Drawing::Size(146, 61);
			this->bEnvia->TabIndex = 4;
			this->bEnvia->Text = L"Enviar";
			this->bEnvia->UseVisualStyleBackColor = true;
			this->bEnvia->Click += gcnew System::EventHandler(this, &NUEVACONTRA::bEnvia_Click);
			// 
			// text
			// 
			this->text->AutoSize = true;
			this->text->Location = System::Drawing::Point(351, 109);
			this->text->Name = L"text";
			this->text->Size = System::Drawing::Size(121, 20);
			this->text->TabIndex = 5;
			this->text->Text = L"Nombre usuario";
			// 
			// nombreUsuario
			// 
			this->nombreUsuario->Location = System::Drawing::Point(351, 171);
			this->nombreUsuario->Name = L"nombreUsuario";
			this->nombreUsuario->Size = System::Drawing::Size(325, 26);
			this->nombreUsuario->TabIndex = 6;
			// 
			// NUEVACONTRA
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1003, 605);
			this->Controls->Add(this->nombreUsuario);
			this->Controls->Add(this->text);
			this->Controls->Add(this->bEnvia);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->cContrasena);
			this->Controls->Add(this->contrasena);
			this->Controls->Add(this->label1);
			this->Name = L"NUEVACONTRA";
			this->Text = L"NUEVACONTRA";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private: System::Void bEnvia_Click(System::Object^ sender, System::EventArgs^ e) {
	//compara las 2 contraseñas para que si coinciden poder continuar
	if (cContrasena->Text == contrasena->Text) {

		//creo variable para poder comprobar si existe el fichero con los datos del usuario
		std::string Archivo = msclr::interop::marshal_as < std::string>(nombreUsuario->Text);
		MessageBox::Show(nombreUsuario->Text);

		//creo variable con el nombre del fichero del usuario
		std::ifstream ficheroUsuario(Archivo + ".txt");

		//comprobar que existe usuario
		if (ficheroUsuario.is_open()) {
			//creo variable c++ para asignarle el valor de contrasena.text
			std::string acontrasena = msclr::interop::marshal_as<std::string>(contrasena->Text);

			//machaco el fichero anterior con los nuevos datos
			std::ofstream ficheroUsuario(Archivo + ".txt");
			ficheroUsuario << acontrasena;
			ficheroUsuario.close();
		}
		//no existe el usuario, mensaje de error
		else {
			MessageBox::Show("Error, no existe el usuario");

		}

	}
	else {
		//no coincide la contraseña con la comprabación de la contraseña
		MessageBox::Show("Error, las contraseñas no coinciden");
	}

}
};
}
