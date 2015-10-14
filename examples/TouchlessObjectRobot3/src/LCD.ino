/** SLCD Function **/
void LCD_Show(int Position,int x){
  MySerial.print(0xFE);          // Clear Screen
  MySerial.print(Position);
  MySerial.print(x,DEC);              // Show Data in Decimal
}
void LCD_Show_Text(int Position,char* x){
  MySerial.print(0xFE);          // Clear Screen
  MySerial.print(Position);
  MySerial.print(x);                  // Show text
}
void LCD_Clear(){
  MySerial.print(0xFE);          // Clear Screen
  MySerial.print(0x01);
}
void LCD_Show_Vars(){
  LCD_Clear();
  LCD_Show_Text(0x80,"GP2:");
  LCD_Show(0x8A,gp2);
  LCD_Show_Text(0xC0,"DIS:");
  LCD_Show(0xCA,distance);
} 

