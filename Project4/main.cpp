#include <windows.h>
#include <tchar.h>

INT WINAPI _tWinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPTSTR lpszCmdLine, int nCmdShow) {

	const wchar_t message1[] = L"From simple utilities to complex software, window applications cater to diverse needs. They provide seamless integration with hardware, ensuring optimal performance and user satisfaction.";
	const wchar_t message2[] = L"Window applications revolutionize industries, powering everything from gaming to finance. Their adaptability fuels innovation, driving progress in technology and enhancing user experiences worldwide.";
	const wchar_t message3[] = L"Window applications empower users to customize their digital workspace, optimizing efficiency and workflow. They enable seamless communication and collaboration across teams, fostering creativity and productivity.";
	int messageC1 = _tcslen(message1);
	int messageC2 = _tcslen(message2);
	int messageC3 = _tcslen(message3);
	int messageCount = messageC1 + messageC2 + messageC3;
	_TCHAR buff[100];
	MessageBox(0,
		message1, _TEXT("Message"), MB_OK | MB_ICONINFORMATION | MB_SETFOREGROUND);

	MessageBox(0, message2,
		_TEXT("Message"), MB_OK | MB_ICONINFORMATION | MB_SETFOREGROUND);

	_stprintf_s(buff, _TEXT("Word count: %d"), messageCount);

	MessageBox(0,
		message2, buff,
		MB_OK | MB_ICONINFORMATION | MB_SETFOREGROUND);

	_TCHAR buffer[150];

	int number = 3;
	int counter = 0;
	int answer = 0;
	bool bPlayAgain = true;
	bool bGame = false;

	int start = MessageBox(0,
		_TEXT("Start?"),
		_TEXT("Game"), MB_YESNO | MB_ICONQUESTION | MB_SETFOREGROUND);

	if (start == IDYES) {
		do {
			wsprintf(buff, _TEXT("It's number: %d ?"), counter);

			answer = MessageBox(0,
				buffer,
				_TEXT("Numbers"),
				MB_YESNO | MB_ICONQUESTION | MB_DEFBUTTON2 | MB_SETFOREGROUND);
			if (counter != number && answer == IDYES) {
				MessageBox(0,
					_TEXT("Nice!"),
					_TEXT("game"), MB_OK | MB_ICONEXCLAMATION | MB_SETFOREGROUND);
				bGame = true;
			}

			if (bGame) {
				int playAgain = MessageBox(0,
					_TEXT("Want to play again?"),
					_TEXT("Game"),
					MB_YESNO | MB_ICONQUESTION | MB_SETFOREGROUND);

				if (playAgain == IDYES) {
					counter = -1;
					bGame = false;
				}
				else {
					bPlayAgain = false;
				}
			}

			counter++;
		} while (bPlayAgain);
	}

	if (!bPlayAgain || start == IDNO) {
		MessageBox(0,
			_TEXT("GoodBye"),
			_TEXT("Over"), MB_OK | MB_ICONEXCLAMATION | MB_SETFOREGROUND);
	}

	return 0;
}