#include "p6_lib.h" 

int main(int argc, char* argv[])
{
	char ch, ch1; 
	
	ch = 'A'; 
	print_char_info(ch, &ch, sizeof(ch)); // ASCII 'A'
	ch1 = '다'; 
	print_char_info(ch1, &ch1, sizeof(ch1)); // CP949 '가'
	
	wctype_t wc1, wc2; 
	setlocale(LC_ALL, "KOREAN");

	wc1 = L'다';	 
	print_wchar_info(wc1, &wc1, sizeof(wc1)); // Unicode '가'
	wc2 = '다'; // CP949 '가'
	print_wchar_info(wc2, &wc2, sizeof(wc2));

	wprintf(L"\n한글 L'가' 코드값 : %x\n", L'다'); 
	wprintf(L"한글 '가' 출력 : %c\n", L'다'); 
	
	wprintf(L"한글 '가' 코드값 : %x\n", '다'); 
    wprintf(L"한글 '가' 출력 : %c\n", '다'); 

	return 0;
}