#pragma once
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
	/// Resumen de mostrarDatos
	/// </summary>
	public ref class mostrarDatos : public System::Windows::Forms::Form
	{
	public:
		mostrarDatos(String^pasoUsuario, String^pasoContrasena)
		{
			InitializeComponent();
			verusuario->Text = pasoUsuario;
			vercontrasena->Text = pasoContrasena;
			String^ leemos = "inicializo";
			//convertirmos a c++ el string de cli del archivo que queremos abrir
			std::string nombretxt = msclr::interop::marshal_as<std::string>(verusuario->Text);

			//decimos qué archivo queremos abrir
			std::ifstream file(nombretxt + ".txt");

			//leemos el contenido del archvivo
			if (file.is_open()) {
				std::string contenidoArchivo((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
				String^ leer = msclr::interop::marshal_as<System::String^>(contenidoArchivo);
				leemos = leer;
				MessageBox::Show(leemos);

			}
			//cerramos fichero
			file.close();
			
			//
			//TODO: agregar código de constructor aquí
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~mostrarDatos()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ verusuario;
	protected:

	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ vercontrasena;


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
			this->verusuario = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->vercontrasena = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(160, 87);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(122, 16);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Nombre de usuario";
			// 
			// verusuario
			// 
			this->verusuario->AutoSize = true;
			this->verusuario->Location = System::Drawing::Point(160, 127);
			this->verusuario->Name = L"verusuario";
			this->verusuario->Size = System::Drawing::Size(44, 16);
			this->verusuario->TabIndex = 1;
			this->verusuario->Text = L"label2";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(160, 180);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(76, 16);
			this->label3->TabIndex = 2;
			this->label3->Text = L"Contraseña";
			// 
			// vercontrasena
			// 
			this->vercontrasena->AutoSize = true;
			this->vercontrasena->Location = System::Drawing::Point(160, 236);
			this->vercontrasena->Name = L"vercontrasena";
			this->vercontrasena->Size = System::Drawing::Size(44, 16);
			this->vercontrasena->TabIndex = 3;
			this->vercontrasena->Text = L"label4";
			// 
			// mostrarDatos
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(856, 387);
			this->Controls->Add(this->vercontrasena);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->verusuario);
			this->Controls->Add(this->label1);
			this->Name = L"mostrarDatos";
			this->Text = L"mostrarDatos";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	};
}
