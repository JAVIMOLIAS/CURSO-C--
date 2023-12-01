#pragma once

namespace Project1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de CARRITO
	/// </summary>
	public ref class CARRITO : public System::Windows::Forms::Form
	{
	public:
		CARRITO()
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
		~CARRITO()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ bCompra;
	protected:
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ eAutor;

	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ eTitulo;

	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ ePrecio;


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
			this->bCompra = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->eAutor = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->eTitulo = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->ePrecio = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// bCompra
			// 
			this->bCompra->Location = System::Drawing::Point(301, 412);
			this->bCompra->Name = L"bCompra";
			this->bCompra->Size = System::Drawing::Size(118, 66);
			this->bCompra->TabIndex = 0;
			this->bCompra->Text = L"Comprar";
			this->bCompra->UseVisualStyleBackColor = true;
			this->bCompra->Click += gcnew System::EventHandler(this, &CARRITO::bCompra_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(169, 108);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(41, 16);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Autor:";
			// 
			// eAutor
			// 
			this->eAutor->AutoSize = true;
			this->eAutor->Location = System::Drawing::Point(240, 108);
			this->eAutor->Name = L"eAutor";
			this->eAutor->Size = System::Drawing::Size(44, 16);
			this->eAutor->TabIndex = 2;
			this->eAutor->Text = L"label2";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(167, 184);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(43, 16);
			this->label3->TabIndex = 3;
			this->label3->Text = L"Título:";
			// 
			// eTitulo
			// 
			this->eTitulo->AutoSize = true;
			this->eTitulo->Location = System::Drawing::Point(240, 184);
			this->eTitulo->Name = L"eTitulo";
			this->eTitulo->Size = System::Drawing::Size(44, 16);
			this->eTitulo->TabIndex = 4;
			this->eTitulo->Text = L"label4";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(169, 251);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(49, 16);
			this->label5->TabIndex = 5;
			this->label5->Text = L"Precio:";
			// 
			// ePrecio
			// 
			this->ePrecio->AutoSize = true;
			this->ePrecio->Location = System::Drawing::Point(240, 251);
			this->ePrecio->Name = L"ePrecio";
			this->ePrecio->Size = System::Drawing::Size(44, 16);
			this->ePrecio->TabIndex = 6;
			this->ePrecio->Text = L"label6";
			// 
			// CARRITO
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(825, 659);
			this->Controls->Add(this->ePrecio);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->eTitulo);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->eAutor);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->bCompra);
			this->Name = L"CARRITO";
			this->Text = L"CARRITO";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private: System::Void bCompra_Click(System::Object^ sender, System::EventArgs^ e) {
}
};
}
