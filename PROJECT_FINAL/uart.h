// Function prototypes defined in header file for UART library
// .h files should be included in main app in order to use the library

void uart_SetBaudRate(int baud);
void uart_init (int baud);
void uart_transmit (unsigned char data);
unsigned char uart_recieve (void);
int uart_recieve_ready (void);
void UART_Write_Text(char * UART_text);
#define SET_BIT(REG,BIT) REG|=(1<<BIT)
#define CLR_BIT(REG,BIT) REG&=~(1<<BIT)
void UART_receiveString(char *str, unsigned char maxLength);

