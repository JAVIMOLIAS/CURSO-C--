#pragma once

#include <mysql.h>
#include <Windows.h>
#include <fstream>
#include "msclr/marshal_cppstd.h"

//variables para el código necesario para acceder a las bases SQL
MYSQL* conectar;
MYSQL_RES* resultado;
MYSQL_ROW fila;

namespace BASEDATOS {

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



	private:
		bool conectamos() {
			//código para conectar con la base de datos
			conectar = mysql_init(0);

			//puerto de entrada a sql
			int puerto = 3366;

			//datos de usuario y base de datos a la que queremos acceder
			conectar = mysql_real_connect(conectar, "localhost", "JAVIMOLIAS", "ARZOBISPO1974@", "curso cpp", puerto, NULL, 0);

			//comprobamos que pueda conectar
			if (!conectar) {
				// no conectra
				return false;
			}

			//si conecta
			return true;
		}

			bool leerdatos() {
				//comprobar que ademas de poder entrar en la base de datos accedamos correctamente a la tabla

				if (mysql_query(conectar, "SELECT * FROM alumnos")) {
					//no accede correctamente a la tabla
					return false;
				}

				//accede correctamente a la tabla alumnos

				resultado = mysql_store_result(conectar); // asignar a resultado la consulta

				//creamos una tabla en la que colocaremos los datos de la tabla de la base de datos
				DataTable^ Tabla = gcnew DataTable();

				//asignamos a cada columna el nombre del campo mientras haya campos
				for (unsigned int i = 0; i < mysql_num_fields(resultado); i++) {
					Tabla->Columns->Add(gcnew String(mysql_fetch_field_direct(resultado, i)->name));
				}

				//recorremos la tabla de la base de datos
				while ((fila = mysql_fetch_row(resultado))) {

					//añadir nueva fila a la table
					DataRow^ datarow = Tabla->NewRow();

					//mientras haya filas en la tabla de la base de datos
					for (unsigned int i = 0; i < mysql_num_fields(resultado); i++) {

						//asignamos los valores de la tabla de la base de datos a datarow
						datarow[i] = gcnew String(fila[i] ? fila[i] : "NULL");
					}

					//metemos los valores de datarow en nuestra tabla
					Tabla->Rows->Add(datarow);
				}

				dataGridView1->DataSource = Tabla; //asignamos al data grid del formulario los datos de la tabla que acabamos de crear con  los datos de SQL

				mysql_free_result(resultado); // para limpiar los datos de la consulta
				return true;


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
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::DataGridView^ dataGridView1;

	private: System::Windows::Forms::TextBox^ nombre;
	private: System::Windows::Forms::TextBox^ contrasena;






	protected:

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
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->nombre = (gcnew System::Windows::Forms::TextBox());
			this->contrasena = (gcnew System::Windows::Forms::TextBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(118, 449);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(133, 73);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Consultar";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Location = System::Drawing::Point(299, 160);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersWidth = 51;
			this->dataGridView1->RowTemplate->Height = 24;
			this->dataGridView1->Size = System::Drawing::Size(639, 292);
			this->dataGridView1->TabIndex = 1;
			// 
			// nombre
			// 
			this->nombre->Location = System::Drawing::Point(131, 565);
			this->nombre->Name = L"nombre";
			this->nombre->Size = System::Drawing::Size(179, 22);
			this->nombre->TabIndex = 3;
			// 
			// contrasena
			// 
			this->contrasena->Location = System::Drawing::Point(440, 565);
			this->contrasena->Name = L"contrasena";
			this->contrasena->Size = System::Drawing::Size(221, 22);
			this->contrasena->TabIndex = 4;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1243, 665);
			this->Controls->Add(this->contrasena);
			this->Controls->Add(this->nombre);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->button1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {


		//llama a la función para conectar a la base de datos
		if (conectamos()){

			//pasamos a string c++ los datos que quermos introducir
			std::string NombreStr = msclr::interop::marshal_as < std::string>(nombre->Text); 
			std::string ContrasenaStr = msclr::interop::marshal_as<std::string>(contrasena->Text);

			//pasamos a c++ la orden de SQL para insertar los datos 
			std::string query = "INSERT INTO alumnos (nombre, contrasena) VALUES ('"+ NombreStr +"', '" + ContrasenaStr + "')";


			//comprueba si ya existe el alumno
			if (mysql_query(conectar, query.c_str())) {
				// si se cumple da error y no crea el usuario
				MessageBox::Show("error");
			}

			//después de añadir los datos refresa la ventana
			leerdatos();
		}



	}
private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
	//llamada a la función para conectar a la base de datos
	if (conectamos()) {

		//llamada a la función que lee los datos de la tabla
		if (!leerdatos()) {

			//ha conectado con la base de datos, pero algo falla en la tabla
			MessageBox::Show("Error, no se puede hacer la consulta");
		}

		//cerramos la base de datos
		mysql_close(conectar);
	}
	else {

		//si no consigue entrar en la base de datos
		MessageBox::Show("no conectado");
	}
}
};
}
