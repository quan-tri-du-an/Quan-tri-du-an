// hàm gửi lệnh điều khiển

void LCD_Send_Command(unsigned char x)
{
	LCD_DATA=x;
	RS=0; //Chon thanh ghi lenh
	RW=0; //De ghi du lieu
	EN=1;
	Delay_ms(1);
	EN=0;
	Wait_For_LCD(); //Doi cho LCD san sang
	EN=1;
}
// hàm gửi kí tự
void LCD_Write_One_Char(unsigned char c)
{
	LCD_DATA=c; //Dua du lieu vao thanh ghi
	RS=1; //Chon thanh ghi du lieu
	RW=0;
	EN=1;
	Delay_ms(1);
	EN=0;
	Wait_For_LCD();
	EN=1;
}
// khởi tạo lcd
void LCD_init()
{
	//Chon che do 5x7 bit, 2 hang cho LCD
	LCD_Send_Command(0x38);
	//Bat hien thi, nhap nhay con tro
	LCD_Send_Command(0x0E);
	LCD_Send_Command(0x01); //Xoa man hinh
	LCD_Send_Command(0x80); //Ve dau dong
}