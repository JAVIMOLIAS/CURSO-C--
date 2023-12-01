#pragma once

#include <mysql.h>
#include <Windows.h>
#include "msclr/marshal_cppstd.h"
#include "CARRITO.h"


//variables para poder hacer consultas a la base de datos
MYSQL* conectar;
MYSQL_RES* resultado;
MYSQL_ROW fila;

namespace Project1 {

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
		//función para conectar con la base de datos, devuelve true si conecta, false si no
		bool conectamos(void)
		{
			
			conectar = mysql_init(0);

			//puerto de conexción
			int puerto = 3366;

			//pasamos los datos de la base de datos
			conectar = mysql_real_connect(conectar, "localhost", "JAVIMOLIAS", "ARZOBISPO1974@", "biblioteca", puerto, NULL, 0);

			if (!conectar) {
				return false;
			}
			return true;
		}


		//función que lee los datos de la tabla para mostrarlos en el datagrid del formulario
		bool tomadatos(void)
		{
			//comprobamos que podemos leer los datos, devuelve true si puede, false si no
			if (mysql_query(conectar, "SELECT * FROM libros")) {
				return false;
			}
			resultado = mysql_store_result(conectar);

			//creamos una tabla a la que añadir los datos de la tabla SQL
			DataTable^ Tabla = gcnew DataTable();

			for (unsigned int i = 0; i < mysql_num_fields(resultado); i++) {
				Tabla->Columns->Add(gcnew String(mysql_fetch_field_direct(resultado, i)->name));
			}

			while (fila = mysql_fetch_row(resultado)) {
				DataRow^ datarow = Tabla->NewRow();
				for (unsigned int i = 0; i < mysql_num_fields(resultado); i++) {
					datarow[i] = gcnew String(fila[i] ? fila[i] : "NULL");
				}
				Tabla->Rows->Add(datarow);
			}

			dataGridView1->DataSource = Tabla;
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
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::Button^ button1;
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
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->button1 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Location = System::Drawing::Point(279, 149);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersWidth = 51;
			this->dataGridView1->RowTemplate->Height = 24;
			this->dataGridView1->Size = System::Drawing::Size(832, 430);
			this->dataGridView1->TabIndex = 0;
			this->dataGridView1->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MyForm::dataGridView1_CellContentClick);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(545, 695);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(110, 69);
			this->button1->TabIndex = 1;
			this->button1->Text = L"button1";
			this->button1->UseVisualStyleBackColor = true;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1694, 946);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->dataGridView1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {

		//comprobación de que hemos podido conectar con la base de datos
		if (!conectamos()) {

			//no conecta
			MessageBox::Show("Error, no se ha podido conectar");
		}
		else {
			//conecta
			MessageBox::Show("Conexción correcta");
			if (!tomadatos()) {
				MessageBox::Show("Se ha conectado con la base de datos \n pero no con la tabla");
			}
		}
	}
	private: System::Void dataGridView1_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {


		//creamos para poder entrar al formulario carrito
		CARRITO^ principal = gcnew CARRITO();

		principal->ShowDialog();
	}
};
}
