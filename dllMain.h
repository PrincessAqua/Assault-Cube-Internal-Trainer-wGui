#pragma once

extern void Patch(BYTE* destination, BYTE* source, unsigned int size);
extern void Nop(BYTE* destination, unsigned int size);
extern int healthFunc();
extern int jmpFunc();

extern bool healthThreadStatus;
extern bool jumpThreadStatus;

namespace internalTrainer {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de dllMain
	/// </summary>
	public ref class dllMain : public System::Windows::Forms::Form
	{
	public:
		dllMain(void)
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
		~dllMain()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ btnHealth;
	protected:
	private: System::Windows::Forms::Button^ btnAmmo;
	private: System::Windows::Forms::Button^ btnJmp;
	private: System::Windows::Forms::Button^ btnRecoil;
	private: System::Windows::Forms::Button^ btnRapidFire;
	private: System::Windows::Forms::Button^ btnExit;

	private: bool bHealth = 0;
	private: bool bAmmo = 0;
	private: bool bJump = 0;
	private: bool bRecoil = 0;
	private: bool bRapidFire = 0;

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(dllMain::typeid));
			this->btnHealth = (gcnew System::Windows::Forms::Button());
			this->btnAmmo = (gcnew System::Windows::Forms::Button());
			this->btnJmp = (gcnew System::Windows::Forms::Button());
			this->btnRecoil = (gcnew System::Windows::Forms::Button());
			this->btnRapidFire = (gcnew System::Windows::Forms::Button());
			this->btnExit = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// btnHealth
			// 
			this->btnHealth->Font = (gcnew System::Drawing::Font(L"Nirmala UI", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnHealth->Location = System::Drawing::Point(157, 12);
			this->btnHealth->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->btnHealth->Name = L"btnHealth";
			this->btnHealth->Size = System::Drawing::Size(75, 22);
			this->btnHealth->TabIndex = 0;
			this->btnHealth->Text = L"Health";
			this->btnHealth->UseVisualStyleBackColor = true;
			this->btnHealth->Click += gcnew System::EventHandler(this, &dllMain::btnHealth_Click);
			// 
			// btnAmmo
			// 
			this->btnAmmo->Font = (gcnew System::Drawing::Font(L"Nirmala UI", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnAmmo->Location = System::Drawing::Point(157, 41);
			this->btnAmmo->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->btnAmmo->Name = L"btnAmmo";
			this->btnAmmo->Size = System::Drawing::Size(75, 22);
			this->btnAmmo->TabIndex = 1;
			this->btnAmmo->Text = L"Ammo";
			this->btnAmmo->UseVisualStyleBackColor = true;
			this->btnAmmo->Click += gcnew System::EventHandler(this, &dllMain::btnAmmo_Click);
			// 
			// btnJmp
			// 
			this->btnJmp->Font = (gcnew System::Drawing::Font(L"Nirmala UI", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnJmp->Location = System::Drawing::Point(157, 70);
			this->btnJmp->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->btnJmp->Name = L"btnJmp";
			this->btnJmp->Size = System::Drawing::Size(75, 22);
			this->btnJmp->TabIndex = 2;
			this->btnJmp->Text = L"Jump";
			this->btnJmp->UseVisualStyleBackColor = true;
			this->btnJmp->Click += gcnew System::EventHandler(this, &dllMain::btnJmp_Click);
			// 
			// btnRecoil
			// 
			this->btnRecoil->Font = (gcnew System::Drawing::Font(L"Nirmala UI", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnRecoil->Location = System::Drawing::Point(157, 99);
			this->btnRecoil->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->btnRecoil->Name = L"btnRecoil";
			this->btnRecoil->Size = System::Drawing::Size(75, 22);
			this->btnRecoil->TabIndex = 3;
			this->btnRecoil->Text = L"Recoil";
			this->btnRecoil->UseVisualStyleBackColor = true;
			this->btnRecoil->Click += gcnew System::EventHandler(this, &dllMain::btnRecoil_Click);
			// 
			// btnRapidFire
			// 
			this->btnRapidFire->Font = (gcnew System::Drawing::Font(L"Nirmala UI", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnRapidFire->Location = System::Drawing::Point(157, 128);
			this->btnRapidFire->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->btnRapidFire->Name = L"btnRapidFire";
			this->btnRapidFire->Size = System::Drawing::Size(75, 22);
			this->btnRapidFire->TabIndex = 4;
			this->btnRapidFire->Text = L"RapidFire";
			this->btnRapidFire->UseVisualStyleBackColor = true;
			this->btnRapidFire->Click += gcnew System::EventHandler(this, &dllMain::btnRapidFire_Click);
			// 
			// btnExit
			// 
			this->btnExit->Font = (gcnew System::Drawing::Font(L"Nirmala UI", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnExit->ForeColor = System::Drawing::Color::Red;
			this->btnExit->Location = System::Drawing::Point(157, 230);
			this->btnExit->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->btnExit->Name = L"btnExit";
			this->btnExit->Size = System::Drawing::Size(75, 22);
			this->btnExit->TabIndex = 5;
			this->btnExit->Text = L"DetachExit";
			this->btnExit->UseVisualStyleBackColor = true;
			this->btnExit->Click += gcnew System::EventHandler(this, &dllMain::btnExit_Click);
			// 
			// dllMain
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Lavender;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(244, 301);
			this->Controls->Add(this->btnExit);
			this->Controls->Add(this->btnRapidFire);
			this->Controls->Add(this->btnRecoil);
			this->Controls->Add(this->btnJmp);
			this->Controls->Add(this->btnAmmo);
			this->Controls->Add(this->btnHealth);
			this->DoubleBuffered = true;
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"dllMain";
			this->Text = L"AC Internal Trainer";
			this->ResumeLayout(false);

		}
#pragma endregion
private: System::Void btnHealth_Click(System::Object^ sender, System::EventArgs^ e)
{
	this->bHealth = !this-> bHealth;
	healthThreadStatus = bHealth;

	if (this->bHealth)
	{
		CloseHandle(CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)healthFunc, NULL, NULL, NULL));
	}
}

private: System::Void btnAmmo_Click(System::Object^ sender, System::EventArgs^ e)
{
	this->bAmmo = !this->bAmmo;
	uintptr_t moduleBase = (uintptr_t)GetModuleHandle(L"ac_client.exe");

	if (this->bAmmo)
	{
		Nop((BYTE*)moduleBase + 0xC73EF, 2);
	}
	else
	{
		Patch((BYTE*)moduleBase + 0xC73EF, (BYTE*)"\xFF\x08", 2);
	}
}

private: System::Void btnJmp_Click(System::Object^ sender, System::EventArgs^ e)
{
	this->bJump = !this->bJump;
	jumpThreadStatus = bJump;

	if (this->bJump)
	{
		CloseHandle(CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)jmpFunc, NULL, NULL, NULL));
	}

}

private: System::Void btnRecoil_Click(System::Object^ sender, System::EventArgs^ e)
{
	this->bRecoil = !this->bRecoil;
	uintptr_t moduleBase = (uintptr_t)GetModuleHandle(L"ac_client.exe");

	if (this->bRecoil)
	{
		Nop((BYTE*)moduleBase + 0xC8E52, 5);
	}
	else
	{
		Patch((BYTE*)moduleBase + 0xC8E52, (BYTE*)"\xF3\x0F\x11\x50\x40", 5);
	}

}

private: System::Void btnRapidFire_Click(System::Object^ sender, System::EventArgs^ e)
{
	this->bRapidFire = !this->bRapidFire;
	uintptr_t moduleBase = (uintptr_t)GetModuleHandle(L"ac_client.exe");

	if (this->bRapidFire)
	{
		Nop((BYTE*)moduleBase + 0xCB795, 6);
	}
	else
	{
		Patch((BYTE*)moduleBase + 0xCB795, (BYTE*)"\x89\x9D\xEC\x01\x00\x00", 6);
	}

}

private: System::Void btnExit_Click(System::Object^ sender, System::EventArgs^ e)
{
	uintptr_t moduleBase = (uintptr_t)GetModuleHandle(L"ac_client.exe");

	if (healthThreadStatus){healthThreadStatus = 0;}
	if (jumpThreadStatus){jumpThreadStatus = 0;}
	if (bAmmo){ Patch((BYTE*)moduleBase + 0xC73EF, (BYTE*)"\xFF\x08", 2); }
	if (bRecoil){ Patch((BYTE*)moduleBase + 0xC8E52, (BYTE*)"\xF3\x0F\x11\x50\x40", 5); }
	if (bRapidFire){ Patch((BYTE*)moduleBase + 0xCB795, (BYTE*)"\x89\x9D\xEC\x01\x00\x00", 6); }
	FreeLibraryAndExitThread(0,0);
}

};
}
