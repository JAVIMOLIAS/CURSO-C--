#pragma once
#include "mostrarDatos.h"

//librerias para trabajar con archivos
#include <fstream>
#include "msclr/marshal_cppstd.h"


namespace FormsVentana {

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
	private: System::Windows::Forms::Button^ benviar;
	protected:
	private: System::Windows::Forms::Label^ enombre;
	private: System::Windows::Forms::Label^ econtrasena;
	private: System::Windows::Forms::TextBox^ nombreUsuario;
	private: System::Windows::Forms::TextBox^ contrasena;

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
			this->benviar = (gcnew System::Windows::Forms::Button());
			this->enombre = (gcnew System::Windows::Forms::Label());
			this->econtrasena = (gcnew System::Windows::Forms::Label());
			this->nombreUsuario = (gcnew System::Windows::Forms::TextBox());
			this->contrasena = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// benviar
			// 
			this->benviar->Location = System::Drawing::Point(387, 383);
			this->benviar->Name = L"benviar";
			this->benviar->Size = System::Drawing::Size(75, 23);
			this->benviar->TabIndex = 0;
			this->benviar->Text = L"Enviar";
			this->benviar->UseVisualStyleBackColor = true;
			this->benviar->Click += gcnew System::EventHandler(this, &MyForm::benviar_Click);
			// 
			// enombre
			// 
			this->enombre->AutoSize = true;
			this->enombre->Location = System::Drawing::Point(162, 68);
			this->enombre->Name = L"enombre";
			this->enombre->Size = System::Drawing::Size(122, 16);
			this->enombre->TabIndex = 1;
			this->enombre->Text = L"Nombre de usuario";
			// 
			// econtrasena
			// 
			this->econtrasena->AutoSize = true;
			this->econtrasena->Location = System::Drawing::Point(162, 180);
			this->econtrasena->Name = L"econtrasena";
			this->econtrasena->Size = System::Drawing::Size(76, 16);
			this->econtrasena->TabIndex = 2;
			this->econtrasena->Text = L"Contraseña";
			// 
			// nombreUsuario
			// 
			this->nombreUsuario->Location = System::Drawing::Point(165, 111);
			this->nombreUsuario->Name = L"nombreUsuario";
			this->nombreUsuario->Size = System::Drawing::Size(211, 22);
			this->nombreUsuario->TabIndex = 3;
			// 
			// contrasena
			// 
			this->contrasena->Location = System::Drawing::Point(165, 232);
			this->contrasena->Name = L"contrasena";
			this->contrasena->Size = System::Drawing::Size(168, 22);
			this->contrasena->TabIndex = 4;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1064, 567);
			this->Controls->Add(this->contrasena);
			this->Controls->Add(this->nombreUsuario);
			this->Controls->Add(this->econtrasena);
			this->Controls->Add(this->enombre);
			this->Controls->Add(this->benviar);
			this->Name = L"MyForm";
			this->Text = L"Forms ventanas";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void benviar_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ pasoUsuario = nombreUsuario->Text;
		String^ pasoContrasena = contrasena->Text;
		mostrarDatos^ principal = gcnew mostrarDatos(pasoUsuario, pasoContrasena);
		//this->Hide();
		principal->ShowDialog();
		//this->Show();

		
		String^ datosenvio = nombreUsuario->Text + contrasena->Text;

		//convertimos a string de consola
		std::string paraEnviarStr = msclr::interop::marshal_as<std::string>(datosenvio);
		std::string nombre = msclr::interop::marshal_as<std::string>(nombreUsuario->Text);

		//creamos el archivo con nombre
		std::ofstream file(nombre + ".txt");

		//comprobamos que se ha creado el fichero
		if (file.is_open()) {
			file << paraEnviarStr; //grabamos datos en el fichero
			file.close();
		}
		nombreUsuario->Text = "";
		contrasena->Text = "";

	}
};
}
